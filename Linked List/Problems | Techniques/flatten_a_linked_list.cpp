// PROBLEM - 


// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.


// LINK - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

// BRUTE FORCE - O(nlogn) time and O(n) space
// Store all values in a set and then a create a new linked list and return it


// OPTIMAL - O(n) time and O(1) space
// We will use the approach of merge sort
// starting from the last linked list and second last linked list
// we merge them and return the merged linked list
// we repeat this with this new merged one and curr linked list

Node* mergeTwoLists(Node* a, Node* b) {
    Node* res = new Node(-1);
    Node* temp = res;
    
    // add the smaller one and move ahead
    while(a != NULL and b != NULL) {
        if(a -> data < b -> data) {
            temp -> bottom = a;
            temp = temp -> bottom;
            a = a -> bottom;
        } else {
            temp -> bottom = b;
            temp = temp -> bottom;
            b = b -> bottom;
        }
    }
    
    // if a is left then attach a
    if(a != NULL) {
        temp -> bottom = a;
    } else if(b != NULL) { // else if b is left then attach b
        temp -> bottom = b;
    }
    

    return res -> bottom;
}
Node *flatten(Node *root)
{
   // if reached the last linked list then return itself
   // or if the node is empty then also 
   if(root == NULL or root->next == NULL) {
       return root;
   }
   
   // recursively call for ahead of it linked list
   root->next = flatten(root->next);
   
   // merge this incoming linked list (ie root-> next one)
   // and current one (ie root one) linked list
   root = mergeTwoLists(root, root->next);
   
   return root;
}

