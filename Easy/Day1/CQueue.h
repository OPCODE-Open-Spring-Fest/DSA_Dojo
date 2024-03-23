template <typename T> class CQueue
{
	private: 
		int front, back;
		int length;
		int *arr;
	public:
		CQueue(int s);				//constructor for circular queue object
		void push(T value);			//insert element into circular queue
		T pop();					//delete the element from the front of circular queue and return it
		const &T front();			//return element present at the front of the queue
        T size();                   //return number of elements in circular queue 
};