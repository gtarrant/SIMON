#include "simon.h"
#include <iostream>

void SIMON::encrypt(void* addr, unsigned nblocks){
	INT* data = static_cast<INT*>(addr);
	for (int i = 0; i < nblocks; ++i){
		INT& x = *data;
		data++;
		INT& y = *data;
		data++;
		for (int j = 0; j < T; ++j){
			round(x, y, j);
		}
	}


}

void SIMON::decrypt(void* addr, unsigned nblocks){
	INT* data = static_cast<INT*>(addr);
	for (int i = 0; i < nblocks; ++i){
		INT& x = *data;
		data++;
		INT& y = *data;
		data++;
		for (int j = T-1; j >= 0; --j){
			roundInv(x, y, j);
		}
	}
}


void SIMON::roundInv(INT& x, INT &y, const unsigned& i){
	INT temp = y;
	y = x ^ (rol(y,1) & rol(y,8)) ^ rol(y,2) ^ k[i];
	x = temp;
}

void SIMON::round(INT& x, INT& y, const unsigned& i){
	INT temp = x;
	x = y ^ (rol(x,1) & rol(x,8)) ^ rol(x,2) ^ k[i];
	y = temp;
}

void SIMON::setKey(const pair<INT, INT>& key){
	k[0] = key.second;
	k[1] = key.first;
	for (int i = m; i < T; ++i){
		INT temp = ror(k[i-1],3);
		temp = temp ^ ror(temp, 1);
		k[i] = ~k[i-m] ^ temp ^ z[(i-m) % 62] ^ 3;
	}
}
