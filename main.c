#include "func.h"
int main(void){
FILE*input;
FILE*output;
char temp[512];
int** arr;
int* len_arr;
int n=0,m=0,p=0;
char* string;
input=fopen("data.dat.txt", "r");
output=fopen("data.res.txt", "w");
if(!input || !output)
    {
        printf("Error! Cannot open file...\n");
        return 1;
    }
while(fgets(temp, sizeof(temp), input)!=NULL)
    {
     n++;
    }
fseek(input, 0, 0);
arr=(int**)malloc(n*sizeof(int*));
len_arr=(int*)malloc(n*sizeof(int));
if (arr==NULL || len_arr==NULL)
    {
        printf("Error! Cannot allocate memory...\n");
        return 1;
    }
for (int i=0; i<n; i++)
    {
        string=fgets(temp, sizeof(temp), input);
        p=0;
        m=0;
        while (string[p]!='\0')
        {
            p++;
        }
        for (int k=0; k<p-1; k++)
            {
                if (string[k]==' ')
                    {
                        m++;
                    }
            }
         len_arr[i]=m+1;
    }
fseek(input, 0, 0);
for(int i=0; i<n; i++)
    {
        arr[i]=(int*)malloc(len_arr[i]*sizeof(int));
        for (int j=0; j<len_arr[i]; j++)
            {
                fscanf(input, "%d", &(arr[i][j]));
            }
    }

printf("Isnatchalniy massiv:\n");
for (int i=0; i<n; i++)
    {
        for(int j=0; j<len_arr[i]; j++)
            {
                printf("%d ", arr[i][j]);
            }
        printf("\n");
    }
func(arr, &n, len_arr);
printf("Otvet:\n");
for (int i=0; i<n; i++)
    {
        for(int j=0; j<len_arr[i]; j++)
            {
                printf("%d ", arr[i][j]);
                fprintf(output,"%d ", arr[i][j]);
            }
        printf("\n");
        fprintf(output, "\n");
    }

free(len_arr);
for(int i=0; i<n; i++)
    {
        free(arr[i]);
    }
free(arr);
fclose(input);
fclose(output);
printf("Starting autotest:\n");
Autotest();
return 0;
}
