// template <typename T> class CQueue
// {
// 	private: 
// 		int front, back;
// 		int length;
// 		int *arr;
// 	public:
// 		CQueue(int s);				//constructor for circular queue object
// 		void push(T value);			//insert element into circular queue
// 		T pop();					//delete the element from the front of circular queue and return it
// 		const &T front();			//return element present at the front of the queue
//         T size();                   //return number of elements in circular queue 
// };
#include <stdexcept>

template <typename T>
class CQueue {
private:
    int front, back, length; static const int maxSize = 10; 
    T* arr;

public:
    // Constructor
    CQueue(int s = 10) : front(-1), back(-1), length(s) {
        if (s > maxSize) {
            throw std::invalid_argument("Initial size exceeds the maximum allowable size.");
        }
        arr = new T[maxSize];
    }

    // Destructor
    ~CQueue() {
        delete[] arr;
    }

    // Insert element into circular queue
  void push(T value) {
    // Check if the queue is full.
    // Two scenarios indicate a full queue:
    // 1. The back is right before the front in a wrapped situation (back + 1) % maxSize == front.
    // 2. The back is at the end (maxSize-1) and front is at the beginning (0), meaning the queue has filled up and wrapped around.
    if ((front == 0 && back == maxSize-1) ||
        ((back + 1) % maxSize == front)) {
        throw std::overflow_error("Queue is full");
    }
    // If the queue is empty, set both front and back to 0 and insert the first element. This condition initializes the queue.
    else if (front == -1) {
        front = back = 0;
        arr[back] = value;
        length = 1;
    }
    // If the back of the queue has reached the end of the array but the front isn't at the beginning,
    // wrap the back to the beginning of the array. This allows for efficient use of space in the circular queue.
    else if (back == maxSize-1 && front != 0) {
        back = 0;
        arr[back] = value;
          length++; //tracking length
    }
    // If the queue is neither full nor at a wrapping point, increment 'back' and insert the new value.
    else {
        back = (back + 1) % maxSize;
        arr[back] = value;
          length++; //tracking length
    }
  
}

    // Delete the element from the front of circular queue and return it
    T pop() {
     if (front == -1) //The queue is empty if the front index is -1.
    {
      throw std::underflow_error("Queue is empty");
       
    }
 
    T data = arr[front]; //  Store the data at the front 
    
    if (front == back) 
    {
        front = -1;
        back = -1; //there's only one element in the queue.so both indices are reset to -1.
        length = 0; //reset
    }
    else 
    {
        if (front == maxSize-1)  //If the front index is at the end of the array, wrap it around to 0
        front = 0;
    else
        front = (front + 1) % maxSize; //else increment

        length--; // since element is popped
    }
    return data; //pop
    }

    // Return element present at the front of the queue
    const T& frront() const {
        if (length == 0) {
            throw std::underflow_error("Queue is empty");
        }
        return  arr[front ];
    }

    // Return number of elements in circular queue
    T size() const {
        return static_cast<T>(length);// This method returns the size of the circular queue cast to the same type `T` as the queue's elements.
        //AS SPECIFIED IN THE QUESTION, THE FUNCTION RETURNS VALUE IN T.
        //returning in integer may cause precision error. If T is a floating-point type, casting an integer size to T might introduce precision issues for large sizes. 
    }
};
