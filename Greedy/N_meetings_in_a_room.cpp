// PROBLEM - 

// There is one meeting room in a firm. 
// There are N meetings in the form of (S[i], F[i]) where S[i] is start time of meeting i and F[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room 
// when only one meeting can be held in the meeting room at a particular time? 
// Also note start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// LINK - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
// SOLUTION - https://www.youtube.com/watch?v=II6ziNnub1Q

// Greedy Approach - O(nlogn) time and O(n) space
// The approach is simple since we need to incorporate as many meetings as possible
// so we select the meetings which has lesser end time 
 
bool static comparator(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {

        vector<pair<int, int>> meetings;
        
        // O(n) time and O(n) space
        for(int i=0; i<n; i++) {
            meetings.push_back(make_pair(start[i], end[i]));
        }
        
        // O(nlogn) time
        sort(meetings.begin(), meetings.end(), comparator);
        
        int maxMeetings = 0, endtime = 0;
        for(int i=0; i<n; i++) { // O(n) time 
            if(meetings[i].first > endtime) {
                maxMeetings++;
                // cout<<meetings[i].first<<" "<<meetings[i].second<<endl;
                endtime = meetings[i].second;
            }
        }
        
        return maxMeetings;
        
    }
};
