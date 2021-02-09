#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define int long long
typedef long long ll;
typedef pair<long long , long long> pii;
vector<pair<pii, pair<ll, bool>>> events;
map<int, int> redY;
ll ans[100005];
bool cmp(pair<pii, pair<ll, bool>> a, pair<pii,pair<ll,bool>> b){
    if(a.f.f == b.f.f){
        return a.s.s < b.s.s;
    }
    return a.f.f < b.f.f;
}
struct SegTree{
    ll t[800005];
    void build(int v, int l, int r){
        //cout << v << " " << l << " " << r << endl;
        if(l == r){
            t[v] = 10000000000000;
            return;
        }
        int tm = (l+r)/2;
        build(2*v, l, tm);
        build(2*v+1, tm+1, r);
        t[v] = min(t[2*v], t[2*v+1]);
    }
    void update(int v, int l, int r, int pos, ll val){
        //cout << v << " " << l << " " << r << " " << pos << " " << val << endl;
        if(pos > r || pos < l)return;
        if(l == pos && r == pos){
            t[v] = min(t[v], val);
            return;
        }
        int tm = (l+r)/2;
        update(2*v, l, tm, pos, val);
        update(2*v+1,tm+1, r, pos, val);
        t[v] = min(t[2*v], t[2*v+1]);
    }
    ll query(int v, int lr, int rr, int l, int r){
        //out of range
        if(l > rr || r < lr)return 10000000000000;
        if(lr >= l && rr <= r){
            return t[v];
        }
        int tm = (lr + rr)/2;
        return min(query(2*v,lr,tm,l,r),query(2*v+1,tm+1,rr,l,r));
    }
};

signed main(){
    freopen("slingshot.in" ,"r", stdin);
    freopen("slingshot.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
    cin >> N >> M;
    set<int> y;
    for(int i = 0; i < N;i ++){
        ll a, b, c;
        cin >> a >> b >> c;
        y.insert(b);
        events.pb({{a,b},{c,false}});
    }
    for(int i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        y.insert(b);
        events.pb({{a,b},{i,true}});
    }
    //cuut << "hi" << endl;
    int cr = 0;
    for(auto it : y){
        redY[it] = ++cr;
    }
    assert(cr <= 200005);
    SegTree leftUp;
    SegTree leftDown;
    leftUp.build(1, 1, 200005);
    leftDown.build(1,1,200005);
    sort(events.begin(), events.end());
    //cout << "hi" << endl;
    for(auto it : events){
        //cout << "hi" << endl;
        if(it.s.s){
            //query time
            ll q1 = leftDown.query(1,1,200005, 1, redY[it.f.s]);
            //cout << q1 << endl;
            q1 += it.f.f + it.f.s;
            ll q2 = leftUp.query(1,1,200005, redY[it.f.s], 200005) + (it.f.f - it.f.s);

            ans[it.s.f] = min(min(q1, q2), abs(it.f.s - it.f.f));
            //cout << it.s.f << " " << ans[it.s.f] << endl;
        }
        else{
            //update 
            leftUp.update(1,1,200005, redY[it.f.s], it.f.s - it.f.f + it.s.f);
            leftDown.update(1,1,200005, redY[it.f.s], -1 * it.f.s - it.f.f + it.s.f);
        }
    }
    leftUp.build(1,1,200005);
    leftDown.build(1,1,200005);
    for(int i = events.size() -1;i >= 0; i--){
        pair<pii, pair<ll, bool>> it = events[i];
        if(it.s.s){
            //query
            ll q1 = leftDown.query(1,1,200005, 1, redY[it.f.s]) + (-1 * it.f.f + it.f.s);
            ll q2 = leftUp.query(1,1,200005, redY[it.f.s], 200005) + (-1 * it.f.f - it.f.s);
            ll tmp = min(q1, q2);
            //cout << it.s.f << " " << tmp << "\n";
            ans[it.s.f] = min(ans[it.s.f], tmp);
        }
        else{
            //update
            leftUp.update(1,1,200005, redY[it.f.s], it.f.s + it.f.f + it.s.f);
            leftDown.update(1,1,200005, redY[it.f.s], it.f.f - it.f.s + it.s.f);
        }
    }
    for(int i = 0; i < M; i++){
        cout << ans[i] << "\n";
    }


}

