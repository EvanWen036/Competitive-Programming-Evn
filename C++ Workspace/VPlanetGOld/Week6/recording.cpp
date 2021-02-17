#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int,int>> cows;
int dp[155][155][155];
int main() {
 freopen("recording.in", "r", stdin);
 freopen("recording.out", "w", stdout);
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 cin >> N;
 for(int i = 0; i < N; i++){
   int a, b;
   cin >> a >> b;
   b--;
   cows.push_back({b,a});
 }
 sort(cows.begin(), cows.end());
 int ans = 0;
 for(int i = 1; i <= N;i ++){
   for(int s1=0; s1 <= i; s1++){
     for(int s2=0; s2 <= i; s2++){
       if(s1 == s2 && s1 == i)continue;
       if(i != s1 && i != s2){
         dp[i][s1][s2] = dp[i-1][s1][s2];
       }
       if(i == s1){
         for(int j = 0; j < i; j ++){
           if(j == 0){
              dp[i][s1][s2] = max(dp[i][s1][s2], 1 + dp[i-1][j][s2]);
             continue;
           }
           if(cows[i-1].second > cows[j-1].first){
             dp[i][s1][s2] = max(dp[i][s1][s2], 1 + dp[i-1][j][s2]);
           }
         }
       }
       if(i == s2){
         for(int j = 0;j < i; j++){
           if(j == 0){
             dp[i][s1][s2] = max(dp[i][s1][s2], 1 + dp[i-1][s1][j]);
           }
           if(cows[i-1].second > cows[j-1].first){
             dp[i][s1][s2] = max(dp[i][s1][s2], 1 + dp[i-1][s1][j]);
           }
         }
       }
       //cout << i << " " << s1 << " " << s2 << " " <<  dp[i][s1][s2] << '\n';
       ans = max(ans, dp[i][s1][s2]);
     }
   }
 }
 cout << ans << '\n';
}
