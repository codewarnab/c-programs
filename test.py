from itertools import permutations
finalist = []
for p in permutations([1,2,3]):
    sublist= list(p)
    finalist.append(sublist)
print(finalist)