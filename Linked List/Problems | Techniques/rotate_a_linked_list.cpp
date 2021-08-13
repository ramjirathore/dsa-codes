// PROBLEM -

// Given the head of a linked list, rotate the list to the right by k places.
// LINK - https://leetcode.com/problems/rotate-list/


// BRUTE FORCE - O(k*n) time and O(1) space
// Traverse to the last of the linked list and make the last node, first
// Repeat this k times


// OPTIMAL - O(n) time and O(1) space
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if(k == 0 or head == NULL or head->next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        int len = 1;
        
        // compute length
        while(curr->next) {
            len++;
            curr = curr -> next;
        }
        
        // attach the last node to head
        curr->next = head;
        // handles if k is more than len
        k = k % len;
        // to go till the rotated head
        k = len - k; 
        
        // start from head and go reach the rotated node
        while(k--) {
            curr = curr -> next;
        }
        
        // make the next node head and break the connection
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
    }
};