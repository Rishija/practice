#ifndef random_list_h
#define random_list_h

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
    void print() const;
    void insert(T value);
    Node* insert_without_random(T);
    List<T>& operator= (const List<T> &);
    
private:
    Node* head;
    size_t size;
    
    Node* insert_without_random(Node* &, T);
    void insert(Node* &, T value);
    size_t getIndex(Node*) const;
};

/**
 * Time complexity : O(n^2)
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
        
        // O(n) operation
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
void List<T>::print() const {
    
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

#endif   /* random_list_h */
