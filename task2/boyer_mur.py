def pred_compile_dict(substr):
    dict = {} #char - position
    substr_len = len(substr)
    for i in range(substr_len-1):
        #сколько символов (считая справа подстроки) до этого символа
        dict[substr[i]] = substr_len - i - 1
    dict[substr[substr_len-1]] = 1
    return dict

def boyer_mur(str, substr):
    enter_inds = []
    dict = pred_compile_dict(substr)
    # k-индекс для прохода по строке(справа налево)
    # j-индекс для прохода по подстроке(справа налево)
    # i-индекс указывает на место откуда начался проход по строке(слева направо)
    substr_last_ind = i = j = k = len(substr) - 1
    while i < len(str):
        #символы совпали - движемся по подстроке дальше(от конца к началу)
        #и сравниваем остальные символы 
        if str[k] == substr[j]:
            k-=1
            j-=1
        #символы не совпали - перемещаемся на следуещее
        #вхождение последнего символа подстроки в строку
        else:
            i += dict.get(str[i], substr_last_ind+1)
            k = i
            j = substr_last_ind
        
        if j < 0: #нашли
            enter_inds.append(k+1)
            i += dict.get(str[i], substr_last_ind+1)
            k = i
            j = substr_last_ind
        
    return enter_inds