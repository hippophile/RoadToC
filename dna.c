#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_file(const char* filename, char** content) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = (char*)malloc(file_size + 1);
    if (*content == NULL) {
        fclose(file);
        fprintf(stderr, "Memory allocation error\n");
        return -1;
    }

    size_t bytes_read = fread(*content, 1, file_size, file);

    if (ferror(file)) {
        fclose(file);
        free(*content);
        fprintf(stderr, "Error reading file: %s\n", filename);
        return -1;
    }

    (*content)[bytes_read] = '\0';

    fclose(file);

    return bytes_read;
}


void find_and_print_longest_match(const char* sequence1, const char* sequence2) {
    int seq1_len = strlen(sequence1);
    int seq2_len = strlen(sequence2);

    int longest_start = -1;
    int longest_length = 0;

    int current_start = -1;
    int current_length = 0;

    for (int i = 0; i < seq1_len; ++i) {
        for (int j = 0; j < seq2_len; ++j) {
            int k = i;
            int l = j;

            while (k < seq1_len && l < seq2_len && sequence1[k] == sequence2[l]) {
                if (current_length == 0) {
                    // Start of a new match
                    current_start = k;
                }
                current_length++;
                k++;
                l++;
            }

            // End of the current match
            if (current_length > longest_length) {
                longest_length = current_length;
                longest_start = current_start;
            }
            current_length = 0;
        }
    }

    // Print the longest match
    if (longest_length > 0) {
        printf("Longest matching substring: %.*s\n", longest_length, sequence1 + longest_start);
    } else {
        printf("No matching substring found.\n");
    }
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *seq1, *seq2;
    int seq1_size, seq2_size;

    seq1_size = read_file(argv[1], &seq1);
    seq2_size = read_file(argv[2], &seq2);

    if (seq1_size == -1 || seq2_size == -1) {
        free(seq1);
        free(seq2);
        return EXIT_FAILURE;
    }

    find_and_print_longest_match(seq1, seq2);
printf("File 1: %s, Size: %d\n", argv[1], seq1_size);
printf("File 2: %s, Size: %d\n", argv[2], seq2_size);
printf("Seq1: %s\n", seq1);
printf("Seq2: %s\n", seq2);

    free(seq1);
    free(seq2);

    return EXIT_SUCCESS;
}