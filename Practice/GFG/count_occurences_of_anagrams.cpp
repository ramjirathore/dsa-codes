#include <bits/stdc++.h>
using namespace std;

// Sliding window technique - O(N) time and O(26) space
// How sliding window? - Anagrams - basically permutations 
// Thus the pattern size remains always and we search for these patterns in the given string ie a window

// We count all characters present in pattern
// then traversing given string we reduce each character in map
// and if it reaches zero then we reduce a main COUNT variable (which basically helps in avoiding whole map checking for all zeros)
// if window size hit we check COUNT == 0 , yes then inc ans
// else inc the leaving character count and increment COUNT too by one
// move the window now
// move to next character then
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char, int> mp;
	    
	    int k = pat.length(), size = txt.length();
	    
	    for(int i=0; i<k; i++) {
	        mp[pat[i]]++;
	    }
	    
	    
	    int i=0,j=0, ans =0;
	    int count = mp.size();
	    
	    while(j<size) {
	        mp[txt[j]]--;
	        if(mp[txt[j]] == 0) count --;
	        
	        if(j-i+1 == k) {
	            if(count == 0) ans++; 
	            
	            mp[txt[i]]++;
	            
	            if(mp[txt[i]] == 1) count++;
	            
	            i++;
	        }
	        
	        j++;
	    }
	    
	    return ans;
	}

};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  