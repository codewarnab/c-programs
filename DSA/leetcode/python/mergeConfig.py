# You have several configuration dictionaries, where later
# dictionaries might override values from earlier ones. Create a single view of these
# configurations, prioritizing values from dictionaries that appear later in the input list. If
# a key exists in multiple dictionaries, the value from the dictionary appearing latest in
# the list should be used.


from collections import ChainMap 

class Solution:
    def mergeConfigs(self,*configs:dict) -> ChainMap:
        # chainMap takes dictionaries in order from most to least prioritized 
        # so , the last config in the input list should be the first in chainMap 
        return ChainMap(*reversed(configs))
sol = Solution()
config1 = {"debug": True, "port": 8080}
config2 = {"port": 9000, "host": "localhost"}
config3 = {"debug": False, "timeout": 30}
merged_config1 = sol.mergeConfigs(config1, config2)
print(dict(merged_config1)) 
merged_config2 = sol.mergeConfigs(config1, config2, config3)
print(dict(merged_config2))
merged_config3 = sol.mergeConfigs(config1)
print(dict(merged_config3)) # Expected: {"debug": True, "port": 8080}
