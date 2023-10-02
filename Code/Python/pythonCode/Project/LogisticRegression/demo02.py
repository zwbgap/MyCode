'''
Author: username email@example.com
Date: 2023-03-10 13:29:14
LastEditors: username email@example.com
LastEditTime: 2023-03-11 17:21:32
FilePath: \pythonCode\Project\LogisticRegression\demo02.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''

from sklearn.datasets import load_iris
import pandas as pd
import matplotlib.pyplot as plt

iris = load_iris() # 得到数据集特征，包括data, target, feature_names, taget_names, DESCR等信息
df_X = pd.DataFrame(data=iris.data,columns=iris.feature_names)
y = iris.target
df_X.describe()

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
X_train,X_test,y_train,y_test = train_test_split(df_X,y, test_size=0.2, random_state=20200816)

lr = LogisticRegression()
lr.fit(X_train,y_train)

##查看其对应的w，3分类包含三个逻辑回归的参数
print('the weight(w) of Logistic Regression:\n',lr.coef_)
##查看其对应的w0
print('the intercept(w0) of Logistic Regression:\n',lr.intercept_)


from sklearn import metrics
import seaborn as sns
# 预测
y_train_pred=lr.predict(X_train)
y_test_pred=lr.predict(X_test)

##利用accuracy（准确度）【预测正确的样本数目占总预测样本数目的比例】评估模型效果
print('The accuracy on train set is:',metrics.accuracy_score(y_train,y_train_pred))
print('The accuracy on test set is:',metrics.accuracy_score(y_test,y_test_pred))

# 绘制混淆矩阵
confusion_matrix_result=metrics.confusion_matrix(y_test,y_test_pred)
print('The confusion matrix result:\n',confusion_matrix_result)

##利用热力图对于结果进行可视化
plt.figure(figsize=(8,6))
sns.heatmap(confusion_matrix_result,annot=True,cmap='Blues')
plt.xlabel('Predicted labels')
plt.ylabel('True labels')
plt.show()



