#include<iostream>
using namespace std;

// Generate Balanced brackets using N pairs of round brackets

void generate_brackets(char *out, int n, int indx, int open, int close) {
    // base case
    if(indx == 2*n) {
        out[indx] = '\0';
        cout<<out<<endl;
        return;
    }
    
    // rec case
    // inserting a opening bracket
    if(open < n) {
    	out[indx] = '(';
    	generate_brackets(out, n, indx+1, open+1, close);
    }

    // inserting a closing bracket
    if(close<open) {
    	out[indx] = ')';
    	generate_brackets(out, n, indx+1, open, close+1);
    }
    return;
}



int main() {
	// generate brackets
	int n;
	cin>>n;

	char output[100];
	int indx = 0;
	generate_brackets(output,n, 0, 0, 0);
	return 0;
}
