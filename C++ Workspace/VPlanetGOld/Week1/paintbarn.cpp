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
int arr[1005][1005];
int main(){
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;	
	for(int i =1; i <= N;i ++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a++; b++; c++; d++;
		arr[a][b]++;
		arr[a][d]--;
		arr[c][b]--;
		arr[c][d]++;
	}
	int ans = 0;
	for(int i = 1; i<= 1001;i ++){
		for(int j = 1;j <= 1001;j ++){
			arr[i][j] += arr[i-1][j];
			arr[i][j] += arr[i][j-1];
			arr[i][j] -= arr[i-1][j-1];
			if(arr[i][j] == K)ans++;
		}
	}
	cout << ans << '\n';
}
