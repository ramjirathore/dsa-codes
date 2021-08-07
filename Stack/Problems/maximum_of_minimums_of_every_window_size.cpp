// PROBLEM - 
// Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
// Note: Window size varies from 1 to the size of the Array.

// LINK - https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1#

// BRUTE APPROACH - O(n3) time and O(n) space
// Just simply make all possible i j for every window size k (1...N)
// Then find max of minimum for each window size


// OPTIMAL - O(n) time and O(n) space
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        stack<int> s;
        int pseudo = - 1;
        
        vector<int> left;
        
        // find next smallest on left for each element
        for(int i=0; i<n; i++) {
            while(!s.empty() and arr[s.top()] >= arr[i]) {
                s.pop();
            }
            
            if(s.empty()) {
                left.push_back(pseudo);
            } else {
                left.push_back(s.top());
            }
            s.push(i);
        }
        
        // empty the stack
        while(!s.empty()) {
            s.pop();
        }
        
        // new pseudo for this
        pseudo = n;
        vector<int> right(n);
        
        // find next smallest on right for each element
        for(int j=n-1; j>=0; j--) {
            while(!s.empty() and arr[s.top()] >= arr[j]) {
                s.pop();
            }
            
            if(s.empty()) {
                right[j] = pseudo;
            } else {
                right[j] = s.top();
            }
            
            s.push(j);
        }
        
        // Now we know that arr[i] is minimum of i window size (which is right[i] - left[i] - 1)
        // So we find maximum of minimums for each given window size
        vector<int> res(n+1); // since n size window will also be there
        
        for(int i=0; i<n; i++) {
            int window_size = right[i] - left[i] - 1;
            
            res[window_size] = max(res[window_size], arr[i]);
            
        }
        
        
        // We can see that not all the values will be filled here
        // Some will be still left as 0 
        // Here for test case1 4, 5, 6 will still be 0
        
        // Important Observation -
        // Assume if a window is size of 6 then the answer for this would be the max of min of all window of 6
        // If we reduce the size to 5 then answer for this might be same (if the number we remove was not min)
        // Or it could be greater than this since we removed the min
        // This is the crux => if there is 0 this means the answer is the next i+1
        // Why ? because if it was something other than 0 then it would've been greater than res[i+1]
        // But here it is not hence it is same as res[i+1]
        
        // hence find the remaining window size answers
        for(int i =n-1; i>=0; i--) {
            res[i] = max(res[i], res[i+1]);
        }
        
        
        // since the res is one more index 
        // We need to store it in another vector
        
        vector<int> final = {res.begin()+1, res.end()};
        
        return final;
    }
};