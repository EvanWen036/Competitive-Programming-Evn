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
    int N, R;
    cin >> N >> R;
    vector<pair<double, pair<int, int>>> tangentPoints;
    vector<double> points;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        double dist1 = sqrt(1.0*x*x + 1.0*y*y);
        double theta = acos(R/dist1);
        double alpha = atan2(y,x);
        double angle = alpha+theta;
        
        tangentPoints.pb(mp(alpha-theta, mp(i, 1)));
        //if(abs((theta + alpha) - 3.141592653589)> 0.00000001) angle = (theta+alpha-3.1415926535897932384626) * -1; 
        tangentPoints.pb(mp(angle, mp(i, 0)));
       
        points.pb(alpha-theta);
    }
    sort(tangentPoints.begin(), tangentPoints.end());
    for(auto it : tangentPoints){
        //cout << it.f << " " << it.s.f << endl;
    }
    int ans = 0;
    multiset<double> current;
    for(int i = 0; i < 2; i++){
        for(auto it : tangentPoints){
            //cout << it.s.f << " " << current.size() << endl;
            if(it.s.s == 1 && i == 1){
                ans += current.size();
            }
            if(it.s.s == 1){
                //add it
                current.insert(it.f);
            }

            if(it.s.s == 0){
                current.erase(current.find(points[it.s.f]));
            }
        }
    }
    cout << ans << endl;
    
}

