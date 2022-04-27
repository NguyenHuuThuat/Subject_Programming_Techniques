"""
Yêu cầu của bài tập này là viết 
một chương trình để in tài liệu về 
một số hàm Python được tích hợp sẵn như 
abs(), int(), input() và thêm tài liệu cho hàm bạn tự định nghĩa.
"""

print (abs.__doc__)
print (int.__doc__)
print (input.__doc__)

def binhPhuong (num) :
    return num ** 2;
print(binhPhuong.__doc__)
