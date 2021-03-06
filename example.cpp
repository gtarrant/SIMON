#include <iostream>
#include "uberzahl.h"
#include "simon.h"

using namespace std;

void EncryptingCString() {
	SIMON s(1234);
	s.setAndGenKey();
	
	// bytes must be a multiple of 16
	// or it might seg fault
	// since this implementation used 128bit block sizes
	const int bytes = 32;
	char test[bytes] = "hi i'm encrypting this.";
	
	cout << test << endl;
	s.encryptArray(test, bytes / 16);
	cout << test << endl;
	s.decryptArray(test, bytes / 16);
	cout << test << endl;
}

void EncryptingUberzahl() {
	SIMON s(1234);
	s.setAndGenKey();
	
	uberzahl test;
	test = "10399109190512935182358";
	cout << test << endl;
	uberzahl encrypted = s.encrypt(test);
	cout << encrypted << endl;
	cout << s.decrypt(encrypted) << endl;
}

void EncryptingString() {
	SIMON s(1234);
	s.setKey({0x0f0e0d0c0b0a0908, 0x0706050403020100});
	
	std::string text = "Hi I'm encrypting this.";
	
	cout << text << endl;
	string encrypted = s.encrypt(text);
	cout << encrypted << endl;
	cout << s.decrypt(encrypted) << endl;
}

// official simon128/128 test vector
void TestVectorArray() {
	SIMON s(1234);
	s.setKey({0x0f0e0d0c0b0a0908, 0x0706050403020100});
	
	// bytes must be a multiple of 16
	// or it might seg fault
	// since this implementation used 128bit block sizes
	int bytes = 16;
	INT * data = (INT*)malloc(bytes);
	data[0] = 0x6373656420737265;
	data[1] = 0x6c6c657661727420;
	
	cout << hex << data[0] << " " << hex << data[bytes / 16] <<  endl;
	s.encryptArray(data, 1);
	cout << hex << data[0] << " " << hex << data[bytes / 16] <<  endl;
	s.decryptArray(data, 1);
	cout << hex << data[0] << " " << hex << data[bytes / 16] <<  endl;

}

void TestUberzahl() {
	SIMON s(1234);
	s.setKey({0x0f0e0d0c0b0a0908, 0x0706050403020100});
	uberzahl test("132192742177667483844156138223589028896");
	
	cout << test << endl;
	uberzahl encrypted = s.encrypt(test);
	cout << encrypted << endl;
	cout << s.decrypt(encrypted) << endl;
}

int main() {
  
	EncryptingCString();
	cout << endl;
	EncryptingUberzahl();
	cout << endl;
	EncryptingString();
	cout << endl;
	TestVectorArray();
	cout << endl;
	TestUberzahl();
}
