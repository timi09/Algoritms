import numpy

# функция вычисления матрицы смежности объединения
def graph_merge(S1, S2):

     # матрица смежности объединения двух графов
     # вычисляется поэлементной операцией ИЛИ
     # для соответствующих элементов матриц

     n = S1.shape[0]

     S3 = S1 + S2 #поэлементное

     S3 = numpy.clip(S3, 0, 1)

     print('матрица смежности объединения двух графов')
     print(S3)


# матрица смежности S

S1 = numpy.array([  #v1 v2 v3 v4 v5
                    [0, 1, 0, 1, 0],# v1
                    [1, 0, 1, 0, 0],# v2
                    [0, 1, 0, 1, 0],# v3
                    [1, 0, 1, 0, 0],# v4
                    [0, 0, 0, 0, 0] # v5
])

S2 = numpy.array([  #v1 v2 v3 v4 v5
                    [0, 1, 0, 1, 0],# v1
                    [1, 0, 0, 1, 0],# v2
                    [0, 0, 0, 0, 0],# v3
                    [1, 1, 0, 0, 1],# v4
                    [0, 0, 0, 1, 0] # v5
])

graph_merge(S1, S2)
