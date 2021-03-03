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
int N;
int arr[305];
int dp[305][305][2];
int go(int l, int r, int type){
	//cout << l << " " << r << '\n';
	if(l == r){
		return 0;
	}
	if(dp[l][r][type] != 1e9)return dp[l][r][type];
	for(int lr = l; lr <= r; lr++){
		int curType = (type == 1 ? arr[r]:arr[l]);
		//our left range is from l to lr
		int left = go(l, lr, 0) + (arr[l] != curType ? 1:0);
		left = min(left, go(l,lr,1) + (arr[lr] != curType ? 1 : 0));
		//left = min(left, go(l, lr, arr[lr]) + (arr[lr] != type ? ))
		int right = 0;
		if(lr != r){
			right = go(lr+1, r, 0) + (arr[lr+1] != curType ? 1:0);
			right = min(right, go(lr+1,r,1) + (arr[r] != curType ? 1 : 0));
		}
		//cout << l << " " << r << " " << lr << " " << left << " " << right << '\n';
		dp[l][r][type] = min(dp[l][r][type], left+right);
	}
	//cout << l << " " << r << " " << dp[l][r] << '\n';
 	return dp[l][r][type];
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int cnt1 = 0;
	int cnt2 = 0;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		if(arr[i] == 1)cnt1++;
		if(arr[i] == 2)cnt2++;
	}
	/**
	int ans1 = 1;
	int ans2 = 1;
	for(int i = 1; i<= N;i ++){
		if(arr[i] == 2 && arr[i-1] != 2)ans1++;
	}
	for(int i = 1; i <= N;i ++){
		if(arr[i] == 1 && arr[i-1] != 1)ans2++;
	}
	cout << min(ans1,ans2) << '\n';
	**/
	for(int i = 1; i <= N;i ++){
		for(int j = 1; j <= N;j ++){
			dp[i][j][0] = 1e9;
			dp[i][j][1] = 1e9;
		}
	}
	cout << 1+min(go(1,N,0), go(1,N,1)) << '\n';
	//p2


}
