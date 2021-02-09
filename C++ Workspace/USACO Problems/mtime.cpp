#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    vector< pair<int, int> > T(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        T[i] = make_pair(b,a);
    }
    sort(T.begin(), T.end(), greater<pii>());
    int minimum = T[0].first;
    for(int i = 0; i < N; i++){
        //cout << T[i].first << " " << minimum << endl;
        minimum = min(minimum - T[i].second, T[i].first - T[i].second);
    }
    if(minimum < 0)minimum = -1;
    cout << minimum << endl;


}

