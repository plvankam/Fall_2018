import collections 

queue = collections.deque()
queue.append(1)
queue.append(2)

while(True):
    try:
        print(queue.popleft())
    except IndexError as e:
        print(e)
        break
