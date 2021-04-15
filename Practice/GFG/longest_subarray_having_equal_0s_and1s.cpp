// PROBLEM - 
// Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.


// Link - https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1/?track=md-arrays&batchId=144
// Solution - https://www.youtube.com/watch?v=9ZyLjjk536U




// CODE - 

// So the approach here is to observe
// We are only given 0s and 1s
// So if we assume 0s add one -1 then we can say that wherever the sum is 0 then it has equal 1s and 0s
// moreover, if we start from index 0 and keep adding 1 or -1
// then at some point we will get same this means the number of zeroes and 1s became same in between

class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        unordered_map<int, int> mp;
        int longest_subarray = 0;
        int sum = 0;
        
        for(int i=0; i<N; i++) {
            
            sum += arr[i] == 1 ? 1 : -1;
            
            if(sum == 0) {
                if(longest_subarray < i+1) {
                    longest_subarray = i+1;
                }
            } else if(mp.find(sum)!=mp.end()) {
                if(longest_subarray < i - mp[sum]) {
                    longest_subarray = i - mp[sum];
                }
            } else {
                mp[sum] = i;
            }
        }
        
        
        return longest_subarray;
       
    }
};