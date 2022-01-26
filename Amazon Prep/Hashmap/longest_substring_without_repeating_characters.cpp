// PROBLEM - 
// Given a string s, find the length of the longest substring without repeating characters.

// LINK - https://leetcode.com/problems/longest-substring-without-repeating-characters/


// BRUTE FORCE - O(n^3) time and O(1) space
// This function returns true if all characters in str[i..j]
// are distinct, otherwise returns false
bool areDistinct(string str, int i, int j)
{
 
    // Note : Default values in visited are false
    vector<bool> visited(26);
 
    for (int k = i; k <= j; k++) {
        if (visited[str[k] - 'a'] == true)
            return false;
        visited[str[k] - 'a'] = true;
    }
    return true;
}
 
// Returns length of the longest substring
// with all distinct characters.
int longestUniqueSubsttr(string str)
{
    int n = str.size();
    int res = 0; // result
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}


// OPTIMAL - O(n) time and O(n) space

// Basically we need longest substring without repeating characters which means all the characters must be unique in the substring
// Thus, the map size should be equal to the window size (which is total substring length)
// So we calculate max_len when map size == total len
// and whenever they become unequal then we move the window from the start until they become equal again.

// 1st Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        
        unordered_map<char, int> mp;
        
        int total = 0;
        
        int max_len = 0;
        
        while(j < s.length()) {
            mp[s[j]]++;
            total += 1;
            
            if(mp.size() != total) {
                while(mp.size() != total) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                    total -= 1;
                }  
            } else {
                max_len = max(max_len, j-i+1);
            }
                
            j++;
        }
        
        return max_len;
    }
};


//2nd Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        
        unordered_map<char, int> mp;
    
        int max_len = 0;
        
        while(j < s.length()) {
            mp[s[j]]++;
            
            if(mp.size() < j - i + 1) { // The window has duplicate elements
                while(mp.size() < j - i + 1) { // thus we remove elements from start until it becomes equal
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }  
            } else if(mp.size() == j - i + 1) {
                max_len = max(max_len, j-i+1);
            }
                
            j++;
        }
        
        return max_len;
    }
};


// 3rd Solution
// As soon as I find a duplicate element then start reducing window size.
int longestSubstringWithNoRepeatingCharacters(string str, int n)
{
    long long i, j, res = INT_MIN;
    i = j = 0;
    map<char, int> mp;
    while(j < n)
    {
        mp[str[j]]++;
        if(mp[str[j]] == 1)
            res = max(res, j-i+1);
            
        else if(mp[str[j]] > 1)
        {
            while(mp[str[j]] > 1)
            {
                mp[str[i]]--;
                ++i;
                if(mp[str[j]] == 1)
                    res = max(res, j-i+1);
            }
        }
        ++j;
    }
    return res;
}