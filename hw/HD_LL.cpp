#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node { // LinkedList::Node
        public:
            int data;
            Node* next;
            Node(int val, Node* n=nullptr): data(val), next(n) {} 
    };
    Node* head;
    Node* tail;     
    int len;

public:
    LinkedList() : head(nullptr), tail(nullptr), len(0) {}
    LinkedList(int val) : head(new Node(val)), tail(head), len(0) {}
    ~LinkedList() {
        while(head != nullptr) {
            this->removeStart();
        }
    }
    
    LinkedList(const LinkedList& orig) = delete;
    LinkedList& operator =(const LinkedList& orig) = delete;
    
    void addStart(const int v) { // O(1)
        if(head != nullptr) {
            Node* temp = head;
            head = new Node(v, head);
            head->next = temp;
        } else {
          head = new Node(v, head);
          tail = head;
        }
        len++;
    }

    void addEnd(const int v) {  // O(1)
        if (head != nullptr) {
            Node* temp = new Node(v);
            tail->next = temp;
            tail = tail->next;
            len++;
        } else addStart(v);
    }

    void insert(const int i, const int v) { //O(n)
        if (head != nullptr) {
            Node* temp = head;
            for (int j = 0; j < i-1; j++) {
                if (temp->next == nullptr) {
                    throw out_of_range("i was greater than length");
                    break;
                }
                temp = temp->next;
            }
            Node* newNode = new Node(v, temp->next);
            temp->next = newNode;
            len++;
        } else addStart(v);
    }

    int removeStart() { //O(1)
        if(head == nullptr) { 
            throw out_of_range("Attempting to remove from an empty LL");
        }
        Node* temp = head->next;
        int v = head->data;
        delete head;
        head = temp;
        len--;
        return v;
    }

    // Can't be O(1) unless a DLL is used
    void removeEnd() { //O(n)
        if (head == nullptr)
            throw out_of_range("Attempting to remove from an empty LL");
        else if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;
            len--;
        } else {
            Node* prev;
            Node* p;
            for (p = head; p->next != nullptr; prev = p, p = p->next)
                ;
            delete p;
            prev->next = nullptr;
            len--;
        }
    }

    int getLength() const { //O(1)
        return len;
    }
    
    int get(int n) { //O(n)
        if(head != nullptr){
            Node* temp = head;
            for (int counter = 0; counter < n; counter++){
                temp = temp->next;
                if(temp == nullptr) throw out_of_range("bad index for get");
            }
            return temp->data;
        }
        // https://stackoverflow.com/questions/2709719/throwing-out-of-range-exception-in-c
        throw out_of_range("Attempting to get from an empty LL");
    }
};

int main() {
    LinkedList a;
    const int n = 1000;
    for (int i = 0; i < n; i++)
        a.addStart(i);
    for (int i = 0; i < n; i++)
        a.addEnd(i);
    for (int i = 0; i < n; i++)
        a.removeStart();
    for (int i = 0; i < n; i++)
        a.removeEnd();
    cout << a.getLength() << '\n';

    //REALLY BAD. Don't do this
    for (int i = 0; i < a.getLength(); i++)
      cout << a.get(i) << ", ";
}