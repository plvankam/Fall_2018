
primes = set((1,2,3,5,7,))

# classic solution 
items = list(range(10))

for prime in primes:
    items.remove(prime)

print(items)

# list comprehension
print([item for item in items if item not in primes])

# filter
print(list(filter(lambda item: item not in primes, items)))

