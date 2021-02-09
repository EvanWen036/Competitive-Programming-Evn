#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> P(N+1);
    P[0] = make_pair(0, 0);
    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        P[i] = make_pair(a,i);
    }
    int edgeweight[N+1][N+1];
    for(int i =1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> edgeweight[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        edgeweight[0][i] = edgeweight[1][i];
    }
    sort(P.begin(), P.end());
    int ans[N+1];
    memset(ans, 0, sizeof(ans));
    ans[0] = 0;
    for(int i = 0; i <= N; i++){
        int time = P[i].first;
        //cout << P[i].second << " " << ans[P[i].second] << endl;
        for(int j = i+1; j <= N; j++){
            //cout << P[i].second << " " << P[j].secund << " " << edgeweight[P[i].second][P[j].second] << " " << time << endl;
            if(edgeweight[P[i].second][P[j].second] + time <= P[j].first){
                
                ans[P[j].second] = max(ans[P[j].second], ans[P[i].second] + 1);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < N; i++){
        answer = max(answer, ans[i]);
    }
    if(N==1)answer = 1;

    cout << answer << endl;

}

