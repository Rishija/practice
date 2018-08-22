/*
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 Example:
 
 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* method1(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr)   return l2;
    if(l2 == nullptr)   return l1;
    
    ListNode *head, *current;
    if(l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    }
    else {
        head = l2;
        l2 = l2->next;
    }
    current = head;
    
    while(l1 != nullptr && l2 != nullptr) {
        if(l1->val < l2->val) { current->next = l1; l1 = l1->next; }
        else { current->next = l2; l2 = l2->next; }
        current = current->next;
    }
    current->next = (l1 == nullptr) ? l2 : l1;
    return head;
}

ListNode* method2(ListNode* l1, ListNode* l2) {
    if(l1 == nullptr)   return l2;
    if(l2 == nullptr)   return l1;
    ListNode *head;
    if(l1->val < l2->val) {
        head = l1;
        head->next = method2(l1->next, l2);
    }
    else {
        head = l2;
        head->next = method2(l1, l2->next);
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // return method1(l1, l2);
    return method2(l1, l2);
}
