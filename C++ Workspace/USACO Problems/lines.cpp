#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    pii points[N];
    for(int i =0; i < N; i++){
        cin >> points[i].f >> points[i].s;
    }
    set<double> slopes;
    for(int i = 0; i < N; i++){
        for(int j = i+1 ; j < N; j++){
            if(i != j){
                //cout << i << " " << j << endl;
                int x = (points[j].f - points[i].f);
                int y = (points[j].s - points[i].s);
                //cout << i << " " << j << " " << x << " " << y << endl;
                double slope=  10000000;
                if(y != 0) {
                    slope = (double)x/y;
                }
                slopes.insert(slope);
            }
        }
    }
    cout << slopes.size() << endl;

}

