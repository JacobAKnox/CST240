/********************************************************************
This program takes in a lowercase letter, key (integer) and output ciphertext 
based on Caesar Cryptosystem. Input is guaranteed to be lowercase a-z. In this 
example ONLY, key is guaranteed to be +integer <1000. This key "guarantee" 
is NOT the same as specification of lab which forces key to be 0-25. 
*********************************************************************/
#include <stdio.h>

int main() 
{
    char plaintext, ciphertext; 
    int plain; 
    char continue_ = 'y'; 

    int key; while (continue_ == 'y') 
    { 
        printf("Enter lowercase character to be encrypted using Caesar: "); 
        scanf(" %c", &plaintext); 

        plain = (int)(plaintext) - 97; // plaintext - 97 works also 
        printf("%d\n", plain); 

        printf("Enter key, a number between 0 and 1000:"); 
        scanf("%d", &key); 
        key = key%26; // can’t do this in your program. Need to force user to input 0-25 

        printf("Key is %d\n", key); 
        ciphertext = ((plain+key)%26)+97; 

        printf("Ciphertext is %c\n",ciphertext); 
        printf("Enter y to do again: "); 
        
        scanf(" %c", &continue_); 
    } 
    return 0; 
} 