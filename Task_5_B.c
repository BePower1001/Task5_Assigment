// Created by adria on 04/06/2025.
#include <stdio.h>
#include <ctype.h>

#define MAX_NUM_STUDENTS 30 // Max number of students
#define BASE_ID 4500   //init student ID


int input_grades(float grades[], int student_ids[], int *num_students) {
    int max_students;
    do {
        printf("Enter the number of students (1 - %d): ", MAX_NUM_STUDENTS);
        scanf("%d", &max_students);
        getchar();
        if (max_students < 1 || max_students > MAX_NUM_STUDENTS)
            printf("Invalid input. Number must be between 1 and %d.\n", MAX_NUM_STUDENTS);
    } while (max_students < 1 || max_students > MAX_NUM_STUDENTS);

    *num_students = 0; // initialising number of students
    for (int i = 0; i < max_students; i++) {
        float grade;
        do {
            printf("Enter grade for student %d (0 - 100, -1 to stop): ", i + 1);
            scanf("%f", &grade);
            getchar();
            if (grade == -1) {
                return 1;
            }
            if (grade < 0 || grade > 100)
                printf("Invalid input - Grade must be between 0 and 100.\n");
        } while (grade < 0 || grade > 100);
        grades[i] = grade;
        student_ids[i] = BASE_ID + i; //id generating
        (*num_students)++;
        printf("Grade %.2f recorded for student ID %d\n", grade, student_ids[i]);
    }
    return 1;
}
// function - view grades
void view_grades(float grades[], int student_ids[], int num_students) {
    printf("VIEW GRADES\n++++++++++++\n");
    if (num_students == 0) {
        printf("No grades have been entered yet.\n");
        return;
    }
    printf("ID\t Grade \n");
    printf("++++++++++++++++\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d \t%.2f\n", student_ids[i], grades[i]);
    }
}

// Function to calculate statistics
void calculate_statistics(float grades[], int num_students) {
    printf("GRADE STATISTICS\n++++++++++++++\n");
    if (num_students == 0) {
        printf("No grades to calculate statistics.\n");
        return;
    }
    float sum = 0, highest = grades[0], lowest = grades[0];
    for (int i = 0; i < num_students; i++) {
        sum += grades[i];
        if (grades[i] > highest) highest = grades[i];
        if (grades[i] < lowest) lowest = grades[i];
    }
    printf("Average Grade: %.2f\n", sum / num_students);
    printf("Highest Grade: %.2f\n", highest);
    printf("Lowest Grade: %.2f\n", lowest);
}

// analyze performance
void analyse_performance(float grades[], int num_students) {
    printf("PERFORMANCE ANALYSIS\n++++++++++++++++\n");
    if (num_students == 0) {
        printf("No grades available to analyse performance.\n");
        return;
    }
    int passed = 0, failed = 0;
    for (int i = 0; i < num_students; i++) {
        if (grades[i] >= 50) passed++;
        else failed++;
    }
    printf("Students Passed (>50): %d\n", passed);
    printf("Students Failed (<50): %d\n", failed);
}

//  sort and display grades (bubble sort)
void sort_display_grades(float grades[], int student_ids[], int num_students) {
    printf("SORTED GRADES\n++++++++++++++\n");
    if (num_students == 0) {
        printf("No grades available to sort.\n");
        return;
    }
    // temporary arrays
    float temp_grades[MAX_NUM_STUDENTS];
    int temp_ids[MAX_NUM_STUDENTS];
    for (int i = 0; i < num_students; i++) {
        temp_grades[i] = grades[i];
        temp_ids[i] = student_ids[i];
    }
    // bubble sort algorithm
    for (int i = 0; i < num_students - 1; i++) {
        for (int j = 0; j < num_students - i - 1; j++) {
            if (temp_grades[j] > temp_grades[j + 1]) {
                    // Swap grades
                float temp = temp_grades[j];
                temp_grades[j] = temp_grades[j + 1];
                temp_grades[j + 1] = temp;
                             // swap IDs
                int temp_id = temp_ids[j];
                temp_ids[j] = temp_ids[j + 1];
                temp_ids[j + 1] = temp_id;
            }
        }
    }
    printf("ID\tGrade\n");
    printf("----------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d\t%.2f\n", temp_ids[i], temp_grades[i]);
    }
}

int main(void) {
    float grades[MAX_NUM_STUDENTS];    // Array for grades
    int student_ids[MAX_NUM_STUDENTS]; // Array for IDs
    int num_students = 0;          // Number of students
    char choice;                   // Menu choice

    do {
        printf("\n--- STUDENT GRADE ANALYZER ---\n");
        printf("1. Input Grades\n2. View Grades\n3. Calculate Statistics\n");
        printf("4. Analyze Performance\n5. Sort and Display Grades\n6. Exit\n");
        printf("Enter your choice (1 - 6): ");
        choice = getchar();
        getchar();
        choice = tolower(choice);

        switch (choice) {
            case '1':
                input_grades(grades, student_ids, &num_students);
                break;
            case '2':
                view_grades(grades, student_ids, num_students);
                break;
            case '3':
                calculate_statistics(grades, num_students);
                break;
            case '4':
                analyse_performance(grades, num_students);
                break;
            case '5':
                sort_display_grades(grades, student_ids, num_students);
                break;
            case '6':
                printf("EXITING SYSTEM\n----------------\n");
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter 1–6.\n");
                break;
        }
    } while (1);
}