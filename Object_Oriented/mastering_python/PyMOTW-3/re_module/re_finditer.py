import re

text = 'abbaaabbbbaaaaa'
pattern = 'ab'
index = []
for match in re.finditer(pattern,text):
    s = match.start()
    e = match.end()
    print('Found {!r} at {:d}:{:d}'.format(match,s,e))

