#include <bits/stdc++.h>    
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, K;
vector<int> adj[100005];
vector<int> preset(100005);
ll dp[100005][4];
ll MOD = 1000000007;
ll calc(int currNode, int currentColor, int prevNode){
    //cout << currNode << endl;
    if(dp[currNode][currentColor] == -1){
        //cout << "Hello" << endl;
        if(preset[currNode] != 0 && preset[currNode] != currentColor)return 0;
        //cout << "Sup" << endl; 
        ll sum = 1;
        for(int u : adj[currNode]){
            //cout << "HI" << endl;
            if(u == prevNode)continue;
            ll curr = 0;
            for(int i = 1; i <= 3; i++){
                if(i != currentColor){
                    curr += calc(u, i, currNode);
                    curr %= MOD;
                }
            }
            sum = (sum * curr) % MOD;
        }
        dp[currNode][currentColor] = sum;
    }
    return dp[currNode][currentColor];
}
int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> N >> K;
    cout << "hi\n";
    for(int i =0 ; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i =0; i < N; i++){
        preset[i] = 0;
        for(int j=1; j<=3; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i < K; i++){
        int a, b;
        cin >> a >> b;
        a--;
        preset[a] = b;
    }
    
     cout << (calc(0, 1, -1) + calc(0, 2, -1) + calc(0, 3, -1))%MOD;
           
}

