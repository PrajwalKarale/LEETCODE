/*
 * @lc app=leetcode id=778 lang=java
 *
 * [778] Swim in Rising Water
 */

// @lc code=start
/*
    Logic:
      1. Modified Djikstras
    Time Complexity:
        1. The priority queue operations take O(log(k)) time and then the worst case is that we have to visit each and every cell
        2. T.C -> O(n^2 * log(k))
    Space Complexity:
        1. We are using Priority queue as an auxiliary space and also the visited array
        2. S.C -> O(N^2) where N is the number of rows and columns in the grid.
*/
class Pair{
    int value;
    int x;
    int y;
    Pair(int value, int x, int y){
        this.value = value;
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int swimInWater(int[][] grid) {
        int rows = grid.length;
        int columns = grid[0].length;
        
        boolean[][] visited = new boolean[rows][rows];
        
        int result = Integer.MIN_VALUE;
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        PriorityQueue<Pair>pq = new PriorityQueue<>((a,b) -> a.value - b.value);
        
        pq.add(new Pair(grid[0][0], 0, 0));
        visited[0][0] = true;
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            if(p.x == rows - 1 && p.y == rows - 1){
                return p.value;
            }
            for(int i = 0; i < 4; ++i){
                int newX = p.x + dx[i];
                int newY = p.y + dy[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < columns && visited[newX][newY] == false){
                    visited[newX][newY] = true;
                    int time = Math.max(grid[newX][newY], p.value);
                    pq.add(new Pair(time, newX, newY));
                }
            }
        }
        return 0;
    }
}
// @lc code=end

