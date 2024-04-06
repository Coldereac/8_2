//
// Created by malinka on 06.04.24.
//

#ifndef INC_8_2_FUNCTIONS_H
#define INC_8_2_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXL 41
#define N 10

struct book // шаблон структури з дескриптором book
{
    char title[MAXL];
    char author[MAXL];
    int pages;
    float price;
};

struct array{
    int size;
    struct book catalog[N];
};

struct book initialize();

struct array input();

void print(struct book output);

void printArray(struct array output);

struct array findByAuthor(char *author, struct array catalog);

struct array findByPrice(float min_price, float max_price, struct array catalog);

struct book findBiggestBook(char *author, struct array catalog);

char *allocateLine();

#endif //INC_8_2_FUNCTIONS_H
