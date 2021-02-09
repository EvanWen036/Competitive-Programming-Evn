#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m, k;
  cin >> n >> m >> k;
  vector<int> p(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
  }
  multiset<int> ms;
  for(int i = 0; i < m; i++){
    int x;
    cin >> x;
    ms.insert(x);
  }
  sort(p.begin(), p.end());
  int ans = 0;
  for(int i = 0; i < n; i++){
    multiset<int>::iterator it = ms.lower_bound(p[i]-k);
    if(it != ms.end() && *it <= p[i] + k){
      ans++;
      ms.erase(it);
    }
  }
  cout << ans << endl;	


}

