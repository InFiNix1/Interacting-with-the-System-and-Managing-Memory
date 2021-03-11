#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void encrypt(FILE* f, int key)
{
    int c;
    while((c=fgetc(f))!=EOF)
    {
        if(isalpha(c))
        {
            c=tolower(c);
            c-='a';
            c+=key;
            c%=26;
            c+='a';
        }
        printf("%c", c);
    }
}

int main(int argc, char** argv)
{
    if(argc!=3)
    {
        fprintf(stderr, "Too Few Arguments. Please Enter File Name.\nUsage: <Program_Name> <File Name> <Key>\n");
        return EXIT_FAILURE;
    }

    int key=atoi(argv[2]);
    if(key==0)
    {
        fprintf(stderr, "Key Cannot Be Zero(0)\n");
        return EXIT_FAILURE;
    }

    FILE* f=fopen(argv[1], "r");
    if(f==NULL)
    {
        perror("Could Not Open File");
        return EXIT_FAILURE;
    }

    encrypt(f, key);

    if(fclose(f)!=0)
    {
        perror("Could Not Close File!");
        return EXIT_FAILURE;
    }
    return 0;
}
