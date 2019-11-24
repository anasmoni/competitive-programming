#include<bits/stdc++.h>
using namespace std;

// http://codeforces.com/contest/832/problem/B

int main()
{
    string s,t;

    cin>>t>>s;

    int n;
    scanf("%d",&n);

    map<char,bool>good;

    for(int i=0 ; i<t.size(); ++i) good[ t[i] ] = true;

    while(n--)
    {

        cin>>t;

        int ts = t.size(), ss = s.size();

        bool yup=true;

        for(int i=0,z=0  ; z<ts || i<ss ; i++,z++)
        {
            if(z==ts){
                if(ss-i>1 || s[i]!='*'){yup=false; break;}
            }
            else if(i==ss){yup=false ; break;}

            if(s[i] != t[z])
            {

                if(s[i]=='*')
                {
                    if(good[t[i]]){z--; continue;}

                    for(; z<ts && good[t[z]]==false; z++);

                    int j;
                    z--;

                    for(j=i ; j<ss && good[s[j]]==false && s[j]!='?' ; j++);

                    if(j>i){

                        j--;
                        int jj=j, zz=z;

                        if(j>z+1){yup=false;break;}

                        for( ; j>i && z>i && t[z]==s[j] ; j--,z--);

                        if(i==j) z=zz,i=jj;
                        else z=i-1;
                    }



                }
                else if(s[i]=='?')
                {

                    if(good[ t[z] ] == false)
                    {
                        yup=false;
                        break;
                    }
                }
                else
                {
                    yup=false;
                    break;
                }
            }

        }

        if(yup)cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}


/**-------------------------that's better--------------

#include <bits/stdc++.h>
using namespace std;

string a,b,c(256,0);
int n,i,j,al,bl,y;

int main()
{
	cin>>a;

    for (char i:a) c[i]=1; // instead of map

	cin>>a;
    al=a.size();
	cin>>n;

	while (n--)
	{
		cin>>b;
		bl=b.size();
        y=1;

		for (i=j=0; y && i<al; i++)
		{
			if (a[i]=='*')
			{
				while (j<bl-(al-i-1))
					if (c[b[j++]]) y=0;
			}
			else
			{
				if(a[i]=='?'? c[b[j]]: a[i]==b[j]) j++;

				else y=0;
			}
		}

		if (j<bl) y=0;
		cout<<(y?"YES\n":"NO\n");
	}
}
*/
