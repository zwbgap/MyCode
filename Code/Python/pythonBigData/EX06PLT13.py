import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt

points = np.arange(-5, 5, 0.01) #1000个间隔相等的点
xs, ys = np.meshgrid(points, points) #生成网格点坐标矩阵
z = np.sqrt(xs**2 + ys**2) #xs*xs + ys*ys = z*z

fig = plt.figure() #创建一个新Figure
fig.suptitle("Image plot of r'$\sqrt{x^2+y^2}$' for a grid of values") #设置总标题

#第1个子图
ax1 = fig.add_subplot(221) 
plt.imshow(z)
#第2个子图
ax2 = fig.add_subplot(222) 
plt.imshow(z, cmap = plt.cm.gray) 
#第3个子图
ax3 = fig.add_subplot(223) 
plt.imshow(z, cmap = plt.cm.cool)
#第4个子图
ax4 = fig.add_subplot(224)
plt.imshow(z, cmap = plt.cm.hot)

plt.show()
