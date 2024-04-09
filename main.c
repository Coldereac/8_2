#include "functions.h"

int main() {
    struct array catalog = input();
    char *findAuthor = allocateLine();
    float minPrice, maxPrice;
    char *findAuthorBiggestBook = allocateLine();
    puts("Input author to search: ");
    getchar();
    gets(findAuthor);
    printArray(findByAuthor(findAuthor, catalog));
    free(findAuthor);
    puts("Input min and max price to search: ");
    scanf("%f%f", &minPrice, &maxPrice);
    printArray(findByPrice(minPrice, maxPrice, catalog));
    puts("Input author to search the biggest book");
    getchar();
    gets(findAuthorBiggestBook);
    print(findBiggestBook(findAuthorBiggestBook, catalog));
    free(findAuthorBiggestBook);
    return 0;
}