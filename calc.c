#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, const char * argv[]){
    /*  update input to be -> ["calc", "123", "12", "1"] */
    // 1. Create 2D array
    // 2. Traverse array 
    // 3. If first element is not "calc", return 0
    // 4. Convert current element to integer
    // 5. Add current element value to "Sum"
    // 6. Return "Sum"

    
    char input[255];
    printf("Gimme your order sir\n");
    
    char *arr[255];
    // type input:
    fgets(input, sizeof input, stdin);
    
    char *token = strtok(input, " ");
    int idx = 0;
    
    while (token != NULL){
        arr[idx] = token;
        token = strtok(NULL, " ");
        idx += 1;

    }


    char *methodType = arr[0];
    int result = strcmp(methodType, "calc");
    if (result != 0){
        printf("%s\n", "method should be 'calc'");
        return 0;
    }


    int sum = 0;
    for (int i = 1; i < idx; i++){
        sum += atoi(arr[i]);
    }

    printf("%s", "sum:");
    printf("%d\n", sum);
}