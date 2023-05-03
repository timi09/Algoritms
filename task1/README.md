## Задание

1. Изучить временные характеристики алгоритмов.

2. Изучить методы сортировки.

3. Программно реализовать 3 метода сортировки массивов: быстрая
сортировка (для разных способов выбора ключа), обменная поразрядная
сортировка, двухпутевое слияние.

4. Разработать и программно реализовать средство для проведения
экспериментов по определению временных характеристик алгоритмов
сортировки.

5. Провести эксперименты по определению временных
характеристик алгоритмов сортировки. Результаты экспериментов
представить в виде таблиц 1, 2 и 3, клетки которых содержат количество
операций сравнения при выполнении алгоритма сортировки массива с
заданным количеством элементов.

6. Построить график зависимости количества операций сравнения от
количества элементов в сортируемом массиве.

7. Определить аналитическое выражение функции зависимости
количества операций сравнения от количества элементов в массиве.
 
8. Определить порядок функций временной сложности алгоритмов
сортировки при сортировке упорядоченных, неупорядоченных и
упорядоченных в обратном порядке массивов.

## Алгоритмы решения задач

1. Алгоритм быстрой сортировки Хоара состоит в том, чтобы разбить
сортируемое множество на три подмножества относительно ключа. Ключ
\- это элемент множества. Обычно в качестве ключа берут первый,
последний или средний элемент множества, или для наилучшей
стабильности сортировки берут медианное значения из этих трех
элементов. Множество разбивается на три подмножества: меньшее
ключа, равное ключу и большее ключа. Для этого мы идем от левого края
множества в центр и от правого края в центр и когда слева мы находим
элемент больший ключа, а справа элемент меньший ключа, они меняются
местами. Затем для получившегося подмножества которое меньше и для
того которое больше производят тоже вычисление ключа и разбивают их
на новые подмножества по тому же алгоритму, и так до момента пока
подмножество не будет содержать всего 1 элемент.



<a name="br3"></a>

2. Алгоритм обменной поразрядной сортировки похож на алгоритм
быстрой сортировки. описанной выше, но в нем не используется ключ.
Вместо ключа здесь сравниваются биты чисел начиная от старших
разрядов и двигаясь к младшим. Самое левое число содержащее в бите 1
обменивается с самым правым числом содержащем в том же бите 0.
Стоит отметить что данный алгоритм работает только на целых числах.
 
 <a name="br3"></a>
 
3. Алгоритм двухпутевого слияния заключается в разбиении множества
на два подмножества относительно середины множества. Новые
подмножества также разбиваются относительно середины и так до
момента пока они не разобьются на одноэлементные множества. Затем
начинаются операции слияния наших подмножеств. Берутся элементы
подмножеств стоящие на одинаковых местах, сравниваются, меньший
элемент записывается в новое объединенное множество, затем в том
подмножестве из которого мы взяли элемент - берется следующий
элемент, в том подмножестве из которого не взяли элемент - элемент
остается прежним, они снова сравниваются и так далее пока одно из
объединяемых подмножеств не кончится. Если во втором подмножестве
еще остались элементы добавляем их в объединенное множество.
Выполняем данный алгоритм для полученных объединенных множеств
пока они не кончатся и не останется одно.

## Сравнительный анализ алгоритмов

  Временные затраты алгоритмов для разных множеств показаны в
таблицах 1, 2, 3.

Таблица 1

Упорядоченный массив

