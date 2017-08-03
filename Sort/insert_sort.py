# coding=utf-8
'''
插入排序
python
简单实现
'''
import random
def insert_sort(list):
    for i in range(len(list)):
        j = i - 1
        while j >= 0 and list[j] > list[j + 1]:
            list[j], list[j+1] = list[j+1] , list[j]
            j -= 1
list = []
for x in range(10):
    list.append(random.randint(0,99))
print list
insert_sort(list)
print list

'''测试''''''
[45, 31, 80, 2, 14, 59, 99, 36, 33, 78]
[2, 14, 31, 33, 36, 45, 59, 78, 80, 99]
'''
