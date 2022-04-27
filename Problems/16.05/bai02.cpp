/*§Viết chương trình quản lý thời khóa biểu của 1 người. Yêu cầu:

§Sử dụng các nhãn “Thu 2”, …. “”Chu Nhat” để biểu thị các ngày trong tuần

§Mỗi ngày nhập vào 1 công việc, mô tả nội dung công việc bởi một xâu kí tự 
(yêu cầu nâng cao: mở rộng bài toán, biểu diễn một danh sách công việc)

§Nhập/Hiển thị thời khóa biểu

§Tìm kiếm nội dung công việc của 1 ngày (nhập vào Ngày)

§***Nâng cao: Điều khiển bằng menu, với các chức năng: Nhập vào thời khóa biểu; 
Hiển thị TKB; Cập nhật TKB; Tìm kiếm danh sách công việc của 1 ngày; 
Tìm kiếm ngày cần thực hiện công việc nào đó, bằng cách nhập vào một từ khóa mô tả công việc đó.*/

#include<stdio.h>

enum ngayTrongTuan { Thu2 = 1, Thu3 = 2, Thu4 = 3, Thu5 = 4, Thu6 = 5 , Thu7 = 6 , CN = 7};

int main() {
	enum ngayTrongTuan ngay;
	const char* day[] = { "", "thu 2", "thu 3",  "thu 4",  "thu 5",  "thu 6",  "thu 7",  "chu nhat" };
	
	for (ngay = Thu2; ngay <= CN; ngay++) {
		printf("%2d%11s\t", ngay, day[ngay])
	}



}