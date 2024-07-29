#include <bits/stdc++.h> 
using namespace std;

int solve(vector<int>& arr, int n, int x, bool flag) {
    int start = 0;
    int end = n-1;
    int mid, ans = -1;

    while(start <= end ) {
        mid = end + (start-end) /2;

        if(arr[mid] == x) {
            ans = mid;
            if(flag) {
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }else if(arr[mid] > x) {
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }

    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = solve(arr, n, k, 1);
    if(first == -1) {
        return {-1, -1};
    }
    return {first, solve(arr, n, k, 0)};
}


int main() {
    vector<int> nums = {0, 0, 1, 1, 2, 2, 2, 2};
    int n = nums.size();
    int k = 2;

    pair<int,int> index = firstAndLastPosition(nums, n, k);

    cout<<index.first<<" "<<index.second<<endl;;

}