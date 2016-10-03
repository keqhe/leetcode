
class HitCounter {
public:
    //https://discuss.leetcode.com/topic/51465/java-code-with-circular-buffer
    vector<int> cache;
    int last_time;
    int sum;
    /** Initialize your data structure here. */
    HitCounter() {
        last_time = 0;
        sum = 0;
        cache.resize(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        updateCache(timestamp);
        cache[timestamp%300] +=1;
        sum += 1;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        updateCache(timestamp);
        return sum;
    }
    
    void updateCache(int timestamp) {
        int span = timestamp - last_time;
        if (span >= 300) {
            for (int i = 0; i < 300; i ++)
                cache[i] = 0;
            sum = 0;
        }
        else {
            for (int i = 1; i <= span; i ++) {
                sum -= cache[(last_time+i)%300];
                cache[(last_time+i)%300] = 0;
            }
        }
        last_time = timestamp;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
