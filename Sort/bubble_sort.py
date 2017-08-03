'''
冒泡排序
python
简单实现
'''
# coding=utf-8
import random
def bubble_sort(list):
    for i in range(len(list))[::-1]:
        for j in range(i):
            if (list[j] > list[j + 1]):
                list[j], list[j + 1] = list[j + 1], list[j]
list = []
for x in range(10):
    list.append(random.randint(0, 99))
print list
bubble_sort(list)
print list
