def quick_linear_search(arr, elem, timer, is_sorted = False):
    enter_inds = []
    arr.append(elem)
    i = 0
    while(True):
        if is_sorted and arr[i] > elem:
            break
        timer.inc()
        if arr[i] == elem:
            if i == len(arr)-1:
                break
            enter_inds.append(i)
        i+=1
    arr.pop()
    return enter_inds