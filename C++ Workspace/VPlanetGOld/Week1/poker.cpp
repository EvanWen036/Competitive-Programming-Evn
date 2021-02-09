#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("poker.in", "r", stdin);
  freopen("poker.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> A(n+1);
  for(int i = 1; i <= n; i++){
    cin >> A[i];
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++){
    ans += max(0, A[i] - A[i-1]);
  }
  cout << ans << '\n';
}