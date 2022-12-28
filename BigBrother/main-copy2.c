#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char* name;
    int frequency;
    int size;
    int length;
} Student;

void readNameDB(char* filename, struct Student* students) {
    students = malloc(sizeof(struct Student));

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Couldn't read file.");
        exit(1);
    }
    char line[30];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        struct Student currentStudent = {strtok(line, "\n\t"), 0,0, 0};
    }

    free(students);

    fclose(file);
}

int main() {
    struct Student students;

    students.name = (char *) malloc(sizeof((int)  students.size));
    students.length = 0;

    readNameDB("E:\\programming\\c workspace\\c\\vornamen.txt", &students);

    return 0;
}
