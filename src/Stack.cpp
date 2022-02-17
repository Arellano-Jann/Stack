

template <typename T>
Stack<T>::Stack()
    : itemCount(0)
    , top(nullptr)
{}

template <typename T>
bool Stack<T>::push(const T& newEntry){
    Node<T>* newNode = new Node<T>(newEntry, top);
    top = newNode;
    itemcount++;
    return true;

}

template <typename T>
bool Stack<T>::pop(){
    if (itemCount < 1) return false;
    Node<T>* deleteNode = top;
    top = deleteNode->getNext();
    delete deleteNode;
    itemCount--;
    return true;

}

template <typename T>
T Stack<T>::peek() const{
    return top->getEntry();
}

template <typename T>
bool Stack<T>::isEmpty() const{
    return itemCount == 0;
}

template <typename T>
Stack<T>::~Stack(){
    for (i = 0; i < itemCount; i++){
        pop();
    }
}