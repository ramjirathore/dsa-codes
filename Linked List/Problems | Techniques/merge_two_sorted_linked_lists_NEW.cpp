// PROBLEM - 

// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

// LINK - https://leetcode.com/problems/merge-two-sorted-lists/

// BRUTE - O(n1+n2) time and O(n1+n2) space
// Traverse using two pointers and add smaller value to the new linked list
// Move the pointer to next from which this value came
// Exhaust both the linked lists 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        
        while(l1 and l2) {
            if(l1->val <= l2->val) {
                temp->next = new ListNode(l1->val);
                l1 = l1 -> next;
            } else {
                temp->next = new ListNode(l2->val);
                l2 = l2 -> next;
            }
            temp = temp->next;
        }
        
        
        while(l1) {
            temp->next = new ListNode(l1->val);
            temp = temp -> next;
            l1 = l1 -> next;
        }
        
        
        while(l2) {
            temp->next = new ListNode(l2->val);
            temp = temp -> next;
            l2 = l2 -> next;
        }
        
        return head->next;
    }
};

// OPTIMAL - O(n1+n2) time and O(1) space
// Doing Inplace 
// Assume l1 will always be one having small value node
// find when its not
// just connect from there using previous
// and now l1 has become larger node, (but shouldn't it be smaller?)
// That's why swap to make it so.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // if one empty return the other one
        if(l1 == NULL) return l2;
        if(l2== NULL) return l1;
            
        // swap if l1 has more value
        // since we want our l1 to always have lesser value at node
        if(l1 -> val > l2 -> val) swap(l1, l2);
        
        ListNode* res = l1;
        
        while(l1 != NULL and l2 != NULL) {
            // temp to store where the prev of l1
            ListNode* temp = NULL;
            
            // we move in l1 until we get a value greater than l2's value
            while(l1 != NULL and l1->val <= l2 -> val) {
                temp = l1;
                l1 = l1 -> next;
            }
            
            // point this prev to l2
            temp->next = l2;
            
            // swap since l1 must always be one with smaller value
            swap(l1, l2);
        }
        
        // return resultant linked list
        return res;
    }
};