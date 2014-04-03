#include "simon.h"
#include <iostream>
#include <cstdlib>
#include "timer.h"

using std::cout;
using std::cin;
using std::endl;
using std::hex;

int main(){
	/*
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
	*/
	SIMON s(1234);
	
	s.setKey(s.genKey());
	Timer timer;
	
	cout << "ENCRYPTION" << endl;
	for (int i = 0; i < 12; i++) {
	    INT bytes = 2 << i;
	    INT * dicks = (INT*)malloc(bytes);
	    for (int j = 0; j < 2*i; j += 2) {
		dicks[j] = 0x6373656420737265;
		dicks[j + 1] = 0x6c6c657661727420;
	    }
	    
	    timer.start();
	    for (int k = 0; k < 10; k++) {
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	      s.encrypt(dicks, bytes);
	    }
	    timer.stop();
	    
	    cout << bytes << " " << (double) timer.getDuration() << endl;
	}
	cout << endl;
	
	cout << "DECRYPTION" << endl;
	for (int i = 0; i < 12; i++) {
	    INT bytes = 2 << i;
	    INT * dicks = (INT*)malloc(bytes);
	    for (int j = 0; j < 2*i; j += 2) {
		dicks[j] = 0x6373656420737265;
		dicks[j + 1] = 0x6c6c657661727420;
	    }
	    
	    timer.start();
	    for (int k = 0; k < 10; k++) {
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	      s.decrypt(dicks, bytes);
	    }
	    timer.stop();
	    
	    cout << bytes << " " << (double) timer.getDuration() << endl;
	}

}