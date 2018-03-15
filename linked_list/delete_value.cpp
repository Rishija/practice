#include "linked_list.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
int Linked_list<T>::delete_value(T k) {
    
    int count = 0;
    Node* dummyHead;
    dummyHead -> next = head;
    
    delete_value(dummyHead, k, count);
    
    head = dummyHead -> next;
    return count;
}

template<class T>
void Linked_list<T>::delete_value(Node* node, T k, int &count) {
    
    if(node == nullptr || node -> next == nullptr)
        return;
    
    Node* nextNode = node -> next;
    
    if(nextNode -> val == k) {
        ++ count;
        delete node -> next;        // free memory
        node -> next = nextNode -> next;
        delete_value(node, k, count);
    }
    else
        delete_value(node -> next, k, count);
}

int main() {
    Linked_list<int>list;
    list.insert(40);
    list.insert(40);
    list.insert(5);
    list.insert(25);
    list.insert(40);
    list.insert(40);
    list.insert(35);
    list.insert(0);
    list.insert(15);
    list.insert(40);
    list.insert(30);
    list.insert(40);
    list.insert(40);
    list.print();
    cout << endl << "Occurences deleted: " << list.delete_value(40) << endl << endl;
    list.print();
    return 0;
}

