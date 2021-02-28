#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
    const char * const * p1 = vp1;
    const char * const * p2 = vp2;
    return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
    qsort(data, count, sizeof(char *), stringOrder);
}


int main(int argc, char ** argv) 
{

    if(argc==0){
        fprintf(stderr, "Too Few Arguments.\n");
        return EXIT_FAILURE;
    }

    if(argc==1)
    {
        char** arr=NULL;
        char* line=NULL;
        size_t sz=0;
        int i=0;
        while(getline(&line, &sz, stdin)>=0)
        {
            arr=realloc(arr, (i+1)*sizeof(*arr));
            arr[i]=line;
            line=NULL;
            i++;
        }
        free(line);
        sortData(arr, i);
        for(int j=0; j<i; j++)
        {
            printf("%s", arr[j]);
            free(arr[j]);
        }
        free(arr);
    }
    else
    {
        for(int count=1; count<argc; count++)
        {
            char** arr=NULL;
            char* line=NULL;
            size_t sz=0;
            int i=0;

            FILE* f=fopen(argv[count], "r");
            if(f==NULL)
            {
                perror("Could Not Open File.\n");
                return EXIT_FAILURE;
            }
            while(getline(&line, &sz, f)>=0)
            {
                arr=realloc(arr, (i+1)*sizeof(*arr));
                arr[i]=line;
                line=NULL;
                i++;
            }
            free(line);
            sortData(arr, i);

            for(int j=0; j<i; j++)
            {
                printf("%s", arr[j]);
                free(arr[j]);
            }
            free(arr);
            if(fclose(f)!=0)
            {
                perror("Failed to Close File.\n");
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
