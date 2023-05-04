## Задание

1. Изучить алгоритмы поиска:
    1\) в неупорядоченном массиве:

        а) линейный;

        б) быстрый линейный;

    2\) в упорядоченном массиве:

        а) быстрый линейный;

        б) бинарный;

        в) блочный.

2. Разработать и программно реализовать средство для проведения

экспериментов по определению временных характеристик алгоритмов поиска.

3. Провести эксперименты по определению временных

характеристик алгоритмов поиска. Результаты экспериментов представить в виде таблиц 1.1 и 1.2. Клетки таблицы 1.1 содержат максимальное количество операций сравнения при выполнении алгоритма поиска, а клетки таблицы 1.2 – среднее число операций сравнения.

4. Построить графики зависимости количества операций сравнения

от количества элементов в массиве.

5. Определить аналитическое выражение функции зависимости

количества операций сравнения от количества элементов в массиве.

6. Определить порядок функций временной сложности алгоритмов

поиска.

### Сравнительный анализ алгоритмов

Временные затраты алгоритмов показаны в таблице 1.1 и 1.2.

Таблица 1.1

Максимальное количество операций сравнения

<table><tr><th colspan="1" rowspan="3" valign="top">Алгоритмы поиска (см.задание)</td><th colspan="9" valign="top">Количество элементов в массиве</td></tr>
<tr></td><td colspan="1" valign="top">50</td><td colspan="1" valign="top">100</td><td colspan="1" valign="top">150</td><td colspan="1" valign="top">200</td><td colspan="1" valign="top">250</td><td colspan="1" valign="top">300</td><td colspan="1" valign="top">350</td><td colspan="1" valign="top">400</td><td colspan="1" valign="top">450</td></tr>
<tr></td><td colspan="9">Количество операций сравнения</td></tr>
<tr><td colspan="1" valign="top">1.а</td><td colspan="1" valign="top">50</td><td colspan="1" valign="top">100</td><td colspan="1" valign="top">150</td><td colspan="1" valign="top">200</td><td colspan="1" valign="top">250</td><td colspan="1" valign="top">300</td><td colspan="1" valign="top">350</td><td colspan="1" valign="top">400</td><td colspan="1" valign="top">450</td></tr>
<tr><td colspan="1" valign="top">1.б</td><td colspan="1" valign="top">51</td><td colspan="1" valign="top">101</td><td colspan="1" valign="top">151</td><td colspan="1" valign="top">201</td><td colspan="1" valign="top">251</td><td colspan="1" valign="top">301</td><td colspan="1" valign="top">351</td><td colspan="1" valign="top">401</td><td colspan="1" valign="top">451</td></tr>
<tr><td colspan="1" valign="top">2.а</td><td colspan="1" valign="top">51</td><td colspan="1" valign="top">101</td><td colspan="1" valign="top">151</td><td colspan="1" valign="top">201</td><td colspan="1" valign="top">251</td><td colspan="1" valign="top">301</td><td colspan="1" valign="top">351</td><td colspan="1" valign="top">401</td><td colspan="1" valign="top">451</td></tr>
<tr><td colspan="1">2.б</td><td colspan="1">5</td><td colspan="1">6</td><td colspan="1">7</td><td colspan="1">7</td><td colspan="1">7</td><td colspan="1">8</td><td colspan="1">8</td><td colspan="1">8</td><td colspan="1">8</td></tr>
<tr><td colspan="1">2.в</td><td colspan="1">5</td><td colspan="1">6</td><td colspan="1">7</td><td colspan="1">7</td><td colspan="1">7</td><td colspan="1">8</td><td colspan="1">8</td><td colspan="1">8</td><td colspan="1">8</td></tr>
</table>

Таблица 1.2

Среднее количество операций сравнения

<table><tr><th colspan="1" rowspan="3" valign="top">Алгоритмы поиска (см.задание)</td><th colspan="9" valign="top">Количество элементов в массиве</td></tr>
<tr></td><td colspan="1">50</td><td colspan="1">100</td><td colspan="1">150</td><td colspan="1">200</td><td colspan="1">250</td><td colspan="1">300</td><td colspan="1">350</td><td colspan="1">400</td><td colspan="1">450</td></tr>
<tr></td><td colspan="9" valign="top">Количество операций сравнения</td></tr>
<tr><td colspan="1">1.а</td><td colspan="1">50</td><td colspan="1">100</td><td colspan="1">150</td><td colspan="1">200</td><td colspan="1">250</td><td colspan="1">300</td><td colspan="1">350</td><td colspan="1">400</td><td colspan="1">450</td></tr>
<tr><td colspan="1">1.б</td><td colspan="1">51</td><td colspan="1">101</td><td colspan="1">151</td><td colspan="1">201</td><td colspan="1">251</td><td colspan="1">301</td><td colspan="1">351</td><td colspan="1">401</td><td colspan="1">451</td></tr>
<tr><td colspan="1" valign="top">2.а</td><td colspan="1" valign="top">25</td><td colspan="1" valign="top">50</td><td colspan="1" valign="top">75</td><td colspan="1" valign="top">100</td><td colspan="1" valign="top">125</td><td colspan="1" valign="top">150</td><td colspan="1" valign="top">175</td><td colspan="1" valign="top">200</td><td colspan="1" valign="top">225</td></tr>
<tr><td colspan="1" valign="top">2.б</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">6</td><td colspan="1" valign="top">6</td></tr>
<tr><td colspan="1" valign="top">2.в</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">6</td><td colspan="1" valign="top">6</td></tr>
</table>

Общая оценка сложности алгоритмов показана в таблице 2.

Таблица 2



|Поиск|Сложность|
| - | - |
|Линейный|N|
|Быстрый линейный|N|
|Бинарный|Log2N|
|Блочный|X+N/X (X-количество блоков)|
