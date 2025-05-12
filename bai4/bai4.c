#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void doc(int n, int m, FILE **fout, char *filename, int ***a) {
    *fout = fopen(filename, "r");
    if (*fout == NULL) {
        printf("Khong mo duoc file!\n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {  
        for (int j = 0; j < n; j++) { 
            fscanf(*fout, "%d", &(*a)[i][j]);
        }
    }

    printf("Ma tran da doc:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d", (*a)[i][j]);
        }
        printf("\n");
    }

    fclose(*fout);
}

void maxhang(int n, int m, int **a) {
    for (int i = 0; i < m; i++) {  
        int max = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Gia tri lon nhat cua hang %d la: %d\n", i + 1, max);
    }
}

int main() {
    int n, m;
    int **a;
    FILE *f, *fin, *fout;
    char filename[50];

    printf("Nhap ten file input: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    f = fopen(filename, "r");
    fin = fopen(filename, "r");

    int demcot = 0, demptu = 0;
    while (!feof(f)) {
        char x;
        fscanf(f, "%c", &x);
        if (x == ' ') continue;
        if (x == '\n') break;
        demcot++;
    }
    printf("So cot la: %d", demcot);

    n = demcot;

    while (!feof(fin)) {
        int x;
        fscanf(fin, "%d", &x);
        demptu++;
    }
    printf("\nSo hang la: %d\n", demptu);

    m = demptu / demcot;

    a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    doc(n, m, &fout, filename, &a);

    maxhang(n, m, a);

    for (int i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
