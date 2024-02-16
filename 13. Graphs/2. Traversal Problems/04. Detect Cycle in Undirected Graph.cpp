/*
QUESTION:-

Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having an edge with.

APPROACH:
- To check whether the graph contains a cycle or not, we can perform a Depth-First Search (DFS) traversal on the graph and keep track of the visited nodes.
- During the DFS traversal, if we encounter a node that is already visited and is not the parent of the current node (indicating a back edge), then there is a cycle in the graph. We need to check this condition for every node in the graph.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph. In the worst case, we may need to visit all the vertices and edges of the graph.
- Space Complexity: O(V), where V is the number of vertices. We use an additional array to keep track of visited nodes.
*/

bool dfs(int node, int parent, vector<int> adj[], vector<bool>& vis){
    vis[node] = true; // Marking the current node as visited
    for(auto v:adj[node]){ // Iterating through adjacent nodes of the current node
        if(!vis[v]){ // If the adjacent node is not visited yet
            if(dfs(v, node, adj, vis)) // Recursively call DFS on the adjacent node
                return true; // If DFS returns true, there's a cycle
        }
        else if(v != parent){ // If the adjacent node is visited and not the parent of the current node
            return true; // This indicates a cycle
        }
    }
    return false; // If no cycle is found in the current DFS traversal
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V); // Initialize a boolean array to keep track of visited nodes
    for(int i = 0; i < V; i++){
        if(!vis[i]){ // If the current node is not visited yet
            if(dfs(i, -1, adj, vis)) // Start DFS from the current node
                return true; // If DFS returns true, there's a cycle
        }
    }
    return false; // If no cycle is found in any DFS traversal
}
