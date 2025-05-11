#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} diem;

void doc(int *n, FILE **f, char *filename, diem **a) {
    printf("Nhap ten file input: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    *f = fopen(filename, "r");

    if(*f == NULL) {
        printf("Loi mo file");
        return;
    }

    fscanf(*f, "%d", n);
    *a = (diem*)malloc(* n * sizeof(diem));

    for(int i = 0; i < *n; i++) {
        fscanf(*f, "%d %d", &(*a)[i].x, &(*a)[i].y);
    }

    fclose(*f);
}

float gapkhuc(int n, diem *a) {
    float gk = 0;

    for(int i = 0; i < n - 1; i++) {
        gk += sqrt(pow(a[i].x - a[i + 1].x, 2) + pow(a[i].y - a[i + 1].y, 2));
    }

    return gk;
}

int demcathoanh(int n, diem *a) {
    int dem = 0;

    for(int i = 0; i < n; i++) {
        if(a[i].y * a[i + 1].y < 0) {
            dem++;
        }
    }

    return dem;
}

int main() {
    int n;
    diem *a;
    FILE *f;
    char filename[50];

    doc(&n, &f, filename, &a);

    printf("Do dai duong gap khuc la: %.1f\n", gapkhuc(n, a));

    printf("So diem cat truc hoanh la: %d", demcathoanh(n, a));

    free(a);

    return 0;
}