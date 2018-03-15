#include "linked_list.h"

/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 */
template<class T>
void Linked_list<T>::Delete(Node* node) {
    
    if(head == nullptr)
        return;
    
    Node* dummyHead;
    dummyHead -> next = head;
    Node* current = dummyHead;
    
    while( current -> next != node && current != nullptr)
        current = current -> next;
    
    // Given node actually belongs to the list
    if(current != nullptr) {
        Node* temp = current;
        current -> next = current -> next -> next;
        delete temp -> next;        // free memory
    }
    
    head = dummyHead -> next;
}
