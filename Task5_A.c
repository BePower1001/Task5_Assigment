// Created by adria on 29/05/2025.
#include <stdio.h>

#define MAX_NUM_STUDENTS 30 // Max number of students
#define BASE_ID 4500   //init student ID

int main(void) {
    float grades[MAX_NUM_STUDENTS];    // Array student grades
    int student_ids[MAX_NUM_STUDENTS];//array  student IDs
    int num_students;       // Num of students
    char choice;                 // menu

    printf("/// STUDENT ANALYSER ///\n");
    printf("a. Input Grades\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);
    getchar();
    if (choice == 'a' || choice == 'A') {
        //num students
        do {
            printf("Enter the number of students (1 - %d): ", MAX_NUM_STUDENTS);
            scanf("%d", &num_students);
            getchar();
            if (num_students < 1 || num_students > MAX_NUM_STUDENTS)
                printf("Invalid input. Number of students must be between 1 and %d.\n", MAX_NUM_STUDENTS);
        } while (num_students < 1 || num_students > MAX_NUM_STUDENTS);
        // input for grades
        for (int i = 0; i < num_students; i++) {
            // Validate grade
            do {
                printf("Enter grade for student %d: ", i + 1);
                scanf("%f", &grades[i]);
                getchar();
                if (grades[i] < 0)
                    printf("Invalid input. Grade must be non-negative.\n");
            } while (grades[i] < 0);
            student_ids[i] = BASE_ID + i; // simple id gen
            printf("Grade %.2f recorded for student ID %d\n", grades[i], student_ids[i]);
        }
        // prompting data
        printf("\nGrades Saved Successfully!\n");
        printf("Student Data:\n");
        printf("ID\tGrade\n");
        printf("----------------\n");
        for (int i = 0; i < num_students; i++) {
            printf("%d\t%.2f\n", student_ids[i], grades[i]);
        }
    } else {
        printf("Invalid choice. Enter 'a' or 'A'.\n");
        return 1;
    }
    return 0;
}