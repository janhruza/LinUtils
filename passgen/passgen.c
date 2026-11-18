/*
 *  passgen.c - Simple password generator utility.
 *  Created by Jan Hruza on 18 Now 2026
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

static unsigned int randomize_seed(void)
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    unsigned int seed = (unsigned int)(ts.tv_nsec ^ ts.tv_sec ^ (getpid() << 16));
    srand(seed);
    return seed;
}

size_t FillArray(char* buf, size_t buf_len, char* chars, size_t chars_len)
{
    size_t count = 0;
    for (int i = 0; i < buf_len; i++)
    {
        buf[i] = chars[rand() % chars_len];
        count++;
    }

    buf[buf_len -1] = 0;
    return count;
}

static char* arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789/()[]{}<>#$@!\"\'-.,\\`";

int main(int argc, char **argv)
{
    (void)randomize_seed();
    
    if (argc == 1)
    {
        // show help
        fprintf(stderr, "%s: No arguments passed.\nUsage: %s [pass_len]\n", argv[0], argv[0]);
        return EXIT_SUCCESS;
    }

    char *endptr;
    long len = strtol(argv[1], &endptr, 10);

    if (endptr == argv[1] || *endptr != 0 || len <= 0 || len >= 256)
    {
        fprintf(stderr, "%s: Argument '%s' is not a valid input value.\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    len += 1; // add space for the null terminator
    char buf[len];
    size_t read = FillArray(buf, len, arr, strlen(arr));
    if (read != len)
    {
        fprintf(stderr, "FillArray failed. Only %zu/%zu characters was generated.\n", read, len);
        return EXIT_FAILURE;
    }

    printf("%s\n", buf);
    return EXIT_SUCCESS;
}