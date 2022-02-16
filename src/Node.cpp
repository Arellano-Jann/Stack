template <typename T>
Node<T>::Node()
    : next(nullptr)
    {}

template <typename T>
Node<T>::Node(const T& item)
    : item(item)
    , next(nullptr)
    {}

template <typename T>
Node<T>::Node(const T& item, Node<T>* nextNodePtr)
    : item(item)
    , next(nextNodePtr)
    {}


template <typename T>
void Node<T>::setItem(const T& newItem){
    item = newItem;
}

template <typename T>
void Node<T>::setNext(Node<T>* nextNodePtr){
    next = nextNodePtr;
}

template <typename T>
T Node<T>::getItem() const{
    return item;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
    return next;
}
