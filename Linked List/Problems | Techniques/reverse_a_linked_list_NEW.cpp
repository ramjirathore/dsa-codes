// PROBLEM -

// 206. Reverse Linked List
// LINK - https://leetcode.com/problems/reverse-linked-list/

// Brute force - O(n) time and O(n) space
// Take a stack push all nodes
// Pop one by one and add it to new linked list or you can also replace in the new one

// O(n) time and O(1) space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        
        while(head != NULL) {
            // Preserve the linked list present after this node
            ListNode* temp = head->next;
            // point this node's to prev
            head->next = prev;
            // update the prev to this node
            prev = head;
            // update this node to next node
            head = temp;
        }
        
        return prev;
    }
};
