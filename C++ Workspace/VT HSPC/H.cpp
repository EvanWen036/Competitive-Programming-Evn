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
ll n;
int e;
ll po;
ll dp[20][2][2];
//dp i,j,k = number of integers using with the first i
//j is whether you are unrestricted
//k is whether 2^e has been included
vector<int> digit; 
vector<int> digit2;
long long calc(int idx, int tight, int included){
	//cout << idx << " " << tight << " " << included << '\n';
	if(idx == -1){
		return (included == 1 ? 1:0);
	}
	if(dp[idx][tight][included] != -1){
		return dp[idx][tight][included];
	}
	long long ret = 0;
	//just include another digit
	int k = (tight) ? digit[idx]:9;
	for(int i =0;i <=k ;i++){
		int newTight = (digit[idx] == i) ? tight:0;
		ret += calc(idx-1, newTight, included);
	}
	
	//include the length of digits
	if(idx+1 >= digit2.size()){
		int newTight = 0;
		bool wrk = true;
		for(int i = 0; i < digit2.size();i++){
			int curr = digit2[i];
			if(curr <= k){
				//hard vibing 
				newTight = (digit[idx] == digit2[i]) ? tight:0;
				k = newTight ? digit[idx]:9;
			}
			else{
				wrk = false;
				break;
			}
		}
		if(wrk){
			ret += calc(idx - digit2.size(), newTight, 1);
		}
	}
	dp[idx][tight][included] = ret;
	return dp[idx][tight][included];
}
void getDigits(long long x){
	while(x){
		digit.pb(x % 10);
		x/=10;
	}
}
void getDigits2(long long x){
	while(x){
		digit2.pb(x%10);
		x/=10;
	}
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> e;
	po = 1 << (1LL*e);
	getDigits(n);
	getDigits2(po);
	reverse(digit2.begin(), digit2.end());
	memset(dp, -1, sizeof(dp));
	//cout << po << '\n';
	cout << calc(digit.size()-1, 1, 0) << '\n';
	/**
	for(int i = 0; i <= digit.size()-1; i++){
		for(int j = 0;j < 2;j ++){
			for(int k = 0;k < 2;k ++){
				cout << i << " " << j << " " << k << " " << dp[i][j][k] <<'\n';
			}
		}
	}**/


}
