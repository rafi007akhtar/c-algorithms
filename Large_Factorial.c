#include <stdio.h>
#define max 16900

int main()
{
    //number of test cases
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n,b,fact[max],carry=0,len,k=1,count=0;
        printf("Enter the number: ");
        scanf("%d",&n);

        for (int i = 0; i < max; i++)
            fact[i]=0;
        fact[0]=1;

        for (int a = 2; a <= n; a++)
        {
            carry = 0;

            for (int i = 0; i < max; i++)
            {
                fact[i] = (fact[i]*a) + carry;
                carry = (fact[i])/10;
                fact[i]= fact[i]%10;
            }
        }

        for (int i = max-1; i > 0 ; i--)
        {
            if(fact[i] != 0)
            {
                count = i;
                break;
            }
        }

        printf("The factorial of %d is: ",n);
        for(int j=count; j >= 0; j--)
            printf("%d",fact[j]);
        printf("\n");
    }
}