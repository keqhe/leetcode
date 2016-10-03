
class Logger {
public:
    //super easy java reference: https://discuss.leetcode.com/topic/48483/super-easy-java-hashmap-solution
    
    /** Initialize your data structure here. */
    unordered_map<string, int> cache;//key is message, value is timestamp
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (cache.find(message) != cache.end() && (timestamp - cache[message] < 10)) {
            return false;
        }
        cache[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
