#include <initializer_list>
#include <iostream>
#include <iostream>
#include <vector>

int main() {
    std::vector<bool> v = {true, false, true};

    // Это сработает
    for (auto&& x : v) {
        std::cout<<x;  // Можно изменять элементы
         /*
        универсальная ссылка, ошибок не возникает
        */
    }

    // Это не сработает
    for (auto& x : v) {
        std::cout<<x;  // Ошибка компиляции
          /*
        x - неконстантная lvalue ссылка. 
        Прокси-объект std::vector<bool> не может быть 
        связан с неконстантной lvalue ссылкой. 
        Это ограничение связано со специализированной 
        реализацией std::vector<bool>.
        */
    }


    return 0;
}