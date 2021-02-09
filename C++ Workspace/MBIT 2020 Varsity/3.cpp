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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> A(N+1);
	vector<int> B(N+1);
	vector<int> pos(N+1);
	int ans = 0;
	for(int i = 0; i < N;i ++){
		cin >> A[i];
		pos[A[i]] = i;
	}
	for(int i = 0; i < N;i ++){
		cin >> B[i];
		ans += abs(i - pos[B[i]]);
	}
	//cout << ans << '\n';
	//int fi = B[0];
	//B.pb(fi);
	vector<int> n;
	n.pb(B[N-1]);
	for(int i = 0; i < N-1; i++){
		n.pb(B[i]);
	}
	int temp = 0;
	for(int i = 0; i < N;i ++){
		cout << n[i] << " ";
		temp += abs(i - pos[n[i]]);
	}
	cout << temp << '\n';
	ans = min(ans, temp);
	cout << ans << '\n';


}
