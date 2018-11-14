import builtins
import collections

# this is one way
builtin_vars = vars(builtins)
if key in locals():
    value = locals()[key]
elif key in globals():
    value = globals()[key]
elif key in builtin_vars:
    value = builtin_vars[key]

# this is a better way 
mappings = collections.ChainMap(globals(), locals(), vars(builtins))
value = mappings[key]

