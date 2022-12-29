#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 1500

typedef struct Student {
    char* name;
    int frequency;
    struct Student* next;
} Student;

Student* create_student(char* name, int frequency) {
    Student* newStudents = malloc(sizeof(Student));

    if (NULL != newStudents) {
        newStudents->name = name;
        newStudents->frequency = frequency;
        newStudents->next = NULL;
    }

    return newStudents;
}

Student* add_student(Student* students, Student student) {
    Student* newStudent = create_student(student.name, student.frequency);

    if (NULL != newStudent) {
        newStudent->next = students;
    }

    return newStudent;
}

void readNameDB(char* filename) {

}

int main() {
    char data[MAX_LINES][MAX_LENGTH];

    // Open file in reading mode.
    FILE *file;

    file = fopen("E:\\programming\\c workspace\\c\\BigBrother\\vornamen.txt" , "r");

    // Exit program when file couldn't be read.
    if (file == NULL) {
        perror("Couldn't read file!");
        return 1;
    }

    int line = 0;

    while (!feof(file) && !ferror(file)) {
        if (fgets(data[line], MAX_LENGTH, file) != NULL) {
            ++line;
        }
    }

    fclose(file);

    for (int i = 0; i < line; i++)
        printf("%s", data[i]);

    return 0;
}