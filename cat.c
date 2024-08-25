#include<stdio.h> 
#include<string.h>
#include<unistd.h>

/**
 * @brief first feature of the tool: read the input form file, then print it on the screen 
 * 
 * @param address the path (relative path), to read the file
 */
void readFromFile(char* address){
    FILE *fptr;
    char fileContent[1024];
    fptr = fopen(address, "r");
    
    //return an error message and exit the tool in case of wrong path
    if(fptr == NULL){
        printf("Sorry, file not found\n");
        printf("we will exit\n");
        return; 
    }

    //read the input from the file and print it
    while(fgets(fileContent, sizeof(fileContent), fptr)) {
        printf("%s", fileContent);
    }
    printf("\n"); //print new line for clarity
}

/**
 * @brief second feature of the tool: read the input form standard input, then print it on the screen
 * 
 */
void readFromSTD(){
    char buffer[1024];
    //while there is input read it then print it 
    while(fgets(buffer, sizeof(buffer), stdin) != NULL){
        printf("%s", buffer);
    }
    printf("\n"); //print new line for clarity
}


int main(int argc, char *argv[]){
    
    if(strcmp(argv[1], "-")!=0 && argc > 1){
       
       readFromFile(argv[1]);

    }else{
        readFromSTD();
    }
    return 0; 
}