


// BRUTE FORCE - O(n*m) time and O(1) space
// Place a pointer on first linked list and search this node in second linked list
// if found return it, else move this curr to next and again search in second linked list
// Repeat until the first linked list is not exhausted
// In the end return NULL (since we couldn't find the intersection)


// BETTER APPROACH - O(n+m) time and O(n) space
// Use a hashmap to store nodes of first linked list
// Now traverse second linked list and check if you find curr node in hashmap
// if yes return it, else in the end return NULL
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        
        ListNode* temp = headA;
        
        while(temp) {
            s.insert(temp);
            temp = temp -> next;
        }
        
        temp = headB;
        
        while(temp) {
            if(s.count(temp)) return temp;
            temp = temp -> next;
        }
        
        return NULL;
        
    }
}


// OPTIMAL 1 - O(m) time and O(1) space
// m is the length of longer linked list
// First calculate length of both lists l1, l2
// on the longer place a pointer and move it "l2-l1" steps forward
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL or headB == NULL) return NULL;
        
        int len1 = 0;
        int len2 = 0;
        
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        while(tempA or tempB) {
            if(tempA) {
                len1++;
                tempA = tempA -> next;
            }
            
            if(tempB) {
                len2++;
                tempB = tempB -> next;
            }
        }
        
        ListNode* skip;
        if(len1 >= len2) {
            skip = headA;
        } else {
            skip = headB;
        }
        
        // make the pointer skip the difference
        // in the longer linked list
        int count = 0;
        while(count++ < abs(len1-len2)) {
            skip = skip -> next;
        }
        
        ListNode* temp = len1 < len2 ? headA : headB;
        
        // now go and if at any point they are equal stop
        // And if they are non intersecting they both will stop at NULL
        // so all cases are handled
        while(temp != skip) {
            temp = temp -> next;
            skip = skip -> next;
        }
        
        return temp;
    }
};

// OPTIMAL 2 - O(m) time and O(1) space
// m is the length of longer linked list
// Traverse both pointers till end of lls
// when one becomes NULL restart it to other ll's head
// So when both will start they will be at same distance from intersection
// Why this works?
// Because the one who reaches first gets to travels the difference afterwards
// Thus making them at same distance from intersection when we restart

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        
        
        while(a != b) {
            a = a != NULL ? a -> next : headB;
            b = b != NULL ? b -> next : headA;
        }
        
        return a;
    }
};
