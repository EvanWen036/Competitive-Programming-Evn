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
	int N, Q;
	cin >> N >> Q;
	int p[N+1];
	p[0] = 0;
	for(int i = 1;i <= N; i++){
		int x;
		cin >> x;
		p[i] = p[i-1] ^ x;
	}
	for(int i  = 0; i < Q;i ++){
		int a, b;
		cin >> a >> b;
		cout << (p[b] ^ p[a-1]) << '\n'; 
	}


}
