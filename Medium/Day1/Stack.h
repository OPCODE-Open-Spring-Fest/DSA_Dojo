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