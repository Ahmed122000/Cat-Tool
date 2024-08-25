#include<stdio.h> 
#include<string.h>
#include<unistd.h>


void readFromFile(char* address){
    FILE *fptr; //file pointer 
    char fileContent[1024];
    fptr = fopen(address, "r");
    if(fptr == NULL){
        printf("Sorry, file not found\n");
        printf("we will exit\n");
        return; 
    }

    while(fgets(fileContent, 100, fptr)) {
        printf("%s", fileContent);
    }
    printf("\n");

    
}


void readFromSTD(){
    char buffer[1024];
    while(fgets(buffer, sizeof(buffer), stdin) != NULL){
        printf("%s", buffer);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    
    if(strcmp(argv[1], "-")!=0 && argc >1){
       
       readFromFile(argv[1]);

    }else{
        readFromSTD();
    }
    return 0; 
}