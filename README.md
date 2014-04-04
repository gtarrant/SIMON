=====SIMON=====

=====COMPILE INSTRUCTIONS=====

Use included Makefile to compile to use main.cpp.
Included main.cpp file is a test file for performance and can be used as a reference. 
Replace main.cpp with your own main.cpp to call the encryption/decryption/key gen functions.

Compiled with gcc 4.7.0 to support command line option "-std=c++11".

=====USAGE INSTRUCTIONS=====

See included main.cpp as an example.

SIMON's constructor argument serves as a seed.
SIMON's genKey will generate a key. Use the class' setKey to set that output as the Key.
SIMON's encrypt and decrypt argument accepts a single uberzahl as an argument.

=====PERFORMANCE=====

Generated performance chart used on CAEN Machines using Red Hat Linux using a 100 trials per bit size.
