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
int pts[2005];
bool solved[2005][2005];
int cnt[2005];
bool cmp(pii a, pii b){
    if(a.f == b.f){
        if(cnt[a.f] == cnt[b.f]){
            return a.s < b.s;
        }
        return cnt[a.f] > cnt[b.f];
    }
    return a.f > b.f;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, k, p;
    cin >> n >> k >> p;
    
    for(int i =0; i < n; i++){
        for(int j = 0; j < k;j ++){
            int x;cin >> x;
            if(x == 0){
                pts[j]++;
            }
            else{
                solved[i][j] = true;
                cnt[i]++;
            }
        }
    }
        vector<pii> standings;
    for(int i = 0; i < n; i++){
        int score = 0;
        for(int j = 0; j < k; j++){
            if(solved[i][j])score += pts[j];
        }
        standings.pb({score, i+1});
    }
    sort(standings.begin(), standings.end(), cmp);
    for(int i = 1; i <= n; i++){
        //cout << standings[i-1].f << " " << standings[i-1].s << "\n";
        if(standings[i-1].s == p){
            cout << standings[i-1].f << " " << i; 
            return 0;
        }
    }

}

