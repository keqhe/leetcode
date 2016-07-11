
//design problem, cool
//https://discuss.leetcode.com/topic/48626/java-deque-and-hashset-design-with-detailed-comments
//this blog is wrong, but useful: https://discuss.leetcode.com/category/437/design-snake-game

struct PairHash {
  template <typename A, typename B> 
  std::size_t operator()(const pair<A, B>& x) const {
      return std::hash<A>()(x.first) ^ std::hash<B>()(x.second);
  }
};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    int width;
    int height;
    vector<pair<int, int>> food;
    int index;
    unordered_set<pair<int, int>, PairHash> us;//snake may eat itself, this data structure help quickly check whether "eat itself" happens or not
    deque<pair<int, int>> de;//snake body tracker
    int score; 
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        index = 0;
        us.insert(make_pair(0, 0));
        de.push_back(make_pair(0, 0));
        score = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (score == -1) // already game over, still game over
            return -1;
            
        auto curr = de.front();
        int row = curr.first;
        int col = curr.second;
        
        if (direction == "U")
            row --;
        else if (direction == "D")
            row ++;
        else if (direction == "L")
            col --;
        else
            col ++;
        
        us.erase(de.back());//temporarily remove tail, because it is okay that head moves to old head's location
        //check out of board or eat itself
        if (row < 0 || row >= height || col < 0 || col >= width || us.find(make_pair(row, col)) != us.end()) {
            score = -1;//game over
            return -1;
        }
        //eat food
        if (index < food.size() && row == food[index].first && col == food[index].second) {
            us.insert(de.back());
            us.insert(make_pair(row, col));
            de.push_front(make_pair(row, col));
            score ++;
            index ++;
            return score;
        }
        de.push_front(make_pair(row, col));//add new head
        us.insert(make_pair(row, col));
        de.pop_back();//remove old tail
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
