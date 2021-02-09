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
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    string s;
    cin >> s;
    int dp[N+1];
    dp[0] = 0;
    dp[1] = a[0];
    for(int i = 2; i <= N; i++){
        if(s[i-2] == '1'){
            dp[i] = max(a[i-1], dp[i-1]);
            dp[i-1] = min(a[i-1], dp[i-1]);
        }
        else{
            if(a[i-1] < dp[i-1]){
                cout << "No" << endl;
                return 0;
            }
            dp[i] = a[i-1];
        }
        //cout << i << " " << dp[i] << endl;
    }
    cout << (dp[N] == N ? "Yes":"Nu");
    

}

