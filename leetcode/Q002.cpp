/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Example:
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    
    int carry = 0;
    ListNode *c1 = l1, *c2 = l2;
    ListNode head(0);
    ListNode *current = &head;
    
    while(c1 != nullptr && c2 != nullptr) {
        current -> next = new ListNode((c1 -> val + c2 -> val + carry) % 10);
        carry = (c1 -> val + c2 -> val + carry) / 10;
        current = current -> next;
        c1 = c1 -> next;
        c2 = c2 -> next;
    }
    
    if(c1 == nullptr && c2 == nullptr) {
        if(carry > 0)
            current -> next = new ListNode(1);
        return head.next;
    }
    
    if(carry) {
        
        ListNode *node = (c1 == nullptr) ? c2 : c1;
        while(node != nullptr && carry > 0) {
            current -> next= new ListNode((carry + node -> val) % 10);
            carry = (carry + node -> val) / 10;
            current = current -> next;
            node = node -> next;
        }
        if(carry)
            current -> next = new ListNode(1);
        else
            current -> next = node;
    }
    else
        current -> next = (c1 == nullptr) ? c2 : c1;
    return head.next;
}
