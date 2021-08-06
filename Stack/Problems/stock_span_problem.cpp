// PROBLEM - 

// The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
// The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
// For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.


// BRUTE FORCE - O(N*N) time and O(N) space
// Simply check for consecutive smaller elements for each elements
// Use stack to implement this 
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res;
       stack<int> s;
       
       for(int i=0; i<n; i++) {
           stack<int> temp = s;
           int count = 1;
           while(!temp.empty() and temp.top() <= price[i]) {
               count++;
               temp.pop();
           }
           
           
           res.push_back(count);
           s.push(price[i]);
          
       }
       
       return res;
    }
};




// (my Solution)
// OPTIMAL - O(N) time and O(N) space
// Main thing is to know how many of the elements are <= (that too consecutively)
// For this we store this count for each element and use it for the upcoming elements

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res;
       stack<pair<int,int>> s;
       
       for(int i=0; i<n; i++) {
          int cnt = 1;
          
          while(!s.empty() and s.top().first <= price[i]) {
              cnt += s.top().second + 1;
              s.pop();
          }
          
          res.push_back(cnt);
          
          s.push({price[i], cnt-1});
       }
       
       return res;
    }
};


// Little better 
// Just removed that count thing
// Now it transforms to finding nearest greatest on left problem
// Use index to find it

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> res;
       stack<int> s;
       
       for(int i=0; i<n; i++) {
          
          while(!s.empty() and price[s.top()] <= price[i]) {
              s.pop();
          }
          
          if(s.empty()) {
              res.push_back(i+1);
          } else {
              res.push_back(i - s.top());
          }
         
          s.push(i);
       }
       
       return res;
    }
};
