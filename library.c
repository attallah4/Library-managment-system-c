#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Funcs_Interface.h"
#include "library_Interface.h"

char books=0;
char id=0;
BOOK_t library[MAX_BOOKS];

void library_menu_init(void)
{
    int choice=7;
    do
    {
        printf("********************************************************\n");
        printf("*                WELCOME TO NTI LIBRARY                *\n");
        printf("*********************************************************\n");
        printf("1. Add Book\n");
        printf("2. Print Library\n");
        printf("3. Borrow Book\n");
        printf("4. Delete Book\n");
        printf("5. Buy Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_book(library);
            break;
        case 2:
            print_Library(library);
            break;
        case 3:
            borrow_book(library);
            break;
        case 4:
            delete_book(library);
            break;
        case 5:
            buy_book(library);
            break;
        case 6:
            system("cls");
            printf("***************************************************************\n");
            printf("*          Thank you for using our services. Goodbye.         *\n");
            printf("***************************************************************\n");
            choice=7;
            break;
        default:
            system("cls");
            printf("***************************************************************\n");
            printf("*               Wrong choice!! Please try again.              *\n");
            printf("***************************************************************\n");
            break;
        }
    }
    while (choice != 7);
}

void  add_book(BOOK_t *book)
{
    int add_flag=0;
    if (books<MAX_BOOKS)
    {
        printf("\n\nEnter the book's title: ");
        fflush(stdin);
        gets((char*)book[id].title);
        for (int i=0; i<id; i++)
        {
            if (!strcmp((char*)book[i].title,(char*)book[id].title))
            {
                add_flag=1;
                book->no_of_cpys++;
                books++;
                break;
            }
        }

        if (!add_flag||!id)
        {
            scan_book(book);
            books++;
            id++;
        }
        else
        {
            system("cls");
            printf("        **********************************\n");
            printf("        *       the book is added        *\n");
            printf("        **********************************\n");
            printf("\n\n\n");
        }
    }
    else
    {
        system("cls");
        printf("        **********************************\n");
        printf("        *  you can't add book right now  *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }
}



void scan_book(BOOK_t *book)
{

    printf("Enter the book's author: ");
    fflush(stdin);
    gets((char*)book[id].author);
    printf("Enter the book's puplication year: ");
    fflush(stdin);
    scanf("%d", &book[id].year);
    printf("Enter the book's price: ");
    fflush(stdin);
    scanf("%f", &book[id].price);
    book[id].id=id;
    book[id].no_of_cpys=1;
    strcpy((char*)book[id].status,"available");
    system("cls");
    printf("        **********************************\n");
    printf("        *         operation done         *\n");
    printf("        **********************************\n");
    printf("\n\n\n");

}


void print_Library(BOOK_t *book)
{
    system("cls");
    if(!id)
    {
        system("cls");
        printf("        **********************************\n");
        printf("        *   There is no books right now  *\n");
        printf("        **********************************\n");
        printf("\n\n\n");

    }
    else
    {


        for(int i=0; i<id; i++)
        {

            printf("\n");
            printf("***************************************************************\n");
            printf("ID :");
            printf("%d\n",book[i].id);
            printf("Title :");
            str_print((char*)book[i].title);
            printf("\n");
            printf("Author Name :");
            str_print((char*)book[i].author);
            printf("\n");
            printf("Publication Year :");
            printf("%d\n",book[i].year);
            printf("Price :");
            printf("%.2f$\n",book[i].price);
            printf("Number of copies :");
            printf("%d\n",book[i].no_of_cpys );
            printf("status :");
            str_print((char*)book[i].status);
            printf("\n***************************************************************\n");
            printf("\n");
        }
    }
}
void borrow_book(BOOK_t*book)
{

    int i_d=0;
    print_Library(book);
    printf("\nchoose the book's id :");
    scanf("%d",&i_d);

    if (i_d<=id &&book[i_d].no_of_cpys)
    {

        book[i_d].no_of_cpys--;

        system("cls");
        printf("        **********************************\n");
        printf("        *         operation done         *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
        if(!book[i_d].no_of_cpys)
        {
            strcpy((char*)book[i_d].status,"Not available");
        }
    }

    else
    {
        system("cls");
        printf("        **********************************\n");
        printf("        *         Not available          *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }

}

void delete_book(BOOK_t*book)
{

    int i_d=0;
    print_Library(book);
    printf("\nchoose the book's id :");
        scanf("%d",&i_d);
    if (i_d<id )
    {

        books-=book[i_d].no_of_cpys;
        book[i_d]=book[id-1];
        id--;

        system("cls");
        printf("        **********************************\n");
        printf("        *         operation done         *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }

    else
    {
        system("cls");
        printf("        **********************************\n");
        printf("        *         Not available          *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }


}

void buy_book(BOOK_t*book)
{
    int i_d=0,num=0;
    print_Library(book);
    printf("\nchoose the book's id :");
    scanf("%d",&i_d);
    if (i_d<=id &&books<MAX_BOOKS)
    {

        printf("\nnumbers of books to be bought from 1 to %d  :",MAX_BOOKS-books);
        scanf("%d",&num);
        if(!book[i_d].no_of_cpys)
        {
            strcpy((char*)book[i_d].status,"available");
        }
        book[i_d].no_of_cpys+=num;
        books+=num;


        system("cls");
        printf("        **********************************\n");
        printf("        *         operation done         *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }

    else
    {
        system("cls");
        printf("        **********************************\n");
        printf("        *         Not available          *\n");
        printf("        **********************************\n");
        printf("\n\n\n");
    }


}
