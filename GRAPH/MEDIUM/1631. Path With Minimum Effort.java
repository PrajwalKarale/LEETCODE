/*
    Logic: Djikstras Algorithm
    Time Complexity: 
        1. We are visiting each and every cell in the matrix.
        2. T.C -> O(rows * cols * log(rows * cols))
    Space Complexity:
        1. Auxiliary Space we have taken is a minimum heap and a auxiliary matrix which is storing the minimum effort
        2. S.C -> O(rows * cols)
*/
class Pair{
    int x;
    int y;
    int value;
    Pair(int value, int x, int y){
        this.value = value;
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int minimumEffortPath(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;
        PriorityQueue<Pair>pq = new PriorityQueue<>((a,b) -> Integer.compare(a.value, b.value));
        int [][] dist = new int[rows][cols];
        int result = Integer.MIN_VALUE;
        
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        pq.add(new Pair(0, 0, 0));
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        dist[0][0] = 0;
        while(!pq.isEmpty()){
            Pair p = pq.poll();
            int effort = p.value;
            int x = p.x;
            int y = p.y;
            if(effort > dist[x][y]){
                continue;
            }
            if(p.x == rows - 1 && p.y == cols - 1){
                return effort;
            }
            for(int i = 0; i < 4; ++i){
                int newX = p.x + dx[i];
                int newY = p.y + dy[i];
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols){
                    int newEffort = Math.max(effort, Math.abs(heights[x][y] - heights[newX][newY]));
                    if(newEffort < dist[newX][newY]){
                        dist[newX][newY] = newEffort;
                        pq.add(new Pair(newEffort, newX, newY));
                    }
                }
            }
        }
        return -1;
    }
}
