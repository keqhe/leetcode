#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// To execute C++, please define "int main()"
int main() {
  int a[10] = {1,2,3,4};
  
  for (int i = 0; i < 4; i ++)
      cout << a[i] << " ";
  cout << endl;
  vector<int> nums;//dynamic array
  for (int i = 0; i < 5; i ++)
      nums.push_back(i); //array append
  for (int i = 0; i < nums.size(); i ++)// array size
      cout << nums[i] << " ";
  cout << endl;
  
  for (int i = 0; i < 2; i ++)
    nums.pop_back();
  
  for (int i = 0; i < nums.size(); i ++)// array size
      cout << nums[i] << " ";
  cout << endl;
      
  
  vector<int> fixed(5, 0);//declear an fixed size array with defaults 0
  for (auto & x : fixed)
      cout << x << " ";
  cout << endl;
  
  //2D array
  vector<vector<int>> dp;//dynamic 2D array
  cout << "is dp empty? " << dp.empty() << endl;
  vector<vector<int>> dp2(5, vector<int>(4, -1));//5 row, 4 col, defaults -1
  cout << "is dp2 empty? " << dp2.empty() << endl;
  cout << "is dp2[0] empty? " << dp2[0].empty() << endl;
  //
  for (int i = 0; i < dp2.size(); i ++) {
    for (int j = 0; j < dp2[0].size(); j ++) {//carefull, Ln 38 is not always valid
      cout << dp2[i][j] << " ";
    }
    cout << endl;
  }
  
  cout << endl << endl;
  //remove the last row
  dp2.pop_back();
  for (int i = 0; i < dp2.size(); i ++) {
    for (int j = 0; j < dp2[0].size(); j ++) {//carefull, Ln 38 is not always valid
      cout << dp2[i][j] << " ";
    }
    cout << endl;
  }
  
  //
  vector<int> tmp = {1,2,3,4};
  dp2.push_back(tmp);
  
  cout << endl << endl;
  
  for (int i = 0; i < dp2.size(); i ++) {
    for (int j = 0; j < dp2[0].size(); j ++) {//carefull, Ln 38 is not always valid
      cout << dp2[i][j] << " ";
    }
    cout << endl;
  }
  
  //what else we need to know
  //1. you need to know how to sort an array
  vector<int> number = {1,0,3,9,6};
  sort(number.begin(), number.end());//o(nlogn), except for couting/radix sort
  
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  
  sort(number.begin(), number.end(), std::greater<int>());
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  //2. you need to know how to delete an element
  number.erase(number.begin());
  
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  
  number.erase(number.begin()+1, number.begin()+3);//O(n)
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  //3. how to insert an element
  number.insert(number.begin()+1, 3);//number.begin is type of iterator, O(n)
  
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  
  //4. how to reverse an array
  reverse(number.begin(), number.end());//time compleity O(n)
  for (auto x : number)
      cout << x << " ";
  cout << endl;
  
  
  return 0;
}

