template <typename T>
class Node {
public:
    T data;
    Node<T> *first;
    Node<T> *second;

    Node(T& n) {
        this->data = n;
        this->first = nullptr;
        this->second = nullptr;
    }
};

template <typename T>
class Set {
private:
    Node<T> *root;
    int length;

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

private:
    Node<T>* insertRecursive(Node<T>* root, T element);
    bool containsRecursive(Node<T>* root, T number);
    void inorderTraversal(Node<T>* root);
    Node<T>* removeRecursive(Node<T>* root, T number);
    Node<T>* minValueNode(Node<T>* node);
    
};



template <typename T>
Set<T>::Set() {
    root = nullptr;
    length = 0;
}

template <typename T>
Set<T>::Set(T element) {
    root = new Node<T>(element);
    length = 1;
}

template <typename T>
Set<T>::Set(T arr[], int n) {
    root = nullptr;
    length = 0;

    for (int i = 0; i < n; ++i) {
        insert(arr[i]);
    }
}

template <typename T>
void Set<T>::insert(T element) {
    if (!contains(element)) {
        root = insertRecursive(root, element);
        length++;
    }
}

template <typename T>
Node<T>* Set<T>::insertRecursive(Node<T>* root, T element) {
    if (root == nullptr) {
        return new Node<T>(element);
    }

    if (element < root->data) {
        root->first = insertRecursive(root->first, element);
    } else if (element > root->data) {
        root->second = insertRecursive(root->second, element);
    }

    return root;
}

template <typename T>
bool Set<T>::empty() {
    return length == 0;
}

template <typename T>
int Set<T>::size() {
    return length;
}

template <typename T>
void Set<T>::remove(T number) {
    if (contains(number)) {
        root = removeRecursive(root, number);
        length--;
    }
}

template <typename T>
Node<T>* Set<T>::removeRecursive(Node<T>* root, T number) {
    if (root == nullptr) {
        return root;
    }

    if (number < root->data) {
        root->first = removeRecursive(root->first, number);
    } else if (number > root->data) {
        root->second = removeRecursive(root->second, number);
    } else {
        if (root->first == nullptr) {
            Node<T>* temp = root->second;
            delete root;
            return temp;
        } else if (root->second == nullptr) {
            Node<T>* temp = root->first;
            delete root;
            return temp;
        }

        Node<T>* temp = minValueNode(root->second);
        root->data = temp->data;
        root->second = removeRecursive(root->second, temp->data);
    }
    return root;
}

template <typename T>
Node<T>* Set<T>::minValueNode(Node<T>* node) {
    Node<T>* current = node;
    while (current->first != nullptr) {
        current = current->first;
    }
    return current;
}

template <typename T>
bool Set<T>::contains(T number) {
    return containsRecursive(root, number);
}

template <typename T>
bool Set<T>::containsRecursive(Node<T>* root, T number) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == number) {
        return true;
    }

    if (number < root->data) {
        return containsRecursive(root->first, number);
    } else {
        return containsRecursive(root->second, number);
    }
}

template <typename T>
void Set<T>::display() {
    inorderTraversal(root);
}

template <typename T>
void Set<T>::inorderTraversal(Node<T>* root) {
    if (root != nullptr) {
        inorderTraversal(root->first);
        std::cout << root->data << " ";
        inorderTraversal(root->second);
    }
}

// Added the required functions

// Union
template <typename T>
Set<T> Set<T>::Union(Set& s) {
    Set<T> result(*this);
    Node<T>* temp = s.root;
    while (temp != nullptr) {
        result.insert(temp->data);
        temp = temp->second;
    }
    return result;
}

// Intersection
template <typename T>
Set<T> Set<T>::Intersection(Set& s) {
    Set<T> result;
    Node<T>* temp = root;
    while (temp != nullptr) {
        if (s.contains(temp->data))
            result.insert(temp->data);
        temp = temp->second;
    }
    return result;
}

// Difference of two sets
template <typename T>
Set<T> Set<T>::operator-(Set& s) {
    Set<T> result(*this);
    Node<T>* temp = s.root;
    while (temp != nullptr) {
        if (result.contains(temp->data))
            result.remove(temp->data);
        temp = temp->second;
    }
    return result;
}

// True if both sets are equal else false
template <typename T>
bool Set<T>::operator==(Set& s) {
    if (length != s.size())
        return false;

    Node<T>* temp = root;
    while (temp != nullptr) {
        if (!s.contains(temp->data))
            return false;
        temp = temp->second;
    }
    return true;
}

// Cartesian product of the sets
template <typename T>
void Set<T>::operator*(Set& s) {
    Node<T>* temp1 = root;
    while (temp1 != nullptr) {
        Node<T>* temp2 = s.root;
        while (temp2 != nullptr) {
            std::cout << "(" << temp1->data << ", " << temp2->data << ")" << std::endl;
            temp2 = temp2->second;
        }
        temp1 = temp1->second;
    }
}

// Upper bound
template <typename T>
T Set<T>::upper_bound(T num) {
    Node<T>* temp = root;
    T upper = std::numeric_limits<T>::max();
    while (temp != nullptr) {
        if (temp->data > num && temp->data < upper)
            upper = temp->data;
        temp = temp->second;
    }
    return upper;
}

// Lower bound
template <typename T>
T Set<T>::lower_bound(T num) {
    Node<T>* temp = root;
    T lower = std::numeric_limits<T>::min();
    while (temp != nullptr) {
        if (temp->data < num && temp->data > lower)
            lower = temp->data;
        temp = temp->second;
    }
    return lower;
}