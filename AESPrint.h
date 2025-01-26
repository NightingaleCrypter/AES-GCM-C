#ifndef AES_PRINT_H
#define AES_PRINT_H

#include "AES.h"

void printInputHex(uint8_t(*input)[AES_STATE_BYTE_SIZE]);
void printStateHex(uint8_t(*state)[AES_STATE_BYTE_ROW_SIZE][AES_STATE_BYTE_COLUMN_SIZE]);
void printKeyHex(uint8_t* key, AesType type);

#endif