<table><tr><th colspan="1" rowspan="2" valign="top">Сортировка</td><th colspan="9" valign="top">Количество элементов в массиве</td></tr>
<tr></td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">10</td><td colspan="1" valign="top">15</td><td colspan="1" valign="top">20</td><td colspan="1" valign="top">25</td><td colspan="1" valign="top">30</td><td colspan="1" valign="top">35</td><td colspan="1" valign="top">40</td><td colspan="1" valign="top">45</td></tr>
<tr><td colspan="1">Быстрая (средний ключ)</td><td colspan="1">31410 ns</td><td colspan="1">13440 ns</td><td colspan="1">10879 ns</td><td colspan="1">16116 ns</td><td colspan="1">34361 ns</td><td colspan="1">24345 ns</td><td colspan="1">43373 ns</td><td colspan="1">34532 ns</td><td colspan="1">41043 ns</td></tr>
<tr><td colspan="1">Быстрая (левый ключ)</td><td colspan="1">30570 ns</td><td colspan="1">26161 ns</td><td colspan="1">28992 ns</td><td colspan="1">42316 ns</td><td colspan="1">11889 7 ns</td><td colspan="1">91607 ns</td><td colspan="1">189711 ns</td><td colspan="1">160753 ns</td><td colspan="1">15982 1 ns</td></tr>
<tr><td colspan="1" valign="top">Быстрая (правый ключ)</td><td colspan="1" valign="top">35967 ns</td><td colspan="1" valign="top">22267 ns</td><td colspan="1" valign="top">24110 ns</td><td colspan="1" valign="top">34894 ns</td><td colspan="1" valign="top">84408 ns</td><td colspan="1" valign="top">87906 ns</td><td colspan="1" valign="top">135139 ns</td><td colspan="1" valign="top">106850 ns</td><td colspan="1" valign="top">15217 4 ns</td></tr>
<tr><td colspan="1" valign="top">Быстрая (медиана трех как ключ)</td><td colspan="1" valign="top">18827 ns</td><td colspan="1" valign="top">8619 ns</td><td colspan="1" valign="top">11616 ns</td><td colspan="1" valign="top">17853 ns</td><td colspan="1" valign="top">28468 ns</td><td colspan="1" valign="top">30329 ns</td><td colspan="1" valign="top">62309 ns</td><td colspan="1" valign="top">39323 ns</td><td colspan="1" valign="top">46446 ns</td></tr>
<tr><td colspan="1">Поразрядная</td><td colspan="1">71307 ns</td><td colspan="1">18934 ns</td><td colspan="1">25448 ns</td><td colspan="1">29938 ns</td><td colspan="1">37680 ns</td><td colspan="1">43445 ns</td><td colspan="1">84839 ns</td><td colspan="1">67442 ns</td><td colspan="1">60409 ns</td></tr>
<tr><td colspan="1">Слияние</td><td colspan="1">48152 ns</td><td colspan="1">13246 ns</td><td colspan="1">20076 ns</td><td colspan="1">27320 ns</td><td colspan="1">53164 ns</td><td colspan="1">43373 ns</td><td colspan="1">84770 ns</td><td colspan="1">57158 ns</td><td colspan="1">67853 ns</td></tr>
</table>


Таблица 2

Массив, упорядоченный в обратном порядке

<table><tr><th colspan="1" rowspan="2" valign="top"><p>Сортиро</p><p>вка</p></td><th colspan="9" valign="top">Количество элементов в массиве</td></tr>
<tr></td><td colspan="1">5</td><td colspan="1">10</td><td colspan="1">15</td><td colspan="1">20</td><td colspan="1">25</td><td colspan="1">30</td><td colspan="1">35</td><td colspan="1">40</td><td colspan="1">45</td></tr>
<tr><td colspan="1">Быстрая (средний ключ)</td><td colspan="1" valign="top">4463 ns</td><td colspan="1" valign="top">10459 ns</td><td colspan="1" valign="top">10615 ns</td><td colspan="1" valign="top">16921 ns</td><td colspan="1" valign="top">21546 ns</td><td colspan="1" valign="top">24006 ns</td><td colspan="1" valign="top">29938 ns</td><td colspan="1" valign="top">35659 ns</td><td colspan="1" valign="top">41275 ns</td></tr>
<tr><td colspan="1">Быстрая (левый ключ)</td><td colspan="1" valign="top">4755 ns</td><td colspan="1" valign="top">17257 ns</td><td colspan="1" valign="top">24226 ns</td><td colspan="1" valign="top">39314 ns</td><td colspan="1" valign="top">57775 ns</td><td colspan="1" valign="top">80218 ns</td><td colspan="1" valign="top">100328 ns</td><td colspan="1" valign="top">133385 ns</td><td colspan="1" valign="top">145758 ns</td></tr>
<tr><td colspan="1">Быстрая (правый ключ)</td><td colspan="1" valign="top">4924 ns</td><td colspan="1" valign="top">19758 ns</td><td colspan="1" valign="top">26320 ns</td><td colspan="1" valign="top">45321 ns</td><td colspan="1" valign="top">64200 ns</td><td colspan="1" valign="top">90715 ns</td><td colspan="1" valign="top">103786 ns</td><td colspan="1" valign="top">145310 ns</td><td colspan="1" valign="top">151811 ns</td></tr>
<tr><td colspan="1">Быстрая (медиана трех как ключ)</td><td colspan="1" valign="top">3780 ns</td><td colspan="1" valign="top">11590 ns</td><td colspan="1" valign="top">11233 ns</td><td colspan="1" valign="top">26006 ns</td><td colspan="1" valign="top">24927 ns</td><td colspan="1" valign="top">26930 ns</td><td colspan="1" valign="top">32651 ns</td><td colspan="1" valign="top">43155 ns</td><td colspan="1" valign="top">46217 ns</td></tr>
<tr><td colspan="1" valign="top">Поразрядная</td><td colspan="1">13292 ns</td><td colspan="1">28091 ns</td><td colspan="1">24923 ns</td><td colspan="1">55154 ns</td><td colspan="1">42081 ns</td><td colspan="1">53082 ns</td><td colspan="1">58516 ns</td><td colspan="1">66505 ns</td><td colspan="1">68971 ns</td></tr>
<tr><td colspan="1" valign="top">Слияние</td><td colspan="1">6658 ns</td><td colspan="1">18236 ns</td><td colspan="1">20246 ns</td><td colspan="1">47344 ns</td><td colspan="1">37137 ns</td><td colspan="1">42769 ns</td><td colspan="1">51624 ns</td><td colspan="1">60735 ns</td><td colspan="1">67486 ns</td></tr>
</table>

