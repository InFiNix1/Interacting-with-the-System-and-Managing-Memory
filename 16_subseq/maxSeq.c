#include<stdio.h>
#include<stdlib.h>
#include"maxSeq.h"
size_t maxSeq(int* array, size_t n)
{
    size_t maxlength=0;
    size_t length=1;
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    for(size_t i=1; i<n; i++)
    {
        if(array[i]> array[i-1])
        {
            length++;
        }
        else
        {
            if(length>maxlength)
            {
                maxlength=length;
            }
            length=1;
        }
    }
    if(length>maxlength)
    {
        maxlength=length;
    }
    return maxlength;

}
