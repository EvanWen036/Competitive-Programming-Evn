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
	int n, m;
	cin >> n >> m;
	vector<int> A(n);
	for(int i = 0; i < n;i ++)cin >> A[i];
	sort(A.begin(), A.end());
	if(n <= m){
		ll sum = 1;
		for(int i = 0; i < n;i ++){
			for(int j = i+1;j < n;j ++){
				sum *= abs(A[i] - A[j]);
				sum %= m;
			}
		}
		cout << sum << '\n';
	}
	else{
		cout << 0 << '\n';
	}


}
