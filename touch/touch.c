/*
 *  touch.c - Simple touch command implementation.
 *  Created by Jan Hruza on 18 Nov 2026
 */ 

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        fprintf(stderr, "%s: No file provided.\nUsage: %s file1 [file2 ...]\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }


    for (int i = 1; i < argc; i++)
    {
        if (argv[i] == NULL) break;

        FILE *fp = fopen(argv[i], "w");
        if (fp == NULL)
        {
            perror("fopen()");
            continue;
        }

        fwrite(NULL, 0, 0, fp);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}