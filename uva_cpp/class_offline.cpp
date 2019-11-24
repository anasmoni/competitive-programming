#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

class String
{
    char *str ;
    int len ;
public:
    String(char *s){strcpy(str,s);}

    void concat(char *s){strcat(str,s);}

    void concat(int a);

    void concat(double d);

    void concat(char c){str[strlen(str)]=c ;}

    void concat(int a, char c);

    String(){ gets(str); for(int i=0 ; str[i] ; str[i++]=' ') ;}

    void show(){cout<<str ;}

};

void String::concat(int a)
{
    char x[100] ;
    itoa(a,x,10) ;
    strcat(str,x);

}

void String::concat(double d)
{
    char c[150];
    sprintf(c,"%lf",d);
    strcat(str,c) ;
    int i=strlen(str)-1 ;
    for( ; str[i]=='0';i--);
    if(str[i]!='.') str[i+1] = '\0' ;

}

void String::concat(int a, char c)
{
        for(int i=0 ; i<a ; i++)
        {
            char x[10];
            x[0]=c ;
            x[1]='\0';
            strcat(str,x) ;
        }


}

int main()
{
    String ob("Hello ") , x ;

    ob.concat("World!");

    ob.concat(14.25404);

    ob.concat(4,'5');

    ob.show();
    x.show();



    return 0;
}
