#include <iostream>
using namespace std;



class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};


class SinglyLinkedList 
{
private:

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    

    void add(int data) 
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    

    void remove(int data) 
    {
        if (!head) return;

        if (head->data == data) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }


        Node* current = head;
        while (current->next && current->next->data != data) {
            current = current->next;
        }


        if (current->next) 
        {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

   

    bool search(int data) const {

        Node* current = head;
        while (current) {

            if (current->data == data) return true;
            current = current->next;
        }
        return false;
    }

   

    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    
    ~SinglyLinkedList() {
        Node* current = head;


        while (current)
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

void main() 
{
    SinglyLinkedList list;

    

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "List after adding elements: ";
    list.print();

   

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not found") << endl;
    cout << "Searching for 50: " << (list.search(50) ? "Found" : "Not found") << endl;

    

    list.remove(20);
    cout << "List after removing 20: ";
    list.print();


    list.remove(10);
    cout << "List after removing 10: ";
    list.print();


    

}






