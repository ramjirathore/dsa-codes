#include<iostream>
using namespace std; 

// PROBLEM - Given a string s, task is to find all permutations of string s


// Solution - for ex "abc"
// Select a'bc' (permute bc ie then do the same in bc) => abc,acb
// Select b'ac' (ie swap a with b)(then permute ac ie do the same in ac) => bac,bca
// Select c'ab' (ie swap a with c)(then permute ab ie do the same in ab) => cab,cba

// Main Problem which arises by this method -
// Not all Permutations we get : since array is passed by reference
// So to overcome this we have undo the changes(ie undo swap) => backtracking 


void permute(char *in, int i) { // i to iterate the string
	// base case
	if(in[i] == '\0') {
		cout << in << endl;
		return;
	}

	// recursive case
	for(int j=i; in[j]!='\0'; j++) {
		swap(in[i], in[j]); 
		permute(in, i+1);

		//Backtracking - To restore the original string
		swap(in[i], in[j]); 
	}

}



int main() {
	char input[20];
	cin >> input;

	permute(input, 0);

	return 0;
}