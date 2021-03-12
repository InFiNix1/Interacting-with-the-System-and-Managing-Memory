#include<stdio.h>
#include<stdlib.h>
size_t maxSeq(int* array, size_t n);
int main()
{
    int arr[]={};
    size_t ans1=maxSeq(arr, sizeof(arr)/sizeof(int));
    if(ans1!=0)
    {
        return EXIT_FAILURE;
    }

    int arr2[]={1,2,1,3,5,7,2,4,6,9};
    size_t ans2=maxSeq(arr2, sizeof(arr2)/sizeof(int));
    if(ans2!=4)
    {
        return EXIT_FAILURE;
    }
    int arr3[]={1,2,3,4};
    size_t ans3=maxSeq(arr3, sizeof(arr3)/sizeof(int));
    if(ans3!=4)
    {
        return EXIT_FAILURE;
    }
    int arr4[]={1,-2,3,4};
    size_t ans4=maxSeq(arr4, sizeof(arr4)/sizeof(int));
    if(ans4!=3)
    {
        return EXIT_FAILURE;
    }
    int arr5[]={10, 9, 8, 7};
    size_t ans5=maxSeq(arr5,sizeof(arr5)/sizeof(int));
    if(ans5!=1)
    {
        return EXIT_FAILURE;
    }
    int arr6[]={1, 2, 2, 4};
    size_t ans6=maxSeq(arr6,sizeof(arr6)/sizeof(int));
    if(ans6!=2)
    {
        return EXIT_FAILURE;
    }
    int arr7[]={3, -4, 5, 6 };
    size_t ans7=maxSeq(arr7,sizeof(arr7)/sizeof(int));
    if(ans7!=3)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
