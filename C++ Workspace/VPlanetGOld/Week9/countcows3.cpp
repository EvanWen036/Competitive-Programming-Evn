#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
typedef long long ll;
typedef pair<int, int> pii;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll dp[40][2][2][2];
int ydig[40];
int ddig[40];
int xdig[40];
ll query2(ll x, ll y, ll d){
	if(d < 0)return 0;
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0] = 1;
	ll pow3 = 1;
	for(int j = 1;j <= 38;j ++){
		pow3 *= 3;
	}
	memset(xdig, 0, sizeof(xdig));
	memset(ydig, 0, sizeof(ydig));
	memset(ddig, 0, sizeof(ddig));
	for(int j = 38;j >= 0;j --){
		if(y >= pow3){
			ydig[j+1] = y/pow3;
			y %= pow3;
		}
		if(d >= pow3){
			ddig[j+1] = d/pow3;
			d %= pow3;
		}
		if(x >= pow3){
			xdig[j+1] = x/pow3;
			x %= pow3;
		}
		//cout << ydig[j] << '\n';
		pow3/=3;
	}
	//find number of d2 <= d such that there is a cow at d2, y+d2
	for(int pos = 0; pos < 39; pos++){
		for(int carryx = 0; carryx < 2; carryx++){
			for(int carryy = 0; carryy < 2; carryy++){
				for(int lt = 0; lt < 2; lt ++){
					for(int nd = 0; nd < 3; nd++){
						//make sure this number will be less than d 
						int nextprefix = 0;
						if(nd > ddig[pos+1] || (nd == ddig[pos+1] && lt == 1)){
							nextprefix = 1;
						}
						else{
							nextprefix = 0;
						}
						int nextYpos = (nd + carryy + ydig[pos+1])%3;
						int nextCarryy = (nd+carryy+ydig[pos+1]>=3 ? 1:0);
						int nextXpos = (nd + carryx + xdig[pos+1])%3;
						int nextCarryx = (nd + carryx + xdig[pos+1] >= 3 ? 1 :0);
						if((nextYpos + nextXpos)%2 == 0){
							dp[pos+1][nextCarryx][nextCarryy][nextprefix] += dp[pos][carryx][carryy][lt];
						}
					}
				}
			}
		}
	}
	return dp[39][0][0][0];
}
ll solve(ll x, ll y, ll d){
	return query2(x-min(x,y), y - min(x,y), min(x,y)+d) - query2(x-min(x,y), y - min(x,y), min(x,y)-1);

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	for(int i = 0; i < q;i ++){
		ll d, x, y;
		cin >> d >> x >> y;
		cout << solve(x,y,d) << '\n';
	}


}
