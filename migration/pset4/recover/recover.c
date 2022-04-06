#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function prototype
void recover(FILE *ptr);

FILE *infile, *outfile;

int main(int argc, char *argv[])
{
    // Ensures proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Opens file for reading
    if (!(infile = fopen(argv[1], "r")))
    {
        fprintf(stderr, "Cannot open %s\n", argv[1]);
        return 1;
    }

    // Recovers deleted jpeg files
    recover(infile);

    fclose(infile);

    return 0;
}

// Recovers files
void recover(FILE *ptr)
{
    const short block = 512;

    unsigned char buffer[block];

    short count = 0, bytes = 0;

    char filename[7];

    // Finds the start of the first jpeg
    while (fread(buffer, sizeof(unsigned char), block, ptr) == block)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Creates new file
            sprintf(filename, "%03i.jpg", count);
            if (!(outfile = fopen(filename, "w")))
            {
                fprintf(stderr, "Could not open %s\n", filename);
                exit(1);
            }

            // Writes to it
            fwrite(buffer, sizeof(unsigned char), block, outfile);
            break;
        }

    }

    // Continues with the rest of the file after finding first jpeg
    while ((bytes = fread(buffer, sizeof(unsigned char), block, ptr)) == block)
    {
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            // Creates new file
            fclose(outfile);
            count++;
            sprintf(filename, "%03i.jpg", count);
            if (!(outfile = fopen(filename, "w")))
            {
                fprintf(stderr, "Could not open %s\n", filename);
                exit(1);
            }

            // Writes to it
            fwrite(buffer, sizeof(unsigned char), block, outfile);
        }

        else
        {
            fwrite(buffer, sizeof(unsigned char), block, outfile);
        }
    }

    // Writes what's left if total bytes read is less than a block
    fwrite(buffer, sizeof(unsigned char), bytes, outfile);
    fclose(outfile);
}