#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main(int argc, char *argv[]) {
    // Check if there are no arguments (except the program name)
    if (argc == 1) {
        printf("Error: No words to count.\n");
        return 1;  // Exit with an error code
    }


    char words[MAX_WORDS][MAX_LENGTH];
    int frequencies[MAX_WORDS];
    int word_count = 0;


    for (int i = 1; i < argc; i++) {

        int found = 0;
        for (int j = 0; j < word_count; j++) {
            if (strcmp(argv[i], words[j]) == 0) {
                frequencies[j]++;
                found = 1;
                break;
            }
        }


        if (!found) {
            strcpy(words[word_count], argv[i]);
            frequencies[word_count] = 1;
            word_count++;
        }
    }

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], frequencies[i]);
    }

    return 0;
}
