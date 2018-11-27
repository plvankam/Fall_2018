
# iterable  --> any object that has __iter__ or __getitem__ defined
# iteration --> any object that has __next__ defined
# iteration --> the process of iterating over a container 

def generator_function(num):
    for i in range(num):
        yield i

def fib(n):
    a = b = 1
    for i in range(n):
        yield a
        a, b = b, a+b


# main()
def main():
    for item in generator_function(10):
        print(item," ",end='')
    fib1 = fib(9)
    while(True):
        try:
            print(next(fib1))
        except StopIteration as e:
            print(e)
            break
    string = "paper"
    str_iter = iter(string)
    while(True):
        try:
            print(next(str_iter)," ",end='')
        except StopIteration as e:
            print(e," ",end='')
            break
    


main()


