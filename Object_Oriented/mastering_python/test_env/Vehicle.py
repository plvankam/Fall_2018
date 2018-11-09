class Vehicle:
    def __init__(self, name, color):
        self.__name = name
        self.__color = color
    def getColor(self):
        return self.__color
    def getName(self):
        return self.__name
    def setColor(self,color):
        self.__color = color

class Car(Vehicle):
    def __init__(self, name, color, model):
        super().__init__(name, color)
        self.__model = model
    def getDescription(self):
        return self.getName() + " " + self.__model + \
               " in " + self.getColor()


if __name__ == "__main__":
    mazda = Car("protege", "black", str(610))
    print(mazda.getDescription())

