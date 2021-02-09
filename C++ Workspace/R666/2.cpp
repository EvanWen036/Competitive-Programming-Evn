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
    long double n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    //take n-1 root of last value
    ll power = ceil(pow(1.0*a[n-1], 1.0/(n-1)));
    //cout << power << endl;
    ll curr = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i] - curr);
        cout << ans << endl;
        curr *= power;
    }
    //cuut << power << endl;
    power--;
    assert(power==floor(pow(1.0*a[n-1], 1.0/(n-1))));
    curr = 1;
    ll test = 0;
    for(int i = 0; i < n; i++){
        test += abs(a[i] - curr);
        curr *= power;
    }
    ans = min(ans, test);
    cout << ans << endl;
    
 
 
}
 
