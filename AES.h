#ifndef AES_HEADER_H
#define AES_HEADER_H

#include <stdint.h>
#include "AESConstant.h"

typedef enum {
    AES_128,
    AES_192,
    AES_256
} AesType;

enum Mode {
    ENCRYPTION,
    DECRYPTION
};

void encrypt(uint8_t(*input)[AES_STATE_BYTE_SIZE], uint8_t* key, AesType type);

#endif
