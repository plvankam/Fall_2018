import collections
import pprint

nodes = [
    ('a','b'),
    ('a','c'),
    ('b','a'),
    ('b','d'),
    ('c','a'),
    ('d','a'),
    ('d','b'),
    ('d','c'),
    ]

graph = dict()
for from_, to in nodes:
    if from_ not in graph:
        graph[from_] = []
    graph[from_].append(to)

pprint.pprint(graph)


# now use the defaultdict 
# available from collections
#

graph = collections.defaultdict(list)
for from_, to in nodes:
    graph[from_].append(to)

pprint.pprint(graph)

