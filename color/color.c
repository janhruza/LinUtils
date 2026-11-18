/*
 *  color.c
 *  Created by Jan Hruza on 18 Now 2026
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

# define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

char *colors[] = {
    " 0 - Black   8 - Gray",
    " 1 - Blue    9 - Light Blue",
    " 2 - Green   A - Light Green",
    " 3 - Aqua    B - Light Aqua",
    " 4 - Red     C - Light Red",
    " 5 - Purple  D - Light Purple",
    " 6 - Yellow  E - Light Yellow",
    " 7 - White   F - Bright White",
};

void ShowHelp(char* prog)
{
    printf("%s: No color specified.\n\nUsage: %s ## where:\n - The first # is the requested background color.\n - The second # is the requested foreground color.\n\n", prog, prog);
    printf("Here is a list of all available colors:\n");

    for (int i = 0; i < ARRAY_SIZE(colors); i++)
    {
        puts(colors[i]);
    }

    printf("\nExample: '%s 0F' will set the white text on a black screen.\n", prog);
}

long ReadColor(char c)
{
    char buf[2] = { c, '\0' };
    char *end;

    errno = 0;
    long value = strtol(buf, &end, 16);

    if (end == buf || *end != '\0' || errno != 0)
    {
        return -1;
    }

    return value;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ShowHelp(argv[0]);
        return EXIT_FAILURE;
    }

    if (strlen(argv[1]) != 2)
    {
        fprintf(stderr, "%s: Argument '%s' is invalid.\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    long bg = ReadColor(argv[1][0]);
    long fg = ReadColor(argv[1][1]);

    if (bg == -1 || fg == -1)
    {
        fprintf(stderr, "%s: Parsing error.\n", argv[0]);
        return EXIT_FAILURE;
    }

    // get the correct codes
    int bgCode = (bg < 8) ? 40 + bg : 100 + (bg - 8);
    int fgCode = (fg < 8) ? 30 + fg : 90 + (fg - 8);

    // change the color
    printf("\033[%d;%dm", fgCode, bgCode);
    return EXIT_SUCCESS;
}