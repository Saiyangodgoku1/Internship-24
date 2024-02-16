/*
QUESTION:-
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

APPROACH:
- We can use Depth-First Search (DFS) to mark all land cells connected to the boundary of the grid as uncountable (i.e., cells that we can walk off the boundary).
- First, we initialize a copy of the grid called 'vis' to store the visited status of each cell.
- Then, we perform DFS from all land cells located at the boundary of the grid. During the DFS, we mark all connected land cells as visited by changing their value to -1 in the 'vis' matrix.
- After performing DFS from boundary cells, all remaining land cells in the 'vis' matrix represent cells that we cannot walk off the boundary of the grid.
- Finally, we count the number of land cells in the 'vis' matrix and return the count as the result.

COMPLEXITY ANALYSIS:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. In the worst case, we may need to visit all the cells of the matrix during DFS.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. We use additional space for the 'vis' matrix.
*/

class Solution {
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        queue<pair<int,int>> q; // Queue to store boundary land cells
        int n = grid.size(); // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid
        int vis[n][m] = {0}; // 2D array to track visited cells
        
        // Traverse boundary elements
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Check if the cell is on the boundary (first row, first column, last row, or last column)
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    // If it is a land cell, store it in the queue and mark it as visited
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, +1, 0}; // Array to represent row shifts: up, right, down, left
        int delcol[] = {0, +1, +0, -1}; // Array to represent column shifts: up, right, down, left
        
        // Perform BFS traversal starting from boundary land cells
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // Traverse all 4 directions
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                // Check for valid coordinates, unvisited land cells, and mark them as visited
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        // Count the number of unvisited land cells
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) 
                    cnt++; // Increment the count for unvisited land cells
            }
        }
        return cnt; // Return the count of unvisited land cells
    }
};
