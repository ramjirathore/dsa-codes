// PROBLEM -
// 234. Palindrome Linked List

// LINK - https://leetcode.com/problems/palindrome-linked-list/

// BRUTE FORCE - O(n) time and O(n) space
// Store all nodes of linked list in an array
// and just normally check for palindrome


// OPTIMAL - O(n) time and O(1) space
// Using mid and then reversing the ll after it
// Then compare each elements one by one 
// of 1st part and 2nd part
class Solution {
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
                
        return slow;
    }
    ListNode* reverseLL(ListNode *head) {
        ListNode* prev = NULL;
        ListNode* temp = NULL;
        
        while(head) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {

        // get mid of ll
        ListNode* mid = getMid(head);
        // reverse the ll after mid
        mid = reverseLL(mid);
        
        // now just compare one by one
        // elements of both parts 
        while(mid) {
            if(head->val != mid->val) {
                return false;
            }
            head = head->next;
            mid = mid->next;
        } 
        
        return true;
    }
};