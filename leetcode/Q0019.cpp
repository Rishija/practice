/*
 Given a linked list, remove the n-th node from the end of list and return its head.
 
 Example:
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5
 
 Note:
 Given n will always be valid.
 
 Follow up:
 Could you do this in one pass?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* helper1(ListNode* head, int n) {
    if(head == nullptr)
        return nullptr;
    
    queue<ListNode*> q;
    ListNode* current = head;
    while(current != nullptr) {
        if(q.size() == n + 1)
            q.pop();
        q.push(current);
        current = current->next;
    }
    // Node to be removed is head itself
    if(q.size() < n + 1)
        return q.front()->next;
    
    auto parent = q.front();
    q.pop();
    parent->next = q.front()->next;
    return head;
}

ListNode* helper2(ListNode* head, int k) {
    if(head == nullptr)
        return nullptr;
    
    ListNode *left = head, *right = head;
    for(int i = 0; i < k; ++i)
        right = right->next;
    // Node to be removed is head itself
    if(right == nullptr)
        return head->next;
    
    while(right->next != nullptr) {
        left = left->next;
        right = right->next;
    }
    
    left->next = left->next->next;
    return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // return helper1(head, n);
    return helper2(head, n);
    /* Method 3
     Find length of linked size (=n). Traverse first n-k nodes. Delete current node
     */
}
