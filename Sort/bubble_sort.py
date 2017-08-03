# coding=utf-8
'''
冒泡排序
python
简单实现
'''
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

'''测试''''''
[9, 20, 84, 57, 10, 52, 49, 31, 42, 41]
[9, 10, 20, 31, 41, 42, 49, 52, 57, 84]
'''
