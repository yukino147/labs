# Прочитаем текстовый файл и посчитаем количество слов в нем,# а также количество уникальных слов.
file = open (r"C:\aa\питон\файлы\Pushkin_Ruslan_i_Lyudmila.txt", "r")

# читаем содержимое файла в переменную
poem = file.read() 

#  понижаем регистр всех букв в переменной
poem = poem.lower() 

#  Кол-во строк
s=0
for i in poem:
    if(i == '\n'):
        s+=1 

#  Разбиваем текст по словам и создаем список из слов
poem = poem.split() 

# Топ уникалоьных слов
d = dict()
for word in poem:
    if word in d: 
        # Увеличить счетчик слов на 1 
        d[word] = d[word] + 1 
    else: 
    # Добавить слово в словарь с количеством 1 
        d[word] = 1
# Сортирока
sd = dict(sorted(d.items(), key=lambda x: x[1], reverse=True))

# Посчитаем количество уникальных слов используя множество
slova = set (poem) # все дубли слов удалятся при внесении их в множество

#  Записываем в файл
with open("output.txt", "w") as out:
    print("В файле <<", file.name, ">>",file=out)
    print("Строк:", s, file=out)
    print("Слов:",len(poem), file=out)
    print("Уникальных слов:", len(slova), file=out)
    print("Топ-20 уникальных слов:", file=out)
    i=0
    for key in list(sd.keys()):  
        i+=1
        if(i>20):
            break
        else:
            print(key, "-", sd[key],file=out)

print("Файл изменен")
out.close()
file.close()