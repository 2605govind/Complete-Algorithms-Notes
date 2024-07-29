#include <bits/stdc++.h> 
using namespace std;


// https://www.naukri.com/code360/problems/rearrange-alternatively_873851?leftPanelTabValue=PROBLEM
void rearrange(vector<int> &arr){
	vector<int> pos, neg;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] <= 0) {
			neg.push_back(arr[i]);
		}else {
			pos.push_back(arr[i]);
		}
	}

	// arrange neg or pos

	if(pos.size() > neg.size()) {
		for(int i = 0; i < neg.size(); i++) {
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}

		int index = neg.size() * 2;
		for(int i = neg.size(); i < pos.size(); i++) {
			arr[index] = pos[i];
			index++;
		}
	}else {
		for(int i = 0; i < pos.size(); i++) {
			arr[2*i] = pos[i];
			arr[2*i+1] = neg[i];
		}

		int index = pos.size() * 2;
		for(int i = pos.size(); i < neg.size(); i++) {
			arr[index] = pos[i];
			index++;
		}
	}

}

int main() {
    vector<int> arr = {1, -1, -1};

    rearrange(arr);

    
}