"""
用随机模块生成已一个200个元素的列表，元素是0~1之间的浮点数，计算均值和方差。
"""
import numpy as np
if __name__ == '__main__':
    list1 = [np.random.rand() for i in range(200)]
    print(f'随机生成列表:\n{list1}')
    mean_value = np.mean(list1)
    print(f'均值：{mean_value}')
    # print(f'均值：{sum(list1) / len(list1)}')

    sp1 = []
    variance = np.var(list1)
    print(f'方差：{variance}')
    # ss = sum(((i-mean_value)**2) for i in list1) / len(list1)
    # print(f'方差：{ss}')
