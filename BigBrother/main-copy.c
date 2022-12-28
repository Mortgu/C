#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char* name;
    int count;
};

struct Student* readNameDB(char* filename, struct Student *students) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Couldn't read file.");
        exit(1);
    }
    char line[30];
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        struct Student currentStudent = {strtok(line, "\n\t"), i};
        students[i] = currentStudent;
        ++i;
    }

    fclose(file);

    return students;
}

int main() {
    struct Student students_test[] = {};

    struct Student *students = readNameDB("E:\\programming\\c workspace\\c\\vornamen.txt", students_test);
    printf("%d", 1);

    int i;

    for (i = 0; i < sizeof(students)/sizeof(students[0]); i++) {
        printf("%s\n", students[i].name);
        printf("%d\n", students[i].count);
    }
}
