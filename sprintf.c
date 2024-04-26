#include <stdio.h>

int main() {
    char stack[5] = {'(', '1', '+', '2', ')'}; // Το stack σας
    char str[6]; // Το string στο οποίο θα αποθηκευτούν τα στοιχεία του stack

    // Χρησιμοποιήστε τη συνάρτηση sprintf για να μετατρέψετε τα στοιχεία του stack σε string
    sprintf(str, "%c%c%c%c%c", stack[0], stack[1], stack[2], stack[3], stack[4]);

    printf("%s\n", str); // Εκτυπώνει: [1+2]

    return 0;
}
