#include <iostream>
using namespace std;

class Queue 
{
    private:
        string* q_arr;  
        int q_capacity;
        int q_front;
        int q_back;
        int q_size;
    
        //Copy other queue
        void copyQueue(const Queue& other) 
        {
            q_arr = new string[other.q_capacity];
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
    
            //Copy elements from the other queue 
            for (int i = 0; i < q_capacity; i++) 
            {
                q_arr[i] = other.q_arr[i];
            }
        }
    
    public:
        //Constructor with specified cap
        Queue(int cap = 10) : q_capacity(cap), q_size(0), q_front(0), q_back(-1) 
        {
            q_arr = new string[q_capacity];
        }
    
        // Destructor to free the allocated memory
        ~Queue() 
        {
            delete[] q_arr;
        }
    
        // Copy Constructor
        Queue(const Queue& cope) 
        {
            copyQueue(cope);
        }
    
        // Copy Assignment Operator
        Queue& operator=(const Queue& cope) 
        {
            if (this != &cope) {
                delete[] q_arr;  // Deallocate old memory
                copyQueue(cope);
            }
            return *this;
        }
    
        //Is Empty
        bool empty() const 
        {
            return q_size == 0;
        }
    
        //Queue size
        int size() const 
        {
            return q_size;
        }
    
        //Reset queue
        void clear() 
        {
            q_size = 0;
            q_front = 0;
            q_back = -1;
        }
    
        //Front element
        int front() const 
        {
            if (empty()) {
                return -1;
            }
            return q_front;
        }
    
        //Back element
        int back() const 
        {
            if (empty()) 
            {
                cout << "Queue is empty." << endl;
                return -1;
            }
            return q_back;
        }
    
        //Enqueue
        void enqueue(string value) 
        {
            if (q_size == q_capacity) 
            {
                cout << "Failed to enqueue - Queue is already full." << endl;
                return;
            }
            q_back = (q_back + 1) % q_capacity;
            q_arr[q_back] = value;
            q_size++;
        }
    
        //Dequeue
        string dequeue() 
        {
            if (empty()) 
            {
                return NULL;
            }
            string value = q_arr[q_front];
            q_front = (q_front + 1) % q_capacity;
            q_size--;
            return value;
        }
    
        // Display the queue contents / Traverse
        void show() const 
        {
            if (empty()) 
            {
                cout << "Queue is empty." << endl;
                return;
            }
            for (int i = 0; i < q_size; i++) 
            {
                cout << q_arr[(q_front + i) % q_capacity] << " ";
            }
            cout << endl;
        }
};

//DRIVER
int main() 
{
    Queue students(5);
    students.enqueue("Kent");
    students.enqueue("Peter");
    students.enqueue("Christian");
    students.enqueue("Joseph");
    students.enqueue("Jervie");
    cout << "All elements: ";
    students.show();
    cout << "Removed element: " << students.dequeue() << endl;
    students.show();
    //Copy constructor
    Queue q2 = students;  
    cout << "Copied constructor: ";
    q2.show();
    //Copy assignment operator
    Queue q3;
    q3 = students;
    q3.enqueue("Kent");
    cout << "Copied assignment operator: ";
    q3.show();

    return 0;
}
