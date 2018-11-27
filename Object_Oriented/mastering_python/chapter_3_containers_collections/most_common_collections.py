import collections
import math

counter = collections.Counter('eggs')
for k in 'eggs':
    print('Count for %s: %d' %(k, counter[k]))

counter = collections.Counter()
for i in range(100000):
    counter[math.sqrt(i) // 25] += 1

for key, count in counter.most_common(5):
    print('%-5s: %-6d' %(key, count))
