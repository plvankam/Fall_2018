import re

text = 'abbaaabbbbaaaaa'
pattern = 'ab'
index = []
for match in re.findall(pattern,text):
    print('Found {!r}'.format(match))

