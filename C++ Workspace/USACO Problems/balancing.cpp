#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
struct SegTree{
    int t[4000000];
    void build(int v, int l, int r){
        if(l == r){
            t[v] = 0;
            return;
        }
        int tm = (l+r)/2;
        build(2*v, l, tm);
        build(2*v+1, tm+1, r);
    }
    void update(int v, int l, int r, int idx, int val){
        //cout << v << " " << l <<" " << r << idx << endl;
        if(idx < l || idx > r)return;
        if(l == idx && r == l){
            t[v] += val;
            return;
        }
        int tm = (l+r)/2;
        update(2*v, l, tm, idx, val);
        update(2*v+1, tm+1, r, idx, val);
        t[v] = t[2*v] + t[2*v+1];
    }
    int query(int v, int lr, int rr, int l, int r){
        if(l > rr || r < lr){
            return 0;
        }
        if(lr >= l && rr <= r){
            return t[v];
        }
        int tm = (lr+rr)/2;
        return query(2*v, lr, tm, l, r) + query(2*v+1, tm+1, rr, l, r);

    }
};
//SegTree right;
//SegTree left;
pair<int, int> pt[100005];
int ans = 100005;
int main(){
    
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i= 0 ; i < N; i++){
        cin >> pt[i].f >> pt[i].s;
    }
    sort(pt, pt+N);
    /**
    for(int i = 0; i < N;i ++){
        //cout << pt[i].f << " " << pt[i].s << endl;
    }**/
    //cout << "hi" << endl;
    SegTree left;
    SegTree right;
    right.build(1, 0, 1000000);
    left.build(1, 0, 1000000);
    //cout << "hi" << endl;
    for(int i = 0; i < N;i ++){
        right.update(1, 0, 1000000, pt[i].s, 1);
    }
    //cout << right.t[0] << endl;
    //cout << right.query(1,0,1000000, 0, 1000) << endl;
    for(int i =1; i < N; i++){
        left.update(1,0,1000000, pt[i-1].s, 1);
        right.update(1,0,1000000,pt[i-1].s, -1);
        //bsearch on where the x line should be
        int l = 0;
        int h = 1000000;
        
        while(l < h){
            int mid = (l+h)/2;
            int ul = left.query(1,0,1000000, mid, 1000000);
            int ll = left.query(1,0,1000000,0,mid-1);
            int ur = right.query(1,0,1000000, mid, 1000000);
            int lr = right.query(1,0,1000000, 0, mid-1);
            //max(ul, ur) gets bigger as mid goes down 
            //max(ll, lr) gets bigger as mid goes up
            int max1 = max(ul, ur);
            int max2 = max(ll, lr);
            if(max1 == max2){
                ans = min(ans, max(max1, max2));
                break;
            }
            if(max2 > max1){
                //go down
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
    }
    cout << ans << endl;
    
}

