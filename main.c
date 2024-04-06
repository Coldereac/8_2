#include "functions.h"

int main() {
    struct book catalog[N];
    int size;
    char* findAuthor;
    float findPrice;
    char* findAuthorBiggestBook;
    puts("Input amount of books: ");
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        catalog[i] = initialize();
    }
    print(findByAuthor(catalog, findAuthor, size));
    print(findByPrice(catalog, findPrice, size));
    print(findBiggestBook(catalog, findAuthorBiggestBook, size));
    return 0;
}