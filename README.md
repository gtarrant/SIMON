=====SIMON=====
128/128 block size

=====COMPILE INSTRUCTIONS=====

Use included Makefile to compile to use example.cpp as main function.
Included example.cpp file shows examples for usage and serves as a main function.

Compiled with gcc 4.7.0 to support command line option "-std=c++11".

=====USAGE INSTRUCTIONS=====

See included example.cpp as an example.

SIMON's constructor argument serves as a seed.
SIMON includes a setAndGenKey() function to generate and set a key.
SIMON also includes manual setKey and genKey functions.
SIMON's encrypt and decrypt argument accepts a single uberzahl as an argument.

=====PERFORMANCE=====

Generated performance chart used on CAEN Machines using Red Hat Linux using a 100 trials per bit size.
