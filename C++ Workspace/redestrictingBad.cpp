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
int arr[300005];
int dp[300005];
int st[8 * 300005];
#define INF 1000000000
void build(int v, int l, int r){
    //cout << v<< " " << l << " " << r << endl;
    if(l == r){
        st[v] = INF;
        return;
    }
    int tm = (l+r)/2;
    build(2*v, l, tm);
    build(2*v+1, tm+1, r);
    st[v] = min(st[2*v], st[2*v+1]);
}
void update(int v, int l, int r, int idx, int val){
    if(l > idx || r < idx)return;
    if(l == idx && r == idx){
        if(val == INF){
            //cout << "hi" << endl;
            st[v] = INF;
            return;
        }
        assert(val != INF);
        //cout << "hi" << endl;
        st[v] = min(st[v], val);
        return;
    }
    int tm = (l+r)/2;
    update(2*v, l, tm, idx, val);
    update(2*v+1, tm+1, r, idx, val);
    st[v] = min(st[2*v+1], st[2*v]);
}
int query(int v, int lr, int rr, int l, int r){
    //cout << v << " " << lr << " " << rr << " " << l << " " << r << endl;
    if(l > rr || r < lr)return INF;
    if(lr >= l && rr <= r){
        return st[v];
    }
    int tm = (lr+rr)/2;
    return min(query(2*v, lr, tm, l, r), query(2*v+1, tm+1,rr, l, r));
}
int pref[300005];
//set<int> s[2 * 300005];
int main(){
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    pref[0] = N;
    multiset<int> sets[2*300005];
    for(int i= 1; i <= N; i++){
        arr[i] = s[i-1] == 'G' ? 1:-1;
        pref[i] = pref[i-1] + arr[i];
        assert(pref[i] >= 0 && pref[i] <= 2 * N);
        //cuut << arr[i] << " " << pref[i] << "\n";
        //cout << arr[i] << "  ";
        dp[i] = INF;
    }
    //cout << endl;
    build(1,0,2*N);
    dp[0] = 0;
    update(1,0,2*N,N,0);
    sets[N].insert(0);
    for(int i = 1; i <= N; i++){
        int cnt = 0;
        //cout << "hi" << endl;
        
        //cuut << "hi" << endl;
        int holstein = query(1,0,2*N,pref[i]+1, 2*N);
        int guernsey = query(1,0,2*N,0,pref[i])+1;
        //cuut << i << " " << holstein << " " << guernsey << endl;
        //cout << "hi" << endl;
        dp[i] = min(holstein, guernsey);
        //cuut << pref[i] << " " << dp[i] << "\n";
        //update(1,0,2*N,pref[i], dp[i]);
        if(i >= K){
            sets[pref[i-K]].erase(sets[pref[i-K]].find(dp[i-K]));
            int newValue = 0;
            if(sets[pref[i-K]].size() > 0){
                newValue = *sets[pref[i-K]].begin();
            }
            else{
                newValue = INF;
            }
            update(1,0,2*N, pref[i-K], INF);
            update(1, 0, 2*N, pref[i-K], newValue);
        }
        sets[pref[i]].insert(dp[i]);
        update(1,0,2*N, pref[i], dp[i]);
        //cuut << dp[i] << "\n";
    }
    cout << dp[N] << "\n";


}

