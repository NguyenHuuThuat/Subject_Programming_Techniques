"""
Định nghĩa một class có ít nhất 2 method: 

getString: để nhận một chuỗi do người dùng nhập vào 
từ giao diện điều khiển.

printString: in chuỗi vừa nhập sang chữ hoa. 

Thêm vào các hàm hiểm tra đơn giản để kiểm tra method của class.
"""
#class bongDen :

#    #Thuoc tinh cua doi tuong
#    def __init__(self, tenhang, loaibong):
#        self.tenhang = tenhang
#        self.loaibong = loaibong

#    #Phuong thuc
#    def batden(self):
#        return "{} dang bat".  format(self.tenhang)
#    def tatden(self):
#        return "{} dang tat".  format(self.tenhang)

#rangdong = bongDen("rangdong", "tuyp")
#huynhquang = bongDen("huynhquang", "LED")

#print ("Bong {} co hang san xuat la: {}.  Loai bong su dung la: {}".format(
#rangdong.tenhang, rangdong.tenhang, rangdong.loaibong))
#print ("Bong {} co hang san xuat la: {}.  Loai bong su dung la: {}".  format(
#huynhquang.tenhang, huynhquang.tenhang, huynhquang.loaibong))


#print(rangdong.batden())
#print(huynhquang.tatden())
class InputOutString(object) :

    def __int__(self):
        self.s = ""

    def getString(self) :
        self.s = input("Nhap chuoi: ")

    def printString(self) :
        print(self.s.upper())

a = InputOutString()
a.getString()
a.printString()




