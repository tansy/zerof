/*
 * zerof.c
 *
 * This program is distributed under General Public License version 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int flength (FILE *f);

#define BUF_SIZE 1024*4


int main (int argc, char** argv)
    {
    char *program_name;
    FILE *FIN;
    long int size;
    char* buf;
    int i;

    if(argc<2)
        {
        printf("Zero bytes in a file.\n Usage: zerof <file-name>\n");
        return 0;
        }
    program_name = argv[1];
    FIN = fopen(argv[1], "rb+");
    if (FIN == NULL)
        {
        fprintf(stderr, "Cannot open input file %s\n", program_name);
        return 1;
        }
    buf = (char*)calloc(BUF_SIZE, 1);
    size = flength (FIN);
    while((size -= BUF_SIZE) > 0)
        {
        fwrite(buf, BUF_SIZE, 1, FIN);
        }
    fwrite(buf, (size + BUF_SIZE), 1, FIN);

    return 0;
    } /* int main (int argc, char** argv) */

long int flength (FILE *f)
    {
    long int pos;
    long int end;

    pos = ftell (f);
    fseek (f, 0, SEEK_END);
    end = ftell (f);
    fseek (f, pos, SEEK_SET);

    return end;
    }

/* EOF zerof.c */
