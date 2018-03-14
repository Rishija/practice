#include "linked_list.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
void Linked_list<T>::reverse_iterative() {
    
    if(head == nullptr || head -> next == nullptr)
        return;
    
    Node *current = head, *parent = nullptr, *temp;
    while(current != nullptr) {
        temp = current -> next;
        current -> next = parent;
        parent = current;
        current = temp;
    }
    head = parent;
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
    list.reverse_iterative();
    list.print();
    return 0;
}
