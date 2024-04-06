//
// Created by malinka on 06.04.24.
//

#include "functions.h"

struct book initialize() {
    struct book input;
    printf("Введіть назву книги \n");
    fgets(input.title, MAXL, stdin);
    printf(" Введіть ПІБ автора \n");
    fgets(input.author, MAXL, stdin);
    printf("Введіть кількість сторінок.\n");
    scanf("%d", &input.pages);
    printf("Введіть ціну.\n");
    scanf("%f", &input.price);
    return input;
}

void print(struct book output) {
    printf("%s %s сторінок: %d коштує %.2f грн.\n", output.title, output.author, output.pages, output.price);
}

struct book findByAuthor(struct book catalog[], char *author, int size) {
    int found = 0;
    int i;
    for (i = 0; i < size && !found; ++i) {
        if (strcmp(catalog[i].author, author) == 0) {
            found = 1;
        }
    }
    return catalog[i];
}

struct book findByPrice(struct book catalog[], float price, int size) {
    int found = 0;
    int i;
    for (i = 0; i < size && !found; ++i) {
        if (catalog[i].price == price) {
            found = 1;
        }
    }
    return catalog[i];
}

struct book findBiggestBook(struct book catalog[], char *author, int size) {
    int biggestBookNumber = 0;
    for (int i = 0; i < size; ++i) {
        if (strcmp(catalog[i].author, author) == 0) {
            if (catalog[biggestBookNumber].pages < catalog[i].pages){
                biggestBookNumber = i;
            }
        }
    }
    return catalog[biggestBookNumber];
}