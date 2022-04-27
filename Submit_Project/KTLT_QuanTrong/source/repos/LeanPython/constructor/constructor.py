class SoPhuc :
    """Tao mot truong so phuc
    co dang z = a + bi """
    def ___int__(self, a , b ):
        self.phanthuc = a
        self.phanao = b

    def getData(self):
        print("{} + {}i". format(self.phanthuc , self.phanao))

c1 = SoPhuc(2,3)
c1.getData()