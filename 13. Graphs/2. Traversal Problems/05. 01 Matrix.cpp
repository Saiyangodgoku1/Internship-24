/*
QUESTION:-
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.

APPROACH:
- We can use a Breadth-First Search (BFS) traversal to find the distance of the nearest 0 for each cell.
- First, we initialize the distance matrix with -1 for all cells.
- Then, we iterate through the matrix and find all cells with the value 0. For each 0 cell found, we add it to the queue and set its distance to 0 in the distance matrix.
- Next, we perform a BFS starting from the cells with 0. During the BFS, we update the distance of each cell from the nearest 0 cell and continue the BFS until all cells are visited.
- Finally, we return the distance matrix.

COMPLEXITY ANALYSIS:
- Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. In the worst case, we may need to visit all the cells of the matrix.
- Space Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix. We use additional space for the distance matrix and the queue during BFS.
*/

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(); // Number of rows in the matrix
    int n = mat[0].size(); // Number of columns in the matrix
    vector<vector<int>> dis(m, vector<int>(n, -1)); // Initialize a matrix to store distances with -1 initially
    queue<pair<int, int>> q; // Initialize a queue to perform BFS

    // Pushing all the cells with 0s into the queue and setting their distance to 0
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Direction arrays for moving up, down, left, and right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    int level = 1; // Initialize the level (distance) to 1

    // BFS traversal to update distances
    while(!q.empty()){
        int size = q.size(); // Current number of cells in the queue
        while(size--){
            auto p = q.front(); // Current cell coordinates
            q.pop();
            int x = p.first, y = p.second;
            // Check all four adjacent cells
            for(int i = 0; i < 4; i++){
                int nx = x + dr[i], ny = y + dc[i];
                // Check if the adjacent cell is within the matrix boundaries and not visited yet
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && dis[nx][ny] == -1){
                    dis[nx][ny] = level; // Update the distance of the adjacent cell
                    q.push({nx, ny}); // Push the adjacent cell into the queue for further processing
                }
            }
        }
        level++; // Increment the distance level for the next iteration
    }

    return dis; // Return the matrix with updated distances
}
