#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define f first
#define s second
#define INF 1000000010
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
    int N, D;
    cin >> N >> D;
    int B[2*N];
    int E[2*N];
    //cin >> N >> D; 
    for(int i = 0; i < 2 * N; i++){
        cin >> B[i] >> E[i];
    }
    set<pii> bessie;
    set<pii> elsie;
    queue<int> q;
    int dist[2*N];
    for(int i = 0; i < 2 * N;i ++){
        if(i >= N){
            //this is elsie's pie
            if(B[i] == 0){
                //could end on this
                dist[i] = 1;
                q.push(i);
            }
            else{
                dist[i] = INF;
                elsie.insert(mp(B[i], i));
            }
        }
        if(i < N){
            if(E[i] == 0){
                dist[i] = 1;
                q.push(i);
            }
            else{
                dist[i] = INF;
                bessie.insert(mp(E[i], i));
            }
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u < N){
            //this is bessie pie it is elsie turn to give her a pie
            int val = B[u] - D;
            auto it = elsie.lower_bound(mp(val,-1));
            while(it != elsie.end() && (*it).first <= B[u]){
                dist[(*it).second] = dist[u]+1;
                q.push((*it).second);
                it = elsie.erase(it);
            }
        }
        else{
            //this is elsie's pie and it is bessie's turn
            int val = E[u] -D;
            auto it = bessie.lower_bound(mp(val, -1));
            while(it != bessie.end() && E[(*it).second] <= E[u]){
                dist[(*it).second] = dist[u]+1;
                q.push((*it).second);
                it = bessie.erase(it);
            }

        }
    }
    for(int i = 0; i < N; i++){
        if(dist[i] == INF)cout << -1 << endl;
        else{cout << dist[i] << endl;}
    }



}

