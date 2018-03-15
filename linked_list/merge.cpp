#include "linked_list.h"

/**
 * Time complexity : O( max(length(list1), length(list2) )
 * Space complexity : O( length(list1) + length(list2) )
 */
template<class T>
typename Linked_list<T>::Node* Linked_list<T>::merge(Linked_list<T> list1, Linked_list<T> list2) {
    
    head = nullptr;
    Node *head1 = list1.head, *head2 = list2.head, *current = head;
    
    while(head1 != nullptr && head2 != nullptr) {
        
        if(head1 -> val < head2 -> val) {
            this -> insert(head1 -> val);
            head1 = head1 -> next;
        }
        else {
            this -> insert(head2 -> val);
            head2 = head2 -> next;
        }
        
        if(current == nullptr)
            current = head;
        else
            current = current -> next;
    }
    
    Node* listLeft = (head1 == nullptr) ? head2 : head1;
    
    if(head == nullptr)
        head = listLeft;
    else
        this -> insert(current, listLeft);      // set pointer to rest of the list
    
    return head;
}

int main() {
    Linked_list<int> l1, l2, l3;
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    l1.insert(50);
    l2.insert(15);
    l2.insert(17);
    l3.merge(l1, l2);
    l3.print();
    return 0;
}
