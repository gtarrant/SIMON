=====SIMON=====
128bit block size

=====COMPILE INSTRUCTIONS=====

Use included Makefile to compile to use example.cpp.
Included example.cpp file shows examples for usage and serves as a main function.
Included main.cpp is deprecated and NOT used in compiling, but contains performance function.

Compiled with gcc 4.7.0 to support command line option "-std=c++11".

=====USAGE INSTRUCTIONS=====

See included example.cpp as an example.

SIMON's constructor argument serves as a seed.
SIMON's genKey() will generate a key. Use the class' setKey() to set that output as the Key.
Alternatively, SIMON also includes a setAndGenKey() function to do both.
SIMON's encrypt and decrypt argument accepts a single uberzahl as an argument.

=====PERFORMANCE=====

Generated performance chart used on CAEN Machines using Red Hat Linux using a 100 trials per bit size.
