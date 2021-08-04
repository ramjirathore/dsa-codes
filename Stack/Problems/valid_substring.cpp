// PROBLEM - 
// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', 
// find out the length of the longest valid(well-formed) parentheses substring.

// LINK - https://practice.geeksforgeeks.org/problems/valid-substring0624/1

// BRUTE FORCE - 
// Generate every possible substring and check if its valid
// Then update max length
// O(n3) time and O(n) space

class Solution {
    bool checkValid(string str, int i, int j) {
        stack<char> s;
        while(i<=j) {
            if(str[i] == '(') {
                s.push('(');
            } else {
                if(s.empty()) return false;
                s.pop();
            }
            i++;
        }
        
        return s.empty();
    }
  public:
    int findMaxLen(string s) {
        int len = s.length();
    
        int mx = 0;
        
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                if(checkValid(s, i, j)) {
                    mx = max(mx, j-i+1);
                }
            }
        }
        
        return mx;
    }
};


// BETTER SOLUTION - O(N) time and O(N) space
// Maintain previous ( bracket index if present else closing one
// to find out the length of valid everytime when it forms
// Hence update

class Solution {
  public:
    int findMaxLen(string str) {
        stack<int> s;
        int res = 0;
        s.push(-1); // for 0 index to find length
        
        for(int i=0; i<str.length(); i++) {
            if(str[i] == '(') {
                s.push(i);
            } else {
                // if not empty then pop the top
                if(!s.empty()) {
                    s.pop();
                }
                
                // update the max length now
                if(!s.empty()) {
                    res = max(res, i - s.top());
                } else {
                    s.push(i);
                }
            }
        }
        
        return res;
        
        
    }
};


// OPTIMAL SOLUTION - O(N) time and O(1) space
// The idea is mainly we traverse from left to right
// We allow ( to come and whenever ( ) becomes equal we know it is valid => we update max length
// Whenever ) becomes more than ( we reset left and right to 0
// Similarly, we do it for right to left
// just the left and right gets swapped for conditions


class Solution {
  public:
    int findMaxLen(string s) {
        int left = 0;
        int right = 0;
        
        int res = 0;
        
        // Traverse from left to right
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if(left == right) {
                res = max(res, 2*right);
            } else if(right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        // Traverse from right to left
        for(int j=s.length()-1; j>=0; j--) {
            if(s[j] == '(') {
                left++;
            } else {
                right++;
            }
            
            if(left == right) {
                res = max(res, 2*right);
            } else if(left > right) {
                left = right = 0;
            }
        }
        
        return res;
    }
};
