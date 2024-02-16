/*
QUESTION:

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

Example:

Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.

CODE:
*/

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // Copying the original image to preserve it
    vector<vector<int>> ans(image.begin(), image.end());
    int m = image.size(), n = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc}); // Pushing the starting pixel into the queue
    int s = ans[sr][sc]; // Storing the original color of the starting pixel
    ans[sr][sc] = color; // Changing the color of the starting pixel to the new color

    // Direction arrays for moving up, down, left, and right
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    // BFS traversal to perform flood fill
    while (!q.empty()) {
        int siz = q.size(); // Current number of pixels in the queue
        while (siz--) {
            auto p = q.front(); // Current pixel coordinates
            q.pop();
            int x = p.first, y = p.second;

            // Checking adjacent pixels for the same original color and changing them to the new color
            for (int i = 0; i < 4; i++) {
                int nx = x + dr[i], ny = y + dc[i];
                // Checking if the new coordinates are within the image boundaries and have the same original color
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && ans[nx][ny] == s && ans[nx][ny] != color) {
                    ans[nx][ny] = color; // Changing the color
                    q.push({nx, ny}); // Adding the new pixel to the queue for further processing
                }
            }
        }
    }

    return ans; // Returning the modified image after flood fill
}
