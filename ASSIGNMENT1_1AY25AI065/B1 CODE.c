#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main() {
    struct Student *ptr;
    int n, i, choice;
    float sum = 0;
    struct Student *top;

    printf("Enter number of students: ");
    scanf("%d", &n);

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter roll number, name and marks:\n");
        scanf("%d %19s %f",
              &(ptr + i)->roll_no,
              (ptr + i)->name,
              &(ptr + i)->marks);
    }

    printf("\nDo you want to add 2 more students? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        ptr = (struct Student *)realloc(
            ptr,
            (n + 2) * sizeof(struct Student)
        );

        if (ptr == NULL) {
            printf("Memory reallocation failed!");
            return 1;
        }

        for (i = n; i < n + 2; i++) {
            printf("\nEnter roll number, name and marks:\n");
            scanf("%d %19s %f",
                  &(ptr + i)->roll_no,
                  (ptr + i)->name,
                  &(ptr + i)->marks);
        }

        n = n + 2;
    }

    top = ptr;

    for (i = 0; i < n; i++) {
        sum = sum + (ptr + i)->marks;

        if ((ptr + i)->marks > top->marks) {
            top = ptr + i;
        }
    }

    printf("\nAverage Marks = %.2f", sum / n);

    printf("\n\nStudent with Highest Marks:");
    printf("\nRoll Number: %d", top->roll_no);
    printf("\nName: %s", top->name);
    printf("\nMarks: %.2f\n", top->marks);

    free(ptr);

    return 0;
}
