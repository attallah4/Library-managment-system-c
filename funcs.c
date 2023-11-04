
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include"library_Interface.h"

/***************functions******************************/


void arr_print(int *arr,int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d   ",arr[i]);
    }
}



int str_len(char *str)
{
    int i=0;
    for(i=0;str[i];i++)
    {
        //nothing
    }
       return i;
}
void swap_1(int*a,int*b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


int linear_search(int *arr,int size,int num)
{
    int i=0;
    for (i=0;i<size;i++)
    {
        if(arr[i]==num)
        {
            return i;
        }
    }
    return -1;
}


int binary_search(int *arr,int size,int num)
{

    int f,l,m;
    f=0;
    l=size-1;

   while(f<=l)
    {
         m=(f+l)/2;
        if(arr[m]==num)
        {
            return m;
        }
        else if (arr[m]<num)
        {
            f=m+1;
        }
        else if (arr[m]>num)
        {
            l=m-1;
        }
    }
    return -1;
}


void bubble_sort(int*arr,int size)
{
    int flag=1;
    for (int i=0;(i<size-1&&flag);i++)
    {
        flag=0;
        for (int j=0;j<size-i-1;j++)
        {
            if (arr[j]>arr[j+1])
            {
                swap_1(&arr[j],&arr[j+1]);
                flag=1;
            }

        }
    }
}


void swap_pointers(int**a,int**b)
{
    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

void str_print(char *str)
{
    for (int i=0;str[i];i++)
    {
        printf("%c",str[i]);
    }
}


int binary_search_in_struct(BOOK_t *arr,int size,int num)
{

    int f,l,m;
    f=0;
    l=size-1;

   while(f<=l)
    {
         m=(f+l)/2;
        if(arr[m].id==num)
        {
            return m;
        }
        else if (arr[m].id<num)
        {
            f=m+1;
        }
        else if (arr[m].id>num)
        {
            l=m-1;
        }
    }
    return -1;
}
/*****************************************************/
