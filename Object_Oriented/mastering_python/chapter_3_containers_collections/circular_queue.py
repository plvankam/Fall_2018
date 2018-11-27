import collections

circular = collections.deque(maxlen=2)

for i in range(5):
    print('appending %02d to circular buffer' %(i))
    circular.append(i)

print("[",end='')
for i in range(len(circular)):
    print('%2d' %(circular[i]), end='')
    if(not (i+1) == len(circular)): 
        print(', ',end='')
print("]",end='')
