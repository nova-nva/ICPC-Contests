/**
 * GRAFOS 1
 * B - Bicoloring
 * Grafos bipartitos - BFS 
 * (Accepted)
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int nodes; cin>>nodes;
    while(nodes != 0){
        int edges; cin>>edges;
        vector<int> connections[nodes];
        for(int i = 0; i<edges; i++){
            int a, b; cin>>a>>b;
            connections[a].push_back(b);
            connections[b].push_back(a);
        }
        int s = 0;
        queue<int> q; q.push(0);
        vector<int> color(nodes, -1); color[0] = 0;
        bool isBipartite = true;
        while(!q.empty() and isBipartite){
            int u = q.front(); q.pop();
            for(int j = 0; j<connections[u].size(); j++){
                int v = connections[u][j];
                if(color[v] == -1){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    isBipartite = false;
                    break;
                }
            }
        }
        string response = (isBipartite) ? "BICOLORABLE." : "NOT BICOLORABLE.";
        cout<< response <<endl;
        cin>>nodes;
    }
}

// Bibliography: CP3, page: 123, 124 (Pure BFS)