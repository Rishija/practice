#include "linked_list.h"

/**
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 */
template<class T>
bool Linked_list<T>::isPalimdrome() const {
    
    if(head == nullptr || head -> next == nullptr)
        return true;
    
    Node *slow = head, *fast = head;
    stack<T> stack;
    
    while(fast != nullptr && fast -> next != nullptr) {
        stack.push(slow -> val);
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    if(fast != nullptr)
        slow = slow -> next;
    
    while(!stack.empty()) {
        if(stack.top() != slow -> val)
            return false;
        stack.pop();
        slow = slow -> next;
    }
    return true;
}


int main() {
    Linked_list<int>list;
    list.insert(40);
    list.insert(5);
    list.insert(30);
    list.insert(66);
    list.insert(66);
    list.insert(30);
    list.insert(5);
    list.insert(40);
    list.print();
    cout << list.isPalimdrome() << endl;
    list.insert(40);
    cout << list.isPalimdrome() << endl;
    return 0;
}
