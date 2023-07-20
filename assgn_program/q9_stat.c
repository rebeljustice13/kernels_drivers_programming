#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
   
    struct stat file_stat;
    char f_name[50];
    printf("Please enter the file name\n");
    scanf("%s",f_name);
    if(stat(f_name, &file_stat) < 0){
    	perror("Error in getting file size");
    	return 1;
    }
    

    printf("File size: %ld bytes\n", file_stat.st_size);

    return 0;
}

