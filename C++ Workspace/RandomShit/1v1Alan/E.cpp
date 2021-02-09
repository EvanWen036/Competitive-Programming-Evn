#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int cnt[4];
void solve(){
    int n; cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n;i ++){
        if(s[i] == 'R')cnt[0]++;
        else if(s[i] == 'P')cnt[1]++;
        else{cnt[2]++;}
    }
    int ans = 0;
    ans += min(b, cnt[0]);
    ans += min(c, cnt[1]);
    ans += min(a, cnt[2]);
    if(ans >= (n+1)/2){
        cout << "Yes\n";
        vector<string> ans(n);
        for(int i = 0; i < n; i++){
            if(s[i] == 'R' && b){ans[i] = "P"; b--;}
            if(s[i] == 'P' && c){ans[i] = "S"; c--;}
            if(s[i] == 'S' && a){ans[i] = "R"; a--;}
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == ""){
                if(a > 0){cout << "R";a--;}
                else if(b> 0){ cout << "P"; b--;}
                else{cout << "S"; c--;}
            }
            else{
                cout << ans[i] << " ";
            }
        }
        cout << "\n";
    }
    else{
        cout << "No" << "\n";
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

