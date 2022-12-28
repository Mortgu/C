#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char* name;
    int frequency;
} Student;

static void insert(Student *s, char *name, int frequency) {
    s->name = name;
    s->frequency = frequency;
}

struct Student* readNameDB(char* filename, struct Student* students, size_t arraySize) {
    //students = malloc(sizeof(struct Student));

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Couldn't read file.");
        exit(1);
    }

    char chunk[50];
    size_t length = sizeof(chunk);
    char *line = malloc(length);

    if (line == NULL) {
        perror("Unable to allocate memory for the line buffer.");
        exit(1);
    }

    line[0] = '\n';

    while (fgets(chunk, sizeof(chunk), file) != NULL) {
        size_t length_used = strlen(line);
        size_t chunk_used = strlen(chunk);

        if (length - length_used < chunk_used) {
            length *= 2;

            if ((line = realloc(line, length)) == NULL) {
                perror("Unable to reallocate memory for the line buffer.");
                free(line);
                exit(1);
            }
        }

        strncpy(line + length_used, chunk, length - length_used);
        length_used += chunk_used;

        if (line[length_used - 1] == '\n') {
            fputs(line, stdout);
            fputs("|*\n", stdout);

            //printf("line length: %zd\n", length_used);

            // EMPTY LINE BUFFER
            line[0] = '\n';
        }
    }

    fclose(file);
    free(line);

    printf("\n\tMax line size: %zd\n", length);

    return students;
}

int main() {
    Student students[] = {};

    Student *test = readNameDB("E:\\programming\\c workspace\\c\\BigBrother\\vornamen.txt", students, sizeof(students)/sizeof(students[0]));

    //printf("%s\n", students[0].name);

    return 0;
}
