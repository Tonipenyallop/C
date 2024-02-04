#include <stdio.h>
int main(int argc, const char *argv[]){
    int counter = 1;
    while (counter < argc){
        printf("%s ", argv[counter]);
        counter += 1;
    }
    printf("%s\n","");
    return 0;
}