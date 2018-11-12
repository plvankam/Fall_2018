
def cal_avg(*args):
    if len(args) > 0:
        sum = 0
        for elem in args:
            sum += elem
        return float(sum)/len(args)


def publish_error(startStr, endStr, *args):
    print(startStr)
    for elem in args:
        print("Error: {}".format(elem))
    print(endStr)


print(cal_avg(1,2,3,4,5,6),end='')
print(" is the average.")
            
publish_error("Begin: ", "End: ","Invalid Parms", "Paper Trail")
