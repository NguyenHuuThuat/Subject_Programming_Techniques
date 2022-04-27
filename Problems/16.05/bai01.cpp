/*§Nhập vào một danh sách lớp sinh viên gồm các thông tin: Mã số sinh viên, Họ tên, điểm.

§Hiển thị danh sách sinh viên

§Tính điểm trung bình cộng của các sinh viên

§Tìm và hiển thị tên các sinh viên đạt điểm lớn hơn hoặc bằng giá trị trung bình cộng tính được.

§Tìm và hiển thị tên sinh viên có điểm cao nhất lớp.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct SinhVien
{
    char MSSV[10];
    char name[40];
    float diem;
};

typedef struct SinhVien SinhVien;

void nhapSinhVien(SinhVien* danh_sach, int n);
void xuatSinhVien(SinhVien* danh_sach, int n);
float diemTrungBinh(SinhVien* danh_sach, int n);
void sinhVienCaoDiemNhat(SinhVien* danh_sach, int n);
void sinhVienDiemTrenTrungBinh(SinhVien* danh_sach, int n);

int main()
{

    SinhVien* danhSach;
    int soSV;

    printf("Nhap so sinh vien: ");
    scanf("%d", &soSV);
    fflush(stdin);
    danhSach = (int*)malloc(soSV * sizeof(SinhVien));
    nhapSinhVien(danhSach, soSV);

    xuatSinhVien(danhSach, soSV);

    printf("Diem trung binh cong cua lop : %f\n", tinhDiemTrungBinh(danhSach, soSV));

    sinhVienCaoDiemNhat(danhSach, soSV);

    sinhVienDiemTrenTrungBinh(danhSach, soSV);

    free(danhSach);

    return 0;

}

void nhapSinhVien(SinhVien* danh_sach, int n)
{

    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("Nhap sinh vien thu %d\n", i + 1);
        printf("     Nhap MSSV:");
        gets(danh_sach[i].MSSV);
        printf("     Nhap ten:");
        gets(danh_sach[i].name);
        printf("     Nhap diem:");
        scanf_s("%f", &danh_sach[i].diem);
        fflush(stdin);
    }

}

void xuatDanhSachSinhVien(SinhVien* danh_sach, int n)
{

    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("Sinh vien thu %d\n", i + 1);
        printf("   MSSV:");
        puts(danh_sach[i].MSSV);
        printf("   Ten:");
        puts(danh_sach[i].name);
        printf("   Diem: %f\n", danh_sach[i].diem);
    }

}

float diemTrungBinh(SinhVien* danh_sach, int n)
{

    int i = 0;
    float tong = 0;

    for (i = 0; i < n; i++)
    {
        tong += danh_sach[i].diem;
    }

    return tong / n;

}

void sinhVienCaoDiemNhat(SinhVien* danh_sach, int n)
{

    int i = 0;

    SinhVien result = danh_sach[0];

    for (i = 0; i < n; i++)
    {
        if (danh_sach[i].diem > result.diem)
        {
            result = danh_sach[i];
        }
    }

    printf("Sinh vien diem cao nhat:\n");
    printf("   MSSV:");
    puts(result.MSSV);
    printf("   Ten:");
    puts(result.name);
    printf("   Diem: %f\n", result.diem);

}

void sinhVienDiemTrenTrungBinh(SinhVien* danh_sach, int n)
{

    int i = 0;

    float trungBinh = tinhDiemTrungBinh(danh_sach, n);

    printf("Danh sach sinh vien diem lon hon trung binh:\n");

    for (i = 0; i < n; i++)
    {
        if (danh_sach[i].diem > trungBinh)
        {
            printf("   MSSV:");
            puts(danh_sach[i].MSSV);
            printf("   Ten:");
            puts(danh_sach[i].name);
            printf("   Diem: %f\n", danh_sach[i].diem);
        }
    }

}
