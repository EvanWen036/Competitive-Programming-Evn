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
int mat[505][505];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i  = 1; i <= n; i++){
		for(int j = 1 ; j <= m ;j ++){
			cin >> mat[i][j];
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j=  1;j <= m ;j++){
			if((i+j)%2 == 0){
				cout << 720720 << " ";
			}
			else{
				cout << 720720 - mat[i][j]*mat[i][j]*mat[i][j]*mat[i][j] << " ";
			}
		
		}
		cout << '\n';
	}


}
