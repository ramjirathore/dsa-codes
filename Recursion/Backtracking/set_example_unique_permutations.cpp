#include<iostream>
#include<set>
#include<string>
using namespace std; 

// PROBLEM - Given a string s, task is to find all UNIQUE permutations of string s


// Solution - Solution of permuations + use set


void permute(char *in, int i, set<string> &soln) { // i to iterate the string
	// base case
	if(in[i] == '\0') {
		string s(in);
		soln.insert(s);
		return;
	}

	// recursive case
	for(int j=i; in[j]!='\0'; j++) {
		swap(in[i], in[j]); 
		permute(in, i+1, soln);

		//Backtracking - To restore the original string
		swap(in[i], in[j]); 
	}

}



int main() {
	char input[20];
	cin >> input;

	set<string> s;

	permute(input, 0, s);

	// print
	for(auto str: s) {
		cout<<str<<endl;
	}

	return 0;
}