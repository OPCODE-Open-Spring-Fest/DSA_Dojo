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

template <typename T>
class CQueue {
private:
    T *front, *back;  
    int length;

public:

	CQueue();                   //default constructor
    CQueue(T element);          //constructor to initialize queue with one number
    CQueue(T arr[],int n);      //constructor to initialize queue from an array
    void push(T value);			//inserts element into the queue
    T pop();					//return element at front of queue and deletes it
    const T& front() const;		//return element at front of the queue
    T size() const;				//return true if queue is empty and false otherwise
    bool empty() const;			//return true if queue is empty and false otherwise
};