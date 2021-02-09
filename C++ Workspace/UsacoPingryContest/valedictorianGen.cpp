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

	registerGen(argc, argv, 1);
	int N = atoi(argv[1]);
	int K = atoi(argv[2]);
	cout << N << " " << K <<'\n';
	for(int i = 0;i < K; i++){
		for(int j = 0;j < N; j++){
			cout << rnd.next(0, 100);
			if(j != N-1)cout << " ";
		}
		cout << '\n';
	}
}
