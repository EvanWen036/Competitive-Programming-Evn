#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int n;
string s;
void solve(){
    cin >> n >> s;
    string ans = "";
    int curr = 0;
    for(int len = 0; len < n; len++){
        ans += s[len + curr];
        curr++;
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

