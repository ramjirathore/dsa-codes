// PROBLEM - 
// Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.


// LINK - https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1


// BRUTE FORCE - O(n^3) time and O(1) space
// Generate all substrings O(n2) and then check each one whether it has exactly k unique characters or not O(n).
// Overall hence it will take O(n^3).

// BETTER - O(n^2) time and O(n) space
// We can improve brute force by checking for unique characters by creating hashmap and using it.

// OPTIMAL - O(n) time and O(n) space
// We need to observe few things that we are looking for max size substring this means window is variable.
// Thus we need to check for the given condition and change our window size accordingly. Ultimately, we  need to update max window
// whenever we hit the condition.
// Hence, in solution we need handle the three cases.
// 1. unique characters count < k
// 2. unique characters count == k
// 3. unique characters count > k

int longestKSubstr(string s, int k) {
    unordered_map<int, int> mp;
    
    int i = 0;
    int j = 0;
    
    int len = s.length();
    int mx = 0;
    
    while(j < len) {
        mp[s[j]]++;
    
        // if we reach k unique characters then update max len    
        if(mp.size() == k) {
            mx = max(mx, j-i+1);
        } else if(mp.size() > k) { // if more than k then we need to reduce
            
            // start removing elements from start of the window until we reach count <= k
            while(mp.size() > k) {
                mp[s[i]]--;
                
                if(mp[s[i]] == 0) { // if element count becomes zero then remove it
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        j++;
    }
    

    return mx ? mx : -1;
    
}