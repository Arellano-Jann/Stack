

template <typename T>
bool Stack<T>::push(const T& newEntry){
    
}

template <typename T>
bool Stack<T>::pop(){
    
}

template <typename T>
T Stack<T>::peek() const{
    
}

template <typename T>
bool Stack<T>::isEmpty() const{
    
}

template <typename T>
Stack<T>::~Stack(){
    for (i = 0; i < itemCount; i++){
        pop();
    }
}