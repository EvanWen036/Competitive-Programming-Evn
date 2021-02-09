#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    int val[N];
    map<int, int> lastSeen;
    int ans = -1;
    for(int i = 0; i < N;i ++){
        int a;
        cin >> a;
        val[i] = a;
        lastSeen[a] = -1;
    }
    for(int i = 0; i < N; i++){
        if(i - lastSeen[val[i]] <= K && lastSeen[val[i]] != -1){
            ans = max(ans, val[i]);
        }
        lastSeen[val[i]] = i;
    }
    cout << ans << endl;


}

