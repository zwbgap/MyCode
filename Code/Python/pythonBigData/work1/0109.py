from operator import itemgetter
import random
lit = [random.randint(0,1000) for i in range(10000)]
lit1 = set(lit) # set 可去重
dit_a = dict()
for i in lit1:
    dit_a[i] = lit.count(i)
# print(dit)
# print((sorted(dit.items(),key = itemgetter(1)))
lit2 = sorted(dit_a.items(),key = itemgetter(1))
# print(lit2)
# print()
print("Finshed with set and dict:")
print(lit2[:10])
# print()
print(lit2[::-1][:10])

#  print({lit1.pop():lit.count(lit1.pop()) for i in range(10)})              


list_a = []
for i in range(10000):
     list_a.append(random.randint(0,1000))
list_a = sorted(list_a)  #将list_a排列, 方便观察统计出来的结果，sorted 默认升序排序。
dic_b = dict()   #创建字典
for i in list_a:
    if i not in dic_b:    #如果元素i在字典dic_b中第一次出现, 就dic_b[i]等于1.
        dic_b[i] = 1
    else:
        dic_b[i] += 1   #如果元素不是第一次出现， 就加1
# print(dic_b)
lit2 = sorted(dit_a.items(),key = itemgetter(1))
print("Finshed with List:")
print(lit2[:10])
print(lit2[::-1][:10])