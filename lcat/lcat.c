#include <stdlib.h>
#include <stdio.h>

// simple cat with a line counter
int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    
    for (int i = 1; i < argc; i++)
    {
        FILE *file;
        char *line = NULL;
        size_t len = 0;
        ssize_t read;
        int line_count = 0;

        file = fopen(argv[i], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        while ((read = getline(&line, &len, file)) != -1) {
            line_count++;
            printf("%-4d  %s", line_count, line);
        }

        free(line);
        fclose(file);
    }

    return EXIT_SUCCESS;
}