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
struct SegmentTree{
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
		    t[v].second = max(t[v*2].second, t[v*2+1].second);
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
    long long maximum(int v, int lr, int rr, int l, int r){
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
    	return max(maximum(2*v, lr, tm, l, r), maximum(2*v+1, tm+1, rr, l, r));
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
  
};
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    pii cp[N];//build(dist, skipDist, 1, 0, N-1);

    for(int i =0;i < N; i++){
        cin >> cp[i].f >> cp[i].s;
    }
    int dist[N-1];
    for(int i = 0;i  < N-1; i++){
        dist[i] = abs(cp[i+1].s-cp[i].s) + abs(cp[i+1].f-cp[i].f);
    }
    int skipDist[N-1];
    skipDist[0] = 0;
    for(int i = 1; i < N-1; i++){
        skipDist[i] = abs(cp[i+1].s-cp[i-1].s) + abs(cp[i+1].f-cp[i-1].f) - dist[i-1] - dist[i];
    }
    SegmentTree s;
    s.build(dist, 1, 0, N-1);
    SegmentTree d;
    d.build(skipDist,1,1,N-2);
    for(int i = 0; i < Q; i++){
        string c;
        cin >> c;
        if(c=="U"){
            //update
            int j, x, y;
            cin >>j >> x >> y;
            //update the distances
            j--;
            cp[j].f = x;
            cp[j].s = x;
            for(int x = j; x >= j-1; x--){
                int org = dist[x];
                dist[x] = abs(cp[x+1].s-cp[x].s) + abs(cp[x+1].f-cp[x].f);
                s.updateRange(1,0,N-1,j, j, dist[x]-org);
            }
            for(int x =  j+1; 
        }
        else{
            int l ,r;
            cin >> l >> r;
            cout << s.sum(1,0,N-1,l,r) - d.maximum(1,1,N-2, l+1, r-1);
        }
    }

}

