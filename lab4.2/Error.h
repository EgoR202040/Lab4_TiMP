#pragma once
/** @file
 * @author Егоров Е.А.
 * @version 1.0
 * @brief Заголовочный файл ошибок
 */
#include <stdexcept>
#include <string>
#include <system_error>
/** @brief Класс ошибки
 * @details Сообщение ошибки указывается в параметрах конструктора.Является наследником класса runtime_error
 */
class My_Error:public std::runtime_error{
public:
    My_Error(const std::string& s):std::runtime_error(s){}
    };
