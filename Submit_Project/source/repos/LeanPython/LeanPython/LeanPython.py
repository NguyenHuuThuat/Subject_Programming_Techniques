
import math
"""
Giai PT bac 2: ax^2 + bx + c = 0
a : he so bac 2
b: he so bac 1
c: he so tu do
"""
def giaiPTBac2(a, b,c):
    #kiem tra cac he so
    if a == 0:
        if b == 0:
            if c == 0:
                print("PT da cho vo so nghiem")
            else :
                print("PT da cho vo nghiem")
        else:
            print ("PT co mot nghiem: x = ", (-c / b))
        return;

    #tinh denta
    denta = b*b - 4*a*c
    #tinh nghiem
    if denta > 0: 
        x1 = (float)((-b + math.sqrt(denta)) / 2*a)
        x1 = (float)((-b - math.sqrt(denta)) / 2*a)
        print ("PT co 2 nghiem phan biet: x1= ", x1, "Va x2 = ", x2);
    elif (denta == 0):
        x = (float)(-b / 2*a);
        print ("PT co nghiem kep: x = ", x);
    else:
        print ("PT vo nghiem!!!")

#Nhap he so
a = float(input("a = "));
b = float(input("b = "));
c = float(input("c = "));
#goi ham
giaiPTBac2(a, b,c)


