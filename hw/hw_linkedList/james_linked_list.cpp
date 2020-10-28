#include <iostream>
using namespace std;

class LinkedList {
private:
    class Node { // LinkedList::Node
        public:
            int data;
            Node* next;
            Node(int val, Node* n=nullptr): 
                                        data(val), 
                                        next(n)
            {
            } 
    };
    
    Node* head;
    Node* tail;
    int len;

public:
    LinkedList() : 
                head(nullptr),
                tail(nullptr),
                len(0)
    {
    }

    LinkedList(int val) : 
                    head(new Node(val)),
                    tail(head),
                    len(0)
    {
    }

    ~LinkedList() {
        while(head != nullptr) {
            this->removeStart();
        }
    }
    
    LinkedList(const LinkedList& orig) = delete;
    LinkedList& operator =(const LinkedList& orig) = delete;
    
    void addStart(int v) { // O(1)
        if (head != nullptr) {
            Node* temp = head;
            head = new Node(v, head);
            head->next = temp;
        }
        else{
            head = new Node(v, head);
            tail = head;
        }
        len++;
    }

    void addEnd(int v) { // O(1)
        if (head != nullptr) {
            Node* temp = new Node(v);
            tail->next = temp;
            tail = tail->next;
            len++;
        }
        else{
            addStart(v);
        }
    }

    void insert(const int i, const int v) { //O(n)
        if (head != nullptr){
            Node* temp = head;
            for (int j = 0; j < i; j++){
                if (temp->next != nullptr) {
                    throw out_of_range("i was greater than length");
                    break;
                }
                temp = temp->next;
            }
            Node* newNode = new Node(v, temp->next);
            temp->next = newNode;
            len += 1;
        }
        else{
            addStart(v);
        }
    }

    int removeStart() { //O(1)
        if(head == nullptr){ 
            throw out_of_range("Attempting to remove from an empty LL");
        }

        Node* temp = head->next;
        int v = head->data;
        delete head;
        head = temp;
        len--;
        return v;
    }

    void removeEnd() { //O(n)
        if (head == nullptr){
            throw out_of_range("Attempting to remove from an empty LL");
        }
        else if (head->next == nullptr) { // next deletion will cause prev to not exist
            head = nullptr;
            tail = nullptr;
            len--;
        }
        else {   
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
    
    int get(int i) { //O(n)
        if(head != nullptr){
            Node* temp = head;
            for (int counter = 0; counter < i; counter++){
                temp = temp->next;
                if(temp == nullptr){
                    throw out_of_range("bad index for get");
                    break;
                }
            }
            return temp->data;
        }
        else {
            // https://stackoverflow.com/questions/2709719/throwing-out-of-range-exception-in-c
            throw out_of_range("Attempting to get from an empty LL");
        }
    }
};


int main() {
    LinkedList LL;
    const int n = 1000;

    for (int i = 0; i < n; i++)
        LL.addStart(i);
    for (int i = 0; i < n; i++)
        LL.addEnd(i);
    for (int i = 0; i < n; i++)
        LL.removeStart();
    for (int i = 0; i < n; i++)
        LL.removeEnd();

    cout << LL.getLength() << endl;

    //REALLY BAD. Don't do this
    for (int i = 0; i < LL.getLength(); i++)
      cout << LL.get(i); // 1 + 2 + 3 + ... + (n-1)+n O(n^2)
}