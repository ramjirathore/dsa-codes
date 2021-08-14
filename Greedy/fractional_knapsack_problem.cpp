// PROBLEM - 



// LINK - https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


// OPTIMAL APPROACH - O(nlogn) time and O(1) space
// We need to maximise value 
// Since this is fractional knapsack so we can take fractions also
// hence sort the array in descending order of value/weight 
// And now we can pickup weights if Required weight >= weight of current element
// So in this case the total value will be contributed, make sure you reduce now this curr element weight from required one
// Else if required < curr element weight => then we can't pickup whole
// we can pickup the required amount and thus add the corresponding value for this amount
// Since required weight becomes zero,hence stop


class Solution
{
    static bool comp(Item a, Item b) {
        return 1.0*a.value/a.weight > 1.0*b.value/b.weight;
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    	// sort in descending order by value/weight
        sort(arr, arr+n, comp);
        
        double total = 0;

        for(int i=0; i<n; i++) {
        	// if curr weight <= weight => we can take this whole element
            if(arr[i].weight <= W) {
                total += arr[i].value;
                W -= arr[i].weight; // reduce W 
            } else { // else we can only take W amount
                total += W * (1.0 * arr[i].value)/arr[i].weight;
                break;
            }
        }
        
        return total;
    }
        
};