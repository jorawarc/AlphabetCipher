#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "alphacipher.h"

// Command line args must be in following format:
// [flags | default = encrypt] [key] [message]

// Constraints:
// flag must either be -e or -d
// message must only contain letters.
// message can not contain numbers or special characters

int main(int argc, char** argv){

    int flag = 1;
    int arg;

    while((arg = getopt(argc,argv,"ed")) != -1){
        switch(arg){
            case 'e':
                flag = 1;
                break;
            case 'd':
                flag = 0;
                break;
        }

    }

    cipher(flag,argv[2],argv[3]);

}
