import random

def generate_counts(k=1000,n=100):
    x = 2 * (random.rand(k,n) > 0.5) - 1
    S = sum(x, axis=0)
    return S


generate_counts()
