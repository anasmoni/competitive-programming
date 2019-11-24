/**http://codeforces.com/problemset/problem/798/B*/
#include <iostream>
#include <string>
using namespace std;

int cnt=0,ans=0x3f3f3f3f;

int main(){
	int n;
	string a[55],temp;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			temp=a[j]+a[j];
			if(temp.find(a[i])==string::npos) {cout<<-1<<endl;return 0;}
			cnt+=temp.find(a[i]);
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}
