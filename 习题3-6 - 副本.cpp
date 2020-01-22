
#include<iostream>
#include<string.h>
#include<string>
#pragma warning(disable:4996)
#define LOCAL
#ifdef LOCAL
FILE *fin = freopen("œ∞Ã‚3-6in.txt", "r", stdin);
FILE *fout = freopen("œ∞Ã‚3-6out.txt", "w", stdout);
#endif 
#include <stdio.h>
#include <stdlib.h>
 
int main()
{		
    int m,n,u=0;
    while((~scanf("%d",&m))&&m)
    {
        scanf("%d",&n);getchar();
        if(u) printf("\n");
        char puzzle[m][n+1];
        int i,j;
        for(i=0;i<m;i++)
            for(j=0;j<=n;j++)
                puzzle[i][j]=getchar();
        int num[m][n],k=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(puzzle[i][j]!='*'&&(!i||!j||puzzle[i-1][j]=='*'||puzzle[i][j-1]=='*'))
                    num[i][j]=++k;
                else if(puzzle[i][j]!='*')
                    num[i][j]=-1;
                else
                    num[i][j]=0;
            }
//        for(i=0;i<m;i++)
//            for(j=0;j<n;j++)
//         {
//             printf("%d",num[i][j]);
//             printf("\n");
//         }
        printf("puzzle #%d:\n",++u);
        printf("Across\n");
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(num[i][j]>0)
                {
                    printf("%3d.",num[i][j]);
                    for(;j<n&&num[i][j];printf("%c",puzzle[i][j++]));
                    printf("\n");
                }
 
            }
        printf("Down\n");
        int ii;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(num[i][j]>0)
                {
                    printf("%3d.",num[i][j]);
                    for(ii=i;ii<m&&num[ii][j];printf("%c",puzzle[ii][j]),num[ii++][j]=0);
                    printf("\n");
                }
            }
    }
    return 0;
}
