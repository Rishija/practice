#include "random_list.h"

/* Method 2 : Use map to store indices of nodes of original list */

/**
 * Time complexity : O(n)
 * Space complexity : O(1)
 */
template<class T>
typename List<T>::Node* List<T>::insert_without_random(T value) {
    
    return insert_without_random(head, value);
}

template<class T>
typename List<T>::Node* List<T>::insert_without_random(Node* &node, T value) {
    
    if(node == nullptr) {
        node = new Node(value);
        return node;
    }
    else
        return insert_without_random(node -> next, value);
}

/**
 * Time complexity : O(n)
  * Time complexity : O(Log(n))        with method 2
 * Space complexity : O(1)
 */
template<class T>
size_t List<T>::getIndex(Node* node) const {
    
    if(node == nullptr)
        return 0;
    
    /* Uncomment to use method 2
     return indexx.find(node) -> second + 1;
     */
    
    size_t index = 1;
    Node* current = head;
    while(current != node) {
        current = current -> next;
        ++ index;
    }
    return index;
}

/**
 * Time complexity : O(n^2)
 * Time complexity : O(n Log(n))        with method 2
 * Space complexity : O(n)
 */
template<class T>
List<T>& List<T>::operator=(const List<T> &source) {
    
    if(source.head == nullptr) {
        this -> head = nullptr;
        return *this;
    }
    
    Node *current = source.head, *current2;
    int index;
    
    while(current != nullptr) {
        
        Node* temp = this -> insert_without_random(current -> val);
        index = source.getIndex(current -> random);
        
        if(!index) {
            temp -> random = nullptr;
        }
        else {
            -- index;
            current2 = this -> head;
            while(index > 0) {
                current2 = current2 -> next;
                -- index;
            }
            temp -> random = current2;
        }
        
        current = current -> next;
    }
    return *this;
}

int main() {
    List<int>list1, list2;
    list1.print();
    list2 = list1;
    list2.print();
    
    list1.insert(10);
    
    list1.print();
    list2 = list1;
    list2.print();
    
    list1.insert(20);
    list1.insert(30);
    list1.insert(40);
    list1.insert(50);
    list1.insert(60);
    list1.insert(70);
    list1.insert(80);
    list1.insert(90);
    list1.print();
    list2 = list1;
    list2.print();
    return 0;
}
