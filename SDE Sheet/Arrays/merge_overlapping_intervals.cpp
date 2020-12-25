// PROBLEM -

// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the non-overlapping intervals 
// that cover all the intervals in the input.


// Link - https://leetcode.com/problems/merge-intervals/
// Solution - https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6



// BRUTE FORCE - O(n*n) time and O(n) space
// .......







// OPTIMAL - O(nlogn) time and O(n) space

// Firstly sort like previously .. O(nlogn) time
// Create the datastructure to return .. O(n) space
// Create a temp vector/pair store the first interval
// Traverse and Compare if the further intervals merges .. O(n) time
// if yes then update this temp pair and continue
// else store temp pair in dataStructure and copy the next one pair to this temp one.

class Solution {
public:
    // O(nlogn) time and O(n) space
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) {
            return intervals;
        }
        
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
                   
        vector<int> tempInterval = intervals[0];
        
        for(auto intv: intervals) {
            if(intv[0] <= tempInterval[1]) {
                tempInterval[1] =  max(intv[1], tempInterval[1]);
            } else {
                merged.push_back(tempInterval);
                tempInterval = intv;
            }
        }
        
        merged.push_back(tempInterval);
        
        return merged;
    }
};