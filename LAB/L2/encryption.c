// By Jacob Knox
// for CST240 Lab 2 due: 1/25/2022


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 100;

int get_key() {
    // prompt user for key, try again if not between 0 and 25
    int key;
    int result;
    printf("Enter key, a number between 0 and 25: ");
    result = scanf("%d", &key);
    while (key < 0 || key > 25 || result != 1) {
        scanf("%*[^\n]"); //clears input buffer
        printf("Key must be between 0 and 25: ");
        scanf("%d", &key);
    }
    return key;
}

char * encrypt_ceaser(char plaintext[MAX], int key) {
    // convert plaintext to ciphertext in all caps, plaintext must be all lowercase text
    int i;
    char * ciphertext = malloc(MAX);
    for (i = 0; i < MAX; i++) {
        if (plaintext[i] == '\0') {
            break;
        }
        ciphertext[i] = (plaintext[i] - 97 + key) % 26 + 65;
        //97 is ascii for 'a', 65 is ascii for 'A'
    }
    return ciphertext;
}

char * encrypt_rail_fence(char plaintext[MAX]) {
    // return ciphertext in all caps, plaintext will be all uppercase
    //uses 2 rail fence encryption
    int i;
    int len = strlen(plaintext);
    char * ciphertext = malloc(MAX);
    for (i = 0; i < MAX; i++) {
        if (plaintext[i] == '\0') {
            break;
        }
        if (i < len/2) {
            ciphertext[i] = plaintext[2*i];
        } else {
            ciphertext[i] = plaintext[2*(i-len/2)+1];
        }
    }
    return ciphertext;
}

int main(int argc, char **argv) 
{
    char plaintext[MAX];
    char * ceaser_text;
    char * rail_text; 
    int plain; 
    int key;
    char continue_ = 'y'; 

    if (argc != 2) 
    { 
        printf("Usage: ./ecryption <filename>\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        printf("Could not open file %s\n", filename);
        return 2;
    }

    // file is garenteed to be lowercase a-z, on one line, less than 100 characters
    fgets(plaintext, 100, fp);
    fclose(fp);

    key = get_key();

    ceaser_text = encrypt_ceaser(plaintext, key);

    printf("From Ceaser: %s\n", ceaser_text);

    rail_text = encrypt_rail_fence(ceaser_text);

    printf("After Rail Fence: %s\n", rail_text);

    //save to cipher.txt
    fp = fopen("cipher.txt", "w");
    if (fp == NULL) 
    {
        printf("Could not open file for saving cipher.txt\n");
        return 2;
    }

    fprintf(fp, "%s", rail_text);
    fclose(fp);

    free(rail_text);
    free(ceaser_text);
    return 0; 
} 