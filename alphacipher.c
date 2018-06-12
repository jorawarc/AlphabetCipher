// alphacipher.c

#include "alphacipher.h"

// Helper function to convert ascii decimal value
// to an ordinate position in the alphabet
int asciiToPostion(char letter){
    if(isupper(letter)){
        return letter - 'A';
    }
    else if(islower(letter)){
        return letter - 'a';
    }
    else{
        return -1;
    }
}

// encodes and decodes a message using a key 
// flag = 1 will encode the message
// flag = 0 will decode the message
void cipher(int flag, char key[], char message[]){
    int messageLen = strlen(message);
    char newMessage[messageLen+1];

    for(int i = 0;i<messageLen;i++){
        char keyCurrent = key[i % strlen(key)];
        char messageChar;

        if(flag == 1){
         // Calculates the ecoded character
            messageChar = (asciiToPostion(keyCurrent) + asciiToPostion(message[i])) % 26 + 'a';
        }
        else if (flag == 0){
        // Calculates the decoded character
            messageChar = (asciiToPostion(message[i]) - asciiToPostion(keyCurrent) + 26) % 26 + 'a';
        }

        newMessage[i] = messageChar;
    }
    newMessage[messageLen] = '\0';
   printf("%s\n",newMessage);
}