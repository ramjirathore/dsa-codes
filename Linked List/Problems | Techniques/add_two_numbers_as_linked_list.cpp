
// PROBLEM - 

// 2. Add Two Numbers

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// LINK - https://leetcode.com/problems/add-two-numbers/

// O(max(n1, n2)) time and space  
// Maintain a carry and sum
// Possibilities - 
// 1. both next nodes are there
// 2. only one node is there
// 3. no nodes are there and no carry is there
// 4. no nodes are there but carry is there => one new node will be added
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        int carry = 0;
        
        while(l1 or l2 or carry) {
            int sum = 0;
            
            if(l1) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
              
            if(l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
                    
            sum += carry;
            carry = sum/10;
            
            temp->next = new ListNode(sum % 10);
            temp = temp -> next;
        }
        
        return head->next;
    }
};