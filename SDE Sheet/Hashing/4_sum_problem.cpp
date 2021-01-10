// PROBLEM - 

// Given an array nums of n integers and an integer target, 
// are there elements a, b, c, and d in nums such that a + b + c + d = target? 
// Find all unique quadruplets in the array which gives the sum of target.

// Notice that the solution set must not contain duplicate quadruplets.

// Example - 
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]


// Link - https://leetcode.com/problems/4sum/
// Solution - https://www.youtube.com/watch?v=4ggF3tXIAp0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=20


// BRUTE FORCE - O(n3logn) time and O(1) space
// Sort the array -> O(nlogn)
// Then take four pointers i j k 
// i -> 0 to n   ..   j ->i+1 to n  k-> i to j        -> O(n3) time
// Do binary search for the remaining value in the right part  -> O(logn) time

// Thus total time -> O(n3logn) + O(nlogn)
// and we generally don't consider the returning answer space so -> O(1) space