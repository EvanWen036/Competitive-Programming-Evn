#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	freopen("bbreeds.in","r",stdin);
	freopen("bbreeds.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    string s;
    cin >> s;
    int l = s.length();
    int balance[l+5];
    memset(balance, 0, sizeof(balance));
    for(int i = 1; i <= l; i++){
        int add = (s[i-1] == '(' ? 1:-1);
        balance[i] = balance[i-1] + add;
    }
    int dp[l+5][1005];
    for(int i = 0; i <= l; i++){
        for(int j = 0;j <= l;j ++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int i = 1; i <= l; i++){
        //next one is a holstein
        int add = (s[i-1] == '(' ? 1:-1);
        //cout << add << endl;
        for(int j = 0; j <= l;j ++){
            if(j+add >= 0){
                dp[i][j+add] += dp[i-1][j];
                dp[i][j+add] %= 2012;
            }
            if(balance[i]-j>=0){
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= 2012;
            }
        }
        
        
    }
    cout << dp[l][0];
    


}

