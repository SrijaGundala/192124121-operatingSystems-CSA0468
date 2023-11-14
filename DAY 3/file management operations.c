#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char content[100];

    file = fopen("srija1", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "This is the content for srija1.");
    fclose(file);

    file = fopen("srija1", "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    printf("Content read from the file 'srija1':\n");
    while (fscanf(file, "%s", content) != EOF) {
        printf("%s ", content);
    }
    fclose(file);
    file = fopen("srija2", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(file, "This is the content for srija2.");
    fclose(file);
    file = fopen("srija2", "r");

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }
    printf("\nContent read from the file 'srija2':\n");
    while (fscanf(file, "%s", content) != EOF) {
        printf("%s ", content);
    }
    fclose(file);

    return 0; 
}

