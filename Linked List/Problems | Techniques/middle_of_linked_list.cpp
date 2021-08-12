// PROBLEM - 


// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.


// LINK - https://leetcode.com/problems/middle-of-the-linked-list/

// Brute force(two pass) - O(n) time and O(1) space
// Count no. of nodes, let it be n
// now traverse till (n/2)+1 and return the node at there


// OPTIMAL(single pass) - O(n) time and O(1) space
// Using slow and fast pointer
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL and fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
};