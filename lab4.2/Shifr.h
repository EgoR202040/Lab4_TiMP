#pragma once
/** @file
 * @author Егоров Е.А.
 * @version 1.0
 * @brief Заголовочный файл для модуля шифрования/расшифрования методом маршрутной табличной перестановки
 */
#include <string>
#include <vector>
#include <iostream>
#include "Error.h"
/** @brief Класс для шифрования/расшифрования методом маршрутной табличной перестановки
 * @details Ключ указывается в параметрах конструктора.
 * Для шифрования используется метод encrypt,
 * для расшифровки используется метод decrypt
 */
class Shifr
{
/** @brief Атрибут класса,хранящий ключ,который определяет количество столбцов таблицы
*/
    int key; // Кол-во столбцов таблицы
public:
/**
 * @brief Конструктор класса
 * @param [in] k Ключ для шифрования/расшифрования
 * @warning Ключ должен типа int
 * Исключения не возбуждаются
 */
    Shifr(const int k):key(k) {};
/**
 * @brief Функция шифрования
 * @param [in] text Исходная фраза
 * @throw My_Error ,при неверном ключе
 * @return Зашифрованная фраза
 */
    std::string encrypt(const std::string text);
/**
 * @brief Функция шифрования
 * @param [in] text Зашифрованная фраза
 * @throw My_Error ,при неверном ключе
 * @return Исходная фраза
 */
    std::string decrypt(const std::string text);
/**
 * @brief Вспомогательная функция
 * @details Выводит в std::cout параметр text
 * @param [in] text Зашифрованная фраза/исходная фраза
 */
    void print(std::string text);
};
