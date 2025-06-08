
#include "CaesarCipher.h"
#include <stdio.h>
#include <map>
using namespace std;

char* encrypt(char* rawText, int key) {
	int len = strlen(rawText);
	char* encrypted_text = (char*)calloc(len, sizeof(char));
	encrypted_text[len] = '\0';
	map<char, char> code = create_map(key);
	for (int i = 0; i < len; i++) {
		char char_ = rawText[i];
		char encrypted_char = code[char_];
		encrypted_text[i] = encrypted_char;
	}
	return encrypted_text;
}

map<char, char> create_map(int key) {
	map<char, char> dict;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	while (key > 26) key -= 26;
	while (key < -26) key += 26;
	for (int i = 0; i < strlen(alphabet); i++) {
		int key_ = (i + key > 26) ? i + key - 26 : i + key;
		//dict.insert({ alphabet[i], alphabet[key_] });
		dict[alphabet[i]] = alphabet[key_];
	}
	return dict;
}