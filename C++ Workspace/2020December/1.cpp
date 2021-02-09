#include <bits/stdc++.h>
using namespace std;

int mat[105][105];
bool possible[105][105];
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, D;
	cin >> N >> D;
	for(int i = 0; i < N;i ++){
		string s;
		cin >> s;
		for(int j = 0;j  < N; j++){
			if(s[j] == '#'){
				mat[i][j] = 1;
			}
			if(s[j] == '.'){
				mat[i][j] = 0;
			}
			else{
				mat[i][j] = 2;
			}
		}
	}


}
