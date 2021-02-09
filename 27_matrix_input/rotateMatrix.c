#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define ROW_SIZE 12


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
int checkFile(FILE* f)
{
    char row[ROW_SIZE];
    int col=0;
    while(fgets(row, ROW_SIZE, f)!=NULL)
    {
        for(int i=0; i<10; i++)
        {
            if(row[i]=='\n')
            {
                fprintf(stderr, "Too Few Values in Row");
                return 0;
            }
        }
        if(strchr(row, '\n')==NULL)
        {
            fprintf(stderr, "Too many Values in Row.\n");
            return 0;
        }
        col++;
    }
    if(col==10)
    {
        return 1;
    }
    else
    {
        fprintf(stderr, "Too Many Columns.\n");
        return 0;
    }
}
int main(int argc, char** argv)
{
    if(argc!=2)
    {
        fprintf(stderr, "Too Few Arguments.\n");
        return EXIT_FAILURE;
    }

    FILE* f=fopen(argv[1], "r");
    if(f==NULL)
    {
        fprintf(stderr, "Could Not Open File.\n");
        return EXIT_FAILURE;
    }

    if(!(checkFile(f)))
    {
        fprintf(stderr, "Values in File Does Not Match Requriements of 10x10 Matrix.\n");
        if(fclose(f)!=1)
        {
            fprintf(stderr, "File Could Not Be closed\n");
        }
        return EXIT_FAILURE;
    }
    if(fclose(f)!=0)
    {
        fprintf(stderr, "File Could Not Be closed\n");
        return EXIT_FAILURE;
    }

    f=fopen(argv[1], "r");

    if(f==NULL)
    {
        fprintf(stderr, "Could Not Open File1.\n");
        return EXIT_FAILURE;
    }

    char matrix[10][10];

    int c;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            c=fgetc(f);
            if(c=='\n')
            {
                c=fgetc(f);
            }
            matrix[i][j]=c;
        }
    }

    rotate(matrix);

    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }

    if(fclose(f)!=0)
    {
        fprintf(stderr, "File Could Not Be closed2\n");
        return EXIT_FAILURE;
    }
    return 0;
}
