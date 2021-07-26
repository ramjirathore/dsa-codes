
// LINK - https://leetcode.com/contest/weekly-contest-183/problems/minimum-subsequence-in-non-increasing-order/

// 1403. Minimum Subsequence in Non-Increasing Order
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int total = 0;
        for(auto it: nums) {
            total += it;
        }
        
        vector<int> res;
        int sum_so_far = 0;
        for(int i=0; i<nums.size(); i++) {
            sum_so_far += nums[i];
            res.push_back(nums[i]);
            if(sum_so_far > total - sum_so_far) {
                break;
            }
        }
        
        return res;
    }
};

// 1404. Number of Steps to Reduce a Number in Binary Representation to One

class Solution {
public:
    int numSteps(string s) {
        int len = s.length();
        int steps = 0;
        
        while(s.length() != 1) {
            int n = s.length();
            // cout<<s<<endl;
            steps++;
            if(s[n-1] == '1') {
                int j = n-1;
                while(j >=0 and s[j] != '0') {
                    s[j] = '0';
                    j--;
                }
                if(j < 0) {
                    s = "1" + s;
                } else {
                    s[j] = '1';
                }
            } else {
                s = s.substr(0, n-1);
            }
            
        }
        
        return steps;
    }
};


// 1405. Longest Happy String

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if(a + b + c == 0) {
            return "";
        }
    
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        
        string res = "";
         
        while(pq.size() > 1) {
            
            auto ch1 = pq.top();
            pq.pop();
            
            auto ch2 = pq.top();
            pq.pop();
            
            // add twice
            if(ch1.first >= 2) {
                res = res + ch1.second + ch1.second;
                ch1.first -= 2;
            } else {
                res += ch1.second;
                ch1.first -= 1;
            }
            
            
            // add twice
            if(ch2.first >= 2 and ch2.first >= ch1.first) {
                res = res + ch2.second + ch2.second;
                ch2.first -= 2;
            } else {
                res = res + ch2.second;
                ch2.first -= 1;
            }
            
            // if still available push it back
            if(ch1.first > 0) {
                pq.push(ch1);
            }
            
            if(ch2.first > 0) {
                pq.push(ch2);
            }
        }
        
        // if pq is still not empty
        // we can add the element max twice if freq >=2 else only once
        // provided its not the last character
        if(!pq.empty() and pq.top().second != res.back()) {
            auto [count, ch] = pq.top();
            pq.pop();
            
            res += ch;
            
            if(count >= 2)
                res += ch; 
        }
        
        return res;
        
    }
};


// 1406: Stone Game 3

// Needs a bit more understanding
// Basic principle for this - Do your best when its your turn and expect others to do the worse 
// Watch pepcoding video of optimised game design dp video
// Will be adding code soon...