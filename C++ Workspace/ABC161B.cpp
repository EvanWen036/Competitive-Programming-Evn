#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> V(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> V[i];
		sum += V[i];
	}
	double leastVotes = (double)sum / (4 * m);
	sort(V.begin(), V.end());
	reverse(V.begin(), V.end());
	cout << (V[m-1] >= leastVotes ? "Yes" : "No");


}