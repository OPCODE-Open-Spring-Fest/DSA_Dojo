#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <stdexcept>

/**
 * @brief Node class for the circular queue.
 *
 * This class represents a node in the circular queue's linked list.
 * It stores the data element and a pointer to the next node.
 *
 * @tparam T The data type of the elements in the queue.
 */
template <typename T>
class Node
{
public:
    T data;        ///< The data element stored in the node.
    Node<T> *link; ///< Pointer to the next node in the linked list.

    /**
     * @brief Constructs a new Node object.
     *
     * @param n The data element to be stored in the node.
     */
    Node(const T &n) : data(n), link(nullptr) {}
};

/**
 * @brief Circular Queue class.
 *
 *  A FIFO Structure  with Circular links.
 *
 * @tparam T The data type of the elements in the queue.
 */
template <typename T>
class CQueue
{
private:
    Node<T> *front; ///< Pointer to the front node of the queue.
    Node<T> *back;  ///< Pointer to the back node of the queue.
    int length;     ///< The number of elements in the queue.

public:
    /**
     * @brief default constructor.
     *
     * constructs an empty circular queue.
     */
    CQueue();

    /**
     * @brief single element constructor.
     *
     * constructs a circular queue with a single element.
     *
     * @param element the element to be added to the queue.
     */
    CQueue(T element);

    /**
     * @brief Array constructor.
     *
     * Constructs a circular queue from an array of elements.
     *
     * @param arr The array of elements to initialize the queue.
     * @param n The number of elements in the array.
     */
    CQueue(T arr[], int n);

    /**
     * @brief destructor.
     *
     * frees the memory
     */
    ~CQueue();

    /**
     * @brief Inserts an element into the queue.
     *
     * Adds a new element to the back of the queue according to FIFO.
     *
     * @param value The element to be added to the queue.
     */
    void push(T value);

    /**
     * @brief Removes and returns the front element of the queue.
     *
     * Removes the front element from the queue and returns its value.
     *
     * @return The value of the removed element.
     * @throws std::underflow_error If the queue is empty.
     */
    T pop();

    /**
     * @brief Returns the front element of the queue.
     *
     * Retrieves the value of the front element without removing it from the queue.
     *
     * @return A const reference to the front element.
     * @throws std::runtime_error If the queue is empty.
     */
    const T &GetFront() const;

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return The number of elements in the queue.
     */
    int size() const;

    /**
     * @brief Checks if the queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool empty() const;
};

template <typename T>
CQueue<T>::CQueue() : front(nullptr), back(nullptr), length(0) {}

template <typename T>
CQueue<T>::CQueue(T element) : front(nullptr), back(nullptr), length(1)
{
    Node<T> *newNode = new Node<T>(element);
    front = back = newNode;
    back->link = front;
}

template <typename T>
CQueue<T>::CQueue(T arr[], int n) : front(nullptr), back(nullptr), length(n)
{
    if (n == 0)
    {
        throw std::invalid_argument("Cannot initialize queue from an empty array.");
    }

    front = back = new Node<T>(arr[0]);

    Node<T> *current = front;

    for (int i = 1; i < n; ++i)
    {
        current->link = new Node<T>(arr[i]);
        current = current->link;
    }
    back = current;
    back->link = front;
}
template <typename T>
CQueue<T>::~CQueue()
{
    if (front != nullptr)
    {
        Node<T> *current = front;
        do
        {
            Node<T> *temp = current;
            current = current->link;
            delete temp;
        } while (current != front);
    }
    front = back = nullptr;
    length = 0;
}

template <typename T>
void CQueue<T>::push(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (!newNode)
    {
        throw std::bad_alloc();
    }

    if (front == nullptr && back == nullptr)
    {
        front = back = newNode;
        back->link = front;
        length = 1;
    }
    else
    {
        back->link = newNode;
        back = newNode;
        back->link = front;
        ++length;
    }
}

template <typename T>
T CQueue<T>::pop()
{
    if (empty())
    {
        throw std::underflow_error("Cannot pop from an empty queue.");
    }

    Node<T> *toFree = front;
    T value = front->data;

    if (front == back)
    {
        front = back = nullptr;
    }
    else
    {
        back->link = front->link;
        front = front->link;
    }

    length--;
    delete toFree;
    return value;
}

template <typename T>
const T &CQueue<T>::GetFront() const
{
    if (length == 0)
    {
        throw std::runtime_error("Queue is empty");
    }
    return front->data;
}

template <typename T>
int CQueue<T>::size() const
{
    return length;
}

template <typename T>
bool CQueue<T>::empty() const
{
    return length == 0;
}

#endif // CIRCULARQUEUE_H
