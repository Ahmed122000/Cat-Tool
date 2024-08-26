#include<stdio.h> 
#include<string.h>
#include<unistd.h>


int line =1; 
void printWithLineNumber(FILE* fptr){
    char content[1024];

    while(fgets(content, sizeof(content), fptr)) {
        printf("%d %s", line++, content);
    }
}

void printWithoutLineNumber(FILE* fptr){
    char content[1024];
    while(fgets(content, sizeof(content), fptr)) {
        printf("%s", content);
    }
}

/**
 * @brief first feature of the tool: read the input form file, then print it on the screen 
 * 
 * @param address the path (relative path), to read the file
 */
void readFromFile(char* address, char printLines){
    FILE *fptr;
    fptr = fopen(address, "r");
    
    //return an error message and exit the tool in case of wrong path
    if(fptr == NULL){
        printf("Sorry, file not found\n");
        printf("we will exit\n");
        return; 
    }

    //read the input from the file and print it
    if(printLines == 'y'){
        printWithLineNumber(fptr);
    }
    else{
        printWithoutLineNumber(fptr);
    }
}

/**
 * @brief second feature of the tool: read the input form standard input, then print it on the screen
 * 
 */
void readFromSTD(char printLines){
    char buffer[1024];
    //while there is input read it then print it 
    if(printLines == 'y'){
        printWithLineNumber(stdin);
    }
    else{
        printWithoutLineNumber(stdin);
    }
}


int main(int argc, char *argv[]){
    char lineNumber = 'n';
    for(int i =0; i < argc; i++){
        if(strcmp(argv[i], "-n") ==0){
            lineNumber = 'y';
            argc-=1; 
        }
    }


    if(strcmp(argv[1], "-")!=0 && argc > 1){
        //go thorugh all files for concatenation
        for(int i = 1; i < argc; i++)
            readFromFile(argv[i], lineNumber);

    }else{
        readFromSTD(lineNumber);
    }


    printf("\n");
    return 0; 
}