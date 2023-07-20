#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    
    
    struct stat file_st1, file_st2;
    
    char file1[50],file2[50];
    
    printf("Please enter the file 1 name\n");
    scanf("%s",file1);
    
    printf("Please enter the file 2 name\n");
    scanf("%s",file2);
    
    if (stat(file1, &file_st1) < 0) {
        perror("Error getting file information for file 1");
        return 1;
    }
    if (stat(file2, &file_st2) < 0) {
        perror("Error getting file information for file 2");
        return 1;
    }

    if (file_st1.st_dev == file_st2.st_dev && file_st1.st_ino == file_st2.st_ino) {
        printf("%s and %s are hard links to the same file\n", file1, file2);
    } else if (file_st1.st_mode == file_st2.st_mode && file_st1.st_ino == file_st2.st_ino) {
        printf("%s and %s are symbolic links to the same file\n", file1, file2);
    } else {
        printf("%s and %s are not linked\n", file1, file2);
    }

    return 0;
}

