// PROBLEM - (An interesting solution and interview asked problem)
// Given a set of N jobs where each job i has a deadline and profit associated to it. 
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
// We earn the profit if and only if the job is completed by its deadline. 
// The task is to find the maximum profit and the number of jobs done.

// Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

// LINK - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
// Solution - https://www.youtube.com/watch?v=LjPx4wQaRIs


// Greedy Approach - O(nlogn) time and O(n) space
// Basically since we are asked to maximize profit thus we select the jobs with maximum profit first (greedy)
// This is achieved by sorting the job array 
// But there is a catch we still have to think when to do the job means which time unit
// If we think carefully then we'll see that a job with small deadline must be done first and the job with longer deadline can be done on the last day
// This benefits in maximizing the profit
// Crux - if we'd have done the longer deadline job earlier then the job with smaller deadline maybe couldn't be done (see constraints)
// thus we do longer one on last day only in order to secure time for the smaller ones.
class Solution 
{
    public:
    static bool comparator(Job a, Job b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comparator);
        int maxDeadline = arr[0].dead;
        
        for(int i=1; i<n; i++) {
            maxDeadline = max(arr[i].dead, maxDeadline);
        }
        
        vector<int> slot(maxDeadline+1, -1);
        
        int countJobs = 0, jobProfit = 0;
        for(int i=0; i<n; i++) {
            for(int j = arr[i].dead; j>0; j--) {
                if(slot[j] == -1) {
                    slot[j] = arr[i].id;
                    jobProfit += arr[i].profit;
                    countJobs++;
                    break;
                }
            }
        }
        
        return {countJobs, jobProfit};
    } 
};