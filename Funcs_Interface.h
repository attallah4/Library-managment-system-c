#ifndef FUNCS_INTERFACE_H_INCLUDED
#define FUNCS_INTERFACE_H_INCLUDED
#include"library_Interface.h"

void swap_1(int*a,int*b);
void swap_2(int*a,int*b);
void swap_3(int*a,int*b);
int baseof_2(int x);
int binary_search(int *arr,int size,int num);
int linear_search(int *arr,int size,int num);
void bubble_sort(int*arr,int size);

void arr_print(int *arr,int size);
int str_len(char *str);
void swap_pointers(int**a,int**b);
int sub(int x,int y);
int add(int x,int y);
void str_print(char *str);
int binary_search_in_struct(BOOK_t *arr,int size,int num);

#endif // FUNCS_INTERFACE_H_INCLUDED
