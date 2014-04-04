#ifndef SIMON_H
#define SIMON_H

#include <utility>
#include <random>
#include <limits.h>
#include "uberzahl.h"

#define rol(val,k) ((val<<k)|(val>>(sizeof(INT)*CHAR_BIT-k)))
#define ror(val,k) ((val>>k)|(val<<(sizeof(INT)*CHAR_BIT-k)))

// implementation of SIMON using 128-bit blocks and 128-bit keys
// must compile with -std=c++11 
// tested on caen linux; should work if unsigned long long is 64 bits

using std::pair;
using std::mt19937;

typedef unsigned long long INT;

// word size
#define n 64

// # key words
#define m 2

// # of rounds
#define T 68

// round constants
static const unsigned z[62] ={1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,
						1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,0,1,0,
						0,0,0,1,0,0,0,1,1,1,1,1,1,0,0,1,0,1,
						1,0,1,1,0,0,1,1};

// USAGE: create SIMON object w/ optional seed
// call genKey/setKey before encryption/decryption
class SIMON {
	// round keys
	INT k[T];

	// random number generator
	mt19937 gen;

	void round(INT &x, INT &y, const unsigned& i);

	void roundInv(INT& x, INT &y, const unsigned& i);
	
	void uberToArray(const uberzahl &num, INT* data, INT bytes);
	void arrayToUber(uberzahl &num, INT* data, INT bytes);
	void doCryptography(uberzahl &num, bool isEncryption);
  public:
	// constructor takes arg to seed random number generator
	inline SIMON(unsigned seed = 0){ gen.seed(seed); };

	// generate 128-bit key split in two 64-bit ints
	inline pair<INT, INT> genKey(){ return {gen(), gen()}; };

	// set 128-bit key and perform key expansion
	void setKey(const pair<INT, INT>&);

	void setAndGenKey() {setKey(genKey());}

	uberzahl encrypt(uberzahl num);
	uberzahl decrypt(uberzahl num);

	// encrypt nblocks*16 bytes of contiguous memory starting at addr
	// NOTE: can segfault if user does not own 
	// mem in range [addr, addr+16*nblocks)
	void encryptArray(void* addr, unsigned nblocks);
	void decryptArray(void* addr, unsigned nblocks);

};

#endif //SIMON_H
