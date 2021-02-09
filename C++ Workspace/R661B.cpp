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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        ll minA = 1000000000;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            minA = min(minA, a[i]);
        }
        ll b[n];
        ll minB = 1000000000;
        for(int i = 0; i < n;i++){
            cin  >> b[i];
            minB = min(minB, b[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int as = a[i] -minA;
            int bs = b[i] - minB;
            int mini = min(as,bs);
            as-=mini;
            bs-=mini;
            ans += mini+as+bs;
        }
        cout << ans << endl;
    }


}

