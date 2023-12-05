#include <iostream>
#include "Shifr.h"
#include <locale>
#include <codecvt>
#include "Error.h"
#include <boost/program_options.hpp>
namespace po = boost::program_options;
int main(int argc, char **argv)
{
    try {
        std::locale loc("ru_RU.UTF-8");
        std::locale::global(loc);
        int flag;
        po::options_description opts("Allowed options");
        opts.add_options()
        ("help,h", "Показать справку")
        ("flag,f",
         po::value<int>(&flag)->default_value(1),
         "Значения от 1 до 2,где 1 - запуск без пользовательского интерфейса,2-запуск с пользовательским интерфейсом");
        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, opts), vm);
        po::notify(vm);
        if(vm.count("help")) {
            std::cout << "Корректно работает с английским алфавитом" << std::endl;
            std::cout << opts << "\n";
            exit(0);
        }
        int key;
        std::string str;
        if(flag > 2 or flag < 1){
            std::cout << "Флаг принимает два значения: 1 и 2"<<std::endl;
            std::cout << opts << "\n";
            exit(0);
            }
        if(flag == 1) {
            str = "helloworld";
            for(int i = 1; i<=10; i++) {
                key = i;
                Shifr s(key);
                std::cout <<"Ключ: "<< key << std::endl;
                std::string res = s.encrypt(str);
                s.print(res);
                std::string dec_res = s.decrypt(res);
                s.print(dec_res);
            }
        }else{
            std::cout<< "Введите фразу: ";
            std::cin >> str;
            std::cout<<"Введите ключ: ";
            std::cin >> key;
            Shifr s(key);
                std::cout <<"Ключ: "<< key << std::endl;
                std::string res = s.encrypt(str);
                s.print(res);
                std::string dec_res = s.decrypt(res);
                s.print(dec_res);
            }
    } catch(My_Error& ex) {
        std::cerr << "Ошибка: " << ex.what() << std::endl;
    } catch(po::error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
