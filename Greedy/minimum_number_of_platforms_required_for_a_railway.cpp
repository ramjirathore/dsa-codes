// PROBLEM - 

// LINK - 

// O(nlogn) time and O(1) space
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	// sort both arrival and departure time
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int res = 1;
        int platform = 1;
        
        int i=1, j=0;

        // We check if the next train which is arriving 
        // is arriving after current departure time
        // if not this means we need another platform for this new train
        // else if yes we have an platform available since the departed train must have departed
        while(i < n and j < n) {
            if(arr[i] <= dep[j]) {
                platform++;
                i++;
            } else {
                platform--;
                j++;
            }
            
            // update the result
            // whenever the platform becomes more
            if(platform > res) {
                res = platform;
            }
        }
        
        return res;
    }
};