#-*- coding ytf-8 -*-
#Demo subplt

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

ds = pd.Series(np.random.rand(7),index=['星期一','星期二','星期三','星期四','星期五','星期六','星期日'])
ds.plot(kind =" barh",color='r',alpha=0.5)

plt.yticks(rotation=45)

plt.show()
