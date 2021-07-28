// 1413. Minimum Value to Get Positive Step by Step Sum

// O(n) time solution - 
// Understand that we want min StartValue
// Three cases - 
// 1. All positive numbers
// 2. Positive and negative numbers
// 3. All negative numbers

// for case 1: the minimum will be the minimum number all 
// for case 2: There we will be a point when sum will become min in between
// And after that we need at least one to fulfil condition
// So we need 1 + abs(minSum) or 1 - (minSum) since minSum will be negative
// for case3: the same thing ie case 2 works for case 3
 

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, minSum = 0;
        
        // for case 1 minSum will remain zero, so it will work
        for(auto n: nums) {
            sum += n;
            minSum = min(minSum, sum);
        }
        
        return 1 - minSum;
    }
};


// 1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
// This problem needs to be solved for optimal
// Although i've created a recursive solution which works for k <= 10^5





// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// DFS based solution - O(n*k) time and O(n) space

class Solution {
    vector<string> happy;
    void getHappy(string s, int i, int &n) {
        if(i == n) {
            happy.push_back(s);
            return;
        }
        
        for(char ch ='a'; ch <= 'c'; ch++) {
            if(i != 0 and ch == s[i-1]) continue;
            getHappy(s + ch, i + 1, n);
        }
        
    }
public:
    string getHappyString(int n, int k) {
        happy.clear();
        getHappy("", 0, n);
        
        
        if(k > happy.size()) {
            return "";
        }
        
        return happy[k-1];
    }
};


//1416. Restore The Array
// O(n*logk) time and O(n) space
// n is string length

#define ll long long int

class Solution {
    ll t[100001];
    
    const unsigned int mod = 1e9+7;
    int dfs(string &s, int i, int &k) {
        if(i == s.size()) {
            return 1;
        }
        
        // if zero found means its of type 0xyz
        // not allowed
        if(s[i] == '0') {
            return 0;
        }
        
        if(t[i] != -1) {
            return t[i];
        }
        
        ll res = 0;
        ll num = 0;
        
        // Break at each index and recur for remaining
        for(int j=i; j<s.size(); j++) {
            num = num * 10 + (s[j] - '0');
            
            if(num > k) { // cannot be greater than k
                break;
            }
            
            res += dfs(s, j+1, k) % mod;
        }
        
        return t[i] = res % mod;
    }
public: // You can relate to this problem by mcm concept
    int numberOfArrays(string s, int k) {
        memset(t, -1, sizeof(t));
        
        return dfs(s, 0, k);
    }
};