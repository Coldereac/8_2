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

/*
 * Створити масив структур типу struct book. Написати функції введення та
виведення елементів цього масиву.
Додати функції пошуку книги за автором, та за ціною.
Знайти «найбільшу» книгу за кількістю сторінок вказаного автора.
 */

struct book // шаблон структури з дескриптором book
{
    char title[MAXL];
    char author[MAXL];
    int pages;
    float price;
};
typedef struct book book;

struct array{
    int size;
    struct book *catalog;
};
typedef struct array array;

book initialize();

array input();

void print(struct book output);

void printArray(struct array output);

array findByAuthor(char *author, struct array catalog);

array findByPrice(float min_price, float max_price, struct array catalog);

book findBiggestBook(char *author, struct array catalog);

char *allocateLine();

#endif //INC_8_2_FUNCTIONS_H
