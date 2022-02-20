#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int  solution(char*);





int main()
{
    int k;
    char isvalidpass[120]="zaq!2#edc";
    printf("%d",solution(isvalidpass));

}
int  solution(char *s)
{
    int longestpass[100];
    int y=0;
    int sayacletter=0;
    int sayacstring=0;
    int sayacdigit=0;
    int indis;
    int temp=0;

    for(int i=0; s[i]!='\0'; i++)
    {

        for(int j=i; s[j]!='\0'; j++)
        {
            if((i==0))
            {
                temp=-1;

            }
            if(i!=temp+1)
            {
                break;

            }
            if(s[j]!=32)
            {
                sayacstring++;
            }

            if((isdigit(s[j])!=0) ||(isalpha(s[j]) !=0))
            {
                if(isalpha(s[j]))
                {
                    sayacletter++;

                }
                if(isdigit(s[j]))
                {
                    sayacdigit++;

                }

            }

            if(s[j]==32)
            {
                temp=j;
                break;

            }

        }
        if((sayacletter%2==0)&&(sayacdigit%2==1)&&((sayacdigit+sayacletter)==sayacstring))
        {
            longestpass[y++]=sayacstring;

        }
        sayacstring=0;
        sayacdigit=0;
        sayacletter=0;
    }
    for(int i=0; i<y; i++)
    {
        for(int j=i+1; j<y; j++)
        {
            if(longestpass[i]<=longestpass[j])
            {
                temp=longestpass[i];
                longestpass[i]=longestpass[j];
                longestpass[j]=temp;

            }
        }

    }
    int newsayac=0;
    for(int f=0; f<y; f++)
    {
        if(longestpass[f]!=0)
        {
            newsayac++;

        }
    }
    if(newsayac)
    {
        return longestpass[0];

    }
    else
    {
        return -1;
    }
}































