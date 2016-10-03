
struct pairhash {
  template<typename A, typename B>
  std::size_t operator()(const pair<A, B> & p) const {
      return std::hash<A>()(p.first) ^ std::hash<B>()(p.second);
  }  
};
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    bool game_over = false;
    unordered_set<pair<int, int>, pairhash> body;
    deque<pair<int, int>> snake;
    int m;
    int n;
    queue<pair<int, int>> foods;
    int score;
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        m = height;
        n = width;
        for (auto p : food)
            foods.push(p);
        snake.push_front(make_pair(0, 0));
        body.insert(make_pair(0, 0));
        score = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (game_over)
            return -1;
        pair<int, int> head = snake.front();
        int x = head.first;
        int y = head.second;
        if (direction == "U")
            -- x;
        else if (direction == "L")
            -- y;
        else if (direction == "R")
            ++ y;
        else if (direction == "D")
            ++ x;
        if (x < 0 || x >= m || y < 0 || y >= n) {
            game_over = true;
            return -1;
        }
        
        if (foods.empty() || make_pair(x, y) != foods.front()) {
            auto p = snake.back();
            snake.pop_back();
            body.erase(p);
            
            if (body.find(make_pair(x, y)) == body.end()) {
                snake.push_front(make_pair(x, y));
                body.insert(make_pair(x, y));
            }
            else {
                game_over = true;
                return -1;
            }
            return score;
        }
        else {
            if (body.find(make_pair(x, y)) == body.end()) {
                snake.push_front(make_pair(x, y));
                body.insert(make_pair(x, y));
            }
            else {
                game_over = true;
                return -1;
            }
            foods.pop();
            ++ score;
            return score;
        }
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