Таблица 3

Неупорядоченный массив

<table><tr><th colspan="1" rowspan="2" valign="top"><p>Сортировк</p><p>а</p></td><th colspan="9" valign="top">Количество элементов в массиве</td></tr>
<tr></td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">10</td><td colspan="1" valign="top">15</td><td colspan="1" valign="top">20</td><td colspan="1" valign="top">25</td><td colspan="1" valign="top">30</td><td colspan="1" valign="top">35</td><td colspan="1" valign="top">40</td><td colspan="1" valign="top">45</td></tr>
<tr><td colspan="1">Быстрая (средний ключ)</td><td colspan="1">6511 ns</td><td colspan="1">10542 ns</td><td colspan="1">19574 ns</td><td colspan="1">22638 ns</td><td colspan="1">32305 ns</td><td colspan="1">35936 ns</td><td colspan="1">40661 ns</td><td colspan="1">57942 ns</td><td colspan="1">53907 ns</td></tr>
<tr><td colspan="1">Быстрая (левый ключ)</td><td colspan="1">5517 ns</td><td colspan="1">8409 ns</td><td colspan="1">14745 ns</td><td colspan="1">17791 ns</td><td colspan="1">23382 ns</td><td colspan="1">31073 ns</td><td colspan="1">35468 ns</td><td colspan="1">45913 ns</td><td colspan="1">68154 ns</td></tr>
<tr><td colspan="1">Быстрая (правый ключ)</td><td colspan="1">6279 ns</td><td colspan="1">8279 ns</td><td colspan="1">15421 ns</td><td colspan="1">20075 ns</td><td colspan="1">26291 ns</td><td colspan="1">30974 ns</td><td colspan="1">56289 ns</td><td colspan="1">51407 ns</td><td colspan="1">44465 ns</td></tr>
<tr><td colspan="1">Быстрая (медиана трех как ключ)</td><td colspan="1">4463 ns</td><td colspan="1">9204 ns</td><td colspan="1">14658 ns</td><td colspan="1">19931 ns</td><td colspan="1">24764 ns</td><td colspan="1">32203 ns</td><td colspan="1">35249 ns</td><td colspan="1">42208 ns</td><td colspan="1">52112 ns</td></tr>
<tr><td colspan="1">Поразрядная</td><td colspan="1">6279</td><td colspan="1">8279</td><td colspan="1">15421</td><td colspan="1">20075</td><td colspan="1">26291</td><td colspan="1">30974</td><td colspan="1">56289</td><td colspan="1">51407</td><td colspan="1">44465</td></tr>
<tr><td colspan="1">Слияние</td><td colspan="1">7777 ns</td><td colspan="1">22161 ns</td><td colspan="1">21598 ns</td><td colspan="1">29319 ns</td><td colspan="1">47197 ns</td><td colspan="1">73997 ns</td><td colspan="1">61522 ns</td><td colspan="1">65317 ns</td><td colspan="1">95390 ns</td></tr>
</table>

Общая оценка сложности алгоритмов показана в таблице 4.

Таблица 4

<table><tr><th colspan="1" rowspan="2" valign="top">Сортировка</td><th colspan="3" valign="top">Сложность</td></tr>
<tr></td><td colspan="1" valign="top">Данные упорядочены</td><td colspan="1" valign="top">Данные упорядочены в обратном порядке</td><td colspan="1" valign="top">Данные не упорядочены</td></tr>
<tr><td colspan="1">Быстрая</td><td colspan="1">n * log n</td><td colspan="1">n * log n</td><td colspan="1">n * log n</td></tr>
<tr><td colspan="1">Поразрядная</td><td colspan="1">n * k/d (*)</td><td colspan="1">n * k/d (*)</td><td colspan="1">n * k/d (*)</td></tr>
<tr><td colspan="1">Слияние</td><td colspan="1">n * log n</td><td colspan="1">n * log n</td><td colspan="1">n * log n</td></tr>
</table>

\*k - количество разрядов в самом длинном ключе.

d - разрядность данных: количество возможных значений разряда ключа.
