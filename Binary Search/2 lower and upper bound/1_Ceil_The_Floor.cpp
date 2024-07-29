#include<iostream>
#include<vector>
using namespace std;


/*
int solve(vector<int> &a, int n, int x, bool flag) {
	int start = 0;
	int end = n-1;
	int mid, index = -1;

	while(start <= end) {
		mid = end + (start - end) / 2;

		// floor 1
		if(flag) {
			if(a[mid] <= x) {
				index = a[mid];
				start = mid + 1;
			}else {
				end = mid - 1;
			}
		}else {
			if(a[mid] >= x) {
				index = a[mid];
				end = mid - 1;
			}else {
				
				start = mid + 1;
			}
		}
	}

	return index;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int floor = solve(a, n, x, 1);
	int ceil = solve(a, n, x, 0);

	return {floor, ceil};
}

*/



pair<int, int> solve(vector<int> &a, int n, int x) {
	int start = 0;
	int end = n-1;
	int mid;

	while(start < end) {
		mid = end + (start - end) / 2;
		if(a[mid] <= x) {
			start = mid + 1;
		}else {
			end = mid - 1;
		}
	}

	int floor = (end == -1 || end == n) ? -1 : a[end]; 
	int ceil = (start == -1 || start == n) ? -1 : a[start]; 
	return {floor, ceil};
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	return solve(a, n, x);
}



int main() {
    vector<int> array = {3, 4, 4, 7, 8, 10};   // Sorted array for binary search
    int size = array.size();   // Calculate the size of the array
    int target = 8;                            // Element to be searched

    pair<int,int> ans = getFloorAndCeil(array, size, target);

    cout<<"floor is "<<ans.first<<endl;
    cout<<"ceil is "<<ans.second<<endl;

    return 0;
}