#include <iostream>

int main() {
    int x = 0;

    auto lambda = [x]() mutable {
        x++; // 修改被捕获的变量x
        std::cout << "Value of x: " << x << std::endl;
    };
    
   /*  auto lambda = [&x]() {
        x++; // 修改被捕获的变量x
        std::cout << "Value of x: " << x << std::endl;
    } */
    
    lambda(); // 输出: Value of x: 1
    lambda(); // 输出: Value of x: 2

    std::cout << "Final value of x: " << x << std::endl; // 输出: Final value of x: 0

    return 0;
}