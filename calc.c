#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char * argv[]){
    // What I want
    // ./calc
    char methodType[255];
    printf("Type method\n");
    // type input:
    fgets(methodType, sizeof methodType, stdin);

    printf("%s", "methodType:");
    printf("%s\n", methodType);
    char calc[5] = {};
    for (int i = 0; i < 4; i++){
        calc[i] = methodType[i];
    }
    int result= strcmp(calc, "calc");

    if (result == 0){
        int sum = 0;
        /*
            Start from first number
            Assume each number lengths are 1
        */
        for (int i = 5; i < sizeof methodType; i+=2){
            if (strtok(&methodType[i], " ") != NULL){
                sum += atoi(&methodType[i]);
            }
        }


        // calc 1 2 3 4 5
        // result = N
        printf("%s", "sum:");
        printf("%d\n", sum);
    }
    



}