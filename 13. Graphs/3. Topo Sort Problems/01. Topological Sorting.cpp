/*
QUESTION:
Given a DAG (directed acyclic graph), print the Topological sorting of a given graph.

APPROACH:
- Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge u -> v, vertex u comes before v in the ordering.
- To find the topological sorting, we can use Depth-First Search (DFS) with backtracking.
- We perform DFS starting from each unvisited node, and as we finish exploring a node and backtrack, we add it to the front of the topological sorting order.
- We use a stack to keep track of the order of nodes in the topological sorting.

COMPLEXITY ANALYSIS:
- Time Complexity: O(V + E), where V is the number of vertices (nodes) and E is the number of edges in the graph. We visit each node and each edge exactly once during the DFS.
- Space Complexity: O(V), where V is the number of vertices (nodes) in the graph. We use additional space to store the visited status of the nodes and the topological sorting order.
*/

bool dfs(int node, vector<int> adj[], vector<bool>& vis, stack<int>& st){
    vis[node] = true;
    for(auto v : adj[node]){
        if(!vis[v]){
            dfs(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& graph, int edges, int nodes) {
    vector<int> adj[nodes];
    for(auto it : graph){
        adj[it[0]].push_back(it[1]);
    }
    vector<bool> vis(nodes);
    stack<int> st;
    for(int i = 0; i < nodes; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
