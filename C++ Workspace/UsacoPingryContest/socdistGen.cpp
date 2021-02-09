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
	cout << N << " " << K << '\n';
	set<int> xPoints;
	for(int i = 0; i < N; i++){
		int cap = 1e9;
		if(N == 10)cap = 100;
		int x = rnd.next(1, cap);
		while(xPoints.count(x)){
			x = rnd.next(1,cap);
		}
		xPoints.insert(x);
		int y = rnd.next(1, cap);
		cout << x << " " << y << '\n';
	}


}
