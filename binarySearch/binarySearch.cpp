#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	vector<int> a = {1,2,3,4,5};
	//form 1
	int left = 0;
	int right = a.size() - 1;
	
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (a[mid] == 3) {
			cout << "found 3 in this vector!" << endl;	
			break;
		}
		else if (a[mid] < 3)
			right = mid - 1;
		else	
			left = mid + 1;
	}

	//form 2;
	//why we want form 2? because sometimes, it is more intuitive..
	//see leetcode 287
	left = 0;
	right = a.size() - 1;
	while (left < right) {
		int mid = left + (right - left)/2;
		if (a[mid] <= 3) {
			left = mid;
		}
		else
			right = mid - 1;
	}
	if (a[right] == 3)
                cout << "found 3 in this vector using method 2!" << endl;


	//form 2:
	left = 0;
        right = a.size() - 1;
        while (left < right) {
                int mid = left + (right - left)/2;
                if (a[mid] >= 3) {
                        right = mid;
                }
                else
                        left  = mid + 1;
        }
        if (a[left] == 3)
                cout << "found 3 in this vector using method 2!" << endl;	

	//
	a = {1,2,2,3,4,6};
	//how to find the left most 2 and right most 2?
	left = 0;
	right = a.size() - 1;
	int index1 = -1;//-1 mean does not exist
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (a[mid] == 2) {
			index1 = mid;
			right = mid - 1;
		}
		else if (a[mid] < 2) 
			left = mid + 1;
		else
			right = mid - 1;
	}

	cout << "left most 2 appears at index: " << index1 << endl;

	left = 0;
        right = a.size() - 1;
        int index2 = -1;//-1 mean does not exist
        while (left <= right) {
                int mid = left + (right - left)/2;
                if (a[mid] == 2) {
                        index2 = mid;
                        left = mid + 1;
                }
                else if (a[mid] < 2)
                        left = mid + 1;
                else
                        right = mid - 1;
        }

        cout << "right most 2 appears at index: " << index2 << endl;
	return 0;
}
