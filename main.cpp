#include "simon.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

int main(){
	SIMON s(1234);
	s.setKey(s.genKey());
	char * data = (char*)malloc(16);
	data[0] = 't';
	data[1] = 'e';
	data[2] = 's';
	data[3] = 't';
	cout << "plaintext:" << data << endl;
	s.encrypt(data, 1);
	cout << "encypted:" << data << endl;
	s.decrypt(data, 1);
	cout << "decrypted:" << data << endl;
}
