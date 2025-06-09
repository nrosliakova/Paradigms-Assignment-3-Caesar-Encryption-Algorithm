
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    typedef char* (*encrypt_ptr_t)(char*, int);
    typedef char* (*decrypt_ptr_t)(char*, int);

    HINSTANCE CaesarCipher = LoadLibrary(TEXT("CaesarCipher.dll")); 
    //HINSTANCE CaesarCipher = LoadLibrary("CaesarCipher.dll"); 
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

    //char* text = (char*)"hello";
    //int key = -29;
    char* text = (char*)"hello!! I'm Nina";
    int key = 7;
    printf("primary text: %s\n", text);

    char* encrypted_text = encrypt_ptr(text, key);
    printf("encrypted text: %s\n", encrypted_text);

    char* decrypted_text = decrypt_ptr(encrypted_text, key);
    printf("decrypted text: %s\n", decrypted_text);

    FreeLibrary(CaesarCipher);
}
