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
 
	getPerformanceInfo();
	/*
	SIMON s(1234);
	s.setKey({0x0f0e0d0c0b0a0908, 0x0706050403020100});
	//uberzahl num("132192742177667483844156138223589028896");
	uberzahl num("0");
	uberzahl encrypted = s.encrypt(num);
	cout << "enc: " << encrypted << endl;
	cout << "ori: " << num << endl;
	cout << "dec: " << s.decrypt(encrypted) << endl;
	
	cout << endl << endl;
	
	uberzahl num2("132192742177667483844156138223589028896");
	//uberzahl num("2");
	uberzahl encrypted2 = s.encrypt(num2);
	cout << "encrypted: " << encrypted2 << endl;
	cout << "original: " << num2 << endl;
	cout << "decrpyted: " << s.decrypt(encrypted2) << endl;*/
	
	

}

void getPerformanceInfo() {
  
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
