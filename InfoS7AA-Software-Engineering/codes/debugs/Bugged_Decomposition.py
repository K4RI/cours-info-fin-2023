import math

# Definition fonction

def decomposition(n, minFactor):
    for i in range(minFactor, int(math.sqrt(n))+1): # )+1 <- )
        if n%i == 0:
            return [i]+decomposition(n//i, i) # i <- i+1
    return [n]

def solve(n):
    return decomposition(n,2)


# Code à executer

assert solve(7*11) == [7,11]
assert solve(11*11) == [11,11]
assert solve(11*11*13) == [11,11,13]

print(solve(600851475143))
