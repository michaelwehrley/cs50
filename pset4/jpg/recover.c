/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
int build_png(FILE* inptr, char title[], int count, FILE* outptr);
int is_png_header(BYTE block[]);
const int PNG_BLOCK = 512;
BYTE block[PNG_BLOCK];

int main(int argc, char* argv[]) {
  // Open memory card file:
  FILE* inptr = fopen("card.raw", "r");
  if (inptr == NULL) {
    printf("something went wrong and file could not be opened");
    return 1;
  }

  char title[8]; // string literal
  int count = 0;
  sprintf(title, "00%d.jpg", count);
  FILE* outptr = fopen(title, "w");
  if (outptr == NULL) {
    printf("something went wrong and file could not be opened");
    return 1;
  }
  return build_png(inptr, title, count, outptr);
}

int build_png(FILE* inptr, char title[], int count, FILE* outptr) {
  if (fread(&block, sizeof(BYTE), PNG_BLOCK, inptr) == PNG_BLOCK) {
    if (is_png_header(block)) {
      // fclose(outptr);
      sprintf(title, "00%d.jpg", count);
      // Open a new jpg
      FILE* outptr = fopen(title, "w");
      if (outptr == NULL) {
        printf("something went wrong and file could not be appended");
        return 1;
      } else {
        fwrite(block, sizeof(block), 1, outptr);
        count++;
        return build_png(inptr, title, count, outptr);
      }
    } else {
      sprintf(title, "00%d.jpg", count);
      fwrite(block, sizeof(block), 1, outptr);
      return build_png(inptr, title, count, outptr);
    }
  } else {
    return 0;
  }
}

int is_png_header(BYTE block[]) {
  // Find beginning of jpg: 0xff 0xd8 0xff & then it is either 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe8, 0xe9, 0xea, 0xeb, 0xec, 0xed, 0xee, of 0xef. Put another way, the fourth byte’s first four bits are 1110

  const int FIRST = 0xff;
  const int SECOND = 0xd8;
  const int THIRD = 0xff;
  const int LOWER_BOUND = 223;
  const int UPPER_BOUND = 240;

  if (block[0] == FIRST &&
           block[1] == SECOND &&
           block[2] == THIRD &&
           block[3] > LOWER_BOUND &&
           block[3] < UPPER_BOUND) {
    return 1;
  } else {
    return 0;
  }
}
