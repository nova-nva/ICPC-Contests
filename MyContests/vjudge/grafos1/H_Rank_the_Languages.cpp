// Not sent

#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define forit(i, str) for(auto i = str.begin(); i != str.end(); i++)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define all(v) (v).begin(),(v).end()
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define ii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
using namespace std;

int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int n, m;
char mapa[5000][5000];
bool visited[5000][5000];
int cont = 1;

void dfs(int i, int j){
	forn(k, 4){
		int ni = i + di[k];
		int nj = j + dj[k];
		if(ni < n and ni >= 0 and nj < m and nj >= 0 and mapa[i][j] == mapa[ni][nj] and !visited[ni][nj]){
			visited[ni][nj] = true;
			dfs(ni, nj);
		}
	}
}

bool cmp(pair<char, int> a, pair<char, int> b){
	if(a.F == b.F){
		return a.S < b.S;
	}
	return a.F > b.F;
}

void solve(){
//	int n, m; 
	cin>>n>>m;
//	char mp[n][m];
	forn(i, n){
		string a; cin>>a;
		forn(j, m) mapa[i][j] = a[j], visited[i][j] = 0;
	}
	pair<int, char> dat[26];
	forn(i, 26){
		dat[i] = mp(0, 'a' + i);
	}
	forn(i, n){
		forn(j, m){
//			cout<<visited[i][j];
			if(!visited[i][j]){
				dat[mapa[i][j] - 'a'].F++;
				visited[i][j] = true;
				dfs(i, j);
			}
		}
//		cout<<endl;
	}
    cout<<"DAT Before: "<<endl;
    for(int x = 0; x<26; x++){
        cout<<dat[x].F<<": "<<dat[x].S<<endl;
    }
    cout<<endl;
	sort(dat, dat + 26);
    cout<<"DAT After: "<<endl;
    for(int x = 0; x<26; x++){
        cout<<dat[x].F<<": "<<dat[x].S<<endl;
    }
    cout<<endl;
	cout<<"World #"<<cont++<<endl;
	forn(i, 26){
		if(dat[i].F == 0) break;
		cout<<dat[i].S<<": "<<dat[i].F<<endl;
	}
} 

int main(){
	FastIO;
	int t; cin>>t;
	while(t--){
		solve();
	}
}