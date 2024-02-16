/*
QUESTION:-
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

APPROACH:
- We can use Depth-First Search (DFS) to find all regions that are surrounded by 'X'.
- First, we initialize a copy of the board called 'vis' to store the visited status of each cell.
- Then, we perform a DFS starting from all border cells that have 'O's. During the DFS, we mark all connected 'O's as visited by changing them to a special character, such as '#', in the 'vis' matrix.
- After performing DFS from border cells, all remaining '#'s in the 'vis' matrix represent regions that are not surrounded by 'X'.
- Finally, we update the original board by flipping all remaining 'O's to 'X'.

COMPLEXITY ANALYSIS:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. In the worst case, we may need to visit all the cells of the matrix during DFS.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. We use additional space for the 'vis' matrix.
*/

void dfs(int i, int j, vector<vector<char>>& vis){
    // Check if the current cell is within the boundaries and is unvisited ('O')
    if(i >= 0 && i < vis.size() && j >= 0 && j < vis[0].size() && vis[i][j] == 'O'){
        vis[i][j] = '#'; // Mark the current cell as visited ('#')
        // Recursively call DFS on the adjacent cells
        dfs(i + 1, j, vis); // Down
        dfs(i - 1, j, vis); // Up
        dfs(i, j + 1, vis); // Right
        dfs(i, j - 1, vis); // Left
    }
}

void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    // Create a copy of the board to track visited cells
    vector<vector<char>> vis(board.begin(), board.end());
    
    // Perform DFS from border cells
    for(int i = 0; i < n; i++){
        if(vis[0][i] == 'O')
            dfs(0, i, vis); // Top row
        if(vis[m - 1][i] == 'O')
            dfs(m - 1, i, vis); // Bottom row
    }
    for(int i = 0; i < m; i++){
        if(vis[i][0] == 'O')
            dfs(i, 0, vis); // Leftmost column
        if(vis[i][n - 1] == 'O')
            dfs(i, n - 1, vis); // Rightmost column
    }
    
    // Update the original board based on the visited cells
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == 'O')
                board[i][j] = 'X'; // Flip 'O's surrounded by 'X's to 'X'
        }
    }
}
