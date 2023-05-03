#  Эвристический алгоритм (продолжения задания 11)

## Задание

Задача о куче камней. Имеется N камней, известны их веса Pi (i=1...N), задано количество куч M. Требуется разложить камни на M куч так, чтобы минимизировать вес самой тяжелой кучи. (Вариант формулировки: даны N программ с длительностями Pi и M процессоров. Требуется распределить программы так, чтобы раньше закончить выполнение).

Время работы программы для разных наборов данных и сравнение эвристического алгоритма с алгоритмом перебора представлены в таблице 1.

<br/>

Таблица 1 - Время работы программы для разных наборов данных. Сравнение эвристического и переборного методов.

<table><tr><th colspan="1" rowspan="2" valign="top"><p></p><p><b>N</b></p></td><th colspan="1" rowspan="2" valign="top"><p></p><p><b>M</b></p></td><th colspan="2" valign="top"><b>Среднее время</b></td><th colspan="2" valign="top"><b>Количество итераций</b></td></tr>
<tr></td></td><td colspan="1" valign="top"><b>Перебор</b></td><td colspan="1" valign="top"><b>Эвристика</b></td><td colspan="1" valign="top"><b>Перебор</b></td><td colspan="1" valign="top"><b>Эвристика</b></td></tr>
<tr><td colspan="1" valign="top">4</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">30 мс</td><td colspan="1" valign="top">3 мс</td><td colspan="1" valign="top">71</td><td colspan="1" valign="top">8</td></tr>
<tr><td colspan="1" valign="top">5</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">55 мс</td><td colspan="1" valign="top">5 мс</td><td colspan="1" valign="top">175</td><td colspan="1" valign="top">11</td></tr>
<tr><td colspan="1" valign="top">6</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">110 мс</td><td colspan="1" valign="top">7 мс</td><td colspan="1" valign="top">415</td><td colspan="1" valign="top">14</td></tr>
<tr><td colspan="1" valign="top">4</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">80 мс</td><td colspan="1" valign="top">3 мс</td><td colspan="1" valign="top">333</td><td colspan="1" valign="top">7</td></tr>
<tr><td colspan="1" valign="top">5</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">250 мс</td><td colspan="1" valign="top">5 мс</td><td colspan="1" valign="top">1255</td><td colspan="1" valign="top">11</td></tr>
<tr><td colspan="1" valign="top">6</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">790 мс</td><td colspan="1" valign="top">7 мс</td><td colspan="1" valign="top">4495</td><td colspan="1" valign="top">15</td></tr>
<tr><td colspan="1" valign="top">5</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">800 мс</td><td colspan="1" valign="top">4 мс</td><td colspan="1" valign="top">5205</td><td colspan="1" valign="top">9</td></tr>
</table>
