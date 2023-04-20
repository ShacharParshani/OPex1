//
// Created by parshas on 18/04/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    char *path_variable = getenv("PATH"); // Get the current value of the PATH variable
    char *new_directories = NULL;
    for (int i=1; i<argc; i++) {
        if (new_directories == NULL) {
            new_directories = strdup(argv[i]); /
        } else {
            char *temp = realloc(new_directories, strlen(new_directories) + strlen(argv[i]) + 2); // Allocate more memory for additional directories
            if (temp == NULL) {
                perror("realloc failed");
                exit(1);
            }
            new_directories = temp;
            strcat(new_directories, ":");
            strcat(new_directories, argv[i]);
        }
    }

    if (new_directories != NULL) {
        char *new_path = malloc(strlen(path_variable) + strlen(new_directories) + 2);
        sprintf(new_path, "%s:%s", path_variable, new_directories); // Concatenate the new directories to the end of the PATH string
        int overwrite = 1;
        int result = setenv("PATH", new_path, overwrite); // Set the new value of the PATH variable
        if (result == -1) {
            perror("setenv failed");
            exit(1);
        }
        free(new_path);
        free(new_directories);
    }
    char command[100];
    printf("$ ");
    fflush(stdout);
    fgets(command, sizeof(str), stdin);


    return 0;
}
