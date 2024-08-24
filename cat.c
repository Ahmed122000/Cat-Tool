#include<stdio.h> 
#include<string.h>
#include<unistd.h>


int main(int argc, char *argv[]){
    FILE* fptr = fopen(argv[1], "r");
    
    if(fptr == NULL){
        printf("Sorry, file not found\n");
        printf("we will exit\n");
        return -1; 
    }

    char fileContent[100];

    // Read the content and print it
    while(fgets(fileContent, 100, fptr)) {
        printf("%s", fileContent);
    }

    return 0; 
}