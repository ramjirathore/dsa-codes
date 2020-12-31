// PROBLEM - 

// Implement pow(x, n), which calculates x raised to the power n (i.e. x^n).

// Link - https://leetcode.com/problems/powx-n/
// Solution - https://www.youtube.com/watch?v=l0YC3876qxg&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=14



// BRUTE FORCE - O(n) time and O(1) space
// Iterate n times and multiply ans with x everytime 
class Solution {
public:
    double myPow(double x, int n) {
       
        double ans = 1.0;
        long long int p = abs(n);
        
       for(long long int i=1; i<=p; i++ ) {
           ans = ans * x;
       }
        
        return n > 0 ? ans : 1/ans ;
    }
};




// OPTIMAL - O(logn) time and O(1) space
// half the power and square the no. 
// if n is odd at any time multiply x once in ans
// return ans if n>0 else 1/ans

// #imp - n can be negative too
// so when n becoms -2^31 then it goes out of int range when 
// converted to its absolute val 
// handle this by taking a long long int temp variable

class Solution {
public:
    double myPow(double x, int n) {
       
        double ans = 1.0;
        long long int p = abs(n);
        
        while(p > 0) {
            if(p&1) {
                ans = ans * x;
            }
            
            x = x*x;
            p = p/2;
        }
        
        return n > 0 ? ans : 1/ans ;
    }
};