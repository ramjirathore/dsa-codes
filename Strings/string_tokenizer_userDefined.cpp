#include<iostream>
#include<cstring>
using namespace std;

char* mystrtok(char *str, char delim) {
	// Here we are considering string and on delimiter character
	static char* input = NULL;
	if (str != NULL) {
		// we are making first call
		input = str;
	}

	// base case ..so that while loop goes on
	if (input == NULL) {
		return NULL;
	}

	char *output = new char[strlen(input) + 1];
	int i;
	for (i = 0; input[i] != '\0'; i++) {
		if (input[i] != delim) {
			output[i] = input[i];
		} else {
			output[i] = '\0';
			input = input + i + 1;
			return output;
		}
	}

	//corner case
	output[i] = '\0';
	input = NULL;
	return output;

}

int main() {
	char str[] = "This is something new here.";

	char *ptr = mystrtok(str, ' ');
	cout << ptr << endl;

	while (ptr != NULL) {
		ptr = mystrtok(NULL, ' ');
		cout << ptr << endl;

	}
}