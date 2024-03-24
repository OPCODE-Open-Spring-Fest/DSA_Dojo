#include <stdexcept>

template <typename T> class Node {
public:
    T data;
    Node<T> * link;
   
    Node(T& n)
    {
        this->data = n;
        this->link = nullptr;
    }
};

template <typename T> class Stack {
    private:
        Node<T> * Top;

        int stackSize;
    public:
        Stack();                    //default constructor
        Stack(T element);           //constructor to initialize stack with one number
        Stack(T arr[],int n);             //constructor to initialize stack from an array

        int length;
    public:
        Stack();                    //default constructor
        Stack(T element);           //constructor to initialise stack with one number
        Stack(T arr[], int n);      //constructor to initialise stack from an array containing n elements

        const T& top();             //return element at top of the stack
        T pop();                    //return element at top of stack and deletes it
        void push(T element);       //inserts element into the stack
        bool empty();               //return true if stack is empty and false otherwise
        int size();                 //return number of elements present in the stack
};

template<typename T> Stack<T>::Stack() {
    Top = nullptr;
    stackSize = 0;
}

template<typename T> Stack<T>::Stack(T element) {
    stackSize = 1;
    Top = new Node<T>(element);
}

template<typename T> Stack<T>::Stack(T arr[] , int n) {
    stackSize = 0;
    Top = nullptr;
    for(int i=n-1; i>=0; i--){
        push(arr[i]);
    }
}

template<typename T> const T& Stack<T>::top() {
    if(empty()){
        throw std::out_of_range("Stack is empty!!!");
    }
    return Top->data;
}

template<typename T> T Stack<T>::pop() {
    if(stackSize == 0){
        throw std::out_of_range("Stack is empty!!!");
    }
    T popData = Top->data;
    Node<T> *temp = Top;
    Top = Top->link;
    delete temp;
    stackSize--;
    return popData;
}

template<typename T> void Stack<T>::push(T element) {
    Node<T> *newNode = new Node<T>(element);
    newNode->link = Top;
    Top = newNode;
    stackSize++;
}

template<typename T> bool Stack<T>::empty() {
    return Top == nullptr;
}

template<typename T> int Stack<T>::size() {
    return stackSize;
}
