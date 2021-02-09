#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Event{
    int x, i, type;

    bool operator<(const Event other) const{
        return x < other.x;
    }
 };
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    pair< pii, pii > F[N];
    vector< Event > xEvent;
    for(int i = 0; i < N; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        F[i] = make_pair(make_pair(x1,y1),make_pair(x2,y2));
        xEvent.push_back(Event{x1, i, 1});
        xEvent.push_back(Event{x2,i,0});
    }
    
    sort(xEvent.begin(), xEvent.end());
    multiset< pii, greater<pii> > active;
    //multiset< int > activeX;
    long long ans = 0;
    for(int i = 0; i < xEvent.size(); i++){
        
        Event it = xEvent[i];
        //cout << it.x << " " << it.type << endl;
        if(it.type == 1){
            active.insert(make_pair(F[it.i].first.second, 1));
            //activeX.insert(it.x);
        }
        if(i != 0 && !(xEvent[i-1].type == 0 && xEvent[i].type == 1)){
            ll xChange = xEvent[i].x - xEvent[i-1].x;
            ll yChange = 0;
            multiset< pii >::iterator it = active.begin();
            //cout << i << endl;
            int count = 0;
            while(it != active.end()){
                if((*it).second == 1)count++;
                //cout << (*it).first << " " << (*it).second << " " << count << endl;
                if(it != active.begin()){
                    pii curr = *it;
                    pii prev = *(--it);
                    ++it;
                    if(count > 0){
                        //cout << "TEST: " << prev.first <<  " " << curr.first << endl; 
                        yChange += prev.first-curr.first;
                    }
                }
                if((*it).second == 0)count--;
                it++;
            }
            cout << i << " " << xChange << " " << yChange << endl;
            ans += xChange*yChange;
        }
        if(it.type == 1){
            active.insert(make_pair(F[it.i].second.second, 0));
        }
        if(it.type == 0){
            active.erase(active.find(make_pair(F[it.i].first.second, 1)));
            active.erase(active.find(make_pair(F[it.i].second.second, 0)));
            //activeX.erase(activeX.find(F[it.i].first.first));
        }
    }
    cout << ans << endl;


}

