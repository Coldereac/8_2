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

struct array input(){
    struct array input;
    puts("Input amount of books: ");
    scanf("%d", &input.size);
    for (int i = 0; i < input.size; ++i) {
        input.catalog[i] = initialize();
    }
    return input;
}

void print(struct book output) {
    printf("%s %s сторінок: %d коштує %.2f грн.\n", output.title, output.author, output.pages, output.price);
}

void printArray(struct array output) {
    for (int i = 0; i < output.size; ++i) {
        print(output.catalog[i]);
    }
}

struct array findByAuthor(char *author, struct array catalog) {
    struct array founded;
    founded.size = 0;
    for (int i = 0; i < catalog.size; ++i) {
        if (strcmp(catalog.catalog[i].author, author) == 0) {
            founded.catalog[founded.size++] = catalog.catalog[i];
        }
    }
    return founded;
}

struct array findByPrice(float min_price, float max_price, struct array catalog) {
    struct array founded;
    founded.size = 0;
    for (int i = 0; i < catalog.size; ++i) {
        if (catalog.catalog[i].price < max_price && catalog.catalog[i].price > min_price) {
            founded.catalog[founded.size++] = catalog.catalog[i];
        }
    }
    return founded;
}

struct book findBiggestBook(char *author, struct array catalog) {
    int biggest = 0;
    for (int i = 0; i < catalog.size; ++i) {
        if(strcmp(catalog.catalog[i].author, author) == 0){
            if (catalog.catalog[i].pages > catalog.catalog[biggest].pages){
                biggest = i;
            }
        }
    }
    return catalog.catalog[biggest];
}

char *allocateLine() {
    return (char *) malloc(MAXL * sizeof(char));
}