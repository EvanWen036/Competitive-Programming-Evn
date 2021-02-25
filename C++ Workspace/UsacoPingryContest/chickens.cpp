#include <bits/stdc++.h>
using namespace std;


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<pair<int,int>> pts(N);
	//This is Evan's solution which uses the c++ pair for points
	//pts[i].first = the i'th cow's x coordinate
	//pts[i].second = the i'th cow's y coordinate
	for(int i = 0; i < N;i ++){
		cin >> pts[i].first >> pts[i].second;
	}
	int ans = 1e9;
	//iterate through all ordered triples
	//find the coordinates of the bounding rectangles
	for(int i = 0; i < N ;i++){
		for(int j = i + 1; j < N; j++){
			for(int k = j+1; k < N; k++){
				//rightmost point
				int x1 = max(pts[i].first, max(pts[j].first, pts[k].first));
				//left most point
				int x2 = min(pts[i].first, min(pts[j].first, pts[k].first));
				//highest point
				int y1 = max(pts[i].second, max(pts[j].second, pts[k].second));
				//lowest point
				int y2 = min(pts[i].second, min(pts[j].second, pts[k].second));
				ans = min(ans, (y1-y2)*(x1-x2));
			}
		}
	}
	cout << ans << '\n';


}
