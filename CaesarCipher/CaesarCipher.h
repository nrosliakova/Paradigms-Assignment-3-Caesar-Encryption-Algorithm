#pragma once

#ifdef CAESAR_CIPHER_EXPORTS
#define CAESAR_CIPHER_API __declspec(dllexport)
#else
#define CAESAR_CIPHER_API __declspec(dllimport)
#endif


extern "C"
{
	CAESAR_CIPHER_API char* encrypt(char* rawText, int key);

	CAESAR_CIPHER_API char* decrypt(char* encryptedText, int key);
};