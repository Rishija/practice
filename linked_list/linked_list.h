#ifndef linked_list_h
#define linked_list_h

#include <iostream>
using namespace std;

template<class T>
class Linked_list {
public:
    class Node {
    public:
        T val;
        Node* next;
        Node() : next(nullptr) {}
        Node(T value) : val(value), next(nullptr) {}
    };
    
    Linked_list() : head(nullptr) {}
    void insert(T);
    void print();
    void reverse_iterative();
    void reverse_recursive();
    int delete_value(T);
    
private:
    Node* head;
    
    void insert(Node* &, T);
    Node* reverse_recursive(Node*, Node*);
    void delete_value(Node*, T, int &);
};


/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void Linked_list<T>::insert(T value) {
    
    insert(head, value);
}

template<class T>
void Linked_list<T>::insert(Node* &node, T value) {
    
    if(node == nullptr) {
        node = new Node(value);
    }
    else {
        insert(node -> next, value);
    }
}


/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void Linked_list<T>::print() {
    
    Node* current = head;
    while(current != nullptr) {
        cout << current -> val << " ";
        current = current -> next;
    }
    cout << endl;
}

#endif   /* linked_list_h */
