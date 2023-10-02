#-*- coding utf-8 -*-
#Demo of Box

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#设置字体为黑体
plt.rcParams['font.sans-serif'] = ['Simhei']
#解决坐标轴符号'-'显示为方块
plt.rcParams['axes.unicode_minus'] = False

x = np.random.randn(1000)
print(x)
plt.boxplot(x)
plt.xticks([1], ["随机数生成器AlphaRM"])
#plt.xlabel("随机数生成器AlphaRM")
plt.ylabel("随机数值")
plt.title("随机数生成器抗干扰能力的稳定性")
plt.grid(axis="y", ls=":", lw=1, color="gray", alpha=0.4)
plt.show()