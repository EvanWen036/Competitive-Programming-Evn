#include <bits/stdc++.h>
#include "testlib.h"
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

int main(int argc, char* argv[]){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	cout << N << ' ' << M << '\n';
	for(int i = 0; i < M;i ++){
		int a = rnd.next(1, N);
		int b = rnd.next(1,N);
		while(a == b){
			b = rnd.next(1,N);
		}
		int t = rnd.next(1,N);
		cout << a << " " << b << " " << t << '\n';
	}

}
