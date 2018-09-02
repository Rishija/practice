/*
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Example:
 
 Input:
 [
 1->4->5,
 1->3->4,
 2->6
 ]
 Output: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class cmp {
public:
    bool operator() (const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(auto l : lists) if(l != nullptr)  heap.push(l);
        
        ListNode *head = nullptr, *current = nullptr;
        while(!heap.empty()) {
            ListNode* temp = heap.top();
            if(head == nullptr) {
                head = temp;
                current = temp;
            }
            else  {
                current->next = temp;
                current = current->next;
            }
            heap.pop();
            if(temp->next != nullptr)
                heap.push(temp->next);
        }
        return head;
    }
};

// ---------------------------------------------------------------


// Mereg 2 linked lists
ListNode* merge2(ListNode* h1, ListNode* h2) {
    if(h1 == nullptr)   return h2;
    if(h2 == nullptr)   return h1;
    ListNode *head = nullptr, *current = nullptr, *n1 = h1, *n2 = h2;
    while(n1 != nullptr && n2 != nullptr) {
        ListNode* min = (n1->val < n2->val) ? n1 : n2;
        if(head == nullptr) { head = min; current = min; }
        else { current->next = min; current = current->next; }
        min == n1 ? (n1 = n1->next) : (n2 = n2->next);
    }
    current->next = (n1 == nullptr) ? n2 : n1;
    return head;
}

ListNode* mergeKLists(vector<ListNode*> lists) {
    
    int n = lists.size();
    if(n == 0)   return nullptr;
    
    int j = n - 1;
    while(j != 0) {
        // Merge last 2 lists
        ListNode* last2 = merge2(lists[j], lists[j-1]);
        lists.pop_back(); lists.pop_back();
        // Add merged list to `lists`
        if(last2 != nullptr)    lists.push_back(last2);
        --j;
    }
    return lists[0];
}
