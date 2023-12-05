#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const std::wstring& skey, bool rus)
{
    if(rus == true) {
        numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        for (unsigned i=0; i<numAlpha.size(); i++) {
            alphaNum[numAlpha[i]]=i;
        }
        for(auto e:skey){
            if(numAlpha.find(e)==std::string::npos){
                throw std::invalid_argument("Ключ плохой");
                }
            }
        key = convert(skey);
    } else {
        if(rus == false) {
            numAlpha = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            for (unsigned i=0; i<numAlpha.size(); i++) {
                alphaNum[numAlpha[i]]=i;
            }
            for(auto e:skey){
            if(numAlpha.find(e)==std::string::npos){
                throw std::invalid_argument("Ключ плохой");
                }
            }
            key = convert(skey);
        }
    }
}
std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(cipher_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(open_text);
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
