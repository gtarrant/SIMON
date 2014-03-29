all: main.cpp simon.h simon.cpp
	g++ main.cpp simon.cpp -std=c++11 -o simon
