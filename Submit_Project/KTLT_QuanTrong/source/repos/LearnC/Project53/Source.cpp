/* Nhập vào một chuỗi ký tự, hãy đếm số lần xuất hiện của  các ký tự chữ cái
theo hai cách:
 a. Có phân biệt chữ hoa và chữ thường.
 b. Không phân biệt chữ hoa và chữ thường. */

#include<stdio.h>
#include<string.h>
#include<ctype.h>

void demChu(char* c);
void demChuPhanBiet(char* c);


int main() {
    char x[100];
    printf("Nhap xau ky tu: \n");
    fgets(x, 99, stdin);

    printf("Xau vua nhap la: \n");
    puts(x);

    demChu(x);
    demChuPhanBiet(x);

    return 0;
}

void demChu(char* c) {
    int i;
    int count = 0;
    int size = strlen(c);

    for (i = 0; i < size; i++) {
        if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122)) {
            count++;
        }
    }
    printf("\nSo chu cua xau la: %d", count);
}

void demChuPhanBiet(char* c) {
    int i;
    int count1 = 0;
    int count2 = 0;
    int size = strlen(c);

    for (i = 0; i < size; i++) {
        if (c[i] >= 65 && c[i] <= 90) {
            count1++;
        }
    }
    for (i = 0; i < size; i++) {
        if ((c[i] >= 97 && c[i] <= 122)) {
            count2++;
        }
    }

    printf("\nSo chu hoa cua xau la: %d", count1);
    printf("\nSo chu thuong cua xau la: %d", count2);
}