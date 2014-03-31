#include "simon.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::hex;

int main(){
	SIMON s(1234);
	INT k1, k2;
	cout << "input key:\n";
	cin >> hex >> k1;
	cin >> hex >> k2;
	s.setKey({k1, k2});
	cout << "input plaintext:\n";

	INT * data = (INT*)malloc(16);
	cin >> hex >> data[0];
	cin >> hex >> data[1];
	cout << "plaintext:" << hex << data[0] <<
						 ' ' << hex << data[1] << endl;
	s.encrypt(data, 1);
	cout << "encypted:" << hex << data[0] << ' ' << hex << data[1] << endl;
	s.decrypt(data, 1);
	cout << "decrypted:" << hex << data[0] << ' ' << hex << data[1] << endl;
}
