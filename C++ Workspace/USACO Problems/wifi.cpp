#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
long double cost(int l, int r, int A, long double B){
    double ans = B*((r-l)/2) + A;
    //cout << l << " " << r << " " << ans << endl;
    return ans;
}
int main(){
	freopen("wifi.in", "r", stdin);
	freopen("wifi.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, A;
    long double B;
    cin >> N >> A >> B;
    vector<int> pos(N);
    for(int i = 0; i < N;i ++){
        cin >> pos[i];
        pos[i]*=2;
    }
    sort(pos.begin(), pos.end());
    long double dp[N+1];
    for(int i = 1; i <= N; i++){
        dp[i] = 1000000000;
    }
    dp[0] = 0;
    B/=2;
    for(int i = 1; i <= N; i++){
        //cout << pos[i-1] << endl;
        for(int j = 0; j < i; j++){
            dp[i] = min(dp[i], dp[j] + cost(pos[j], pos[i-1], A, B));
        }
    }
    
    string ans = to_string(dp[N]);
    int deci = ans.find(".");
    if(ans[deci+1] == '5'){
        cout << ans.substr(0, deci+2);
        return 0;
    }
    cout << ans.substr(0, deci);
}

