import functools 
import pprint

# Map    --> map(func_to_apply, list_of_inputs)
# Filter --> filter(func_to_apply, list_of_inputs)
# Reduce --> applies rolling computation to sequential pairs
#            reduct(func_to_apply, list)

items = []
for i in range(1,11):
    items.append(i)


squared = list(map(lambda x: x**2, items))
pprint.pprint(squared)

lt_eq_one = list(filter(lambda x: x <= 1, items))
pprint.pprint(lt_eq_one)

sum_list = functools.reduce((lambda x,y: x + y), items)
pprint.pprint(sum_list)
