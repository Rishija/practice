/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

 Return a deep copy of the list.
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    typedef RandomListNode rn;

    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        rn *current = head, *head1 = nullptr;

        while(current != nullptr) {
            rn* node = new rn(current->label);
            if(head1 == nullptr)    head1 = node;

            // Next of new list points to random of original list
            node->next = current->random;

            // Random of original list points to new list
            current->random = node;

            current = current->next;
        }

        // Set random of new list by going to random to
        // original list (through current->random->next) 's random
        current = head;
        while(current != nullptr) {
            if(current->random->next)
                current->random->random = current->random->next->random;
            else
                current->random->random = nullptr;
            current = current->next;
        }

        // Change random of original list and next of new list
        current = head;
        while(current != nullptr) {
            rn* rawSecondListNode = current->random;
            current->random = current->random->next;
            if(current->next != nullptr)
                rawSecondListNode->next = current->next->random;
            else
                // current->random can't be used here because it is modified
                rawSecondListNode->next = NULL;
            current = current->next;
        }
        return head1;
    }
};
