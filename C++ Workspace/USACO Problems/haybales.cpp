#include <bits/stdc++.h>
#define ll long long;
#define MAXN 200000;
using namespace std;
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
long long sum(int v,int lr, int rr, int l, int r){
	if(r < lr || l > rr || lr > rr)return 0;
	if(lazy[v] != 0){
		t[v].first += (rr -lr+1) * lazy[v];
		t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
		lazy[v] = 0;
	}
	if(l <= lr && r >= rr){
		return t[v].first;
	}
	
	else{
		int tm = (lr + rr)/2;
		return sum(v*2, lr, tm, l, r) + sum(v*2+1, tm+1, rr, l, r);
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
int main(){
	
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q;
	cin >> n >> q;
	long long B[n];
	for(int i = 0; i < n; i++){
		cin >> B[i];
	}
	build(B, 1, 0, n-1);
	for(int i = 0; i < q; i++){
		char c;
		int lq, rq;
		cin >> c >> lq >> rq;
		lq--;
		rq--;
		if(c == 'S'){
			cout << sum(1, 0, n-1, lq,rq) << "\n";
		}
		else if(c == 'P'){
			long long addVal;
			cin >> addVal;
			updateRange(1,0,n-1,lq,rq,addVal);
		}
		else{
			cout << minimum(1,0,n-1,lq,rq) << "\n";
		}
	}

}