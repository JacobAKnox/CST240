#include <stdio.h>

char file_name[] = "HELLO.out";
char file_name2[] = "AGOOD.bin";

int main() {
    //read the binary file and output the contents to AGOOD.bin
    FILE *fp = fopen(file_name, "rb");
    FILE *fp2 = fopen(file_name2, "wb");
    if (fp == NULL) {
        printf("Error opening file %s", file_name);
        return 1;
    }
    if (fp2 == NULL) {
        printf("Error opening file %s", file_name2);
        return 1;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, fp2);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}