#include <bits/stdc++.h>
using namespace std;

// Graph class implementing BFS and DFS traversals
class Graph {
    int vertices;
    bool directed;
    vector<vector<int>> adjList;

public:
    // Constructor
    Graph(int v, bool isDirected = false) {
        vertices = v;
        directed = isDirected;
        adjList.resize(v);
    }

    // Add an edge between two nodes
    void addEdge(int u, int v) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid edge (" << u << ", " << v << ")\n";
            return;
        }

        adjList[u].push_back(v);
        if (!directed) {
            adjList[v].push_back(u);
        }
    }

    // Print adjacency list
    void printGraph() {
        cout << "\nAdjacency List Representation:\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Node " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    // Breadth-First Search traversal
    void BFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start node for BFS\n";
            return;
        }

        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal (from node " << start << "): ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Handle disconnected components
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                cout << "| (Disconnected) starting at node " << i << ": ";
                visited[i] = true;
                queue<int> q2;
                q2.push(i);
                while (!q2.empty()) {
                    int node = q2.front();
                    q2.pop();
                    cout << node << " ";
                    for (int neighbor : adjList[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q2.push(neighbor);
                        }
                    }
                }
            }
        }

        cout << "\n";
    }

    // Helper function for DFS
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // Depth-First Search traversal
    void DFS(int start) {
        if (start < 0 || start >= vertices) {
            cout << "Invalid start node for DFS\n";
            return;
        }

        vector<bool> visited(vertices, false);
        cout << "\nDFS Traversal (from node " << start << "): ";
        DFSUtil(start, visited);

        // Handle disconnected components
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                cout << "| (Disconnected) starting at node " << i << ": ";
                DFSUtil(i, visited);
            }
        }

        cout << "\n";
    }
};

int main() {
    cout << "Graph Traversal Visualizer\n";
    cout << "---------------------------\n";

    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    if (vertices <= 0) {
        cout << "Number of vertices must be positive.\n";
        return 0;
    }

    char typeChoice;
    cout << "Is the graph directed? (y/n): ";
    cin >> typeChoice;
    bool isDirected = (typeChoice == 'y' || typeChoice == 'Y');

    Graph g(vertices, isDirected);

    cout << "Enter number of edges: ";
    cin >> edges;

    if (edges < 0) {
        cout << "Number of edges cannot be negative.\n";
        return 0;
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printGraph();

    int startNode;
    cout << "\nEnter starting node for traversal: ";
    cin >> startNode;

    g.BFS(startNode);
    g.DFS(startNode);

    cout << "\nTraversal complete.\n";
    return 0;
}
