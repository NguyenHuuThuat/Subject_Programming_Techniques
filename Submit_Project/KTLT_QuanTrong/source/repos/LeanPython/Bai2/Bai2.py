
"""
Viết một chương trình có thể tính giai thừa 
của một số cho trước. Kết quả được in thành chuỗi 
trên một dòng, phân tách bởi dấu phẩy. 
Ví dụ, số cho trước là 8 thì kết quả đầu ra phải là 40320.
"""

n = int(input("Nhap so can tinh giai thua: "))
def giaiThua (n) :
    if (n == 0) or (n == 1):
        return 1;
    else :
        return n * giaiThua(n-1)

#goi ham
print (giaiThua(n))

