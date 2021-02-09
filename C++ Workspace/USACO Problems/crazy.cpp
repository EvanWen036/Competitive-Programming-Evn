#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N, C;
map< pair<int, int>, vector<pair<int, int>> > adj;
set< pair<int, int> > vis;
vector< vector< pair<int, int> > > polygons;
void traverse(pair<int, int> curr){
    vis.insert(curr);
    for(auto it : adj[curr]){
        if(vis.count(it) == 0){
            polygons[polygons.size()-1].push_back(it);
            traverse(it);
        }
    }
}
int intersect(pii p0, pii p1, pii p2){
    if((p1.second > p0.second) ^ (p2.second > p0.second)){
        return (p1.second-p2.second<0)^(p2.first*(p1.second-p0.second)+p1.first*(p0.second-p2.second)>p0.first*(p1.second-p2.second));
    }
    return false;
}
bool inPolygon(pii point, vector< pii > polygon){
    for(int j=0;j<polygon.size(); j++){
        if(intersect(point, polygon[j], polygon[(j+1)%polygon.size()]))return true;
    }
}
int main(){
    freopen("crazy.in", "r", stdin);
    freopen("crazy.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, C;
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int x1, y1, x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        adj[make_pair(x1,y1)].push_back(make_pair(x2,y2));
        adj[make_pair(x2,y2)].push_back(make_pair(x1,y1));
    }
    for(auto it : adj){
        if(vis.count(it.first) == 0){
            vector< pair<int, int> > x;
            polygons.push_back(x);
            polygons[polygons.size()-1].push_back(it.first);
            traverse(it.first);
        }
    }
    
    string s[C];
    vector< pii > points(C);
    for(int i = 0; i < C; i++){
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x,y);
        s[i] = "";
    }
    
    for(int i = 0; i < polygons.size(); i++){
        for(int j = 0; j < C; j++){
            if(inPolygon(points[j], polygons[i])){
                s[j] += "1";
            }
            else{
                s[j] += "0";
            }
        }
    }
    int ans = 0;
    map<string, int> count;
    for(int i = 0; i < C; i++){
        count[s[i]]++;
        ans = max(ans, count[s[i]]);
    }
    cout << ans << endl;
}

