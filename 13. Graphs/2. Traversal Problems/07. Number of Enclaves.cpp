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

void dfs(int i, int j, vector<vector<int>>& vis){
    // Check if the current cell is within the boundaries and is unvisited
    if(i >= 0 && i < vis.size() && j >= 0 && j < vis[0].size() && vis[i][j] == 1){
        vis[i][j] = -1; // Mark the current cell as visited
        // Recursively call DFS on the adjacent cells
        dfs(i + 1, j, vis); // Down
        dfs(i - 1, j, vis); // Up
        dfs(i, j + 1, vis); // Right
        dfs(i, j - 1, vis); // Left
    }
}

int numEnclaves(vector<vector<int>>& grid) {
    int m = grid.size(); // Number of rows in the grid
    int n = grid[0].size(); // Number of columns in the grid
    vector<vector<int>> vis(grid.begin(), grid.end()); // Copy of the original grid to track visited cells
    
    // Perform DFS from boundary cells (boundary cells with value 1)
    for(int i = 0; i < n; i++){
        if(vis[0][i] == 1)
            dfs(0, i, vis); // Start DFS traversal from the top boundary
        if(vis[m - 1][i] == 1)
            dfs(m - 1, i, vis); // Start DFS traversal from the bottom boundary
    }
    for(int i = 0; i < m; i++){
        if(vis[i][0] == 1)
            dfs(i, 0, vis); // Start DFS traversal from the left boundary
        if(vis[i][n - 1] == 1)
            dfs(i, n - 1, vis); // Start DFS traversal from the right boundary
    }
    
    // Count the number of land cells that are not on the boundary
    int ans = 0;
    for(auto row : vis){
        for(auto col : row){
            if(col == 1)
                ans++; // Increment the count for each land cell that is not on the boundary
        }
    }
    return ans; // Return the total number of land cells that are not on the boundary
}
