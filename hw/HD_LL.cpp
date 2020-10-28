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
    LinkedList() : head(nullptr), tail(nullptr), len(0) {
    }
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
        }
        else {
          head = new Node(v, head);
          tail = head;
        }
        len += 1;
    }

    // DOES NOT WORK YET
    void addEnd(const int v) {  // O(1)
        if (head != nullptr) {
            Node* temp = new Node(v);
            tail->next = temp;
            tail = temp;
            len += 1;
        } else addStart(v);
    }

    void insert(const int i, const int v) { //O(n)
        if (head != nullptr){
            Node* temp = head;
            for (int j = 0; j < i-1; j++) {
                if (temp->next == nullptr) 
                {
                    throw out_of_range("i was greater than length");
                    break;
                }
                temp = temp->next;
            }
            Node* newNode = new Node(v, temp->next);
            temp->next = newNode;
            len += 1;
        }
        else addStart(v);
    }

    int removeStart() { //O(1)
        if(head == nullptr){ 
            throw out_of_range("Attempting to remove from an empty LL");
        }
        Node* temp = head->next;
        int v = head->data;
        delete head;
        head = temp;
        len -= 1;
        return v;
    }

    // DOES NOT WORK YET
    void removeEnd() { //O(n)
        if (head == nullptr)
            throw out_of_range("Attempting to remove from an empty LL");
        Node* prev;
        Node* p;
        for (p = head; p->next != nullptr; prev = p, p = p->next)
            ;
        delete p;
        prev->next = nullptr;
        len--;
    }

    int getLength() const { //O(1)
        return len;
    #if 0
        int count = 0;
        for (Node* p = head; p != nullptr; p = p->next)
          count++;
        return count;
    #endif
    }
    
    int get(int i) { //O(i)
        if(head != nullptr){
            Node* temp = head;
            for (int counter = 0; counter < i; counter++){
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
    const int n = 50;
    // For homework, use this main and implement a linkedlist with head and tail.
    // One of these operations is O(n). You may make that loop < 1000
    // for (int i = 0; i < n; i++)
    //     a.addStart(i);
    for (int i = 0; i < n; i++)
      a.addEnd(i);
    for (int i = 0; i < n/2; i++)
        a.removeStart();
    // Doesn't work yet
    // for (int i = 0; i < n; i++)
    //     a.removeEnd();
    cout << a.getLength() << '\n';

    //REALLY BAD. Don't do this
    for (int i = 0; i < a.getLength(); i++)
      cout << a.get(i) << ", ";
    // #endif
    //     for (LinkedList::iterator i = a; !i; ++i)
    //       cout << *i;
    //     return 0;
}