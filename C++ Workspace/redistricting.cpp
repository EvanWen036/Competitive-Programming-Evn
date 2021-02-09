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
int dp[300005];
int main(){
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n+1);
    for(int i = 1; i <= n;i ++){
        a[i] = s[i-1] == 'G' ? 1:-1;
        dp[i] = 1e8;
    }
    //cuut << "Hi" << endl;
    //dp[0] = 0;
    for(int i  =1;i <= n;i ++){
        //cout << i << endl;
        int sum = 0;
        for(int j =0;j < k && i - j > 0; j++){
            sum += a[i-j];
            if(sum >= 0){
                dp[i] = min(dp[i-j-1] + 1, dp[i]);
            }
            else{
                dp[i] = min(dp[i], dp[i-j-1]);
            }
        }
    }
    cout << dp[n] << "\n";

}

