/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 */

// @lc code=start
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

/*
  Time Complwxity:
    1. If there are N cells in the matrix and there are M walls so the empty cells are N-M.
    2. We will be visiting N-M cells hence T.C will be O(N-M)
  Space Complexity:
    1. We have created 'visited' set which will contain N-M cells.
    2. S.C -> O(N - M)
*/
class Solution {
public:
    typedef pair<int,int> p;
    void dfs(Robot &robot, int x, int y, int direction, unordered_set<string> &visited, vector<p> &directions){
        robot.clean();
        visited.insert(to_string(x) + "_" + to_string(y));
        for(int i = 0; i < 4; i++){
            int newDirection = (direction + i) % 4;
            auto [dx, dy] = directions[newDirection];
            int newX = x + dx;
            int newY = y + dy;
            string point = to_string(newX) + "_" + to_string(newY);
            if(visited.find(point) == visited.end() && robot.move()){
                dfs(robot, newX, newY, newDirection, visited, directions);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }
    void cleanRoom(Robot& robot) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<p> directions = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
        unordered_set<string>visited;
        //Since we dont know the position of the robot we will consider it starts from 0,0
        dfs(robot, 0, 0, 0, visited, directions);
    }
};
// @lc code=end

