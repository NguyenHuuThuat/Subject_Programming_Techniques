class Car:

     # thuộc tính lớp
     loaixe = "Ô tô"

     # thuộc tính đối tượng
     def __init__(self, tenxe, mausac, nguyenlieu):
         self.tenxe = tenxe
         self.mausac = mausac
         self.nguyenlieu = nguyenlieu

      # phuong thuc
      def dungxe( self, mucdich):
          return "{} dang dung xe de {}".format(self.tenxe, mucdich)

# Khoi tao lop Car
toyota = Car("Toyota", "Đỏ", "Điện")
lamborghini = Car("Lamborghini", "Vàng", "Deisel")
porsche = Car("Porsche", "Xanh", "Gas")

#truy cap thuoc tinh cua lop
print("Porsche là {}.".format(porsche.__class__.loaixe))
print("Toyota là {}.".format(toyota.__class__.loaixe))
print("Lamborghini là {}.".format(lamborghini.__class__.loaixe))

#truy cap dac diem cua thuoc tinh
print ("Xe {} co cac dac diem mau {} va nhien lieu su dung {}.". format(toyota.tenxe, toyota.mausac, toyota.nguyenlieu))

print (toyota.dungxe,("nap dien"))