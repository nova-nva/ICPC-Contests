/**
 * GRAFOS 1
 * C - Sending email
 * Dijkstra 
 * (Accepted)
 */

#include <bits/stdc++.h>
#define forn(i,n) for(int i=0; i<int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i<int(n); i++)
#define forit(i, str) for(auto i = str.begin(); i != str.end(); i++)
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define all(v) (v).begin(), (v).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;

int main(){
    FastIO;
    int N; cin>>N;
    for(int i = 0; i<N; i++){
        int n; // number of nodes
        int m; // number of next m connections
        int s, t; // init node, end node to find a path
        cin>>n>>m>>s>>t;

        vector<ii> graph[n]; // una adjList de pares en formato [nodo_destino, costo]
        for(int j = 0; j<m; j++){
            int s1, s2; // node1, node2;
            int w; // weight (latency)
            cin>>s1>>s2>>w;
            graph[s1].pb(ii(s2, w));
            graph[s2].pb(ii(s1, w));
        }

        int dist[n]; // un vector de distancias para cada nodo
        fill(dist, dist + n, INT_MAX); // llenar todo el vector con INT_MAX mediante punteros
        dist[s] = 0; // la distancia de S a S es 0
        
        // Dijkstra
        priority_queue<ii, vector<ii>, greater<ii> > pq; // una cola de prioridad de pares en formato [costo, nodo_destino] para que ordene con el costo por delante
        pq.push(ii(0, s)); // la distancia de S a S es 0
        while(!pq.empty()){
            ii node = pq.top(); pq.pop();
            int costo = node.F, nodo = node.S;
            if(costo > dist[nodo]){
                continue;
            }
            forn(i, graph[nodo].size()){ // navegar por cada nodo conectado al actual
                int vertice = graph[nodo][i].F;
                int distancia = graph[nodo][i].S;
                if(distancia + dist[nodo] < dist[vertice]){
                    dist[vertice] = dist[nodo] + distancia;
                    pq.push(ii(dist[vertice], vertice));
                }
            }
        }
        cout<<"Case #"<<(i+1)<<": ";
        if(dist[t] == INT_MAX){
            cout<<"unreachable"<<endl;
        }
        else{
            cout<<dist[t]<<endl;
        }
    }
}
// Bibliography: CP3, page: 148 (Pure Dijkstra)

/*
████████████████████████████████████████████████████████████
██████ Today I will compete and I will get BETTER!!! ███████
████████████████████████████████████████████████████████████
████████████████████████████████████████████████████████████
███████████████████████▒▒███████████████████████████████████
███████████████████████████▒▒███████████████████████████████
███████████████████████████▒▒▒▒▒▒████████▒▒█████████████████
███████████████████▒▒██▒▒████▒▒▒▒▒▒█████████████████████████
███████████████████▒▒▒▒████▒▒▒▒▒▒▒▒▒▒███████████████████████
█████████████▒▒████▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████
█████████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████████████████████
█████████████████████▒▒▒▒▒▒▒▒▒▒▒▒░░▒▒▒▒▒▒███████████████████
███████████████████▒▒▒▒▒▒░░▒▒░░░░░░▒▒▒▒▒▒███████████████████
███████████████████▒▒▒▒▒▒░░░░░░░░  ░░▒▒▒▒▒▒█████████████████
███████████████████▒▒▒▒▒▒  ░░    ░░░░▒▒▒▒▒▒█████████████████
███████████████████▒▒▒▒▒▒░░        ░░░░▒▒▒▒█████████████████
███████████████████▒▒▒▒░░░░          ░░▒▒▒▒█████████████████
█████████████████████▒▒░░            ░░▒▒▒▒█████████████████
█████████████████████▒▒░░          ░░▒▒▒▒███████████████████
███████████████████████▒▒▒▒        ░░▒▒█████████████████████
███████████████████████████▒▒▒▒▒▒▒▒▒▒███████████████████████
████████████████████████████████████████████████████████████
████████████████████████████████████████████████████████████
█████████████ From the flame comes the PHOENIX █████████████
████████████████████████████████████████████████████████████*/