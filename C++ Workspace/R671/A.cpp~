#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
   int n;
   cin >> n;
   int s;
   cin >> s;
   if(n == 1){
        cout << (s+1)%2 + 1 << "\n";
        return;
   }
   string y = to_string(s);
   int cnt1 = 0;
   int cnt2 = 0;
   //int odds = 0;
   //int evens = 0;
   for(int i = 0; i < n;i ++){
      // if(i%2==0)odds++;
       //if(i%2==1)evens++;
       if(i % 2 == 0 && (y[i] - '0') % 2 == 1){
           cnt1++;
       }
       if(i % 2 == 1 && (y[i] - '0')%2 == 0){
           cnt2++;
       }
   }
   //cnt1 = odds - cnt1;
   //cnt2 = evens - cnt2;
   if(n%2==1)cnt2--;
   cout << (cnt2 >= cnt1 ? 2:1) << "\n";
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }


}

