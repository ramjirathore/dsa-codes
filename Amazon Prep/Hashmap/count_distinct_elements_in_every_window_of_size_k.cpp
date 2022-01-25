// PROBLEM - 
// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// LINK - https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

// BRUTE - O(n*k*k) time and O(1) space
// How? We can put i to 0 then start from i to i + k 
// Then count distinct elements in this window
// => O((n-k+1)*k*k) time, hence the mentioned time complexity

// Counts distinct elements in window of size k
int countWindowDistinct(int win[], int k)
{
    int dist_count = 0;

    // Traverse the window
    for (int i = 0; i < k; i++) {
        // Check if element arr[i] exists in arr[0..i-1]
        int j;
        for (j = 0; j < i; j++)
            if (win[i] == win[j])
                break;
        if (j == i)
            dist_count++;
    }
    return dist_count;
}

// Counts distinct elements in all windows of size k
void countDistinct(int arr[], int n, int k)
{
    // Traverse through every window
    for (int i = 0; i <= n - k; i++)
        cout << countWindowDistinct(arr + i, k) << endl;
}


// OPTIMAL - O(n) time and O(n) space
// Maintain a hashmap in which we store (value, count)
// In each window we store all values alongside the count
// Then we print the distinct elements ie. map size
// Now we shift window, hence dec count of prev element and inc count of new count into hashmap

 vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int> mp;
        
        int i = 0;
        vector<int> res;
    

        while(i<n) {
            
            // add elements till window size is reached
            if(i < k) {
                mp[A[i]]++;
            } else {
                // store the answer
                res.push_back(mp.size());
                
                // remove previous element
                auto &prev = mp[A[i-k]];
                if(prev > 0) {
                    prev--;
                    
                    if(prev == 0) {
                        mp.erase(A[i-k]);
                    }
                } 
                
                // add next element
                mp[A[i]]++;
            }
            
            i++;
        }
        
        // push last window answer to result
        res.push_back(mp.size());
        
        return res;
    }