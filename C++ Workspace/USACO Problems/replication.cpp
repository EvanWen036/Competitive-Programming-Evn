    #include <bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
using namespace std;
int mat[1005][1005];
int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};
int rockdist[1005][1005];
bool vis[1005][1005];
bool canBeCenter[1005][1005];
int bfsDist2[1005][1005];
set<pii> centers[1005*1005];
int main() {
  int n, d;
  cin >> n >> d;
  queue<pii> q;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    for(int j = 0; j < n; j++){
      if(s[j] == '#'){
        mat[i][j] = 0;
        vis[i][j] = true;
        rockdist[i][j] = 0;
        q.push({i,j});
      }
      else if(s[j] == '.'){
        mat[i][j] = 1;
      }
      else{
        mat[i][j] = 2;
        
      }
    }
  }
  while(!q.empty()){
    pii top = q.front(); q.pop();
    for(int i = 0; i < 4;i ++){
      int newR = top.f + dr[i];
      int newC = top.s + dc[i];
      if(newR < 0 || newR >= n || newC < 0 || newC >= n || vis[newR][newC])continue;
      vis[newR][newC] = true;
      rockdist[newR][newC] = rockdist[top.f][top.s]+1;
      q.push({newR, newC});
    }
  }
  /**
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << rockdist[i][j] << " ";
    }
    cout << '\n';
  }
  **/

  memset(vis, false,sizeof(vis));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(mat[i][j] == 2){
        //cout << i << " " << j << '\n';
        q.push({i,j});
        vis[i][j] = true;
        canBeCenter[i][j] = true;
        bfsDist2[i][j] = 0;
      }
    }
  }
  while(!q.empty()){
    pii top = q.front(); q.pop();
    for(int i = 0; i < 4; i++){
      int newR = top.f + dr[i];
      int newC = top.s + dc[i];
      if(newR < 0 || newR >= n || newC < 0 || newC >= n || mat[newR][newC] == 0 || vis[newR][newC])continue;
      if(bfsDist2[top.f][top.s] < 1LL * d * rockdist[top.f][top.s] && bfsDist2[top.f][top.s]+1 <= 1LL * d * rockdist[newR][newC]){
        vis[newR][newC] = true;
        canBeCenter[newR][newC] = true;
        bfsDist2[newR][newC] = bfsDist2[top.f][top.s]+1;
        q.push({newR, newC});
      }
    }
  }
  memset(vis, false, sizeof(vis));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(canBeCenter[i][j]){
        centers[rockdist[i][j]-1].insert({i,j});
      }
    }
  }
  vector<pii> current;
  vector<pii> go;
  for(int i = n*n; i >= 0; i--){
      for(auto it : centers[i]){
          if(vis[it.f][it.s])continue;
          go.pb(it);
          vis[it.f][it.s] = true;
      }
      for(auto it : current){
          for(int i = 0; i < 4;i ++){
              int newR = it.f + dr[i];
              int newC = it.s + dc[i];
              if(newR < 0 || newR >= n || newC < 0 || newC >= n || vis[newR][newC])continue;
              go.pb({newR,newC});
              vis[newR][newC] = true;
          }
      }
      swap(go, current);
  }
  int ans = 0;
  //cout << bfsDist3[1][2] << '\n';
  //cout << closestCenter[1][2].f << " " << closestCenter[1][2].s << '\n';
  for(int i = 0; i < n;i ++){
    for(int j = 0;j < n; j++){
      if(mat[i][j] == 0)continue;
      
      if(vis[i][j]){
          ans++;
          //cout << i << " " << j << '\n';
      }
    }
  }

  cout << ans << '\n';

}