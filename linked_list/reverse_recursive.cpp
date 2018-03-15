#include "linked_list.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void Linked_list<T>::reverse_recursive() {
    
    head = reverse_recursive(head);
    
    /* Method 2
     head = reverse_recursive(head, nullptr);
     */
}

template<class T>
typename Linked_list<T>::Node* Linked_list<T>::reverse_recursive(Node* node) {
    
    if(node -> next == nullptr) {
        return node;
    }
    Node* temp = reverse_recursive(node -> next);
    node -> next -> next = node;
    node -> next  = nullptr;
    return temp;
}

/** Method 2 **/

// Do not pass reference here
template<class T>
typename Linked_list<T>::Node* Linked_list<T>::reverse_recursive(Node* node, Node* parent) {
    
    if(node -> next == nullptr) {
        node -> next = parent;
        return node;
    }
    
    Node* nextNode = node -> next;
    node -> next = parent;
    return reverse_recursive(nextNode, node);
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

