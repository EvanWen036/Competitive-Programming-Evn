#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int n, k;
void solve(){
    cin >> n >> k;
    if(k < n){
        cout << (n%2 == k%2 ? 0:1) << endl;
        return;
    }
    if(k >= n){
        cout << k - n << endl;
        return;
    }
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

