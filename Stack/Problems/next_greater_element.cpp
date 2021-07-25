// PROBLEM - 

// Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
// Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
// If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

// LINK - https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// SOLUTION - O(N) time and O(N) space

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> res;
        
        stack<long long> s;
        s.push(-1);
        // Start from last element
        
        for(int j = n-1; j>=0; j--) {
            long long curr = arr[j];
            // pop all elements from stack which are less than or equal to curr
            // This ensures we will be left with an element which is greater than curr element
            while(!s.empty() and curr >= s.top()) { 
                s.pop();
            }
            
            // if stack is empty this means there is no element which is greater
            // hence the answer is -1
            if(s.empty()) {
                res.push_back(-1);
            } else { // else the answer is the top of stack
                res.push_back(s.top());
            }
            
            // push the curr element now
            s.push(curr);
        }
        
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};