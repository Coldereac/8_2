//
// Created by malinka on 06.04.24.
//

#ifndef INC_8_2_FUNCTIONS_H
#define INC_8_2_FUNCTIONS_H

#include <stdio.h>
#include <string.h>

#define MAXL 41
#define N 10

struct book // шаблон структури з дескриптором book
{
    char title[MAXL];
    char author[MAXL];
    int pages;
    float price;
};

struct book initialize();

void print(struct book output);

struct book findByAuthor(struct book catalog[], char *author, int size);

struct book findByPrice(struct book catalog[], float price, int size);

struct book findBiggestBook(struct book catalog[], char *author, int size);

#endif //INC_8_2_FUNCTIONS_H
