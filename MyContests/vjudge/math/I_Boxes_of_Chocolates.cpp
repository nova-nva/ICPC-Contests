/**
 * METH
 * I - Boxes of Chocolates
 * Aritmetica Modular
 * (accepted)
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
    int T; cin>>T; // number of test cases
    forn(i, T){
        int friends, choco_boxes; cin>>friends>>choco_boxes;
        int sum = 0; // sumador de todos los casos de prueba
        forn(j, choco_boxes){
            int nro; cin>>nro;
            int mult = 1; // multiplicador de un caso de prueba especifico
            forn(k, nro){
                int current_box; cin>>current_box;
                mult = (mult%friends * current_box%friends) % friends;
            }
            sum += mult;
        }
        cout<<(sum%friends)<<endl;
    }
}

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