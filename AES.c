#include <stdio.h>
#include "AES.h"
#include "AESPrint.h"

void encrypt(uint8_t (*input)[AES_STATE_BYTE_SIZE], uint8_t* key, AesType type) {
	printInputHex(input);
	uint8_t state[AES_STATE_BYTE_ROW_SIZE][AES_STATE_BYTE_COLUMN_SIZE];
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		state[i % 4][i / 4] = (*input)[i];
	}
	printStateHex(&state);
	printKeyHex(key, type);

	if (type == AES_128) {
		uint8_t expandedKey[AES_128_KEY_BYTE_SIZE * 11];
		keyExpansion(key, &expandedKey, type);
	}
}