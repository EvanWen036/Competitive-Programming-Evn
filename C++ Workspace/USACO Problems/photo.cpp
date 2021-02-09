#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
map<int, int> pos[5];
bool comp(int a, int b){
    int ac = 0;
    int bc = 0;
    for(int i = 0; i < 5; i++){
        if(pos[i][a] < pos[i][b]){
            ac++;
        }
        else{
            bc++;
        }
    }
    return ac < bc;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
    vector<int> A(N);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < N; j++){
            int x;
            cin >> x;
            if(i == 0){
                A[j] = x;   
            }
            pos[i][x] = j;
        }
    }
    sort(A.begin(), A.end(), [](const int &l, const int &r){int ac = 0;
    int bc = 0;
    for(int i = 0; i < 5; i++){
        if(pos[i][l] < pos[i][r]){
            ac++;
        }
        else{
            bc++;
        }
    }
    return bc < ac;});
    for(int i = 0; i < N; i++){
        cout << A[i] << endl;
    }
}

