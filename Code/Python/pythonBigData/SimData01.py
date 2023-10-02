# -*- coding: utf-8 -*-
'''
This program generate  simdata
'''

import pandas as pd
import numpy as np
import random

df = pd.read_csv("StuSimData23.csv", encoding='utf-8')
# print(df.info())


df1 = pd.DataFrame()

df1[['姓名', '学号', '专业班级']] = df[['姓名', '学号', '专业班级']]
item = []
df1['C21'] = ["{:.1f}".format(random.random() * 100) for x in range(len(df['C1']))]
df1['C22'] = ["{:.1f}".format(random.random() * 100) for x in range(len(df['C1']))]
print(df1)
df1.to_excel("StuSimData232.xlsx", encoding='utf-8', index=False, sheet_name='第二学期')
