// 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

class Solution {
public:
    int isPrefixOfWord(string text, string word) {
        
        int i = 0;
        int n = text.size();
        int count = 0;
                
        while(i < n) {
            string str = "";
            while(i < n and text[i] !=' ') {
                str += text[i];
                i++;
            }
            
            count++;
            
            int j = 0;
            for(int k=0; k<str.size() and j < word.size(); k++) {
                if(word[j] != str[k]) {
                    break;
                } 
                
                
                j++;
            }
            
            if(j == word.size())
                return count;           
            
            i++;
        }
        
        return -1;
        
    }
};

// 1456. Maximum Number of Vowels in a Substring of Given Length

class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        
        int n = s.length();
        
        unordered_map<int, int> mp;
        mp['a'] = 0;
        mp['e'] = 0;
        mp['i'] = 0;
        mp['o'] = 0;
        mp['u'] = 0;
        
        int res = 0;
        
        while(j < n) {
            char ch = s[j];
            if(mp.count(ch)) {
                mp[ch]++;
            }
            
            if(j - i + 1 < k) {
                j++;
            } else {
               int vowels = 0;
               for(auto [ch, count]: mp) {
                   vowels += count;
               } 
                
               res = max(res, vowels);
                
               // remove count by i
               char ch = s[i];
               if(mp.count(ch) and mp[ch] > 0) {
                   mp[ch]--;
               }
               
               i++;
               j++;
            }
        }
        
        return res;
        
    }
};


// 1457. Pseudo-Palindromic Paths in a Binary Tree

class Solution {
    int ans;
    unordered_map<int, int> mp;
    bool ifPseudo() {
        int odd = 0;
        int even = 0;
        
        for(auto [num, cnt]: mp) {
            if(cnt & 1) {
                odd++;
            } else {
                even++;
            }
        }
        
        if(odd > 1) {
            return false;
        }
        
        return true;
    }
    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }
       
        mp[root->val]++;
        
        if(root->left == NULL and root->right == NULL) {
            if(ifPseudo()) {
                ans++;
            }
        }
        
        solve(root->left);
        solve(root->right);
        
        mp[root->val]--;
    }
        
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        mp.clear();
        ans = 0;
        solve(root);
    
        return ans;
    }
};


// 1458. Max Dot Product of Two Subsequences

#define inf -1e9

class Solution {
    int t[501][501];
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j) {
        if(i == nums1.size() or j == nums2.size()) {
            return inf;
        }
        
        if(t[i][j] != -1) {
            return t[i][j];
        }
        
        int ans1 = solve(nums1, nums2, i+1, j);
        int ans2 = solve(nums1, nums2, i, j+1);
        int ans3 = nums1[i] * nums2[j] + solve(nums1, nums2, i+1, j+1);
        int ans4 = solve(nums1, nums2, i+1, j+1);
        int ans5 = nums1[i] * nums2[j];
        
        return t[i][j] = max({ans1, ans2, ans3, ans4, ans5});
        
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(t, -1, sizeof(t));
       return solve(nums1, nums2, 0, 0);
    }
};