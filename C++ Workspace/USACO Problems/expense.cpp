#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
int cost[100005];
int M;
bool check(int val){
    int groups = 1;
    int cur =0;
    for(int i = 0; i < N; i++){
        if(cost[i] > val)return false;
        if(cur + cost[i] <= val){
            cur += cost[i];
        }
        else{
            cur = cost[i];
            groups++;
        }
    }
    return groups <= M; 
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> cost[i];
    }
    int low = 0;
    int high = 1000000000;
    while(low < high){
        int mid = (low+high)/2;
        //cout << low << " " << high << endl;
        if(check(mid)){
            
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    
    cout << low  << endl;



}

