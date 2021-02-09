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
int bLift[1000005][30];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N;i ++){
		for(int j = 0; j <= 26; j++){
			bLift[i][j] = -1;
		}
	}
	for(int i = 0; i < N;i ++){
		cin >> bLift[i][0];
		bLift[i][0]--;
	}	
	for(int j = 1; j <= 29; j++){
		for(int i = 0; i < N; i++){
			int mid = bLift[i][j-1];
			if(mid != -1){
				bLift[i][j] = bLift[mid][j-1];
			}
			//cout << bLift[i][j] << " ";
		}
		//cout << '\n';
	}
	int pos = 0;
	for(int i =0; i <= 29; i++){
		if(K & (1 << i)){
			//cout <<i << " " << pos << '\n';
			pos = bLift[pos][i];
		}
	}
	cout << pos+1 << '\n';
}
