#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// ====== Tree Node Structure ======
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ====== Graph Class ======
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // ====== DFS for Tree ======
    static void treeDFS(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        treeDFS(root->left);
        treeDFS(root->right);
    }

    // ====== DFS for Graph ======
    void graphDFS(int start) {
        vector<bool> visited(V, false);
        stack<int> st;
        st.push(start);
        
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            
            if (!visited[u]) {
                cout << u << " ";
                visited[u] = true;
                
                // Push neighbors in reverse order for same traversal as recursive
                for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                    if (!visited[*it]) {
                        st.push(*it);
                    }
                }
            }
        }
    }

    // ====== BFS for Tree ======
    static void treeBFS(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }

    // ====== BFS for Graph ======
    void graphBFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main() {
    cout << "===== Tree Traversals =====" << endl;
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    cout << "DFS (Pre-order): ";
    Graph::treeDFS(root);
    cout << "\nBFS (Level-order): ";
    Graph::treeBFS(root);
    
    cout << "\n\n===== Graph Traversals =====" << endl;
    // Create a sample graph
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    cout << "DFS (starting from 0): ";
    g.graphDFS(0);
    cout << "\nBFS (starting from 0): ";
    g.graphBFS(0);
    
    return 0;
}