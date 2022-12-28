#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char* name;
    int frequency;
} Student;

struct Student* readNameDB(char* filename, Student *students, size_t arraySize) {
    // Allocate memory for an array of students structs.
    //students = (struct Student*) malloc(sizeof(struct Student));

    struct Student currentStudent = {"test", 2};

    students[2] = currentStudent;

    //printf("%llu", sizeof(students)/ sizeof(students[0]));

    return students;
}

int main() {
    struct Student students[] = {
            {"Oskar", 1},
            { "Oskar2", 2},
    };

    //printf("%d", sizeof(students) / sizeof students[0]);

    Student *test = readNameDB("vorname.txt", students, sizeof(students)/sizeof(students[0]));
    printf("%s\n", students[2].name);

    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        //printf("%d\n", test[i].frequency);
    }

    return 0;
}