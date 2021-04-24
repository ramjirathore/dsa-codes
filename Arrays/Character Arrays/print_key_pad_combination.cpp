#include <iostream>
using namespace std;


// This is the recursion on the way up approach
string codes[] = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string asf){
    
    if(ques.length() == 0) {
        cout<<asf<<endl;
        return;
    }
    
    char init = ques[0] - '0';
    string sub = ques.substr(1);
    
    for(auto ch: codes[init]) {
        printKPC(sub,asf+ch);
    }
    
}

int main(){
    string str;
    cin >> str;
    printKPC(str, "");
}