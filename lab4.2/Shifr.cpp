#include "Shifr.h"
#include <codecvt>
#include <locale>
std::string Shifr::encrypt(const std::string text)
{
    int num_lines;
    if(key >= (int)text.length()){
        throw My_Error("Ключ должен быть меньше длины фразы");
        }
    if(key <= 0){
        throw My_Error("Ключ должен быть больше 0");
        }
    if(text.length()%key == 0) {
        num_lines = text.length()/key;
    } else {
        num_lines = text.length()/key + 1;
    }
    char mass[num_lines][key];
    int m =0;
    for(int i = 0; i<num_lines; i++) {
        for(int j =0; j<key; j++) {
            if(m >=(int)text.length()) {
                mass[i][j] = '~';
            } else {
                mass[i][j] = text[m];
            }
            m++;
        }
    }
    std::string eText;
    for(int i = key-1; i>=0; i--) {
        for(int j =num_lines-1; j>=0; j--) {
            eText += mass[j][i];
        }
    }
    std::string res_text;
    return eText;
}
std::string Shifr::decrypt(const std::string text)
{
    int num_lines;
    if(key >= (int)text.length()){
        throw My_Error("Ключ должен быть меньше длины фразы");
        }
    if(key <= 0){
        throw My_Error("Ключ должен быть больше 0");
        }
    if(text.length()%key == 0) {
        num_lines = text.length()/key;
    } else {
        num_lines = text.length()/key + 1;
    }
    char mass[num_lines][key];
    int m = 0;
    for(int i =key-1; i>=0; i--) {
        for(int j =num_lines-1; j>=0; j--) {
            if(m>=(int)text.length()) {
                mass[j][i] = '~';
            } else {
                mass[j][i] = text[m];
            }
            m++;
        }
    }
    std::string resText;
    for(int i =0; i<num_lines; i++) {
        for(int j =0; j<key; j++) {
            resText += mass[i][j];
        }
    }
    std::string output;
    for(auto e:resText) {
        if(text.find(e)!=std::string::npos) {
            output += e;
        }
    }
    return output;
}
void Shifr::print(std::string text){
    std::string output;
    for(auto e:text) {
        if(e!='~') {
            output += e;
        }
    }
    std::cout << output << std::endl;
    }
