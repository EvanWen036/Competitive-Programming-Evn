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
	int T;
	cin >> T;
	for(int i = 1; i <= T;i ++){
		int N, C;
		cin >> N >> C;
		bool print = false;
		cout << "Case #" << i << ": ";
		vector<int> B;
		for(int j = 1;j <= N;j ++){
			B.pb(j);
		}
		do{
			int ans = 0;
			vector<int> A = B;
			for(int j = 0;j < N-1;j ++){
				int miPos = j;
				for(int k = j; k < N;k ++){
					if(A[miPos] > A[k])miPos = k;
				}
				ans += miPos-j+1;
				reverse(A.begin() + j, A.begin() + miPos + 1);
			}
			if(ans == C){
				for(int k = 1;k < N;k ++){
					cout << B[k-1] << " " ;
				}
				cout << B[N-1] << '\n';
				print = true;
				break;
			}
		}
		
		while(next_permutation(B.begin(), B.end()));
		if(!print){
			cout << "IMPOSSIBLE\n";
		}
	}	


}
