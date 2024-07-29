// Program for finding "Upper Bound" and "Lower Bound"

/*
    Example : 2 6 8 10 45
    lower bound of 8 is 8 at index 2
    upper bound of 8 is 10 at index 3

    upper bound of 9 is 10 at index 3
    lower bound of 9 is 8 at index 2
*/

#include <iostream>
#include <vector>
using namespace std;

class BinarySearchOperation {
public:
    // Method for finding lower bound
    int lowerBound(vector<int> &nums, int key) {
        // Using binary search
        int start = 0, end = nums.size(), mid;

        while(start < end) {
            mid = start + (end - start) / 2;

            // If key is greater then mid value then move right side
            if(key > nums[mid]) {
                start = mid + 1;

            // Else move left side    
            }else {
                end = mid;
            }
        }

        return end;
    }

    int upperBound(vector<int> &nums, int key) {
        // Using binary search
        int start = 0, end = nums.size() , mid;

        while(start < end) {
            mid = start + (end - start) / 2;

            // If key is greater then and equle to mid value then move right side
            if(key >= nums[mid]) {
                start = mid + 1;

            // Else move left side    
            }else {
                end = mid;
            }
        }

        return start;
    }
};

// Driver code
int main() {
    int n;
    cout<<"\nEnter the size of sorted array: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the sorted array\n";
    for(int i = 0; i < n; i++) {
        cin>>nums[i];
    }

    BinarySearchOperation bso;
    while(true) {
        cout<<"Choose your operation insertin number: ";
        cout<<"\nFind upper bound : 1";
        cout<<"\nFind lower bound : 2";
        cout<<"\nExit : 0\n";

        int op, key;
        cin>>op;

        switch(op) {
            case 1: 
                cout<<"Insert key for lower bound ";
                cin>>key;
                cout<<"Lower bound index is "<<bso.lowerBound(nums,key)<<"\n\n";
                break;

            case 2: 
                cout<<"Insert key for upper bound ";
                cin>>key;
                cout<<"Upper bound index is "<<bso.upperBound(nums,key)<<"\n\n";
                break;
            case 0:
                cout<<"\nProgram Terminate!";
                return 0;    
        }

    }

    return 0;
}

/*Enter the size of sorted array: 5
Enter the sorted array
2 6 8 10 45
Choose your operation insertin number: 
Find upper bound : 1
Find lower bound : 2
Exit : 0
2
Insert key for upper bound 10
Upper bound index is 4

Choose your operation insertin number: 
Find upper bound : 1
Find lower bound : 2
Exit : 0
2
Insert key for upper bound 45
Upper bound index is 5

Choose your operation insertin number:
Find upper bound : 1
Find lower bound : 2
Exit : 0
2
Insert key for upper bound 1
Upper bound index is 0

Choose your operation insertin number:
Find upper bound : 1
Find lower bound : 2
Exit : 0
1
Insert key for lower bound 1
Lower bound index is 0

Choose your operation insertin number:
Find upper bound : 1
Find lower bound : 2
Exit : 0
1
Insert key for lower bound 9
Lower bound index is 3

Choose your operation insertin number:
Find upper bound : 1
Find lower bound : 2
Exit : 0
0

Program Terminate!*/
