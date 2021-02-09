#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, D;
    cin >> N >> D;
    vector<pair<int ,int>> points(N);
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
    }
    sort(points.begin(), points.end());
    multiset<pii> xSort;
    multiset<pii> ySort;
    int l = 0;
    int r = 0;
    int current = 0;
    int ans = 1000000000;
    while(l < N && r < N){
        if(current < D){
            xSort.insert(make_pair(points[r].first, points[r].second));
            ySort.insert(make_pair(points[r].second, points[r].first));
            pii last = *(--ySort.end());
            pii fir = *(ySort.begin());
            current = last.first - fir.first;
            r++;
        }
        else{
            pii last = *(--xSort.end());
            pii fir = *xSort.begin();

            ans = min(ans, last.first - fir.first);
            xSort.erase(make_pair(points[l].first, points[l].second));
            ySort.erase(make_pair(points[l].second, points[l].first));
            pii last2 = *(--ySort.end());
            pii fir2 = *(ySort.begin());
            current = last2.first - fir2.first;
            l++;
        }
    }
    cout << ans << endl;

}

