import string
 
values = {'var' : 'foo'}

# ------------------------------
t = string.Template("""
Variable        : $var
Escape          : $$
Variable in text: ${var} is cool
""")
print('TEMPLATE:', t.substitute(values))

# ------------------------------
s = """
Variable        : %(var)s
Escape          : %%
Variable in text: %(var)s is cool
"""
print('INTERPOLATION', s % values)

# ------------------------------
s = """
Variable        : {var}
Escape          : {{}}
Variable in text: {var} is cool
"""
print('FORMAT', s.format(**values))

