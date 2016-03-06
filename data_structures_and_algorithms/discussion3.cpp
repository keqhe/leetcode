#include<iostream>
#include<string>
#include<deque>
#include<set>
#include<unordered_set>

using namespace std;

int main() {
    deque<int> de;//an extension of queue
    de.push_back(2);
    de.push_front(1);
    de.pop_back();
    de.pop_front();
    
    /* for BFS, 
    while (!de.empty()) {
        //BFS...
    }*/
    
    //each element can only appear once
    set<int> se;
    for (int i = 0; i < 5; i ++) {
        se.insert(i);
    }
    se.insert(4);
    se.insert(100);
    se.insert(9);
 
    for(auto x : se) {
        cout << x << " ";
    }
    cout << endl;
    
    auto it = se.begin();
    cout << *(next(it, 2)) << endl;//dangerous

    /*check whether 2 appears in the set */
    if (se.find(2) != se.end())
        cout << "found 2 in this set" << endl;

    cout << se.count(1) << endl;
    
    //lower_bound and upper_bound
    
    unordered_set<int> us;
    //all the functions are similar to set
    //insert, erase, find, count, 
    us.insert(3);
    us.insert(2);
    us.insert(5);
    for (auto x : us) {
        cout << x << " ";
    } 
    cout << endl;

    us.erase(5);
    us.erase(us.begin());
    
    //when you erase using value in multiset, you need to be careful
    multiset<int> mt;
    mt.insert(1);
    mt.insert(1);
    mt.insert(2);
    mt.insert(0);
    for (auto x : mt) {
        cout << x << " ";
    }
    cout << endl;


    
    /*map, unordered_map, vector, list, stack, queue, deque, set, unordered_set, 
    multiset, string*/
    int temp[4][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
    //assuming current postion is [x][y]
    /*for (auto p : temp) {
        int x2 = x + p[0];
        int y2 = y + p[1];
    }
    */ 
    /*heap*/
    
    /*linked list, binary tree, binary search tree, trie, graph */
 
    return 0;
}

