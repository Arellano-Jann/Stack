#pragma once
#define STACK_H

#include "StackInterface.h"
#include "Node.h"

template typename<T>
class Stack : public StackInterface<T>{
    int itemCount = 0;
    Node<T>* top;

public:
    bool push(const T& newEntry);
    bool pop();
    T peek() const;
    bool isEmpty() const;
    ~Stack();

}