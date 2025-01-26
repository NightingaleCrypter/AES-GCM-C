#ifndef AES_CONSTANT_H
#define AES_CONSTANT_H

#include<stdint.h>

#define WORD_BYTE_SIZE 4
#define NB 4

#define AES_STATE_BYTE_SIZE 16
#define AES_STATE_BYTE_ROW_SIZE 4
#define AES_STATE_BYTE_COLUMN_SIZE 4

#define AES_128_KEY_BYTE_SIZE 16
#define AES_128_NR 10

#define AES_192_KEY_BYTE_SIZE 24
#define AES_192_NR 12

#define AES_256_KEY_BYTE_SIZE 32
#define AES_256_NR 14

/**
* Section 5.1.1 Table 4. of FIPS 197u1
*/
extern const uint8_t sbox[256];

/**
* Section 5.2 Table 5. of FIPS 197u1
*/
extern const uint8_t rcon[15];

#endif