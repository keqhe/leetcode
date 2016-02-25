#include <iostream>
#include <vector>
#include<unordered_map> //hash table
#include<map>
#include<set>

using namespace std;

class Solution {
public:
    bool containsDuplicate_v1(vector<int>& nums) {
      for (int i=0; i<nums.size()-1; i++)
        for (int j=i+1; j<nums.size(); j++){
           if (nums[i]==nums[j])
             return true;
        }
      return false;
    }
  
    bool containsDuplicate(vector<int>& nums) {
      unordered_map<int, int> m;//key is an element, value is its index
      for (int i = 0; i < nums.size(); i ++) {
        if (m.find(nums[i]) == m.end())//can not find an matched pair in hash table
          m[nums[i]] = 0;//does not matter if it is 0 or i
        else
          return true;
      }
      return false;
    }
};

int main() {
  class Solution sn;
  vector<int> a = {1,2,2,3,4};
  cout << sn.containsDuplicate(a) << endl;
  
  unordered_map<short, char> m;
  m[0] = 'a';
  m[1] = 'b';
  m[2] = 'c';
  
  cout << m[0] << endl;//0 is the key and m[0] returns the associated value
  cout << (m.find(0) != m.end()) << endl;//that mean 0 exists
  cout << (m.find(5) == m.end()) << endl;//
  
  //how to print all the <key, value> pairs in the hash table
  for (pair<short, char> x : m) {// x is a <key, value> pair
    cout << "(" << x.first << "," << x.second <<")";//x.first is key, x.second is val
  }
  cout << endl;
  
  //data structure called pair
  pair<int, int> p;
  
  map<short, char> mm;//in order, find function is O(logN), balanced binary tree (Red black Tree or AVL)
  mm[0] = 'a';
  mm[1] = 'b';
  mm[2] = 'c';
  
  for (pair<short, char> x : mm) {// x is a <key, value> pair
    cout << "(" << x.first << "," << x.second <<")";//x.first is key, x.second is val
  }
  cout << endl;
  
  //vector (array)
  //hashtable (unordered_map)
  //list (in c++, it is doubly-linked list)
  //an example, 1-->2--->3 : 1-->3
  //queue, deque (1-2 questions), priority_queue (heap)
  //stack
  //unordered_map vs map
  //unordered_set vs set
  //set vs multiset
  //binary tree, binary search tree, graph
  //2-5 questions, more advanged trees
  multiset<int> ms;
  ms.insert(9);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(2);
  ms.insert(5);
  
  for (auto x : ms) {
    cout << x << " ";
  }
  cout << endl;
  
  set<int> s;
  s.insert(9);
  s.insert(1);
  s.insert(1);
  s.insert(1);
  s.insert(2);
  s.insert(5);
  
  for (auto x : s) {
    cout << x << " ";
  }
  cout << endl;
  
  
  //algorithms
  //master theorm
  //sort (quickSort, mergeSort, heapSort), time complexity, space complexity, in place or not, stable or not
  //advanged sort: couting sort, and radix sort
  //recursion (tree)
  //dynamic programming (hard problem)
  //greedy (not too many problems)
  //BFS /DFS (tree and graph)
  //backtracking ()
  //
  return 0;
}
