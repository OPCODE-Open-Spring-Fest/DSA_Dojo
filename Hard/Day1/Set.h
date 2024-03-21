template <typename T> class Node {
public:
    T data;
    Node<T> * first;
    Node<T> * second;
   
    Node(T& n)
    {
        this->data = n;
        this->first = nullptr;
        this->second = nullptr;
    }
};

template <typename T> class Set {
    private:
        Node<T> * root;
        int size;
    public:
        Set();                    //default constructor
        Set(T element);           //constructor to initialise set with one number
        Set(T arr[], int n);      //constructor to initialise set from an array containing n elements
        void insert(T element);   //insert element into the set if it is not present
        bool empty();             //return true if set is empty and false otherwise
        int size();               //return number of elements present in the set
        void remove(T number);    //delete number if it is present in the set
        bool contains(T number);  //return true if number is present in the set and false otherwise
        void display();           //prints all elements of the set
        Set Union(Set &s);        //return a set containing union of elements present in current set and s 
        Set Intersection(Set &s); //return a set containing intersection of elements present in current set and s 
        Set operator-(Set& s);    //return the difference of two sets
        bool operator==(Set& s);  //return true if both sets are equal and false otherwise
        void operator*(Set& s);   //print the cartesian product of two sets
        T upper_bound(T num);     //find upper bound of num in set
        T lower_bound(T num);     //find lower bound of num in set
};