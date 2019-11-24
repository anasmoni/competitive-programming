/**http://codeforces.com/problemset/problem/161/D*/
#include<bits/stdc++.h>

using namespace std;

vector < int > V[100005];

long long M[100005][502],n,k,u,v,i,asd;

void f(int x){

	int i,j;

	M[x][0] = 1; // x theke 0 dist e ase 1 jon

	for(i=0;i<V[x].size();i++)
		if(!M[ V[x][i] ][0]){
			f(V[x][i]);
			for(j=0;j<k;j++)
				asd += M[x][j] * M[ V[x][i] ][k-j-1];

			for(j=1;j<=k;j++)
				M[x][j] += M[ V[x][i] ][j-1];/** x er sathe v[x][i] er dist 1 */
		}
}
int main(){

	cin >> n >> k;

	for(i=n;--i;){
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

	f(1);

	cout << asd;
	return 0;
}
