#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
vector<int> adj[100005];
int dp[100005];
bool works = true;
void dfs(int v, int p, int K){
    set<int> s;
    for(int u : adj[v]){
        if(u != p){
            dfs(u, v, K);
            s.insert(1 + dp[u]);
        }
    }
    if(v != 0 && adj[v].size() ==1){
        //leaf
        dp[v] = 0;
        return;
    }
    if(works == false){
        return;
    }
    int children = adj[v].size()-1;
    //int rem = 0;
    //cout << " HI " << s.size() << endl;
    
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){
        if(it == --s.end() || (*(next(it,1)) >= K && children == 2 && v != 0)){
            dp[v] = *it;
            return;
        }
        //cout << "HI" << endl;
        //not the last
        //--it;
        if(K == 5 && v == 0){
            cout << *it << " " << *s.lower_bound(K-(*it)) << endl;
        }
        if(s.lower_bound(K-(*it)) == s.end()){
            works = false;
            return;
        }
        s.erase(s.lower_bound(K-(*it)));
        children -= 2;
        //s.erase(*it);
        //cout << "hi" << endl;
    }
    if(s.lower_bound(K-1) != s.end() && v == 0){
        works = false;
        return;
    }
    dp[v] = *s.rbegin();
    return;


    
    
}
int main(){

	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--; adj[a].pb(b); adj[b].pb(a);
    }
    int low = 1;
    int high = N;
    int ans = 0;
    while(low != high){
        int mid = (low+high+1)/2;
        //cout << mid << endl;
        dfs(0,-1,mid);
        if(works){
            low = mid;
            ans =max(ans,mid);
        }
        else{
            high = mid-1;
        }
        //cout << mid << endl;
        //for(int i = 0; i < N; i++){
          //  cout  << dp[i] << " ";
        //}
        //cout << endl;
        works = true;
    }
    cout << low <<  endl;
}

