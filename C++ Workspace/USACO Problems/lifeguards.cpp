#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<long long, long long> pii;
int N, K;
vector<pii> intervals;
vector<pii> goodIntervals;
bool fire[100005][105];

ll dp[100005][105];
ll maxD[105];
int search(int j, int k){
    for(int i = k; i < j && i <= (int)goodIntervals.size(); i++){
        if(goodIntervals[i-1].s > goodIntervals[j-1].f){
            return i;
        }
    }
    return -1;
}
int search2(int j, int k){
    int mx = -1;
    for(int i = 1; i < j  && i <= (int)goodIntervals.size(); i++){
        if(goodIntervals[j-1].f > goodIntervals[i-1].s && i >= k){
            mx = i;
        }
    }
    return mx;
}
int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        ll l, r; cin >> l >> r;
        intervals.pb(mp(l,r));
        //cout << l << " " << r << endl;
    }
    sort(intervals.begin(), intervals.end());
    /**
    for(int i = 0; i < N;i ++){
        cout << intervals[i].f << " " << intervals[i].s << "\n";    
    }
    **/
    int cnt = 0;
    ll mx = -1;     
    for(int i = 0; i < N; i++){
        bool bad = false;
        //cuut << intervals[i].f << " " << intervals[i].s << endl;
        if(intervals[i].s <= mx){
            //this interval is bad
            bad = true;
            cnt++;
        }
        mx = max(mx, intervals[i].s);
        if(!bad){
            goodIntervals.pb(intervals[i]);
            //cout << goodIntervals.back().f << " " << goodIntervals.back().s << endl;
        }   
    }
    sort(goodIntervals.begin(), goodIntervals.end());
    memset(dp, 0, sizeof(dp));
    //subtract uut the bad intervals we dun't need
    K -= cnt;
    //cout << N << " " << goodIntervals.size() << " " << K << endl;
    K = max(0, K);
    //assert(K >= 0);
    for(int i = 1; i <= (int)goodIntervals.size();i ++){
        for(int j = 0; j <= K; j++){
            //first interval
            //if(j == 1){
            //no way to fire more than there are
            if(j > i){
                fire[i][j] = true;
                continue;
            }
            if(i == j){
                //must fire this lifeguard
                dp[i][j] = dp[i-1][j-1];
                fire[i][j] = true;
                continue;
            }
            dp[i][j] = goodIntervals[i-1].s - goodIntervals[i-1].f;         
            int se = search(i, j);
            //cout << se << endl;
            //cout << i << " " << se << endl;
            if(se != -1){
                assert(goodIntervals[se-1].s > goodIntervals[i-1].f);
                if(!fire[se][j]){
                    dp[i][j] = max(dp[i][j], dp[se][j] + (goodIntervals[i-1].s - goodIntervals[se-1].s));
                }
                else{
                    dp[i][j] = max(dp[i][j], dp[se][j] + (goodIntervals[i-1].s - goodIntervals[i-1].f));
                }
            }
            se = search2(i, j); 
            if(se != 0){
                assert(goodIntervals[se-1].s <= goodIntervals[i-1].f);
                //cout << se << " " << j << endl;
                dp[i][j] = max(dp[i][j], dp[se][j] + (goodIntervals[i-1].s - goodIntervals[i-1].f));
                
            }
            if(j != 0){
                //dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                if(dp[i-1][j-1] > dp[i][j]){
                    dp[i][j] = dp[i-1][j-1];
                    fire[i][j] = true;
                }
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    cout << dp[goodIntervals.size()][K] << endl;



}

