
#include "pch.h"
#include "CaesarCipher.h"
#include <stdio.h>
#include <map>
using namespace std;

map<char, char> create_map(int key) {
	map<char, char> dict;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	while (key > 26) key -= 26;
	while (key < -26) key += 26;
	for (int i = 0; i < strlen(alphabet); i++) {

		int key_;
		if (key >= 0)
			key_ = (i + key >= 26) ? i + key - 26 : i + key;
		else
			key_ = (i + key < 0) ? i + key + 26 : i + key;

		dict[alphabet[i]] = alphabet[key_];
		dict[toupper(alphabet[i])] = toupper(alphabet[key_]);
	}
	return dict;
}

char* encrypt(char* rawText, int key) {
	int len = strlen(rawText);
	char* encrypted_text = (char*)calloc(len, sizeof(char));
	encrypted_text[len] = '\0';
	map<char, char> code = create_map(key);
	for (int i = 0; i < len; i++) {
		char char_ = rawText[i];
		if (!code.count(char_)) {
			encrypted_text[i] = char_;
			continue;
		}
		char encrypted_char = code[char_];
		encrypted_text[i] = encrypted_char;
	}
	return encrypted_text;
}

char* decrypt(char* encryptedText, int key) {
	char* decrypted_text = encrypt(encryptedText, -key);
	return decrypted_text;
}
