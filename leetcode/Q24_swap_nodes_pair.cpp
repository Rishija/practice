/*
 Given a linked list, swap every two adjacent nodes and return its head.
 */
/*
 Time: O(n)
 Space: O(1)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    
    if(head == nullptr || head -> next == nullptr)
        return head;
    
    ListNode *dummyHead = new ListNode(0);
    dummyHead -> next = head;
    ListNode *current = dummyHead, *temp;
    while(current != nullptr && current -> next != nullptr && current -> next -> next != nullptr) {
        temp = current -> next;
        current -> next = temp -> next;
        temp -> next = current -> next -> next;
        current -> next -> next = temp;
        current = temp;
    }
    head = dummyHead -> next;
    return head;
}

void print(ListNode* head) {
    while(head != nullptr) {
        cout << head -> val << " -> ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    
    ListNode* head;
    head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    print(head);
    head = swapPairs(head);
    print(head);
    return 0;
}
