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
vector<pii> intervals;
int k;
int ok(){
    int currPos = 0;
    int cnt = 0;
    for(pii interval : intervals){
        if(interval.s > currPos){
            //we need a new interval
            //calculate how many intervals we will need
            //cout << currPos << "\n";
            int startingPos = 0;
            //if(currPos >= interval.s)cuntinue;
            if(currPos >= interval.f){
                startingPos = currPos+1;            
            }
            else{
                startingPos = interval.f;
            }

            int amt = (interval.s - startingPos+1)/k;
            if((interval.s - startingPos+1) % k != 0)amt++;
            cnt += amt;
            currPos = startingPos + k * amt - 1;
        }
    }
    return cnt;
}
void solve(int tc){
    int n;
    cin >> n >> k;
    //k++;
    //vector<pii> intervals;
    for(int i = 0; i < n;i ++){
        int a, b;
        cin >> a >> b;
        intervals.pb({a,b-1});
    }
    sort(intervals.begin(), intervals.end());
    
    cout << "Case #" << tc << ": " << ok() << "\n";
    intervals.clear();
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        solve(tt);
    }


}

