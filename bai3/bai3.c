#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doc(int *n, int *m, FILE **f, char *filename, int ***a) {
    printf("Nhap ten file input: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    *f = fopen(filename, "r");

    if (*f == NULL) {
        printf("Loi mo file\n");
       return;
    }

    fscanf(*f, "%d %d\n", n, m);
    *a = (int **)malloc(*n * sizeof(int *));
    for (int i = 0; i < *n; i++) {
        (*a)[i] = (int *)malloc(*m * sizeof(int));
    }

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            fscanf(*f, "%d", &(*a)[i][j]);
        }
    }

    fclose(*f);
}

float trungbinhcong(int n, int m, int **a) {
    float tbc;
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            tong += a[i][j];
        }
    }
    tbc = (float)tong / (n * m);
    return tbc;
}

int main() {
    int n, m;
    int **a;
    FILE *f;
    char filename[50];

    doc(&n, &m, &f, filename, &a);

    printf("Trung binh cong = %.2f\n", trungbinhcong(n, m, a));

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}