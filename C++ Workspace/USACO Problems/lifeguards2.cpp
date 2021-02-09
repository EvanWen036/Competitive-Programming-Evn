#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int N, K;
pii interval[100005];
vector<pii> goodIntervals;
int firstIntersect[100005];
int dp[100005][105];
int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> a >> b;
        interval[i] = {a,b};
    }
    sort(interval, interval+N+1);
    int mx = -1;
    int badIntervals = 0;
    goodIntervals.pb({-1,-1});
    for(int i  = 1; i <= N; i++){
        bool bad = false;
        if(mx >= interval[i].s){
            bad = true;
            badIntervals++;
        }
        mx = max(mx, interval[i].s);
        if(!bad){
            goodIntervals.pb(interval[i]);
        }
    }
    /**
    for(auto it : goodIntervals){
        cout << it.f << " " << it.s << "\n";
    }**/
    //probably not needed
    sort(goodIntervals.begin(), goodIntervals.end());
    //calculate the first intersecting interval
    vector<tuple<int,int,int>> events;
    for(int i= 1; i < goodIntervals.size(); i++){
        //int a, b;
        events.pb(make_tuple(goodIntervals[i].f, 1,i));
        events.pb(make_tuple(goodIntervals[i].s, 0,i));
    }
    sort(events.begin(), events.end());
    queue<int> q;
    for(auto it : events){
        if(get<1>(it) == 1){
            q.push(get<2>(it));
            firstIntersect[get<2>(it)] = q.front();
        }
        else{
            q.pop();
        }
    }
    /**
    for(int i = 1; i < goodIntervals.size(); i++){
        cout << firstIntersect[i] << "\n"; 
    }**/
    K -= badIntervals;
    if(K < 0)K = 0;
    for(int i = 1; i < goodIntervals.size(); i++){
        for(int j = 0;j <= K; j++){
            if(j >= i)continue;
            if(j <= i-1){
                dp[i][j] = goodIntervals[i].s - goodIntervals[i].f;
            }
            if(firstIntersect[i] != 0){
                dp[i][j] = max(dp[i][j], dp[firstIntersect[i]][j - (i - firstIntersect[i] - 1)] +goodIntervals[i].s - goodIntervals[firstIntersect[i]].s);
            }
            int firstNoIntersect = firstIntersect[i]-1;
            if(firstNoIntersect == -1)firstNoIntersect = i-1;
            if(firstNoIntersect != 0){
                dp[i][j] = max(dp[i][j], goodIntervals[i].s - goodIntervals[i].f + dp[firstNoIntersect][j - (i - firstNoIntersect-1)]);
            }
            if(j != 0){
                dp[i][j] = max(dp[i-1][j-1], dp[i][j]);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    int ans = 0;
    for(int i = 1; i < goodIntervals.size(); i++){
        ans = max(ans, dp[i][K]);
    }
    cout << ans << endl;
}

