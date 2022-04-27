/*Tạo 1 mảng A gồm n xâu kí tự (n nhập từ bàn phím). 

1. In các xâu ra màn hình, mỗi xâu trên 1 dòng. 

2. NHập vào 1 xâu P (xâu mẫu). Tìm kiếm sự xuất hiện của xâu P trong mảng A, chỉ rõ xâu P xuất hiện trong xâu thứ bao nhiêu của mảng A và vị trí bắt đầu xuất hiện P.

3. Chuẩn hóa các xâu trong mảng theo cách như sau: Các "từ" cách nhau đúng 1 dấu cách; Loại bỏ các dấu cách ở đầu và cuối xâu; Các từ trong xâu đều bắt đầu bởi chữ hoa, còn lại là chữ thường.

4. Đếm số lượng “từ” trong mỗi xâu của mảng.*/

#include<stdio.h>
#include<string.h>

void xoaKhoangTrang(char S[]);
void nhapMangXau(char S[][100], int n);
void xuatMangXau(char S[][100], int n);
void timXauMau(char s1[], char xauMau[]);
int demTu(char S[]);

int main()
{

    char array[100][100], xauMau[100];
    int n, i = 0;

    printf("Nhap so xau n = ");
    scanf_s("%d", &n);
    fflush(stdin);

    nhapMangXau(array, n);
    xuatMangXau(array, n);

    printf("Nhap xau mau = ");
    gets_s(xauMau);

    for (i = 0; i < n; i++)
    {
        printf("Tai xau thu %d : ", i + 1);
        timXauMau(array[i], xauMau);
    }

    for (i = 0; i < n; i++)
    {
        xoaKhoangTrang(array[i]);
    }

    printf("Sau khi chuan hoa:\n");
    xuatMangXau(array, n);

    for (i = 0; i < n; i++)
    {
        printf("Xau thu %d co %d tu\n", i + 1, demTu(array[i]));
    }

    return 0;

}

void nhapMangXau(char S[][100], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        printf("Nhap xau thu %d:", i);
        gets_s(S[i]);
    }

}

void xuatMangXau(char S[][100], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
    {
        puts(S[i]);
    }

}

void timXauMau(char s1[], char s2[])
{
    int m = 0, n = 0, vitri = -1, len = strlen(s2);

    while (s1[n] != '\0')
    {

        if (s1[n] == s2[m])
        {     // neu ky tu dau tien la giong nhau
            vitri = n;
            // tiep tuc so sanh

            while (s1[n] == s2[m] && s1[n] != '\0')
            {
                n++;
                m++;
            }

            // Neu day ky tu nay co do dai bang chuoi tim kiem
            if (m == len && (s1[n] == ' ' || s1[n] == '\0'))
            {
                printf("Xau mau xuat hien tai vi tri %d\n", vitri);
            }
        }
        else
        {            // Neu ky tu dau tien khong giong nhau
            n++;
            if (s1[n] == '\0')
            {
                printf("Xau mau khong xuat hien\n");
                break;
            }
        }
        n++;
        m = 0;
    }

}

void xoaKhoangTrang(char S[])
{
    int i, len, j;
    len = strlen(S);
    //xoa khoang trang dau xau
    while (S[0] == 32)
    {
        for (j = 0; j < len - 1; j++)
        {
            S[j] = S[j + 1];
        }

        S[len - 1] = '\0';
        len -= 1;
    }

    for (i = 0; i < len; i++)
    {
        //Xoa khoang trang giua xau
        if (S[i] == 32)
        {
            if (S[i + 1] == 32)
            {
                for (j = i + 1; j < len - 1; j++)
                {
                    S[j] = S[j + 1];
                }

                S[len - 1] = '\0';
                len -= 1;
                i--;
            }
        }
    }

    if (S[len - 1] == 32)
    {
        S[len - 1] = '\0';
    }

}

int demTu(char S[])
{
    int dem = 1, i = 0;
    for (i = 0; i < strlen(S); i++)
    {
        if (S[i] == 32)
        {
            dem++;
        }
    }
    return dem;
}


