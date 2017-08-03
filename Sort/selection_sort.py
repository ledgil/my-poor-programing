#coding=utf-8
'''
选择排序
python
简单实现
'''
import random
def selection_sort(list):
    for i in range(len(list)):
        min = j = i
        while j < len(list):
            if  list[j] < list[min] :
                min = j
            j += 1
        list[i] , list[min] = list[min] , list[i]
list = []
for x in range(10):
    list.append(random.randint(0,99))
print list
selection_sort(list)
print list

'''测试''''''
[93, 48, 49, 84, 48, 2, 52, 65, 91, 99]
[2, 48, 48, 49, 52, 65, 84, 91, 93, 99]
'''
