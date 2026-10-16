#include <stdio.h>

typedef struct {
    int row, col, value;
} term;

void fast_transpose(term a[], term b[]) {
    int row_terms[100], starting_pos[100];
    int i, j, num_cols;

    num_cols = a[0].col;

    /* Initialize row_terms */
    for (i = 0; i < num_cols; i++) {
        row_terms[i] = 0;
    }

    /* Count non-zero elements in each column */
    for (i = 1; i <= a[0].value; i++) {
        row_terms[a[i].col]++;
    }

    /* Calculate starting positions */
    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++) {
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    }

    /* Print arrays */
    printf("\nrow_terms[]: ");
    for (i = 0; i < num_cols; i++) {
        printf("%d ", row_terms[i]);
    }

    printf("\nstarting_pos[]: ");
    for (i = 0; i < num_cols; i++) {
        printf("%d ", starting_pos[i]);
    }

    /* Header of transposed matrix */
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    /* Fast transpose */
    for (i = 1; i <= a[0].value; i++) {
        j = starting_pos[a[i].col];

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;

        starting_pos[a[i].col]++;
    }
}

int main() {
    term a[100], b[100];
    int matrix[20][20];
    int rows, cols, i, j, k = 1;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Store matrix using triples */
    a[0].row = rows;
    a[0].col = cols;
    a[0].value = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].value = matrix[i][j];
                k++;
                a[0].value++;
            }
        }
    }

    /* Print original triples */
    printf("\nOriginal matrix triples:\n");
    printf("Row Col Value\n");

    for (i = 0; i <= a[0].value; i++) {
        printf("%d %d %d\n", a[i].row, a[i].col, a[i].value);
    }

    /* Perform fast transpose */
    fast_transpose(a, b);

    /* Print transposed triples */
    printf("\nTransposed matrix triples:\n");
    printf("Row Col Value\n");

    for (i = 0; i <= b[0].value; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
    }

    printf("\nTransposed triples are already in row-major order.\n");

    return 0;
}
