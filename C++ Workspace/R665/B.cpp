#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> x(3);
vector<int> y(3);
void solve(){
    for(int i = 0; i < 3; i++){
        cin >> x[i];
    }
    for(int i =0; i < 3; i++){
        cin >> y[i];
    }
    //make 2 1 pairings
    int ans = 0;
    //int x = 0;
    int mini = min(x[2], y[1]);
    ans += 2 * mini;
    x[2] -= mini;
    y[1] -= mini;
    //make 1 0 and 2 0 pairings
    mini = min(x[1], y[0]);
    x[1] -= mini;
    y[0] -= mini;
    mini = min(x[2], y[0]);
    x[2] -= mini;
    y[0] -= mini;
    //make 0 0 1 1 2 2 pairings
    for(int i = 0; i <= 2; i++){
        mini = min(x[i], y[i]);
        x[i] -= mini;
        y[i] -= mini;
    }
    ans -= 2 * min(x[1], y[2]);
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

