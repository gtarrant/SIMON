#include "simon.h"
#include <iostream>
#include <assert.h>

void SIMON::encryptArray(void* addr, unsigned nblocks){
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

void SIMON::decryptArray(void* addr, unsigned nblocks){
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

uberzahl SIMON::encrypt(uberzahl num) {
	doCryptography(num, true);
	return num;
}

uberzahl SIMON::decrypt(uberzahl num) {;
	doCryptography(num, false);
	return num;
}
std::string SIMON::encrypt(std::string text) {
	cryptoString(text, true);
	return text;
}

std::string SIMON::decrypt(std::string  text) {
	cryptoString(text, false);
	return text;
}

void SIMON::cryptoString(std::string  &text, bool isEncryption) {
  
	INT bytes = text.size();
	short remainder = bytes % 16;
	if (remainder != 0) bytes += 16 - remainder;
	char * data = (char*)malloc(bytes);
	
	if (isEncryption) {
		srand(gen());
		for (int i = 0; i < bytes; i++) data[i] = gen();
	}
	
	// string to array
	int i = 0;
	for (auto c : text) {
		data[i++] = c;
	}
	if (isEncryption) data[i] = '\0';
	
	if (isEncryption) encryptArray(data, bytes / 16);
	else decryptArray(data, bytes / 16);
	
	// array to string
	if (isEncryption) {
	    text.clear();
	    i = 0;
	    for (; i < bytes; i++) text.push_back(data[i]);
	}
	else {
	    text.clear();
	    i = 0;
	    while (data[i] != '\0') text.push_back(data[i++]);
	}
	
	free(data);
}

void SIMON::doCryptography(uberzahl &num, bool isEncryption) {
	INT bytes = num.value.size() * 4;
	short remainder = bytes % 16;
	if (remainder != 0) bytes += 16 - remainder;
	INT * data = (INT*)malloc(bytes);

	uberToArray(num, data, bytes);
	if (isEncryption) encryptArray(data, bytes / 16);
	else decryptArray(data, bytes / 16);
	arrayToUber(num, data, bytes);
	
	free(data);
}

void SIMON::uberToArray(const uberzahl &num, INT* data, INT bytes) {
  
	unsigned long long dataIndice = 0;
	
	uberzahl temp(num);
	while (temp.value.size() % 4 != 0) temp.value.push_back(0);
	
	
	for (int long long i = temp.value.size() - 2; i >= 0; i -= 2) {
		unsigned long long longNum = temp.value[i] + (((unsigned long long) temp.value[i + 1]) << 32);
		data[dataIndice++] = longNum;
	}
	
	for (int i = dataIndice; i < bytes / 8; i++) {
		data[i] = 0;
	}
}

void SIMON::arrayToUber(uberzahl &num, INT* data, INT bytes) {
	unsigned long long dataIndice = bytes / 8 - 1;
	
	num = "0";
	dataIndice = 0;
	for (int i = bytes/8 - 1; i >= 0; i--) {
		 num = num + (uberzahl(data[dataIndice++]) << 64*i);
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
