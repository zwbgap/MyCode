# 1、导入os模块、time模块
import os
import time

# 2、调用rename方法实现重命名（需要手工刷新左侧导航栏）
os.rename('readme.txt', 'python.txt')

# 3、调用time模块中的sleep方法休眠100s
time.sleep(10)

# # 4、删除readme.txt文件
# os.remove('readme.txt')
