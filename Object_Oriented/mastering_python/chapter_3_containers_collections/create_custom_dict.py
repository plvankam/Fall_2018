# we are hashing according  
# to the MSD
def most_significant(value):
    while value >= 10:
        value //= 10
    return value


# place in respective 'bucket'
# we have 10 buckets (0,1,2...9)
def add(collection, key, value):
    index = most_significant(key)
    collection[index].append((key,value))


def contains(collection, key):
    index = most_significant(key)
    for k, v in collection[index]:
        if key == k:
            return True
    return False


collection = [[], [], [], [], [], [], [], [], [], []]


if __name__ == "__main__":
    print(most_significant(980))
    print(most_significant(380))
    print(most_significant(480))

    add(collection, 123, 'a')
    add(collection, 456, 'b')
    add(collection, 789, 'c')
    add(collection, 101, 'd')
    print(collection)
