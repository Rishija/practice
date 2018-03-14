#include "linked_list.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void Linked_list<T>::reverse_recursive() {
    reverse_recursive(head);
}

// Do not pass reference here
template<class T>
void Linked_list<T>::reverse_recursive(Node* node) {
    
    if(node -> next == nullptr) {
        head = node;
        return;
    }
    
    reverse_recursive(node -> next);
    node -> next -> next = node;
    node -> next  = nullptr;
}

int main() {
    Linked_list<int>list;
    list.insert(10);
    list.insert(5);
    list.insert(25);
    list.insert(35);
    list.insert(0);
    list.insert(15);
    list.insert(30);
    list.insert(40);
    list.print();
    list.reverse_recursive();
    list.print();
    return 0;
}

