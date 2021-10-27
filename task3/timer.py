class timer:
    def __init__(self):
        self.arr_len = 0
        self.iters = 0

    def set(self, arr):
        self.iters = 0
        self.arr_len = len(arr)

    def inc(self):
        self.iters+=1

    def get(self):
        print("len/iters = " + str(self.arr_len) + "/" + str(self.iters))