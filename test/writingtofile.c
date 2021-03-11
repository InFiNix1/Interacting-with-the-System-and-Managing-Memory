#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    if(argc!=4) {printf("Too Few Arguments\nUsage: <Program_Name> <File Name> <Start> <End>\n");
        return EXIT_FAILURE;
    }

    int start=atoi(argv[2]);
    int end=atoi(argv[3]);

    FILE* f=fopen(argv[1], "w");

    if(f==NULL) {printf("File Error\n");
        return EXIT_FAILURE;
    }

    for(int i=start; i<=end; i++)
    {
        fprintf(f, "%d*%d(%d Square) = %d\n", i, i, i, i*i);
    }

    if(fclose(f)!=0) {printf("Could Not Close File\n"); 
        return EXIT_FAILURE;
    }
    return 0;
}
