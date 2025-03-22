#pragma once

struct Book
{
   int code;
   char author[40];
   char title[40];
   int stock;
   float price;
   int year;
   int category;
};




void menu_books(int *opt, struct Book *list_books);
void insert_book(struct Book *b);
int get_num_books();
void print_lst_books(struct Book *list_books, int num);
void print_book(struct Book b);
void choose_criterion_sort(struct Book *b);
void sort_by_authors(struct Book *list_books);
void sort_by_titles(struct Book *list_books);
void sort_by_prices(struct Book *list_books);
void sort_by_years(struct Book *list_books);
void sort_by_categories(struct Book *list_books);
void update_book(char *search_title, struct Book *list_books);
void delete_book(char *search_title, struct Book *list_books);
int search_book(char *search_title, struct Book *list_books);
void choose_criterion_find(struct Book *b, char *crit);
void find_author(struct Book *b, struct Book *crit_lst_books, char *crit);
void find_title(struct Book *b, struct Book *crit_lst_books, char *crit);
void find_price(struct Book *b, struct Book *crit_lst_books);
void find_year(struct Book *b, struct Book *crit_lst_books);
void find_category(struct Book *b, struct Book *crit_lst_books, char *crit);
struct Book get_book(int pos, struct Book *list_books);
struct Book default_book();
struct Book get_book_by_id(int code, struct Book *list_books);
