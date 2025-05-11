#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoten[50];
    float toan, ly, hoa, tong;
} thisinh;

void doc(int *n, FILE **f, char *filename, thisinh **a) {
    printf("Nhap ten file input: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    *f = fopen(filename, "r");

    if (*f == NULL) {
        printf("Loi mo file\n");
        exit(1);
    }

    fscanf(*f, "%d\n", n);
    *a = (thisinh *)malloc(*n * sizeof(thisinh));

    for (int i = 0; i < *n; i++) {
        fgets((*a)[i].hoten, 50, *f);
        (*a)[i].hoten[strcspn((*a)[i].hoten, "\n")] = '\0';
        fscanf(*f, "%f %f %f\n", &(*a)[i].toan, &(*a)[i].ly, &(*a)[i].hoa);
        (*a)[i].tong = (*a)[i].toan + (*a)[i].ly + (*a)[i].hoa;
    }

    fclose(*f);
}

void trungtuyen(int n, thisinh *a, float dchuan) {
    thisinh tam;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j].tong > a[i].tong) {
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }

    printf("---Danh sach cac thi sinh trung tuyen---\n");
    printf("%-25s %10s %10s %10s %10s\n", "Ho ten", "Toan", "Ly", "Hoa", "Tong diem");
    for (int i = 0; i < n; i++) {
        if (a[i].tong >= dchuan) {
            printf("%-25s %10.1f %10.1f %10.1f %10.1f\n", a[i].hoten, a[i].toan, a[i].ly, a[i].hoa, a[i].tong);
        }
    }
}

void timthisinh(int n, thisinh *a) {
    char tentim[50];
    printf("Nhap ten thi sinh can tim: ");
    getchar(); 
    fgets(tentim, 50, stdin);
    tentim[strcspn(tentim, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].hoten, tentim) == 0) {
            printf("Ho ten: %s\n", a[i].hoten);
            printf("Toan: %.1f\t Ly: %.1f\t Hoa: %.1f\n", a[i].toan, a[i].ly, a[i].hoa);
            return;
        }
    }

    printf("Khong tim thay thi sinh co ten %s\n", tentim);
}

int main() {
    int n;
    thisinh *a;
    FILE *f;
    char filename[50];

    doc(&n, &f, filename, &a);

    float dchuan;
    printf("Nhap diem chuan: ");
    scanf("%f", &dchuan);
    trungtuyen(n, a, dchuan);

    timthisinh(n, a);

    free(a);

    return 0;
}