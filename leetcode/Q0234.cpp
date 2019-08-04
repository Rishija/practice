/*
 Given a singly linked list, determine if it is a palindrome.

 Example 1:

 Input: 1->2
 Output: false
 Example 2:

 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)    return true;

        stack<int> s;
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != nullptr) slow = slow->next;

        while(!s.empty()) {
            if(s.top() != slow->val)   return false;
            s.pop();
            slow = slow->next;
        }
        return true;
    }
};
