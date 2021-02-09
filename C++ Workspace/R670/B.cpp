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
    vector<ll> a(n);
    vector<ll> pos;
    //int neg = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] >= 0)pos.pb(a[i]);
        //else{pos.pb(a[i]);}
    }
    //if(neg % 2 == 1)neg--;
    vector<ll> negatives;
    for(int i = 0; i < n;i ++){
        if(a[i] < 0)negatives.pb(a[i]);
    }
    sort(negatives.begin(), negatives.end());
    sort(pos.begin(), pos.end(), greater<int>());
    ll ans = -1000000000000000000;
    //amt uf negatives we take
    //cout << pos.size() << endl;
    for(int i=  0; i <= 5; i++){
        ll curr = 1;
        int cnt = 0;
        if(i % 2 == 1){
            //take smaller negatives
            for(int j = negatives.size() -1; cnt < i && j >= 0; j--){
                curr *= negatives[j];
                cnt++;
            }
        }
        else{
            for(int j = 0; j < (int)negatives.size() && j < i; j ++){
                curr *= negatives[j];
                cnt++;
            }
        }
        //if(cnt %  2 == 1)continue;
        for(int j = 0;j < (int)pos.size() && j < 5-i; j++){
            curr *= pos[j];
            cnt++;
        }
        if(cnt != 5)continue;
        cout <<cnt << " " << curr << "\n";
        ans = max(ans, curr);
    }
    cout << ans << "\n";

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

