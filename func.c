#include "func.h"
int func(int** arr, int* n, int* len_arr)
{
int summa=0, kolvo=0, flag=0,s=0, sred=0;
int temp_len=0, leng;
int* temp_arr;
for(int i=0; i<*n; i++ )
    {
        kolvo=kolvo+len_arr[i];
    }
printf("kolvo=%d\n", kolvo);
for (int i=0; i<*n; i++)
    {
        for(int j=0; j<len_arr[i]; j++)
            {
               summa=summa+arr[i][j];
            }

    }
printf("summa=%d\n", summa);
if (summa%kolvo!=0)
    {
        return 0;
    }
else {}
sred=summa/kolvo;
printf("sred=%d\n", sred);
for (int i=0; i<*n; i++)
    {
        for(int j=0; j<len_arr[i]; j++)
            {
               if (arr[i][j]==sred)
                {
                    flag=1;
                    s=i;

                }
               else{}
            }
if(flag!=0)break;
    }
if(flag==0) {
return 2;
}
else
    {
        temp_arr = (int*)malloc(0*sizeof(int));
        for (int d = s; d < (*n-1); d++)
    {
     temp_len = len_arr[d];
     temp_arr = (int*)realloc(temp_arr, temp_len*sizeof(int));
     for (int e = 0; e < temp_len; e++)
             {
              temp_arr[e] = arr[d][e];
             }
     arr[d] = (int*)realloc(arr[d], len_arr[d+1]*sizeof(int));
     for (int j = 0; j < len_arr[d+1]; j++)
             {
              arr[d][j] = arr[d+1][j];
             }
     arr[d+1] = (int*)realloc(arr[d+1], temp_len*sizeof(int));
     for (int f = 0; f < temp_len; f++)
            {
              arr[d+1][f] = temp_arr[f];

            }

    }
    *n = *n-1;
arr = (int**)realloc(arr, (*n)*sizeof(int*));

for (int p=s; p<*n; p++)
    {
        leng=len_arr[p];
        len_arr[p]=len_arr[p+1];
        len_arr[p+1]=leng;
    }
len_arr=(int*)realloc(len_arr, (*n)*sizeof(int));

free(temp_arr);
return 0;
    }
}

void Autotest(void)
{
int **testarr;
int *lenarr;
int  n= 3, m= 3;
testarr = (int**)malloc(3*sizeof(int*));
for (int k=0; k < 3; k++)
    {
testarr[k] = (int*)malloc(3*sizeof(int));
for (int g=0; g < 3; g++)
    {
     testarr[k][g] = 1;

    }
    }
lenarr = (int*)malloc(3*sizeof(int));
for (int j = 0; j < 3; j++)
    {
      lenarr[j] = 3;
    }
func(testarr, &n, lenarr);
if ((testarr[0][0] == 1)&&(testarr[1][0] == 1))
    {
        printf("Passed...respect+\n");
    }
    else
    {
        printf("Failed...\n");
    }
for(int p=0; p < 2; p++)
    {
        free(testarr[p]);
    }
free(testarr);
free(lenarr);
}











