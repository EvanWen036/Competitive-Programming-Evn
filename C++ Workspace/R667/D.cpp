#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
ll po[20];
void solve(){
    ll n, s;
    cin >> n >> s;
    ll currSum = 0;
    ll temp = n;
    while(n > 0){
        currSum += n%10;
        n /= 10;
    }
    ll curr = 0;
    int dig = 0;
    ll ans = 1e18 + 500;
    bool done = false;
    po[0] = 1;
    for(int i =1; i <= 18; i++){
        po[i] = po[i-1] * 10;
    }
    //cout << po[18] << endl;
    if(currSum <= s){
        cout << 0 << endl;
        return;
    }
    while(temp >= 0 && !done){
        if(temp ==0)done=true;
        ll pref = currSum;
        //cout << currSum << " " << curr  << " " << dig << " " << pow(10,dig) <<  endl;
        ll cnt = po[dig] - curr;
        if(pref < s && cnt >= 0){
            ans = min(ans, cnt);
        }
        //dig++;
        //cout << curr << " " << temp%10 << " " << pow(10,dig) << " " << temp%10 * pow(10,dig) << " " << curr + temp%10 * pow(10,dig) << endl;
        curr  += (temp%10) * po[dig];
        //cout << curr << endl;
        currSum -= temp%10;
        temp /= 10;
        dig++;
        //get it to just pref
    }
    cout << ans << endl;

    
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

