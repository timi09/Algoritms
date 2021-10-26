def get_bit(num, bit_ind):
    newnum = num>>bit_ind
    if(newnum % 2 == 1):
        return 1
    else:
        return 0

def radix_sort(arr, start, end, bit_ind, timer):

    if bit_ind == 0:
        return

    if start >=end:
        return

    i=start
    j=end
    
    while(i < j):

        timer.inc()

        while get_bit(arr[i], bit_ind) == 0 and i<j:
            i+=1
        
        while get_bit(arr[j], bit_ind) == 1 and i<j:
            j-=1
        
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]

    if get_bit(arr[i], bit_ind) == 1:
        i-=1

    radix_sort(arr, start, i, bit_ind-1, timer)
    radix_sort(arr, i+1, end, bit_ind-1, timer)









