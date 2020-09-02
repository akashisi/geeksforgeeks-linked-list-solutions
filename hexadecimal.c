#include<stdio.h>
int main()
{
    int i=0,r,x,y,j;
    char ch[10];

    printf("Enter any number in decimal :: ");
    scanf("%d",&x);
    y=x;
    while(x>0)
    {
        r=x%16;
        if(r<10)
        {
          ch[i]=r+48;
          i++;
        }
        else
        {
            ch[i]=r+55;
            i++;
        }

        x=x/16;
    }
    printf("\n Hexadecimal Equivalent is :: ");
    for(j=i-1;j>=0;j--)
        printf("%c",ch[j]);

    return(0);
}
