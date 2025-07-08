arr = [1,3,5,7,9]

all_subarrays=[]
for i in range(0,len(arr)):
    for j in range(i+1,len(arr)+1):
        all_subarrays.append(arr[i:j])
        

max= float('-inf') 
min = float('inf') 
for subarray in all_subarrays:  
    if (sum(subarray)>max ):
        max = sum(subarray)
    if(sum(subarray)< min):
        min = sum(subarray)
print("minimum number ",min);
print("maximum number",max)
    
