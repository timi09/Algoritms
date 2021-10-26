def shift_or(str, substr): #shift_and
    n = len(substr)
    m = len(str)
    old_mask = [1] * n #[0] * n
    enter_inds = []
    for i in range(m):
        bit_shift(old_mask)
        mask = bit_mask(str[i], substr)
        old_mask = bit_or(old_mask, mask) #bit_and(old_mask, mask)
        if old_mask[len(old_mask)-1] == 0: # == 1
            enter_inds.append(i-n+1)
    return enter_inds


def bit_mask(symb, substr):
    n = len(substr)
    mask = [1] * n #[0] * n
    for i in range(n):
        if substr[i] == symb:
            mask[i] = 0 #mask[i] = 1
    return mask

def bit_shift(old_mask):
    old_mask.pop()
    old_mask.insert(0, 0) #old_mask.insert(0, 1)

def bit_or(mask1, mask2):
    return [a|b for a,b in zip(mask1,mask2)]
#for shift-and
def bit_and(mask1, mask2):
    return [a*b for a,b in zip(mask1,mask2)]