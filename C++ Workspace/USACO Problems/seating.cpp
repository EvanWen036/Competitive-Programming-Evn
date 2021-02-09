#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int prefix[4*500005];
int suffix[4*500005];
int longest[4*500005];
int lazy[4*500005];
void build(int v, int l, int r){
    if(l == r){
        prefix[v] = 1;
        suffix[v] = 1;
        longest[v] = 1;
        lazy[v] = 0;
    }
    else{
        build(v*2, l, (l+r)/2);
        build(v*2+1, (l+r)/2+1, r);
        prefix[v] = prefix[2*v] + prefix[2*v+1];
        suffix[v] = suffix[2*v+1] + suffix[2*v];
        longest[v] = longest[2*v] + longest[2*v+1];
        lazy[v] = 0;
    }
}
void propogate(int v, int lr, int rr){
    if(lr == rr)return;
    if(lazy[v] == 1){
        prefix[v] = (rr-lr+1);
        suffix[v] = (rr-lr+1);
        longest[v] = (rr-lr+1);
        lazy[v] = 0;
        if(lr != rr){
            lazy[2*v] = 1;
            lazy[2*v+1] = 1;
        }
    }
    if(lazy[v] == 2){
        prefix[v] = 0;
        suffix[v] = 0;
        longest[v] = 0;
        lazy[v]= 0;
        if(lr != rr){
            lazy[2*v] = 2;
            lazy[2*v+1] = 2;
        }
    }
}
void merge(int v, int lr, int rr){
    int tm = (lr+rr)/2;
    prefix[v] = prefix[2*v] + (prefix[2*v] == (tm-lr+1) ? prefix[2*v+1]:0);
    suffix[v] = suffix[2*v+1] + (suffix[2*v+1] == (rr-tm) ? suffix[2*v]:0);
    longest[v] = max(max(longest[2*v+1], longest[2*v]), suffix[2*v] + prefix[2*v+1]);

}
//returns the first available place where there is a subarray of p empty seats
int walk(int v, int lr, int rr, int p){
    //cout << v << " " << prefix[v] << " " << suffix[v] << " " << longest[v] << endl;
    propogate(v, lr, rr);
    propogate(2*v, lr, (lr+rr)/2);
    propogate(2*v+1, (lr+rr)/2+1, rr);
    if(longest[2*v] >= p){
        return walk(2*v, lr, (lr+rr)/2, p);
    }
    if(suffix[2*v] + prefix[2*v+1] >= p){
        return ((lr+rr)/2 - suffix[2*v])+1;
    }
    return walk(2*v+1, (lr+rr)/2+1, rr, p);

}   
void updateRange(int v, int lr, int rr, int l, int r, int val){
    //cout << v << " " << lr << " " << rr << " " << l << " " << r <<  endl;
    propogate(v, lr, rr); 
    //no lazy now
    //if out of range
    if(lr > rr || l > rr || r < lr)return;
    if(l <= lr && r >= rr){
        //node is completely inside
        if(val == 1){
            //everything should be length
            prefix[v] = (rr-lr+1);
            suffix[v] = (rr-lr+1);
            longest[v] = (rr-lr+1);
            if(lr != rr){
                lazy[2*v] = 1;
                lazy[2*v+1] =  1;
            }
        }
        if(val == 2){
            //everything should be 0
            prefix[v] = 0;
            suffix[v] = 0;
            longest[v] = 0;
            if(lr != rr){
                lazy[2*v] = 2;
                lazy[2*v+1] = 2;
            }
        }
        return;
    }
    int tm = (lr + rr)/2;
    updateRange(2*v, lr, tm, l, r, val);
    updateRange(2*v+1, tm+1, rr, l, r, val);
    //merge
    propogate(2*v,lr,tm);
    propogate(2*v+1,tm+1,rr);
    merge(v, lr, rr);    
    //cout << v << " " << lr << " " << rr << " " << prefix[v] << " " << suffix[v] << " " << longest[v] << endl;
}
int main(){
    freopen("seating.in","r",stdin);
    freopen("seating.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int cnt = 0;
    build(1,0,N-1);
    for(int i= 0 ; i < M; i++){
        string s;
        cin >> s;
        if(s == "A"){
            //add a party of length x
            int x;
            cin >> x;
            if(longest[1] < x){
                cnt++;
                //cout << "FAIL" << endl;
                continue;
            }
            int pos = walk(1,0,N-1,x);
            //cout << pos << endl;
            updateRange(1,0,N-1,pos, pos+x-1, 2);
        }
        if(s == "L"){
            int a, b;
            cin >> a >> b; a--; b--;
            updateRange(1,0,N-1,a,b,1);
        }
    }
    cout << cnt << endl;


}

