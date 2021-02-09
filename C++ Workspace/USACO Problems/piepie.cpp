#include <bits/stdc++.h>
using namespace std;

//#define f first
//#define s second
typedef long long ll;
typedef pair<int, int> pii;
struct State{
    pair<pair<int, int>, int> pie;
    int turn;
};

int main(){
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N, D;
    cin >> N >> D;
    multiset<pair<pair<int, int>, int> > bessie;
    multiset<pair<pair<int, int>, int > > elsie;
    queue<State> q;
    int dist[2*N+5];
    
    
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        //bessie.insert(make_pair(make_pair(b,a),i));
        //dist[i] = 1000000000;
        if(b == 0){
            //elsie thinks this pie is worthless
            dist[i] = 1;
            q.push(State{make_pair(make_pair(a,b), i), 1});  
        }
        else{
            bessie.insert(make_pair(make_pair(b,a),i));
            dist[i] = 1000000000;
        }
    }
    for(int i = 0; i < N;i ++){
        int a, b;
        cin >> a >> b;
        //dist[i+N] = 1000000000;
        //elsie.insert(make_pair(make_pair(a,b),i+N));
        if(b == 0){
            //bessie thinks this pie is worthless
            dist[i+N] = 1;
            q.push(State{make_pair(make_pair(a,b), i+N), 0});
        }
        else{
            dist[i+N] = 1000000000;
            elsie.insert(make_pair(make_pair(a,b), i+N));
        }
    }
    
    while(!q.empty()){
        State s = q.front(); q.pop();
        //cout << s.pie.first.first << " " << s.pie.first.second << endl;
        if(s.turn == 1){
            //bessie gave a pie of worth 0 to elsie which means elsie must have given her a pie of
            int val = s.pie.first.first - D;
            
            multiset<pair<pii, int>>::iterator it = lower_bound(elsie.begin(), elsie.end(), make_pair(make_pair(val,-1), -1));
            while(it != elsie.end() && (*it).first.first <= s.pie.first.first){
                //if(dist[s.pie.second] + 1 < dist[(*it).second]){
                    dist[(*it).second] = dist[s.pie.second]+1;
                    q.push(State{*it, !s.turn});
                    it = elsie.erase(it);
                //}
                
            }
        }
        if(s.turn == 0){
            //bessie must give elsie a pie
            int val = s.pie.first.second-D;
            multiset<pair<pii,int>>::iterator it = lower_bound(bessie.begin(), bessie.end(), make_pair(make_pair(val, -1), -1));
            while(it != bessie.end() && (*it).first.first <= s.pie.first.second){
                //if(dist[s.pie.second]+1 < dist[(*it).second]){
                    dist[(*it).second] = dist[s.pie.second]+1;
                    q.push(State{*it, !s.turn});
                    it = bessie.erase(it);
                //}
               
            }
        }
    }
    
    
    for(int i = 0; i < N;i ++){
        cout << (dist[i] != 1000000000 ? dist[i]:-1) << endl;
    }




}

