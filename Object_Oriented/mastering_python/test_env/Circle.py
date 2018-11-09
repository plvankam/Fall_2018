import math 

class Circle:
    def __init__(self, radius):
        self.__radius = radius

    def setRadius(self, radius):
        self.__radius = radius

    def getRadius(self):
        return self.__radius

    def getArea(self):
        return self.__radius * 2 * math.pi

    def __add__(self, other):
        return Circle(self.__radius + other.getRadius())



