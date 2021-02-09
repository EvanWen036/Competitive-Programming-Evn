#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    ll a, b;
    cin >> a >> b;
    if(b > a)swap(a,b);
    //a is bigger
    if(a%b != 0){
        cout << -1 << "\n";
        return;
    }
    ll rem = a/b;
    ll loge = (ll)log2(rem); 
    if((ll)pow(2,loge) != rem){
        cout << -1 << "\n";
        return;
    }
    ll ans = 0;
    ans += loge/3;
    loge %= 3;
    ans += loge/2;
    loge %= 2;
    ans += loge;
    cout << ans << "\n";
    //cout << loge << "\n";

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

