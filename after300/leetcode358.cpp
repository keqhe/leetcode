
/*
这道题给了我们一个字符串str，和一个整数k，让我们对字符串str重新排序，使得其中相同的字符之间的距离不小于k，这道题的难度标为Hard，看来不是省油的灯。的确，这道题的解法用到了哈希表，堆，和贪婪算法。这道题我最开始想的算法没有通过OJ的大集合超时了，下面的方法是参考网上大神的解法，发现十分的巧妙。我们需要一个哈希表来建立字符和其出现次数之间的映射，然后需要一个堆来保存这每一堆映射，按照出现次数来排序。然后如果堆不为空我们就开始循环，我们找出k和str长度之间的较小值，然后从0遍历到这个较小值，对于每个遍历到的值，如果此时堆为空了，说明此位置没法填入字符了，返回空字符串，否则我们从堆顶取出一对映射，然后把字母加入结果res中，此时映射的个数减1，如果减1后的个数仍大于0，则我们将此映射加入临时集合v中，同时str的个数len减1，遍历完一次，我们把临时集合中的映射对由加入堆中，参见代码如下
*/
class Node {
public:
    char c;
    int count;
    Node(char c, int count) : c(c), count(count) {};
    Node& operator=(const Node& n) {
        this->c = n.c;
        this->count = n.count;
        return *this;
    }
};

struct myCmp {
  bool operator()(const Node & n1, const Node& n2) const {
      if (n1.count != n2.count)
        return n1.count < n2.count;//for max-heap
      else
        return n1.c > n2.c;
  }  
};

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (str.empty() || k == 1 || k == 0)
            return str;
        int len = str.length();
        string res;
        unordered_map<char, int> m;
        for (auto c : str) {
            m[c] ++;
        }
        priority_queue<Node, vector<Node>, myCmp> pq;
        for (auto& kv : m) {
            pq.push(Node(kv.first, kv.second));
        }
        
        while (!pq.empty()) {
            vector<Node> cache;
            int steps = min(k, len);
            //cout << "steps: " << steps << endl;
            for (int i = 0; i < steps; i ++) {
                if (pq.empty())
                    return "";
                Node n = pq.top();
                pq.pop();
                res.push_back(n.c);
                len --;
                if (--n.count > 0) {
                    cache.push_back(n);
                }
            }
            for (auto& n : cache) {
                pq.push(n);
            }
        }
        return res;
    }
};
