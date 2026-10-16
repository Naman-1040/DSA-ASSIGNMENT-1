#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    int emp_id;

    enum {
        FULL_TIME,
        CONTRACT
    } type;

    union {
        float salary;

        struct {
            float hourly_rate;
            int hours_worked;
        } contract_info;

    } pay;

} Employee;

int main() {
    Employee *e;
    int n, i;
    float total = 0, pay;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    e = (Employee *)malloc(n * sizeof(Employee));

    if (e == NULL) {
        printf("Memory allocation failed!");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter employee name and ID: ");
        scanf("%19s %d", (e + i)->name, &(e + i)->emp_id);

        printf("Enter type (0 = Full-time, 1 = Contract): ");
        scanf("%d", (int *)&(e + i)->type);

        if ((e + i)->type == FULL_TIME) {
            printf("Enter monthly salary: ");
            scanf("%f", &(e + i)->pay.salary);
        } else {
            printf("Enter hourly rate and hours worked: ");
            scanf("%f %d",
                  &(e + i)->pay.contract_info.hourly_rate,
                  &(e + i)->pay.contract_info.hours_worked);
        }
    }

    printf("\n----- EMPLOYEE PAYSLIPS -----\n");

    for (i = 0; i < n; i++) {
        if ((e + i)->type == FULL_TIME) {
            pay = (e + i)->pay.salary;
        } else {
            pay = (e + i)->pay.contract_info.hourly_rate *
                  (e + i)->pay.contract_info.hours_worked;
        }

        printf("\nName: %s", (e + i)->name);
        printf("\nEmployee ID: %d", (e + i)->emp_id);
        printf("\nTotal Pay: %.2f\n", pay);

        total = total + pay;
    }

    printf("\nTotal Salary Bill = %.2f\n", total);

    free(e);

    return 0;
}
