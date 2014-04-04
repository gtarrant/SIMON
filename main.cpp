#include "simon.h"
#include <iostream>
#include <cstdlib>
#include "timer.h"
#include "uberzahl.h"

using std::cout;
using std::cin;
using std::endl;
using std::hex;

void getPerformanceInfo();

int main(){
		
	SIMON s(1234); //Seed

	//char* pt = new char;
	//cout << "Enter plaintext (decimal): "<< endl;	
	//cin >> pt;
	//cout << "Enter plaintext (hex): "<< endl;
	//cin >> hex >> pt;

	//s.setKey({0x1,0x0}); //Set Key
	s.setKey(s.genKey()); //Generate Key

	uberzahl num(0x100000000000000);
	uberzahl encrypted = s.encrypt(num);
	uberzahl decrypted = s.decrypt(encrypted);

	cout << "Plaintext (decimal): " << num << endl;
	cout << "Ciphertext (decimal): " << encrypted << endl;
	cout << "Decrypted Ciphertext (decimal): " << decrypted << endl;
	
}

void getPerformanceInfo() {
//Gets performance info  
	SIMON s(1234);
	
	s.setKey(s.genKey());
	Timer timer;
	
	
	cout << "ENCRYPTION" << endl;
	for (int i = 0; i < 13; i++) {
	    INT bytes = 2 << i;
	    uberzahl num;
	    num.random(bytes);
	    
	    timer.start();
	    for (int k = 0; k < 10; k++) {
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	      s.encrypt(num);
	    }
	    timer.stop();
	    
	    cout << bytes << " " << (double) timer.getDuration() << endl;
	}
	cout << endl;
	
	cout << "DECRYPTION" << endl;
	for (int i = 0; i < 13; i++) {
	    INT bytes = 2 << i;
	    uberzahl num;
	    num.random(bytes);
	    
	    timer.start();
	    for (int k = 0; k < 10; k++) {
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	      s.decrypt(num);
	    }
	    timer.stop();
	    
	    cout << bytes << " " << (double) timer.getDuration() << endl;
	}
}
