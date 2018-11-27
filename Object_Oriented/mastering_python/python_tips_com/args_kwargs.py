
def printer(*args):
    for i in args:
        print('{:>10}'.format(i))



if __name__ == "__main__":

    printer("hello", "there", "my", "paper tiger")
