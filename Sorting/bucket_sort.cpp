#include<iostream>
#include<vector>
using namespace std;

// Hint: bucket sort is extended version of counting sort

void bucketSort(vector<pair<int, string>> v, int n) {
	
	// assuming marks are range from 0 - 100
	vector<pair<int, string>> freq[101]; 

	// O(N) time
	for(int i=0; i<n; i++) {
		freq[v[i].first].push_back(v[i]);
	}

	// Iterate over the vector and print the students data from top to bottom
	for(int i=100; i>=0; i--) {
		for(auto it: freq[i]) {
			cout<<it.first<<" "<<it.second<<endl;
		}
	}
}

int main()
{
	vector<pair<int, string>> students;
	
	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		int marks;
		string name;
		cin>>marks>>name;

		students.push_back(make_pair(marks, name));
	}

	bucketSort(students, n);

	return 0;
}