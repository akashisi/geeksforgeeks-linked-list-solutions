#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double a,b,c,s,area;
    cin>>a>>b>>c;
    s=(a+b+c)/2.0;
    cout<<"SEMI PERIMETER :: "<<s<<endl;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    cout<<"AREA :: "<<area<<endl;


    return(0);

}
