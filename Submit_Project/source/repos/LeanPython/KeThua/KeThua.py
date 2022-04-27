class TamGiac(DaGiac) :
    def __init__ (self) : 
        Dagiac.__init__(self,3)

    def dientich (self) :
        a, b, c =self.canh

        s = (a + b + c ) / 2
        area = (s * (s-a) * (s-b) * (s-c)) ** 0.5
        print ("Dien tich la %f" %area)

t = TamGiac()
t.nhapcanh()
