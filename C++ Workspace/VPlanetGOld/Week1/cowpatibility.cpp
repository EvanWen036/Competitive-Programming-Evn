#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mat[50005][5];
vector<vector<int>> subsets[6];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("cowpatibility.in", "r", stdin);
  freopen("cowpatibility.out", "w", stdout);
  int N;
  cin >> N;
  for(int i = 0; i < N;i ++){
    for(int j = 0;j < 5; j++){
      cin >> mat[i][j];
    }
  }
  for(int i = 1; i < 32; i++){
    int cnt = __builtin_popcount(i);
    vector<int> toggled;
    for(int j = 0;j < 5;j ++){
      if(i & (1 << j)){
        toggled.push_back(j);
      }
    }
    subsets[cnt].push_back(toggled);
  }
  ll ans = 0;
  for(int i = 1;i <= 5;i ++){
    //cout << subsets[i].size() << '\n';
    map<ll, int> cnt;
    for(int j = 0; j < subsets[i].size(); j++){
      vector<int> toggled = subsets[i][j];
      for(int k = 0;k < N;k ++){
        vector<int> curr;
        for(int u : toggled){
          curr.push_back(mat[k][u]);
        }
        //hash curr
        sort(curr.begin(), curr.end());
        ll hsh = 0;
        ll pow = 1000000007;
        for(int x = curr.size()-1; x >= 0; x--){
          hsh += pow * curr[x];
          hsh %= 100000000000000000+5379213821;
          pow *= 1000000007;
        }
        cnt[hsh]++;
      }
    }
    ll amt = 0;
    for(auto it : cnt){
      amt += 1LL * (it.second)*(it.second-1) / 2;
    }
    //cout << i << " " << amt << '\n';
    if(i % 2 == 0)ans -= amt;
    else{ans += amt;}
    assert(ans >= 0);
  }
  cout << 1LL * (N)*(N-1)/2 - ans << '\n';

}