#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
void solve(){
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    int bota = max(x, a-n);
    int botb = max(y, b-n);
    //int mini = min(a,b);
    if(bota < botb){
        //decrease a first
        int delta = min(a-x, n);
        a -= delta;
        n -= delta;
        if(n > 0){
            b -= min((b-y), n);
            //cout << a * b << endl;
            //return;
        }
        cout << a * b << endl;
    }
    else{
        //cout << b-y << " " << n << endl;
        int delta = min(b-y, n);
        b -= delta;
        n -= delta;
        //cout << n << endl;
        if( n > 0 ){
            a -= min((a-x), n);
            //cout << a * b << endl;
            //return;
        }

        cout << a * b << endl;
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

