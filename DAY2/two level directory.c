#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50
#define MAX_DIRECTORIES 10

struct File {
    char name[MAX_FILENAME_LENGTH];
};

struct Directory {
    char name[MAX_FILENAME_LENGTH];
    struct File files[MAX_FILES];
    int fileCount;
};

struct Directory rootDirectory[MAX_DIRECTORIES];
int directoryCount = 0;

struct Directory* createDirectory(const char* name) {
    if (directoryCount < MAX_DIRECTORIES) {
        struct Directory* newDirectory = &rootDirectory[directoryCount];
        strncpy(newDirectory->name, name, MAX_FILENAME_LENGTH);
        newDirectory->fileCount = 0;
        directoryCount++;
        return newDirectory;
    } else {
        printf("Directory limit reached. Cannot create more directories, Srija.\n");
        return NULL;
    }
}

void addFile(struct Directory* dir, const char* fileName) {
    if (dir->fileCount < MAX_FILES) {
        strncpy(dir->files[dir->fileCount].name, fileName, MAX_FILENAME_LENGTH);
        dir->fileCount++;
        printf("File '%s' added to the directory '%s', Srija.\n", fileName, dir->name);
    } else {
        printf("Directory is full. Cannot add more files, Srija.\n");
    }
}

void listFiles(struct Directory* dir) {
    int i;
    printf("Files in the directory '%s', Srija:\n", dir->name);
    for (i = 0; i < dir->fileCount; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

int main() {
    struct Directory* root = createDirectory("Root");

    if (root == NULL) {
        printf("Error creating root directory, Srija.\n");
        return 1;
    }

    printf("Two-Level Directory Organization, Srija\n");

    while (1) {
        printf("Options, Srija:\n");
        printf("1. Create a subdirectory\n");
        printf("2. Add a file to a directory\n");
        printf("3. List files in a directory\n");
        printf("4. Exit\n");
        printf("Enter your choice, Srija: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the subdirectory name, Srija: ");
                char subdirName[MAX_FILENAME_LENGTH];
                scanf("%s", subdirName);
                createDirectory(subdirName);
                break;
            case 2:
                printf("Enter the directory name to add a file, Srija: ");
                char dirName[MAX_FILENAME_LENGTH];
                int i;
                scanf("%s", dirName);
                struct Directory* targetDir = NULL;

                for (i = 0; i < directoryCount; i++) {
                    if (strcmp(rootDirectory[i].name, dirName) == 0) {
                        targetDir = &rootDirectory[i];
                        break;
                    }
                }

                if (targetDir == NULL) {
                    printf("Directory not found, Srija.\n");
                } else {
                    printf("Enter the file name to add, Srija: ");
                    char fileName[MAX_FILENAME_LENGTH];
                    scanf("%s", fileName);
                    addFile(targetDir, fileName);
                }
                break;
            case 3:
                printf("Enter the directory name to list files, Srija: ");
                char listDirName[MAX_FILENAME_LENGTH];
                scanf("%s", listDirName);
                struct Directory* listDir = NULL;

                for (i = 0; i < directoryCount; i++) {
                    if (strcmp(rootDirectory[i].name, listDirName) == 0) {
                        listDir = &rootDirectory[i];
                        break;
                    }
                }

                if (listDir == NULL) {
                    printf("Directory not found, Srija.\n");
                } else {
                    listFiles(listDir);
                }
                break;
            case 4:
                printf("Exiting the program, Srija. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, Srija. Please try again.\n");
        }
    }

    return 0;
}

