
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
		int key_ = (i + key > 26) ? i + key - 26 : i + key;
		//dict.insert({ alphabet[i], alphabet[key_] });
		dict[alphabet[i]] = alphabet[key_];
	}
	return dict;
}