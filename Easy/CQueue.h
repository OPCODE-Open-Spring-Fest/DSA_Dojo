#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <stdexcept>

/**
 * @brief A class representing a circular queue.
 * 
 * @tparam T The type of elements stored in the queue.
 */
template <typename T>
class CQueue {
private:
    int front, back;  ///< Index of the front and back elements in the queue
    int length;       ///< Length of the circular queue
    T *arr;           ///< Pointer to the array storing the elements

public:
    /**
     * @brief Constructor for the circular queue object.
     * 
     * @param s The initial size of the circular queue (default size is 10).
     * @throws std::invalid_argument if the size is less than or equal to 0.
     */
    CQueue(int s = 10);

    /**
     * @brief Destructor to deallocate memory.
     */
    ~CQueue();

    /**
     * @brief Pushes an element into the circular queue.
     * 
     * @param value The value to push to the queue.
     * @throws std::overflow_error if the circular queue is full.
     */
    void push(T value);

    /**
     * @brief Deletes the element from the front of the circular queue and returns it.
     * 
     * @return The element removed from the front of the queue.
     * @throws std::underflow_error if the circular queue is empty.
     */
    T pop();

    /**
     * @brief Returns the element present at the front of the circular queue.
     * 
     * @return The element present at the front of the queue.
     * @throws std::underflow_error if the circular queue is empty.
     */
    const T& getFront() const;

    /**
     * @brief Returns the number of elements in the circular queue.
     * 
     * @return The number of elements in the queue.
     */
    int size() const;

    /**
     * @brief Checks if the circular queue is empty.
     * 
     * @return True if the circular queue is empty, false otherwise.
     */
    bool empty() const;
};

template <typename T>
CQueue<T>::CQueue(int s) : front(-1), back(-1) {
    if (s <= 0) {
        throw std::invalid_argument("Size of circular queue should be greater than 0");
    }
    length = s > 10 ? s : 10;  // Set the size to 10 if s is less than or equal to 10
    arr = new T[length];
}

template <typename T>
CQueue<T>::~CQueue() {
    delete[] arr;  // Deallocate the memory allocated for the array
}

template <typename T>
void CQueue<T>::push(T value) {
    if ((back + 1) % length == front) {
        throw std::overflow_error("Circular queue is full");
    }

    if (front == -1) {
        front = 0;
    }

    back = (back + 1) % length;

    arr[back] = value;
}

template <typename T>
T CQueue<T>::pop() {
    if (front == -1) {
        throw std::underflow_error("Circular queue is empty");
    }

    T element_removed = arr[front];

    if (front == back) {
        front = back = -1;
    } else {
        front = (front + 1) % length;
    }

    return element_removed;
}

template <typename T>
const T& CQueue<T>::getFront() const {
    if (front == -1) {
        throw std::underflow_error("Circular queue is empty");
    }

    return arr[front];
}

template <typename T>
int CQueue<T>::size() const {
    if (front == -1) {
        return 0;
    } else if (back >= front) {
        return back - front + 1;
    } else {
        return length - front + back + 1;
    }
}

template <typename T>
bool CQueue<T>::empty() const {
    return front == -1;
}

#endif // CIRCULAR_QUEUE_H
