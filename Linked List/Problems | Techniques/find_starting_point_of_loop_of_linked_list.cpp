// PROBLEM -

// 142. Linked List Cycle II

// LINK - https://leetcode.com/problems/linked-list-cycle-ii/


// BRUTE FORCE - O(n) time and O(n) space
// Use just one pointer and keep storing address of nodes in a hashmap
// If we encounter a node which has been previously visited then that is the cycle point
// Else if our pointer becomes NULL => linked list had no cycle


// OPTIMAL - O(n) time and O(1) space
class Solution {
    ListNode* cyclePoint(ListNode* head, ListNode* meet) {
        ListNode* start = head;
        // start from starting and other from meeting point
        // where both will meet will be the cycle point
        while(start != meet) {
            start = start->next;
            meet = meet->next;
        }
        
        // anyone can be returned
        return start;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next; 
            // if cycle found then 
            // find cycle point
            if(slow == fast) {
                return cyclePoint(head, slow);
            }
        }
        
        // no cycle found
        return NULL;
    }
};