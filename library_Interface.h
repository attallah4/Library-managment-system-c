#ifndef LIBRARY_INTERFACE_H_INCLUDED
#define LIBRARY_INTERFACE_H_INCLUDED

#define MAX_BOOKS 100

typedef struct {

unsigned char title[100];
unsigned char author[100];
unsigned char status[50];
int year;
int no_of_cpys;
float price;
int id ;

}BOOK_t;



/****************************functions prototype***********************/

void add_book(BOOK_t *book);

void print_Library(BOOK_t *book);

void borrow_book(BOOK_t*book);

void delete_book(BOOK_t*book);

void buy_book(BOOK_t*book);

void scan_book(BOOK_t *book);

void library_menu_init(void);

#endif // LIBRARY_INTERFACE_H_INCLUDED
