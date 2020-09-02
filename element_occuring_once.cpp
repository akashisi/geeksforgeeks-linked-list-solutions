#include <iostream>
using namespace std;

int main()
{
	int t,n;
	cout<<endl<<"Enter test cases :: ";
	cin>>t;
	while(t--)
	{
        int n,c=0,i=0,j=0;
        cout<<endl<<"Enter the size of array :: ";
        cin>>n;
        int a[n],freq[n];
        cout<<endl<<"Enter teh array elements :: \n";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            freq[i]=-1;
        }
        for(i=0;i<n;i++)
        {
            c=1;
            for(j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                {
                    c++;
                    freq[j]=0;
                }
            }
            if(freq[i]!=0)
            {
                freq[i]=c;
            }
        }
        for(i=0;i<n;i++)
        {
            if(freq[i]==1)
            {
                cout<<endl<<"Frequency with once :: "<<a[i]<<endl;
               // cout<<" frequency is "<<freq[i];
            }
        }

	}
	return 0;
}
