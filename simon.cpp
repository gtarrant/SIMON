#include "uberzahl.h"
#include <iostream>
#include <limits.h>
#include <utility>
#include <cstdlib>

using std::cout;
using std::endl;
using std::pair;

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

	// left rotate
	inline INT rol(INT val, unsigned k){
		return (val << k) | (val >> (sizeof(INT)*CHAR_BIT-k));
	};

	// right rotate
	inline INT ror(INT val, unsigned k){
		return (val >> k) | (val << (sizeof(INT)*CHAR_BIT-k));
	};

	pair<INT, INT> encBlock(INT x, INT y);

  public:
	// generate 128-bit key split in two 64-bit ints
	pair<INT, INT> genKey(unsigned seed = 0);
	// set 128-bit key and perform key expansion
	void setKey(const pair<INT, INT>&);
};

int main(){
}
