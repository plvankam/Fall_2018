

def filter_modulo(items, modulo):
    item = [x for x in items if not x % modulo == 0]
    return item
            

def fib(num):
    a,b = 0, 1
    array = [0]
    for i in range(num):
        array.append(a + b)
        a,b = b, a+b
    return array

if __name__ == "__main__":
    # filter_modulo()
    print(filter_modulo([1,2,3], 2))
    print(fib(9))

    a = [x**2 for x in (1,2,3)]
    list(a)
    print(a)
    
    try:
        value = input("put a number here: ")
        print(9/value)
    except Exception as e:
        print("exception {} caught".format(e))

    for i, item in enumerate([1,2,3]):
        print(i,item),

