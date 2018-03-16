/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. Create a new list which follows the same struture.
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

template<class T>
class List {
public:
    class Node {
    public:
        T val;
        Node *next, *random;
        Node() : next(nullptr), random(nullptr) { }
        Node(T value) : val(value), next(nullptr), random(nullptr) { }
    };
    
    List() : head(nullptr), size(0) {}
    void print();
    void insert(T value);
    void insert(Node* &, T value);
    
private:
    Node* head;
    size_t size;
    void assignRandom(Node*);
};

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void List<T>::insert(T value) {
    
    insert(head, value);
    ++ size;
}

template<class T>
void List<T>::insert(Node* &node, T value) {
    
    if(node != nullptr)
        insert(node -> next, value);
    
    else {
        node = new Node(value);
        Node* current = head;
        int randd = rand() % (size + 2), i = 0;
        
        while(i < randd) {
            current = current -> next;
            ++i;
        }
        node -> random = current;
    }
}

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void List<T>::print() {
    
    Node* current;
    current = head;
    while(current != nullptr) {
        cout << "Next: " << setw(20) << left
        << current -> next << "Random: " << setw(20) << left
        << current -> random << "Value: " << current -> val << endl;
        current = current -> next;
    }
    cout << endl;
}


int main() {
    List<int>list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    list.insert(70);
    list.insert(80);
    list.insert(90);
    
    list.print();
    return 0;
}
