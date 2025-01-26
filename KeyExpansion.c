#include "KeyExpansion.h"
#include "AESConstant.h"
#include "AESPrint.h"

void rotWord(uint8_t* word) {
    uint8_t temp = word[0];
    for (int i = 0; i < 3; i++) {
        word[i] = word[i + 1];
    }
    word[3] = temp;
}

void subWord(uint8_t* word) {
    for (int i = 0; i < WORD_BYTE_SIZE; i++) {
        word[i] = sbox[word[i]];
    }
}

void keyExpansion(uint8_t* key, uint8_t* expandedKey, AesType type) {
	uint8_t Nb = 4, Nk = 4, Nr = 10;
	if (type == AES_192) {
		Nk += 2;
		Nr += 2;
	}
	if (type == AES_256) {
		Nk += 4;
		Nr += 4;
	}

    uint8_t temp[WORD_BYTE_SIZE];

	for (int i = 0; i < Nk; i++) {
        for (int bw = 0; bw < WORD_BYTE_SIZE; bw++) {
            expandedKey[i * WORD_BYTE_SIZE + bw] = key[i * WORD_BYTE_SIZE + bw];
        }
	}

    for (int i = Nk; i < Nb * (Nr + 1); i++) {
        for (int wb = 0; wb < WORD_BYTE_SIZE; wb++) {
            temp[wb] = expandedKey[(i - 1) * WORD_BYTE_SIZE + wb];
        }

        if (i % Nk == 0) {
            rotWord(temp);
            subWord(temp);
            temp[0] ^= rcon[i / Nk];
        }

        for (int wb = 0; wb < WORD_BYTE_SIZE; wb++) {
            expandedKey[i * WORD_BYTE_SIZE + wb] = expandedKey[(i - Nk) * WORD_BYTE_SIZE + wb] ^ temp[wb];
        }
    }
    printExpandedKey(expandedKey, type);
}