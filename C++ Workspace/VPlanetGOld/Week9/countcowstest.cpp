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
	for(int i = 0; i <= 100;i ++){
		for(int j = 0;j <= 100;j ++){
			int k = 1;
			bool good = true;
			while(k < 100){
				if(((i/k)%3)%2 != ((j/k)%3)%2)good = false;
				k *= 3;
			}

			if(good){
				cout << "1";
			}
			else{
				cout << "0";
			}

		}
		cout << '\n';
	}		


}
