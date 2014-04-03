#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <sys/resource.h>
#include <sys/time.h>

class Timer {
	struct rusage startu;
	struct rusage endu;
	//double duration;
	
public:
  
    void start() {getrusage(RUSAGE_SELF, &startu);}
    void stop() {getrusage(RUSAGE_SELF, &endu);}
    
    double getDuration() {
	double start_sec = startu.ru_utime.tv_sec + startu.ru_utime.tv_usec/1000000.0;
	double end_sec = endu.ru_utime.tv_sec + endu.ru_utime.tv_usec/1000000.0;
	return end_sec - start_sec;
    }
    
    void print() {
	std::cout << getDuration() << std::endl;
    }
};

#endif //TIMER.H