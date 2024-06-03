value = [[1,3],[4,6],[5,10],[15,18]]

first = 0

second = 1

print(value)

while True:
    
    if second > len(value)-1:
        break
    
    else:
        
        v1 = value[first]
        v2 = value[second]
        
        if max(v1) >= min(v2):
            value.insert(second+1, [min(v1[0], v2[0]), max(v1[1], v2[1])])
            
            del value[first], value[first]
        
        else:
            
            first = first + 1
            second = second + 1
        
print(value)