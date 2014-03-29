#include "uberzahl.h"
#include <limits.h>
#include <utility>
#include <random>

// implementation of SIMON using 128-bit blocks and 128-bit keys
// must compile with -std=c++11 

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

class SIMON {
	// round keys
	INT k[T];

	// random number generator
	mt19937 gen;

	// left rotate
	inline INT rol(INT val, unsigned k){
		return (val << k) | (val >> (sizeof(INT)*CHAR_BIT-k));
	};

	// right rotate
	inline INT ror(INT val, unsigned k){
		return (val >> k) | (val << (sizeof(INT)*CHAR_BIT-k));
	};

	void round(INT &x, INT &y, const unsigned& i);

	void roundInv(INT& x, INT &y, const unsigned& i);

  public:
	// constructor takes arg to seed random number generator
	inline SIMON(unsigned seed = 0){ gen.seed(seed); };

	// generate 128-bit key split in two 64-bit ints
	inline pair<INT, INT> genKey(){ return {gen(), gen()}; };

	// set 128-bit key and perform key expansion
	void setKey(const pair<INT, INT>&);

	// encrypt nblocks*128 bits of contiguous memory starting at addr
	// NOTE: can segfault if user does not own mem in range [addr, addr+16*nblocks)
	void encrypt(void* addr, unsigned nblocks);
	void decrypt(void* addr, unsigned nblocks);
};
