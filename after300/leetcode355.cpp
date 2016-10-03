
/*class Twitter {
public:
    //https://discuss.leetcode.com/topic/50032/c-solution-with-max-heap
    unordered_map<int, set<int>> friends;
    unordered_map<int, vector<pair<int, int>>> messages;
    long long time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        messages[userId].push_back({time, tweetId});
        ++ time;
    }
    
    vector<int> getNewsFeed(int userId) {
        if (messages.find(userId) == messages.end() && friends.find(userId) == friends.end())
            return {};
        priority_queue<pair<long long, int>> pq;//max heap
        if (messages.find(userId) != messages.end()) {
            for (auto x : messages[userId]) {
                pq.push(x);
            }
        }
        
        if (friends.find(userId) != friends.end()) {
            for (auto x : friends[userId]) {
                if (messages.find(x) != messages.end()) {
                    for (auto y : messages[x]) {
                        pq.push(y);
                    }
                }
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
            if (res.size() >= 10)
                break;
        }
        //reverse(res.begin(), res.end());
        return res;
    }
    
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            friends[followerId].insert(followeeId);
    }
    
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
*/
class Twitter {
private:    
   unordered_map<int, set<int>> fo;
   unordered_map<int, vector<pair<int, int>>> t;
   long long time; 

public:
/** Initialize your data structure here. */
Twitter() {
    time = 0;
}

/** Compose a new tweet. */
void postTweet(int userId, int tweetId) {
    t[userId].push_back({time++, tweetId});
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
vector<int> getNewsFeed(int userId) {
    priority_queue<pair<int, int>> maxHeap; 
    for (auto it=t[userId].begin();it!=t[userId].end();++it)
        maxHeap.push(*it);
    for (auto it1=fo[userId].begin();it1!=fo[userId].end();++it1){
        int usr = *it1; // get target user
        for (auto it2=t[usr].begin();it2!=t[usr].end();++it2)
            maxHeap.push(*it2);
    }   
    vector<int> res;
    while(maxHeap.size()>0) {
        res.push_back(maxHeap.top().second);
        if (res.size()==10) break;
        maxHeap.pop();
    }
    return res;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void follow(int followerId, int followeeId) {
    if (followerId != followeeId)
        fo[followerId].insert(followeeId);
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void unfollow(int followerId, int followeeId) {
    fo[followerId].erase(followeeId);
}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
