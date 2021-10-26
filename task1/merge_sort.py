def merge_sort(arr, start, end, timer):
    if end - start > 1:
        mid = (start + end)//2
        merge_sort(arr, start, mid, timer)
        merge_sort(arr, mid, end, timer)
        merge(arr, start, mid, end, timer)
 
def merge(arr, start, mid, end, timer):
    left = arr[start:mid]
    right = arr[mid:end]
    k = start
    i = 0
    j = 0
    
    while (start + i < mid and mid + j < end):

        timer.inc()

        if (left[i] <= right[j]):
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1

        k += 1

    if start + i < mid:

        while k < end:

            timer.inc()

            arr[k] = left[i]
            i += 1
            k += 1
    else:

        while k < end:

            timer.inc()
            
            arr[k] = right[j]
            j = j + 1
            k = k + 1
 
 