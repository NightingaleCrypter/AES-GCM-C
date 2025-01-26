#include <stdio.h>
#include "AESPrint.h"
#include "AESConstant.h"

void printInputHex(uint8_t(*input)[AES_STATE_BYTE_SIZE]) {
	printf("------\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("%02X", (*input)[i]);
	}
	printf("\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("a%d ", i);
	}
	printf("\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("%02X ", (*input)[i]);
		if (i > 9) {
			printf(" ");
		}
	}
	printf("\n");
	printf("------\n");
}

void printStateHex(uint8_t(*state)[AES_STATE_BYTE_ROW_SIZE][AES_STATE_BYTE_COLUMN_SIZE]) {
	printf("------\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("%02X", (*state)[i % 4][i / 4]);
	}
	printf("\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("s(%d,%d) ", i % 4, i / 4);
	}
	printf("\n");
	for (int i = 0; i < AES_STATE_BYTE_SIZE; i++) {
		printf("%02X     ", (*state)[i % 4][i / 4]);
	}
	printf("\n");
	printf("------\n");
}

void printKeyHex(uint8_t* key, AesType type) {
	int keySize;
	if (type == AES_128) {
		keySize = AES_128_KEY_BYTE_SIZE;
	}
	else if (type == AES_192) {
		keySize = AES_192_KEY_BYTE_SIZE;
	}
	else if (type == AES_256) {
		keySize = AES_256_KEY_BYTE_SIZE;
	}
	else {
		keySize = 0;
	}
	printf("------\n");
	for (int i = 0; i < keySize; i++) {
		printf("%02X", key[i]);
	}
	printf("\n");
	printf("------\n");
}

void printExpandedKey(uint8_t* expandedKey, AesType type) {
	int expandedKeySize = 0;
	if (type == AES_128) {
		expandedKeySize = AES_128_KEY_BYTE_SIZE * 11;
	}
	if (type == AES_192) {
		expandedKeySize = AES_192_KEY_BYTE_SIZE * 13;
	}
	if (type == AES_256) {
		expandedKeySize = AES_256_KEY_BYTE_SIZE * 15;
	}
	printf("Expanded key words (formatted as in Appendix A):");
	for (int i = 0; i < expandedKeySize; i++) {
		if (i % 4 == 0) {
			printf("\n%d: ", i/4);
		}
		printf("%02X", expandedKey[i]);
	}
	printf("\n");
	printf("------\n");
}

void printWord(uint8_t* word) {
	for (int i = 0; i < WORD_BYTE_SIZE; i++) {
		printf("%02x", word[i]);
	}
	printf("\n");
}