def binary_search(arr, elem, timer): 
    low = 0 
    high = len(arr) - 1 
    mid = int(high/2)

    while arr[mid] != elem and low < high:
        timer.inc()
        if elem > arr[mid]:
            low = mid+1
        else:
            high = mid-1
        mid = int((low+high)/2)
    
    if low > high:
        return None
    else:
        return mid
