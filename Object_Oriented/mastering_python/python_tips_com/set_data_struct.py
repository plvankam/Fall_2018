import pprint 

some_list = ['a', 'b', 'c', 'b', 'd', 'm', 'n', 'n']

duplicates = set([x for x in some_list if some_list.count(x) > 1])
pprint.pprint(duplicates)

valid = set(['yellow', 'red', 'blue', 'green', 'black'])
input_set = set(['red', 'brown'])
pprint.pprint(input_set.intersection(valid))
