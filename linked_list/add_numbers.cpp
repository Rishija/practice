#include "linked_list.h"

/**
 Add two numbers given by linked list
 
 Ex: 1234 + 56 is given as
 
 1-->2-->3-->4
 5-->6
 
 Answer should be   1-->2-->9-->0
 
 Time Complexity : O( max(length of both the lists) )
 Space Complexity : O( max(length of both the lists) )
 */
template<>
Linked_list<int>::Node*  Linked_list<int>::add(Linked_list<int> list1, Linked_list<int> list2){
    
    head = nullptr;
    Node *head1 = list1.head, *head2 = list2.head;
    this -> insert(0);
    Node* current = head;
    
    if(head1 == nullptr && head2 == nullptr)
        return head;
    
    stack<int> stack1, stack2;
    stack<Node*> nodeStack;
    
    int sum;
    bool carry = 0;
    
    while(head1 != nullptr && head2 != nullptr) {
        
        this -> insert(0);
        stack1.push(head1 -> val);
        stack2.push(head2 -> val);
        nodeStack.push(current);
        
        head1 = head1 -> next;
        head2 = head2 -> next;
        current = current == nullptr ? head : current -> next;
    }
    
    Node* listLeft = (head1 == nullptr) ? head2 : head1;
    stack<int> &stackLeft = (head1 == nullptr) ? stack2 : stack1;   // alias for corresponding stack
    
    while(listLeft != nullptr) {
        this -> insert(0);
        stackLeft.push(listLeft -> val);
        nodeStack.push(current);
        listLeft = listLeft -> next;
        current = current == nullptr ? head : current -> next;
    }
    
    
    while(!stack1.empty() && !stack2.empty()) {
        
        sum = stack1.top() + stack2.top() + carry;
        nodeStack.top() -> next -> val = sum % 10;
        
        stack1.pop();
        stack2.pop();
        nodeStack.pop();
        
        carry = sum/10;
    }
    
    stackLeft = (stack1.empty()) ? stack2 : stack1;
    
    while(!stackLeft.empty()) {
        
        sum = stackLeft.top() + carry;
        nodeStack.top() -> next -> val = sum % 10;
        
        stackLeft.pop();
        nodeStack.pop();
        
        carry = sum/10;
    }
    
    if(carry)
        head -> val = 1;
    else
        head = head -> next;
    
    return head;
}


int main() {
    Linked_list<int> l1, l2, l3;
    l3.add(l1, l2);
    l3.print();
    
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l1.insert(9);
    l3.add(l1,l2);
    l3.print();
    
    l2.insert(1);
    l3.add(l1,l2);
    l3.print();
    
    return 0;
}
