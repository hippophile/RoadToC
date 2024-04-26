#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Συνάρτηση για τη δυαδική αναζήτηση
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Ελέγχουμε αν το στοιχείο είναι στη μέση
        if (arr[m] == x)
            return m;

        // Εάν το x είναι μικρότερο, αγνοούμε τα δεξιά
        if (arr[m] < x)
            l = m + 1;
        // Εάν το x είναι μεγαλύτερο, αγνοούμε τα αριστερά
        else
            r = m - 1;
    }
    // Εάν δε βρεθεί το στοιχείο
    return -1;
}

int main() {
    // Δημιουργία ενός πίνακα με 30 θέσεις
    int arr[30];
    // Αρχικοποίηση seed για την rand
    srand(time(0));

    // Γεμίζουμε τον πίνακα με τυχαίους αριθμούς
    printf("Ο πίνακας:\n");
    for (int i = 0; i < 30; i++) {
        arr[i] = rand() % 100; // Τυχαίος αριθμός από 0 έως 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ταξινόμηση του πίνακα για να εφαρμοστεί η δυαδική αναζήτηση
    // Μπορούμε να χρησιμοποιήσουμε οποιοδήποτε αλγόριθμο ταξινόμησης εδώ
    // Για την απλότητα, χρησιμοποιούμε τον αλγόριθμο ταξινόμησης φυσαλίδας
    for (int i = 0; i < 29; i++) {
        for (int j = 0; j < 29 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Ταξινομημένος πίνακας:\n");
    for (int i = 0; i < 30; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Επιλογή τυχαίου αριθμού Χ
    int x = arr[rand() % 30];
    printf("Τυχαίος αριθμός για αναζήτηση: %d\n", x);

    // Δυαδική αναζήτηση
    int result = binarySearch(arr, 0, 29, x);
    if (result == -1)
        printf("Ο αριθμός %d δεν βρέθηκε στον πίνακα.\n", x);
    else
        printf("Ο αριθμός %d βρέθηκε στη θέση %d.\n", x, result + 1);

    return 0;
}
