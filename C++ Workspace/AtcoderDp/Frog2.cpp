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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<int> A(N+1);	
	for(int i = 1; i <= N;i ++)cin >> A[i];
	int dp[N+1];
	for(int i = 1; i<= N;i ++)dp[i] = 1e9;
	dp[1] = 0;
	for(int i = 1; i <= N;i ++){
		for(int j =1;j <= K;j ++){
			if(i + j <= N){
				dp[i+j]=min(dp[i+j], dp[i] + abs(A[i+j]-A[i]));
			}
		}
	}
	cout << dp[N] << '\n';

}
