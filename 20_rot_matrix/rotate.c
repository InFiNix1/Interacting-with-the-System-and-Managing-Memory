#include<stdio.h>
void rotate(char matrix[10][10])
{   
    char mat[10][10];
    int q=9;
    for(int i=0; i<10; i++)
    {
        int p=0;
        for(int j=0; j<10; j++)
        {
            mat[p][q]=matrix[i][j];
            p++;
        }
        q--;
    }
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            matrix[i][j]=mat[i][j];
        }
    }
}
