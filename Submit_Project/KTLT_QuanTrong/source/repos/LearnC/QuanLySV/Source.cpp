/*Ex 6.4. Sinh viên gồm các thông tin: mã sinh viên là số nguyên 4 chữ số, họ và tên đầy đủ,
tuổi, giới tính, điểm. Trong đó họ tên đầy đủ gồm: họ, đệm, tên. Điểm gồm: điểm
toán, văn, anh và trung bình 3 môn này. Tạo struct phù hợp mô tả thông tin môn học,
điểm, thông tin sinh viên. Viết hàm nhập vào thông tin đầy đủ cho 1 sinh viên và trả
về sinh viên vừa nhập. Hãy tạo mảng 100 sinh viên và thực hiện:
a) Thêm mới sinh viên vào danh sách sinh viên.
b) Hiển thị danh sách sinh viên hiện có. Thông tin của mỗi sinh viên phải hiển thị đầy
đủ trên một dòng.
c) Sắp xếp danh sách sinh viên theo tên a->z.
d) Sắp xếp danh sách sinh viên theo điểm trung bình 3 môn giảm dần.
e) Tìm sinh viên có tên được nhập vào từ bàn phím.
f) Ghi thông tin sinh viên trong danh sách hiện có vào file SV.txt.
g) Viết menu cho phép người dùng thực hiện các tùy chọn. Trong đó có chức năng
thoát chương trình. */


#include<stdio.h>

// Dinh Nghia kieu du lieu
struct DiemMH {
	float toan;
	float van;
	float anh;
	float diemTB;
};

struct hoten {
	char ho[20];
	char ten[20];
	char dem[20];
};

struct SinhVien {
	int mssv;
	struct hoten HovaTen;
	int tuoi;
	char gioitinh[10];
	struct DiemMH diem;
};

typedef struct SinhVien SV;

//khai bao nguyen mau ham
void nhapDiem(struct DiemMH* diem);
void nhapHoTen(struct hoten* HovaTen);
SV nhapSV();

int main() {
	SV dssv[100];
	int slsv = 0;
	SV sv;

	sv = nhapSV();
	dssv[slsv++] = sv;
	printf("MSSV: %d    Ho va ten: %s %s  ", sv.mssv, sv.HovaTen.ho, sv.HovaTen.ten);

	return 0;
}

void nhapDiem(struct DiemMH* diem) {
	printf("Toan: ");
	scanf_s("%f", &diem->toan);
	printf("Van: ");
	scanf_s("%f", &diem->van);
	printf("Anh: ");
	scanf_s("%f", &diem->anh);

	diem->diemTB = (diem->toan + diem->van + diem->anh) / 3;
}

void nhapHoTen(struct hoten* HovaTen) {
	printf("Ho: ");
	scanf_s("%c", &HovaTen->ho);
	printf("Dem: ");
	getchar();
	gets_s(HovaTen->dem);
	printf("Ten: ");
	scanf_s("%c", &HovaTen->ten);
}

SV nhapSV() {
	SV sv;
	printf("Nhap MSSV: ");
	scanf_s("%d", &sv.mssv);
	nhapHoTen(&sv.HovaTen);
	printf("Tuoi: ");
	scanf_s("%d", &sv.tuoi);
	printf("Gioi tinh: ");
	scanf_s("%c", &sv.gioitinh);
	nhapDiem(&sv.diem);
	return sv;
}