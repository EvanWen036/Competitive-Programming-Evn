#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
set< pii > vis;
map< pii, int> mp;
int r = 1;
vector<vector<int>> adj;
void dfs(int i, int j){
    mp[make_pair(i,j)] = r;
    vis.insert(make_pair(i,j));
    for(auto x : adj){
        if(vis.count(x) == 0){
            dfs(x.first, x.second);
        }
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        for(int i = 0; i < n;i ++){
            string s;
            cin >> s;
            for(int j = 0; j < m;j ++){
                mat[i][j] = s[j] - 48;
            }
        }
        for(int i = 0; i < n;i ++){
            string s;
            cin >> s;
            vector<pii> temp;
            for(int j = 0; j < m; j++){
               if(s[j] == 'R'){
                   temp.push_back(make_pair(i,j+1));
               }
               if(s[j] == 'L'){
                   temp.push_back(make_pair(i,j-1));
               }
               if(s[j] == 'U'){
                   temp.push_back(make_pair(i-1,j));
               }
               else{
                   temp.push_back(make_pair(i+1,j));
               }
            }
        }
        for(int i = 0; i < n;i ++){
            for(int j = 0; j < m; j++){
                if(vis.count(make_pair(i,j)) == 0){
                    dfs(i,j);
                    r++;
                }
            }
        }
        for(int i = 0 ; i < n;i ++){
            for(int j = 0; j < m; j++){
                cout << mp[make_pair(i,j)] << " ";
            }
            cout << endl;
        }


    }


}

