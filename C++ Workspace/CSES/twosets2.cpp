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
ll dp[125255];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int total = n * (n+1) / 2;
	if(total % 2 == 1){
		cout << 0 << '\n';
		return 0;
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = total; j >= i; j--){
			dp[j] += dp[j - i];
			dp[j] %= 1000000007; 
		}
	}
	dp[total/2]%=1000000007;
	cout << (dp[total/2]*500000004)%1000000007 << '\n';


}
