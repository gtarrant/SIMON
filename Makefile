all: simon.h simon.cpp uberzahl.h uberzahl.cpp example.cpp
	g++ example.cpp simon.cpp uberzahl.cpp -std=c++11 -o simon
