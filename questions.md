# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros. It shall also define macros that specify limits of integer types corresponding to types defined in other standard headers. (https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stdint.h.html)

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Thinking about this integers types, signed or unsigned and that the first bit of the signed cases are reserved for the sign, the use of the unsigned cases may be useful for only positive variables, having a higher range number than the equivalent signed type with the same amount of memory.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

In hexadecimal.

## What's the difference between `bfSize` and `biSize`?

bisize is the size of the bitmapinfoheader and bfsize is the size of the entire file.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner. (DIB is a file format designed to ensure that bitmapped graphics created using one application can be loaded and displayed in another application, retaining the same appearance as the original) 

(https://docs.microsoft.com/en-us/windows/win32/gdi/bitmap-classifications)
(https://docs.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader)

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

The biCompression field.

## Why might `fopen` return `NULL` in `copy.c`?

Because the infile was it.

## Why is the third argument to `fread` always `1` in our code?

Because the number of elements to read each time is 1.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?
int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

3. The size of RGBTRIPLE is 3 bytes, that multiply by 3 is 9. 
9 % 4 is 1; and (4 - 1) % 4 is 3.

## What does `fseek` do?

The fseek function moves the file pointer associated with the stream to a new location that is offset bytes from origin.
In the copy.c program this offset is the value of padding.

(https://en.wikibooks.org/wiki/C_Programming/stdio.h/fseek)

## What is `SEEK_CUR`?

The third argument of seek is associated with the origin location. SEEK_CUR is the case in which this location is the current location.
(https://en.wikibooks.org/wiki/C_Programming/stdio.h/fseek)
