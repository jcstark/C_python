#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
    // The file to recover
    char *infile = argv[1];

    // Open the input file
    FILE *inptr = fopen(infile, "r");

    // Check if inptr point to null
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s\n", infile);
        return 2;
    }

    // Creating the buffer of block size, 512 bytes
    BYTE buffer[BLOCK];

    // Counter for jpeg files
    int i = 0;

    // Start to read
    while (fread(&buffer, BLOCK, 1, inptr) == 1)
    {
        // Each time a header is found...
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Create a .jpg file
            char filename[50];
            sprintf(filename, "%03i.jpg", i);
            FILE *outptr = fopen(filename, "a");
            // Fill the jpg file until a new header or eof is found
            do
            {
                fwrite(&buffer, BLOCK, 1, outptr);
                fread(&buffer, BLOCK, 1, inptr);
            }
            while (!(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) && !feof(inptr));
            // Move the cursor to the beginning of the new header
            fseek(inptr, -BLOCK, SEEK_CUR);
            // Close the previous jpg
            fclose(outptr);
            i++;
        }
    }
    // Close the source file
    fclose(inptr);
    return 0;
}
