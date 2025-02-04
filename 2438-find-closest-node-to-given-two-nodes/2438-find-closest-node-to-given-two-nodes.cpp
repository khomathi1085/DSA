class Solution {
public:
    vector<long long> Dijkstra(vector<vector<int>>& adj, int start) {
        int n = adj.size();
        vector<long long> dist(n, INT_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            for (int neighbor : adj[node]) {
                if (d + 1 < dist[neighbor]) {
                    dist[neighbor] = d + 1;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> graph(n);
        
        // Construct the graph
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                graph[i].push_back(edges[i]);
            }
        }
        
        // Get distances from both nodes
        vector<long long> dist1 = Dijkstra(graph, node1);
        vector<long long> dist2 = Dijkstra(graph, node2);
        
        // Find the closest meeting node
        int minDistNode = -1;
        long long minDist = INT_MAX;
        
        for (int i = 0; i < n; ++i) {
            if (dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue; // Not reachable
            long long maxDist = max(dist1[i], dist2[i]); // Closest common point
            
            if (maxDist < minDist) {
                minDist = maxDist;
                minDistNode = i;
            }
        }
        
        return minDistNode;
    }
};
