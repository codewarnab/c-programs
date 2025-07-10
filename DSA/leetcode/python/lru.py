from collections import OrderedDict

class LRUcache :
    def __init__ (self,capacity:int):
        self.cache = OrderedDict()
        self.capacity = capacity 
    def get(self , key :int)->int:
        if key not in self.cache:
            return -1 
        #Move the accessed key to end  to mark it as recently used 
        self.cache.move_to_end(key=key)
        return self.cache[key]
    def put(self , key :int , value :int) -> None :
        if key in self.cache:
            #update value and move to end 
            self.cache[key] = value 
            self.cache.move_to_end(key=key)
        else :
            #Add new key-value pair 
            self.cache[key] = value 
            if len(self.cache) > self.capacity :
                #pop the leas recently used item(first item )
                self.cache.popitem(last=False)
    
            
lRUCache = LRUcache(2)
lRUCache.put(1, 1)
lRUCache.put(2, 2)
print(lRUCache.get(1)) # return 1
lRUCache.put(3, 3) # evicts key 2
print(lRUCache.get(2)) # return -1
lRUCache.put(4, 4) # evicts key 1
print(lRUCache.get(1)) # return -1
print(lRUCache.get(3)) # return 3
print(lRUCache.get(4)) # return 4
        