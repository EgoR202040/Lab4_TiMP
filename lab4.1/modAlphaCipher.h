#pragma once
/** @file
 * @author Егоров Е.А.
 * @version 1.0
 * @brief Заголовочный файл для модуля шифрования
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
/** @brief Класс для шифрования/расшифрования
 * @details Ключ,флаг,используемого языка указывается в параметрах конструктора.
 * Для шифрования используется метод encrypt,
 * для расшифровки используется метод decrypt
 */
class modAlphaCipher
{
private:
/** @brief Атрибут,хранящий алфавит шифрования
*/
    std::wstring numAlpha;
    std::map <wchar_t,int> alphaNum;
    std::vector <int> key;
    std::wstring lang;
/**
 * @brief Вспомогательная функция.Конвертирование из вектора в строку
 * @param [in] v Вектор данных
 * Тип данных int
 * Исключения не возбуждаются
 * @return Строку,полученную из вектора
 */
    inline std::wstring convert(const std::vector<int>& v);
/**
 * @brief Вспомогательная функция.Конвертирование из строки в вектор
 * @param [in] s Строка
 * Исключения не возбуждаются
 * @return Вектор,полученный из строки
 */
    inline std::vector<int> convert(const std::wstring& s);
public:
    modAlphaCipher()=delete;
/**
 * @brief Конструктор класса
 * @param [in] skey Ключ для шифрования
 * @param [in] rus Флаг шифрования
 * @warning Ключ должен состоять из символов алфавита
 * @throw std::invalid_argument ,при неверном ключе
 */
    modAlphaCipher(const std::wstring& skey, bool rus);
/**
 * @brief Функция шифрования
 * @param [in] open_text Исходная фраза
 * @return Зашифрованную строку
 */
    std::wstring encrypt(const std::wstring& open_text);
/**
 * @brief Функция расшифрования
 * @param [in] cipher_text Зашифрованная фраза
 * @return Исходную строку
 */
    std::wstring decrypt(const std::wstring& cipher_text);
};
