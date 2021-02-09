#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
pair<long long, long long> t[400005];
long long lazy[400005];
void build(int a[], int v, int l, int r){
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
		t[v].first = (rr-lr+1) - t[v].first;
		t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] = !lazy[2*v];
            lazy[2 * v + 1] = !lazy[2*v+1];
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
void updateRange(int v, int lr, int rr, int l, int r, long long val){
	//cout << v << " " << lr << " " << rr << " " << l << " " << r << " " << val << "\n";
	if(lazy[v] != 0){
		t[v].first =  (rr-lr+1) - t[v].first;
		t[v].second += lazy[v];
		if (lr != rr) {                                     // update lazy[] for children nodes
            lazy[2 * v] = !lazy[2*v];
            lazy[2 * v + 1] = !lazy[2*v+1];
        }
		lazy[v] = 0;
	}
	if(lr > rr || l > rr || r < lr )return;
	if(l <= lr && r >= rr){		
        t[v].first = (rr-lr+1)-t[v].first;
		//t[v].second += val;
		//t[v].first += val;
		if(lr != rr){
			lazy[2*v] = !lazy[2*v];
			lazy[2*v+1] = !lazy[2*v+1];
		}
		return;
	}
	int tm = (lr+rr)/2;
	updateRange(2*v, lr, tm, l, r, val);
	updateRange(2*v+1, tm+1, rr, l ,r, val);
	t[v].first = t[2*v].first + t[2*v+1].first;
	//t[v].second = min(t[2*v].second, t[2*v+1].second);
}

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int zeroes[N];
    memset(zeroes, 0, sizeof(zeroes));
    build(zeroes, 1, 0, N-1);
    for(int i = 0; i < M; i++){
        int q;
        cin >> q;
        if(q == 1){
            int x, y;
            cin >> x >> y; x--; y--;
            cout << sum(1,0,N-1, x, y) << endl;
        }
        else{
            int x, y;
            cin >> x >> y; x--; y--;
            //int amt = sum(1,0,N-1, x, y);
            updateRange(1,0,N-1,x,y, 1);
        }
    }


}

