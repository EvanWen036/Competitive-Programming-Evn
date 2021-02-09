#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
//update point p with val
ll BIT[100005];
void update(int pos, ll addVal){
    for(int i = pos; i <= 100000; i+= i&-i){
        BIT[i] += addVal;
    }
}
ll query(int ind){
    ll s = 0;
    for(int i = ind; i >= 1; i-=i&-i){
        s += BIT[i];
    }
    return s;
}
int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    ll N, L, C;
    cin >> N >> L >> C; 
    vector<ll> A(N);

    ll maxS = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        maxS = max(maxS, A[i]);   
    }
    pair<pair<long long, ll>,int> l[N];
    for(int i = 0; i < N; i++){
        l[i].f.f = floor(L*A[i]/maxS);
        l[i].f.s = (L*A[i] % maxS);
        l[i].second = i;
        //cout << l[i] << endl;
    }
    sort(l, l+N);
    //for(int i=  0; i < N; i++){
      //  l[i].first = floor(l[i].first);
    //}
    ll sum = 0;
    sum += l[0].first.f;
    ll ans = 0;
    for(int i = 1; i < N; i++){
        ans += (l[i].first.f * i)-sum;
        sum += l[i].first.f;
    }
    pair<ll, int> cows[N];
    for(int i = 0; i < N; i++){
        cows[i].first= (L*C*A[i]) % (C * maxS);
        cows[i].second = i;
    }
    sort(cows, cows+N);
    map<int, int> mp;
    map<int, int> mapping;
    for(int i = 0; i < N; i++){
        //cout << cows[i].first << " " << cows[i].second << endl;
            if(mapping.find(cows[i].first) == mapping.end()){
                mapping[cows[i].first] = i+1;
            }
            mp[cows[i].second] = mapping[cows[i].first];
    }
    //cout << " HI " << endl;
    memset(BIT, 0, sizeof(BIT));
    for(int i = N-1; i >= 0; i--){
        ans -= query(mp[l[i].second]-1);
        //cout << l[i].secund << endl;
        update(mp[l[i].second], 1);
        
    }
    cout << ans << endl;
}
