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

class Solution{
private:
    // Depth-First Search (DFS) function to traverse 'O's and mark visited cells
    void dfs(int row, int col, vector<vector<int>> &vis, 
             vector<vector<char>> &mat, int delrow[], int delcol[]) {
        vis[row][col] = 1; // Mark the current cell as visited
        int n = mat.size(); // Number of rows in the matrix
        int m = mat[0].size(); // Number of columns in the matrix
        
        // Check top, right, bottom, left neighbors of the current cell
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i]; // New row coordinate
            int ncol = col + delcol[i]; // New column coordinate
            
            // Check for valid coordinates and unvisited 'O's
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
               && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); // Recursively call DFS
            }
        }
    }
public:
    // Function to fill surrounded 'O's with 'X's
    vector<vector<char>> fill(int n, int m, 
                               vector<vector<char>> mat) {
        // Array to represent row shifts: up, right, down, left
        int delrow[] = {-1, 0, +1, 0};
        // Array to represent column shifts: up, right, down, left
        int delcol[] = {0, 1, 0, -1};
        
        // Matrix to track visited cells
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        // Traverse the first and last rows
        for(int j = 0; j < m; j++) {
            // Check for unvisited 'O's in the boundary rows (first row and last row)
            // First row
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol); // Start DFS traversal
            }
            
            // Last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O') {
                dfs(n-1, j, vis, mat, delrow, delcol); // Start DFS traversal
            }
        }
        
        // Traverse the first and last columns
        for(int i = 0; i < n; i++) {
            // Check for unvisited 'O's in the boundary columns (first column and last column)
            // First column
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol); // Start DFS traversal
            }
            
            // Last column
            if(!vis[i][m-1] && mat[i][m-1] == 'O') {
                dfs(i, m-1, vis, mat, delrow, delcol); // Start DFS traversal
            }
        }
        
        // Convert unvisited 'O's to 'X's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        
        return mat; // Return the modified matrix
    }
};
