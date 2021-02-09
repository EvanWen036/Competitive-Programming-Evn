#include <bits/stdc++.h>
using namespace std;
#define pii pair<long double, long double>
#define x first
#define y second
#define int long double 
bool cw(pii a, pii b, pii c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pii a, pii b, pii c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}
signed main(){
  freopen("balance.in", "r", stdin);
  freopen("balance.out", "w", stdout);
  int N;
  cin >> N;
  vector<pii> pt(N+2);
  pt[0] = {0,0};
  pt[N+1] = {N+1, 0};
  for(int i =1;i <= N;i ++){
    int a; cin >> a;
    pt[i] = {i, a};
  }
  vector<pii> up, down;
  sort(pt.begin(), pt.end());
  up.push_back(pt[0]);
  down.push_back(pt[0]);
  for(int i  =1; i < (int)pt.size();i ++){
    if(i == pt.size()-1 || cw(pt[0], pt[i], pt[N+1])){
      while(up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], pt[i])){
        up.pop_back();
      }
      up.push_back(pt[i]);
    }
    if(i == pt.size()-1 || ccw(pt[0], pt[i], pt[N+1])){
      while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], pt[i])){
        down.pop_back();
      }
      down.push_back(pt[i]);
    }
  }
  cout << fixed << setprecision(0);
  for(int i = 0; i < (int)up.size()-1; i++){
    for(int curr = up[i].x; curr < up[i+1].x; curr++){
      if(curr == 0 || curr == N+1)continue;
      if(curr == up[i].x){
        cout << up[i].y*1e5 << "\n";
        continue;
      }
      long long xDiff = up[i+1].x - up[i].x;
      long long yDiff = up[i+1].y - up[i].y;
      //long double ans = (val+val2)*1e5;
      long long ans = 1e5 * yDiff * curr / xDiff + (1e5 * up[i].y - 1e5*up[i].x * yDiff/ xDiff);
      //cout << ans << "\n";
      cout << ans<< "\n";
    }
  }
}