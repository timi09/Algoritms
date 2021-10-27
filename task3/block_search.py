from linear_search import linear_search

def block_search(arr, elem, timer, block_count = 4):
    block_ends = []
    block_len = int(len(arr)/block_count)
    for i in range(len(arr)-1, 0, -block_len):
        block_ends.insert(0,i)

    block_start = 0
    for block_end in block_ends:
        timer.inc()
        if elem == arr[block_end]:
            return block_end
        if(elem < arr[block_end]):
            #linear search
            for i in range(block_start, block_end+1):
                timer.inc()
                if elem == arr[i]:
                    return i
        block_start = block_end+1
    return None