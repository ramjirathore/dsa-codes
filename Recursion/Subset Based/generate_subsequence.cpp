#include<iostream>
using namespace std;

// Problem - Generate all subsequence of given string

void generate_subsequence(char *input, char *output, int i, int j) {
    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    
    // rec case
    // include the current character 
    output[j] = input[i];
    generate_subsequence(input, output, i+1, j+1);
    
    // exclude the current character
    generate_subsequence(input, output, i+1, j);
}



int main() {
	char str[] = "abc"; 
	char output[100];
	
	generate_subsequence(str, output, 0, 0);
	return 0;
}
