// interface node
#pragma once
#define NODE_H

template<typename T> 
class Node{
    T item; // class object
    Node<T>* next; // next node pointer

public: 
    Node(); // default constructor
    Node(const T& item); // constructor for adding an item
    Node(const T& item, Node<T>* nextNodePtr); // constructor for adding an item at a specific place

    void setItem(const T& newItem); // sets the item to newItem
    void setNext(Node<T>* nextNodePtr); // sets next node pointer
    T getItem() const; // gets item
    Node<T>* getNext() const; // gets next node pointer

};

#include "../src/Node.cpp"