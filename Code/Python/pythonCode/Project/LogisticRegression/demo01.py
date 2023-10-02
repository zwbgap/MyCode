# 基础函数库
import numpy as np

#导入画图库
import matplotlib.pyplot as plt
import seaborn as sns

#导入逻辑回归模型函数
from sklearn.linear_model import LogisticRegression

## 数据创建与可视化
x = np.array([[-1, -2], [-2, -1], [-3, -2], [1, 3], [2, 1], [3, 2]])
y = np.array([0, 0, 0, 1, 1, 1])

## 可视化构造的样本数据点
fig = plt.figure(figsize=(6,5))
plt.scatter(x[:,0],x[:,1], c = y, s = 50, cmap = 'viridis')
plt.title("Dataset")
plt.show()

## 根据我们标签设置的结果，左下角为 0 类,右上角为 1 类

# 创建逻辑回归分类器
lr = LogisticRegression()
lr.fit(x, y)   # 拟合数据点

## 查看其对应模型的w
print('the weight(w) of Logistic Regression:',lr.coef_)
## 查看其对应模型的w0
print('the intercept(w0) of Logistic Regression:',lr.intercept_)

# 可视化决策边界
plt.figure()
plt.scatter(x[:,0], x[:,1], c = y, s = 50, cmap = 'viridis')
plt.title('Dataset')

nx, ny = 200, 100  # 指定点个数
x_min, x_max = plt.xlim()  # x轴的边界
y_min, y_max = plt.ylim()  # y轴的边界

# 得到所有可能坐标点组合,以linespace生成的数据点
x_grid, y_grid = np.meshgrid(np.linspace(x_min, x_max, nx), np.linspace(y_min, y_max, ny))

# ravel()将n*m的数组转换为(n*m,1)，np.c_([],[])按行连接两个矩阵,
z_proba = lr.predict_proba(np.c_[x_grid.ravel(), y_grid.ravel()])   # 由此得到所有可能坐标点输入后的概率值, z_proba:(20000,2)
z_proba = z_proba[:, 1].reshape(x_grid.shape)

plt.contour(x_grid, y_grid, z_proba, 1, linewidths=2., colors='blue')  # 绘制等高线，找到所有经过逻辑回归后值相同的点，取中间的等高线

plt.show()


# 分类器预测
## 新的预测点
x_fearures_new1 = np.array([[0, -1]])
x_fearures_new2 = np.array([[1, 2]])

## 预测分类
y_label_new1_predict = lr.predict(x_fearures_new1)
y_label_new2_predict = lr.predict(x_fearures_new2)
print('The New point 1 predict class:\n',y_label_new1_predict)
print('The New point 2 predict class:\n',y_label_new2_predict)

## 预测分类概率
y_label_new1_predict_proba = lr.predict(x_fearures_new1)
y_label_new2_predict_proba = lr.predict(x_fearures_new2)
print('The New point 1 predict Probability of each class:\n',y_label_new1_predict_proba)
print('The New point 2 predict Probability of each class:\n',y_label_new2_predict_proba)