## Задание

Реализовать структуру данных \- двусвязный список


1. Реализовать алгоритм

        1) Объединение двух двусвязных списков.
        2) Пересечение двух двусвязных списков.
2. Реализовать алгоритм поиска простых чисел в диапазоне от 2 до 100 методом решета Эратосфена, используя циклический односвязный список с заглавным звеном.

## Решение

Двусвязный список представлен шаблонным классом List<T>. Класс List использует вспомогательный класс Node<T>. Node - класс представляющий из себя «узел» который хранит данные, а также указатели на предыдущий узел в списке и следующий узел. List содержит поля указатели на первый и на последний узел(Node) списка. Также List содержит методы для добавления, удаления и поиска определенного узла. В List определены бинарные операции объединения (operator | ) и пересечения (operator &) двух списков.
