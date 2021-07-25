// PROBLEM -

// A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
// Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]
// Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.
// Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

// LINK - https://leetcode.com/contest/biweekly-contest-23/problems/reducing-dishes/



// SOLUTION - O(N2) time and space
// Start by simple recursion
// Choose an item or either don't choose the item (then you have to restart the count)
// return the max of both
// Since there will be overlapping subproblems
// So apply DP using memoization

class Solution {
    int t[501][501];
    int solve(vector<int> &sat, int i, int count) {
        if(i == sat.size()) {
            return 0;
        }
        
        if(t[i][count] != -1) {
            return t[i][count];
        }
    
        int include = count * sat[i] + solve(sat, i+1, count+1);
        int exclude = solve(sat, i+1, 1);
        
        return t[i][count] = max(include, exclude);
    }
public:
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        memset(t, -1, sizeof(t));
        
        int res = solve(sat, 0, 1);
        
        if(res > 0) {
            return res;
        }
        
        return 0;
    }
};