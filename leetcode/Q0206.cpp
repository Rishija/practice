/*
 Reverse a singly linked list.

 Example:

 Input: 1->2->3->4->5->NULL
 Output: 5->4->3->2->1->NULL
 Follow up:

 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return head;
        ListNode *parent = head, *current = head->next;
        head->next = nullptr;

        while(true) {
            ListNode *temp = current->next;
            current->next = parent;
            parent = current;
            if(temp == nullptr) return current;
            current = temp;
        }
        return nullptr;
    }
};
