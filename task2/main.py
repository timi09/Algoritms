from shift_or import shift_or
from boyer_mur import boyer_mur

import time

def main():
    str1 = "jhgjhjyh abc hfbb bdfdjhgjhjjyhjyjhvsdrvjhgbbdjhge tthgjhgjh"
    substr = "jhgjh"

    print(len(str1))

    print("shift-or")
    t_start = time.monotonic_ns()
    inds = shift_or(str1, substr)
    t_stop = time.monotonic_ns()
    #test
    for i in inds:
        print(str1[i:i+len(substr)])
    print(str(t_stop - t_start) + " ns")

    print("boyer-mur")
    t_start = time.monotonic_ns()
    inds = boyer_mur(str1, substr)
    t_stop = time.monotonic_ns()
    #test
    for i in inds:
        print(str1[i:i+len(substr)])
    print(str(t_stop - t_start) + " ns")

main()