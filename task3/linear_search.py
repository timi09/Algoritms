def linear_search(arr, elem, timer):
    enter_inds = []
    for i in range(len(arr)):
        timer.inc()
        if arr[i] == elem:
            enter_inds.append(i)
    return enter_inds