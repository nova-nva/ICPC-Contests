/**
 * GRAFOS 1
 * A - No Way
 * DFS 
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

int n; // number of nodes
vector<int> gph[101]; // ajdList global de los nodos y sus conexiones
bool visited[101]; // array de nodos visitados

void dfs(int v){ // para navegar todos los vecinos de un determinado nodo
    forn(i, gph[v].size()){
        if(!visited[gph[v][i]]){
            visited[gph[v][i]] = true;
            dfs(gph[v][i]);
        }
    }
}

int main(){
    FastIO;
    while(cin >> n and n != 0){
        forn(i, n+1){
            gph[i].clear();
            visited[i] = false;
        }
        int init_node;
        while(cin >> init_node and init_node != 0){
            int destiny;
            while(cin >> destiny and destiny != 0){
                gph[init_node].pb(destiny);
            }
            //cin>>init_node; // el final (0) de las conexiones
        }
        int querys; cin>>querys;
        while(querys--){
            int current_query; cin>>current_query;
            // por cada query, corremos un dfs para marcar todos los nodos que alcanza
            dfs(current_query);
            vi not_visited;
            forsn(j, 1, n+1){ // checamos los que no estan visitados y esos son la respuesta
                if(!visited[j]){
                    not_visited.pb(j);
                }
            }
            cout<<not_visited.size();
            forn(j, not_visited.size()){
                cout<<" "<<not_visited[j];
            }
            cout<<endl;
            // limpiar nuestros visitados para el siguiente query
            fill(visited, visited + n + 1, 0);
        }
        // limpiar el global para el siguiente input
        forn(i, n+1){
            gph[i].clear();
        }
    }
}
// Bibliography: CP3, page: 122 (Pure DFS)

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
█████████████ From the flame comes the Phoenix █████████████
████████████████████████████████████████████████████████████*/