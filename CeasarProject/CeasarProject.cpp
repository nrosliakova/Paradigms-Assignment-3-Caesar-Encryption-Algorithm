
#include <iostream>
#include <windows.h>
//#include "CaesarCipher.h"
using namespace std;

char* get_input(const char question[]);

int main()
{
    typedef char* (*encrypt_ptr_t)(char*, int);
    typedef char* (*decrypt_ptr_t)(char*, int);

    HINSTANCE CaesarCipher = LoadLibrary(TEXT("CaesarCipher.dll")); 
    if (CaesarCipher == nullptr || CaesarCipher == INVALID_HANDLE_VALUE)
    {
        cout << "Lib not found" << endl;
        return 1;
    }

    encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(CaesarCipher, "encrypt");
    if (encrypt_ptr == nullptr)
    {
        cout << "Function not found" << endl;
        return 1;
    }
    decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(CaesarCipher, "decrypt");
    if (decrypt_ptr == nullptr)
    {
        cout << "Function not found" << endl;
        return 1;
    }

    int command;
    printf("\tpress '1' for encoding \n\tpress '2' for decoding \n\nChoose the command: ");
    int res = scanf_s("%d", &command);

    while (res != 1) {
        printf("\nError! Command must be an integer.\n");
        printf("Choose the command (press '0' for help) : ");
        res = scanf_s("%d", &command);
    }

    printf("\n");
    char* text = get_input("Your text: \n");

    int key;
    printf("\nEnter key: ");
    int res2 = scanf_s("%d", &key);

    while (res2 != 1) {
        printf("\nError! Key must be an integer.\n");
        printf("Enter key again: ");
        res2 = scanf_s("%d", &key);
    }

    switch (command) {
    case 1: {
        char* encrypted_text = encrypt_ptr(text, key);
        printf("encrypted text: %s\n", encrypted_text);
        break;
    }
    case 2: {
        char* decrypted_text = decrypt_ptr(text, key);
        printf("decrypted text: %s\n", decrypted_text);
        break;
    }
    default:
        printf("Command %d does not exist.\n", command);

    }

    FreeLibrary(CaesarCipher);
}

char* get_input(const char question[]) {
    int text_max_length = 4;
    char* text = (char*)malloc(text_max_length * sizeof(char));
    printf("%s", question);
    while (getchar() != '\n');

    char cur_char = getchar();
    int i = 0;
    while (cur_char != '\n') {
        if (i == text_max_length) {
            text_max_length *= 2;
            text = (char*)realloc(text, text_max_length * sizeof(char));
        }
        text[i] = cur_char;
        cur_char = getchar();
        i++;
    }
    text[i] = '\0';
    return text;
}