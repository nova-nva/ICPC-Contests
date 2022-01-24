#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int nodes; cin>>nodes;
    while(nodes != 0){
        int edges; cin>>edges;
        vector<int> adjList[nodes];
        for(int i = 0; i<edges; i++){
            int a, b; cin>>a>>b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        cout<<"Graph: "<<endl;
        for(int i = 0; i<nodes; i++){
            for(int j = 0; j<adjList[i].size(); j++){
                cout<<adjList[i][j]<<" ";
            }
            cout<<endl<<endl;
        }
        /*
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
        */
    }
}