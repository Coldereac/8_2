//
// Created by malinka on 06.04.24.
//

#include "functions.h"

book initialize() {
    book input;
    getchar();
    printf("Введіть назву книги \n");
    fgets(input.title, MAXL, stdin);
    input.title[strlen(input.title) - 1] = '\0';
    printf("Введіть ПІБ автора \n");
    fgets(input.author, MAXL, stdin);
    input.author[strlen(input.author) - 1] = '\0';
    printf("Введіть кількість сторінок.\n");
    scanf("%d", &input.pages);
    printf("Введіть ціну.\n");
    scanf("%f", &input.price);
    return input;
}

array input() {
    array input;
    puts("Input amount of books: ");
    scanf("%d", &input.size);
    input.catalog =  (book*) malloc(input.size * sizeof (book));
    for (int i = 0; i < input.size; ++i) {
        printf("Книга №%d: \n", i + 1);
        input.catalog[i] = initialize();
    }
    return input;
}

void print(book output) {
    if (strcmp(output.title, "NotFound") != 0) {
        printf("\"%s\" %s сторінок: %d коштує %.2f грн.\n", output.title, output.author, output.pages, output.price);
    } else{
        printf("Not found");
    }
}

void printArray(array output) {
    for (int i = 0; i < output.size; ++i) {
        print(output.catalog[i]);
    }
}

array findByAuthor(char *author, array catalog) {
    array founded;
    founded.size = 0;
    founded.catalog = (book *) malloc(N * sizeof(book));
    for (int i = 0; i < catalog.size; ++i) {
        if (strcmp(catalog.catalog[i].author, author) == 0) {
            founded.catalog[founded.size++] = catalog.catalog[i];
        }
    }
    founded.catalog = (book *) realloc(founded.catalog, founded.size * sizeof(book));
    return founded;
}

array findByPrice(float min_price, float max_price, array catalog) {
    array founded;
    founded.size = 0;
    founded.catalog = (book *) malloc(N * sizeof(book));
    for (int i = 0; i < catalog.size; ++i) {
        if (catalog.catalog[i].price < max_price && catalog.catalog[i].price > min_price) {
            founded.catalog[founded.size++] = catalog.catalog[i];
        }
    }
    founded.catalog = (book *) realloc(founded.catalog, founded.size * sizeof(book));
    return founded;
}
//
book findBiggestBook(char *author, array catalog) {
    int biggest = 0;
    array byAuthor = findByAuthor(author, catalog);
    book biggestBook;
    if (byAuthor.catalog == NULL) {
        strcpy(biggestBook.title, "NotFound");
    } else {
        for (int i = 0; i < byAuthor.size; ++i) {
            if (byAuthor.catalog[i].pages > byAuthor.catalog[biggest].pages) {
                biggest = i;
            }
        }
        biggestBook = byAuthor.catalog[biggest];
    }
    free(byAuthor.catalog);
    return biggestBook;
}

char *allocateLine() {
    return (char *) malloc(MAXL * sizeof(char));
}