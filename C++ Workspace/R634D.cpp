#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int mat[10][10];
void change(int i, int j){
    if(mat[i][j] == 9){
        mat[i][j] = 5;
    }
    else{
        mat[i][j] = 9;
    }
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 9; i++){
            string s;
            cin >> s;
            for(int j = 0; j < 9; j++){
                mat[i][j] = s[j] - 48;
            }
        }
        int center = mat[4][4];
        change(8,0);
        change(5,1);
        change(2,2);
        change(7,3);
        change(4,4);
        change(1,5);
        change(6,6);
        change(3,7);
        change(0,8);
        for(int i = 0; i <9 ;i ++){
            for(int j = 0; j < 9; j++){
                cout << mat[i][j];
            }
            cout << "\n";
        }
        

    }


}

