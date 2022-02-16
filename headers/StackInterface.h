#pragma once
#define STACKINTERFACE_H

template <typename T>
class StackInterface {
public:
    virtual bool push(const T& newEntry) = 0;
    virtual bool pop() = 0;
    virtual T peek() const = 0;
    virtual bool isEmpty() const = 0;
    ~StackInterface(){}
};
