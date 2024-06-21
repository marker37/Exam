#include <iostream>
#include <vector>
using namespace std;



template <typename T>

class Queue {
private:
    vector<T> data;  

public:
    
    void enqueue(const T& element) {
        data.push_back(element);
    }


  

    void dequeue() {
        if (!isEmpty()) {
            data.erase(data.begin());
        }
        else {
            cout << "Queue is empty!" << endl;
        }
    }

    

    T front() const {
        if (!isEmpty()) 
        {
            return data.front();
        }
        else {
            throw runtime_error("Queue is empty!");
        }
    }

    

    bool isEmpty() const {
        return data.empty();
    }
};

void main() 
{
   

    Queue<int> intQueue;

  

    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);

    

    cout << "Front element: " << intQueue.front() << endl;

   

    intQueue.dequeue();
    cout << "Front element after dequeue: " << intQueue.front() << endl;

    intQueue.dequeue();
    intQueue.dequeue();

    

    if (intQueue.isEmpty()) 
    {
        cout << "Queue is empty!" << endl;
    }
    else {
        cout << "Queue is not empty!" << endl;
    }

  
}