class Person :
    #dinh nghia lop "name"
    name = "Person"

    def __init__(self, name = None ):
        self.name = name

Thuat = Person("Thuat")
Nguyen = Person()
Nguyen.name = "Nguyen"
print("%s name la %s" % (Person.name, Nguyen.name))
