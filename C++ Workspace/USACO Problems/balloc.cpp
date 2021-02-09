#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
pair<long long, long long> t[800005];
long long lazy[800005];
void build(long long a[], int v, int l, int r){
	if(l == r){
		t[v].first = a[l];
		t[v].second = a[l];
	}
	else{
		int mid = (l+r)/2;
		build(a, v*2, l, mid);
		build(a, v*2+1, mid + 1, r);
		t[v].first = t[v*2].first + t[v*2+1].first;
		t[v].second = min(t[v*2].second, t[v*2+1].second);
	}
}
long long minimum(int v, int lr, int rr, int l, int r){
	if(r < lr || l > rr || lr > rr)return 1000000000;
	if(lazy[v] != 0){
		t[v].first += (rr-lr+1)*lazy[v];
		t[v].second += lazy[v];
		if(lr != rr){
			lazy[2*v] += lazy[v];
			lazy[2*v+1] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(l <= lr && r >= rr){
		return t[v].second;
	}
	
	int tm = (lr + rr)/2;
	return min(minimum(2*v, lr, tm, l, r), minimum(2*v+1, tm+1, rr, l, r));
}
void updateRange(int v, int lr, int rr, int l, int r, long long val){
	//cout << v << " " << lr << " " << rr << " " << l << " " << r << " " << val << "\n";
	if(lazy[v] != 0){
		t[v].first += (rr -lr+1) * lazy[v];
		t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
		lazy[v] = 0;
	}
	if(lr > rr || l > rr || r < lr )return;
	if(l <= lr && r >= rr){
		t[v].first += (rr - lr+1) * val;
		t[v].second += val;
		//t[v].first += val;
		if(lr != rr){
			lazy[2*v] += val;
			lazy[2*v+1] += val;
		}
		return;
	}
	int tm = (lr+rr)/2;
	updateRange(2*v, lr, tm, l, r, val);
	updateRange(2*v+1, tm+1, rr, l ,r, val);
	t[v].first = t[2*v].first + t[2*v+1].first;
	t[v].second = min(t[2*v].second, t[2*v+1].second);
}
bool compare(const pii a, const pii b){
    if(a.s == b.s){
        return a.f > b.f;
    }
    return a.s < b.s;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int M;
    cin >> M;
    ll B[N];
    for(int i = 0; i < N ;i++){
        cin >> B[i];
    }
    build(B,1,0,N-1);
    vector<pii> ranges(M);
    vector<pair<pii, int>> events;
    for(int i = 0; i < M; i++){
        int l, r;
        cin >> l >> r; l--; r--;
        ranges[i] = mp(l,r);    
    }
    sort(ranges.begin(), ranges.end(), compare);
    //vector<pair<pii,int>> events;
    for(int i = 0; i < M; i++){
        //cout << ranges[i].f << " " << ranges[i].s << endl;
        //events.push_back(mp(mp(ranges[i].f, 1));
        //events.push_back(mp(ranges[i].s, 0));
    }
    sort(events.begin(), events.end());
    int ans = 0;
   // int running = 0;
    //stack<pii> active;
    //stack<pii> stack;
    for(auto it: ranges){
        if(minimum(1,0,N-1,it.f, it.s) > 0){
            ans ++;
            updateRange(1,0,N-1,it.f,it.s,-1);
        }
    }
    cout << ans << endl;
}
