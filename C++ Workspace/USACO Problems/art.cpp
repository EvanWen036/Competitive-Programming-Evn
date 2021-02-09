#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N;
int mat[1005][1005];
int l[1005*1005];
int r[1005*1005];
int u[1005*1005];
int d[1005*1005];
int prefix[1005][1005];
bool cov[1005*1005];
int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
    bool works = false;
    bool works2 = false;
    int fi = -1;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> mat[i][j];
            if(fi == -1 && mat[i][j] != 0)fi = mat[i][j];
            if(mat[i][j] != 0 && mat[i][j] != fi)works2 = true; 
            if(mat[i][j] != 0)works = true;
        }
    }
    if(!works){
        cout << 0 << endl;
        return 0;
    }
    if(!works2){
        cout << N*N-1 << endl;
        return 0;
    }
    for(int i = 1; i <= N*N; i++){
        l[i] = 1000000;
        u[i] = 1000000;
    }
    vector<int> addEvents[N];
    vector<int> reEvents[N];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int curr = mat[i][j];
            l[curr] = min(l[curr], j);
            r[curr] = max(r[curr], j);
            u[curr] = min(u[curr], i);
            d[curr] = max(d[curr], i);
        }
    }
    for(int i = 1; i <= N * N; i++){
        //cout <<i << " " << l[i] << " " << r[i] << " " << u[i] << " " << d[i] << endl;
        if(l[i] != 1000000){
            //cout <<i << endl;
            prefix[u[i]][r[i]+1]--;
            prefix[u[i]][l[i]]++;
            prefix[d[i]+1][r[i]+1]++;
            prefix[d[i]+1][l[i]]--;
        }
    }
    for(int i =1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            //cout << prefix[i][j] << " ";
            prefix[i][j] += prefix[i-1][j];
            prefix[i][j] += prefix[i][j-1];
            prefix[i][j] -= prefix[i-1][j-1];
            //cout << prefix[i][j] << " ";
            if(prefix[i][j] > 1)cov[mat[i][j]] = true;
        }
        //cuut << endl;
    }
    int ans = 0;
    for(int i = 1; i <= N*N; i++){
        if(!cov[i]){
            ans++;
        }
    }
    cout << ans << endl;
    //int64_t hi; 


}

