#include <iostream>
#include "modAlphaCipher.h"

using namespace std;

void check(const wstring& Text, const wstring& key, bool rus)
{
    wcout<<L"key="<<key<<endl;
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key, rus);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout<<Text<<endl;
    wcout<<cipherText<<endl;
    wcout<<decryptedText<<endl;
    if (Text == decryptedText)
        wcout<<L"Ok\n";
    else
        wcout<<L"Err\n";
}
int main(int argc, char **argv)
{
    try {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        check(L"THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG",L"SIMPLE", false);
        check(L"ПРИВЕТ",L"ЕГОР", true);
        check(L"РАБОТАСЛОКАЛЬЮ",L"АБВГД",true);
        check(L"РАБОТАСЛОКАЛЬЮ",L"5",true);
        return 0;
    }catch(std::invalid_argument& e){
        std::wcout <<"Error!" << std::endl;
        }
}
