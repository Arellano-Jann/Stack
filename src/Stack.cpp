

template <typename T>
bool Stack<T>::push(const T& newEntry){
    
}

template <typename T>
bool Stack<T>::pop(){
    
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