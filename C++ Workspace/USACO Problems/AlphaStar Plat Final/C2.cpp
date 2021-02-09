#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
int t[400005];

void build(int v, int l, int r){
    if(l == r){
        t[v] = 0;
    }
    else{
        build(v*2, l, (l+r)/2);
        build(v*2+1,(l+r)/2+1, r);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}
void update(int v, int l, int r, int index, int val){
    if(index < l || index > r)return;
    if(index == l && index == r){
        t[v] = val;
        return;
    }
    update(v*2, l, (l+r)/2, index, val);
    update(v*2+1, (l+r)/2+1, r, index, val);
    t[v] = max(t[2*v], t[2*v+1]);
}
int maxQuery(int v, int lr, int rr, int l, int r){
    //completely outside
    if(l > rr || r < lr)return -1;
    if(lr >= l && rr <= r){
        return t[v];
    }
    int tm = (lr+rr)/2;
    return max(maxQuery(2*v,lr,tm,l,r), maxQuery(2*v+1,tm+1,rr,l,r));
}
bool compare(const pii a, const pii &b){
    if(a.f == b.f){
        return a.s > b.s;
    }
    return a.f < b.f;
}
int main(){
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    int left[N];
    map<int,int> posLeft;
    for(int i = 0; i < N; i++){
        cin >> left[i];
        posLeft[left[i]] = i;
    }
    int right[N];
    map<int, int> posRight;
    for(int i = 0; i < N; i++){
        cin >> right[i];
        posRight[right[i]] = i;
    }
    vector<pii> v;
    for(int i = 0; i < N;i ++){
        for(int j = i-4; j <= i+4; j++){
            if(j >= 1 && j <= N){ 
                v.push_back(mp(posLeft[i], posRight[j]));
            }
        }
    }
    sort(v.begin(), v.end(), compare);
    //sort(v.begin, v.end(), compare);
    int ans = 0;
    //cout << "Hi" << endl;
    build(1,0, N-1);
    for(auto it : v){
        //cout << "HI" << endl;
        int prev = maxQuery(1,0,N-1,0,it.s-1);
        //cout << prev << endl;
        update(1,0, N-1,it.s, prev+1);
        ans = max(ans, prev+1);
        
    }
    cout << ans << endl;

}
