#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, *a, dem = 0, tich = 1;
    float tbn;
    FILE *f;
    char filename[50];

    printf("Nhap ten file input: ");
    fgets(filename, 50, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    f = fopen(filename, "r");

    if(f == NULL) {
        printf("Loi mo file");
        return 1;
    }

    fscanf(f, "%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        fscanf(f, "%d", &a[i]);
    }

    fclose(f);

    for(int i = 0; i < n; i++) {
        if(a[i] >= 10 && a[i] <= 100) {
            dem++;
            tich *= a[i];
        }
    }

    if(dem == 0) {
        printf("Khong tinh duoc!");
    }
    else {
        printf("Trung binh nhan cua cac phan tu la: %.1f", (float)tich / dem);
    }

    free(a);

    return 0;
}