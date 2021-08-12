// PROBLEM - 

// 237. Delete Node in a Linked List

// Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list,
// instead you will be given access to the node to be deleted directly.
// It is guaranteed that the node to be deleted is not a tail node in the list.

// LINK - https://leetcode.com/problems/delete-node-in-a-linked-list/


// O(1) time and O(1) space
// The thing is we just copy the next node
// and we delete the next node simple
class Solution {
public:
    void deleteNode(ListNode* node) {
        // get next node
        ListNode* temp = node->next;
        // copy next node's value to this one
        node->val = temp->val;
        
        // point currrent node's to next node's next
        node->next = temp->next;
        
        // delete the temp node 
        delete(temp);
    }
};