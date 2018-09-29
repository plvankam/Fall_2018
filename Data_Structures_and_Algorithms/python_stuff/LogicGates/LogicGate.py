

# --------------------
# Logic Gate 
# Parent Class 
# --------------------
class LogicGate:
    def __init__(self,n):
        self.label = n
        self.output = None
    def getLabel(self):
        return self.label
    def getOutput(self):
        self.output = self.performGateLogic()
        return self.output

# --------------------
# Binary Gate 
# Super: LogicGate
# --------------------
class BinaryGate(LogicGate):
    def __init__(self,n):
        LogicGate.__init__(self,n)
        self.pinA = None
        self.pinB = None
    def getPinA(self):
        return int(input("Enter Pin A input for gate " + self.getLabel()+"--> "))
    def getPinB(self):
        return int(input("Enter Pin B input for gate " + self.getLabel()+"--> "))

# --------------------
# Unary Gate
# Super: LogicGate
# --------------------
class UnaryGate(LogicGate):
    def __init__(self, n):
        LogicGate.__init__(self,n)
        self.pin = None
    def getPin(self):
        return int(input("Enter Pin input for gate " + self.getLabel()+"--> "))



# --------------------
# AND Gate
# Super: BinaryGate  
# --------------------
class AndGate(BinaryGate):
    def __init__(self,n):
        BinaryGate.__init__(self,n)
    def performGateLogic(self):
        a = self.getPinA()
        b = self.getPinB()
        if 1 == a and 1 == b:   
            return 1
        else:                   
            return 0

# --------------------
# OR Gate
# Super: BinaryGate  
# --------------------
class OrGate(BinaryGate):
    def __init__(self,n):
        UnaryGate.__init__(self,n)
    def performGateLogic(self):
        a = self.getPinA()
        b = self.getPinB()
        if 1 == a or 1 == b:               
            return 1
        else:                    
            return 0

# --------------------
# NOT Gate
# Super: BinaryGate  
# --------------------
class NotGate(UnaryGate):
    def __init__(self, n):
        UnaryGate.__init__(self,n)
    def performGateLogic(self):
        if 1 == self.getPin(): return 0
        else:                  return 1




if __name__ == "__main__":
    
    g1 = AndGate("G1")
    print(g1.getOutput())
    g2 = OrGate("G2")
    print(g2.getOutput())
    g3 = NotGate("G3")
    print(g3.getOutput())

