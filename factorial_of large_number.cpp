#include<iostream>
#define MAX 200000
using namespace std;
int result[MAX];
int result_size;


void multiply(int n)
{
    int carry=0;
    for(int i=0;i<result_size;i++)
    {
        int prod=result[i]*n+carry;
        result[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        result[result_size]=carry%10;
        carry=carry/10;
        result_size++;
    }

}

void factorial(int n)
{
    long long int sum=0,c=0;
    result[0]=1;
    result_size=1;

    for(int i=2;i<=n;i++)
        multiply(i);


    for(int i=result_size-1;i>=0;i--)
    {
        cout<<result[i];
        sum=sum+result[i];
        c++;
    }
    cout<<endl<<"SUM OF DIGITS  :: "<<sum<<endl<<"Number of digits in factorial :: "<<c<<endl;
}
int main()
{
    int n;
    cin>>n;
    factorial(n);
    return(0);
}
