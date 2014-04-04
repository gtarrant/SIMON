all: main.cpp simon.h simon.cpp uberzahl.h uberzahl.cpp timer.h
	g++ main.cpp simon.cpp uberzahl.cpp -std=c++11 -o simon
