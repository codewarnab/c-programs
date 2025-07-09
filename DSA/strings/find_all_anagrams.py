from itertools import permutations 

s = "cbaebabacd"
p = "abc"

finalList = []

for s in permutations(p):
   substr = "".join(p)
   finalList.append(substr)
print(finalList) 