all: main.cpp simon.h simon.cpp uberzahl.h uberzahl.cpp timer.h
	g++ example.cpp simon.cpp uberzahl.cpp -std=c++11 -o simon
