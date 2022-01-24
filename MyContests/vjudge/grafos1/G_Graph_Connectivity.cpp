/**
 * GRAFOS 1
 * G - Graph Connectivity
 * BFS 
 * (Accepted)
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n; cin>>n;
    
    // Limpiar basura
    string a;
    getline(cin, a);
    // Leer Enter
    getline(cin, a);

    for(int i = 0; i<n; i++){
        vector<int> connections[26];
        string nroNodos;
        getline(cin, nroNodos);
        int nro = nroNodos[0] - 65 + 1;

        while(true){
            getline(cin, a);
            if(a.size() == 0) break;
            connections[a[0] - 65].push_back(a[1] - 65);
            connections[a[1] - 65].push_back(a[0] - 65);
        }
        
        vector<int> visitados (nro, -1);
        int subgrafos = 0;
        for(int j = 0; j<nro; j++){
            if(visitados[j] == 1){
                continue;
            }
            subgrafos++;
            queue<int> q; q.push(j); // start from source
            while (!q.empty()) {
                int u = q.front(); q.pop(); // queue: layer by layer!
                for (int k = 0; k < connections[u].size(); k++) {
                    int v = connections[u][k]; // for each neighbor of u
                    if (visitados[v] == -1) { // if v.first is unvisited + reachable
                        visitados[v] = 1; // make d[v.first] != INF to flag it
                        q.push(v); // enqueue v.first for the next iteration
                    }
                }
            }
        }
        cout<<subgrafos<<endl;
        if(i != n-1){
            cout<<endl;
        }
    }

    // Extra task: implementar con Union-Find
}

// Bibliography: CP3, page: 123, 124 (Pure BFS)