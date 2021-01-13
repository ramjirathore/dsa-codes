#include<bits/stdc++.h>
using namespace std;

// O(n) time and O(k) space
int main()
 {
	int T;
	cin>>T;
	
	while(T--) {
	    int n, k;
	    cin>>n;
	    
	    int arr[n+1];
	    
	    for(int i=0; i<n; i++) {
	        cin>>arr[i];
	    }
	    
	    cin>>k;
	    
	   queue<int> q;
	   
	   int i=0, j=0;
	   while(j<n) {
	       if(arr[j] < 0) {
	           q.push(arr[j]);
	       }
	       
	       if(j-i+1 == k) {
	           if(q.empty()) cout<<0<<" ";
	           else {
	               cout<<q.front()<<" ";
	               if(arr[i] == q.front()) {
	                   q.pop();
	               }
	           }
	           i++;
	       }
	       j++;
	   }
	   
	   cout<<endl;
	    
	}
	
	return 0;
}