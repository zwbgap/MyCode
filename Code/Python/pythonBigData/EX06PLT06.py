# -*- coding utf-8 -*-
# Demo of multi bar

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# 设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
# 解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

month = ['1月', '2月', '3月', '4月', '5月', '6月', '7月', '8月', '9月', '10月', '11月', '12月']

df = pd.DataFrame(np.random.rand(12, 3), columns=['部门1', '部门2', '部门3'], index=month)
df.plot(kind='bar')

plt.ylim(0, 1.1)
plt.xticks(rotation=0)

plt.show()
