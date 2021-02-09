#include <bits/stdc++.h>
using namespace std;
int findCost(string s, string s2){
  int cost = 0;
  for(int i  = 0; i < s2.length(); i++){
    if(s[i] == '0' && s2[i] == '1')cost++;
    if(s[i] == '1' && s2[i] == '0')return -1;
  }
  return cost;
}
long long ans = -1;
int cost[2005][10];
int n,k;
set<string> s;
//int dp[2005][2005];
string curr[2005];
bool vis[2005][2005];
void dp(int used, int curk){
    if(used == n){
    //cout << curr << endl;
    if(curk != 0)return;
    string currS = "";
    for(int i = 0; i < n; i++){
        cout << curr[i];
    }
    exit(0);
    
  }
  
  if(vis[used][curk])return;
 
  for(int i = 9; i >= 0; i--){
    if(cost[used][i] != -1 && cost[used][i] <= curk){
          curr[used] = to_string(i);
          dp(used+1, curk - cost[used][i]);
                  
    }
  }
  vis[used][curk] = true;
}
int main() {
  cin >> n >> k;
  string s[n];
  for(int i = 0; i < n;i ++){
    cin >> s[i];
  }
  string num[11];
  num[0] = "1110111";
  num[1] = "0010010";
  num[2] = "1011101";
  num[3] = "1011011";
  num[4] = "0111010";
  num[5] = "1101011";
  num[6] = "1101111";
  num[7] = "1010010";
  num[8] = "1111111";
  num[9] = "1111011";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 10; j++){
      cost[i][j] = findCost(s[i], num[j]);
      //cout << cost[i][j] << " ";
    }
    //cout << endl;
  }
  memset(vis, false, sizeof(vis));
  dp(0, k);
  cout << ans;
}
