// Problem :- Allocate minimum number of pages 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Method for cheking mx is valid or not wher mx is ouput;
    bool isValid(int a[], int n, int k, int mx) {
        // Initialize
        int student = 1;
        int sum = 0;
        
        // Iterate array
        for(int i = 0; i < n; i++) {
            sum += a[i];
            
            // If sum is greater then max value it mean current student get book based on mx
            // Now, move to another student and allocate current book 
            if(sum > mx) {
                student++;
                sum = a[i];
            }
            
            // If sutdent is greater then given student then return 
            if(student > k) return false;
        }
        
        // After complete loop we have successfuly distibute book along with student
        return true;
    }
    
    public:
    int findPages(int a[], int n, int k) {   
        // If number of student is greater form book then return -1
        if(n < k) return -1;
        
        int maximum = a[0];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            maximum = max(maximum, a[i]);
            sum += a[i];
        }
        
        // Using binary search
        int start = maximum;
        int end = sum, mid, result = -1;
        
        while(start <= end) {
            // To pretect integer overflow
            mid = start + (end - start) / 2;
            
            // Book allocate succesfuly then move left side for better minimum ans
            if(isValid(a, n, k, mid) == true) {
                result = mid;
                end = mid - 1;
                
            // Not done book allocation so move right side for bigger value
            }else {
                start = mid + 1;
            }
        }
        
        return result;
    }
};


// Driver Code Starts.
int main() {
    // Number of test cases take form input
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int k;
        cin>>k;
        Solution ob;
        // Function calling
        cout << ob.findPages(A, n, k) << endl;
    }
    return 0;
}

// Driver Code Ends

/*1
    4
    10 20 30 40
    2
    
    60
*/