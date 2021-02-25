#include <bits/stdc++.h>
using namespace std;

long long maxDist[605][55];
long long mdist(pair<int,int> a, pair<int,int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;
	vector<pair<long long,long long>> pts(N);
	for(int i = 0; i < N; i++){
		cin >> pts[i].first >> pts[i].second;
	}
	sort(pts.begin(), pts.end());
	long long ans = 0;
	//maxDist[i][k] is the maximum dist if you use the i'th element as the k'th element in the included set
	for(int i = 1; i <= N; i++){
		for(int k = 1; k <= i && k <= K;k ++){
			//use the i'th as the k'th 
			for(int x = 1; x < i; x++){
				long long dist = mdist(pts[i-1], pts[x-1]);
				if(k==1)dist = 0;
				//DP transitions
				//The last chosen person was at position x and there were previously only k-1 people included
				//Now we take this summed with the distance between people i and x to get a possible value for maxDist[i][k]
				maxDist[i][k] = max(maxDist[i][k], maxDist[x][k-1] + dist);
			}
		}
		//update the answer. the answer is maxDist[i][K] for any i
		ans = max(ans, maxDist[i][K]);
	}
	cout << ans << '\n';

}
