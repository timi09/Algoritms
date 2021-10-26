def med(x, y, z):
    if y <= x and x <= z:
        return x
    elif z <= x and x <= y:
        return x
    
    elif z <= y and y <= x:
        return y
    elif x <= y and y <= z:
        return y
    
    elif y <= z and z <= x:
        return z    
    elif x <= z and z <= y:
        return z



def quick_sort(array, key, timer):
    less = []
    equal = []
    greater = []

    if len(array) > 1:

        elm = array[0]
        if key == "left":
            elm = array[0]
        elif key == "mid":
            elm = array[len(array)//2]
        elif key == "right":
            elm = array[len(array)-1]
        elif key == "median":
            elm = med(array[0], array[len(array)//2], array[len(array)-1])

        for x in array:

            timer.inc()

            if x < elm:
                less.append(x)
            elif x == elm:
                equal.append(x)
            elif x > elm:
                greater.append(x)
        return quick_sort(less, key, timer)+equal+quick_sort(greater,key, timer)
    else:  
        return array