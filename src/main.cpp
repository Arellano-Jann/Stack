#include <iostream>
#include "../headers/Node.h"
#include "../headers/Stack.h"

int main(){
    Stack<int> stack;
    std::cout<< stack.push(5) << std::endl;
    std::cout<< stack.isEmpty() << std::endl;
    std::cout<< stack.peek() << std::endl;
    std::cout<< stack.pop() << std::endl;
    std::cout<< stack.isEmpty() << std::endl;

    return 0;
}