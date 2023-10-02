"""
编程设计一个队列类  Myqueue，主要的类成员包括：   3 个数据成员（队列的最
大长度 size，队列所有数据  data，队列的元素个数  current）和 6 个成员方法如下：
1)  初始化    ：设置队列为空;
2)  判断队列为空：若为空，则返回 TRUE，否则返回  FALSE.
3)  判断队列为满：若为满，则返回 TRUE，否则返回  FALSE.
4)  取队头元素：取出队头元素;
条件：队列不空。
否则，应能明确给出标识，以便程序的处理.
5)  入队：将元素入队，即放到队列的尾部
6)  出队：删除当前队头的元素
"""


class Myqueue(object):

    def __init__(self):  # 定义一个空队列
        self.queue = []

    def in_queue(self, element):  # 1个元素入队列
        self.queue.append(element)
        print('元素%s入队列成功!' % element)

    def many_in_queue(self, *args):  # 多个元素入队列
        self.queue.extend(args)

    def out_queue(self):  # 出队列
        if not self.queue == []:  # 队列不为空时，弹出第一个元素
            out_element = self.queue.pop(0)
            print('元素%s出队列成功!' % out_element)
        else:
            print('队列为空,无法出队列!')  # 队列为空时报错

    def head(self):  # 队列首元素
        if not self.queue == []:  # 队列不为空
            print('队列首元素为%s' % self.queue[0])
        else:
            print('队列为空,无队列首元素!')

    def tail(self):  # 队列尾元素
        if not self.queue == []:  # 队列不为空
            print('队列尾元素为%s' % self.queue[-1])
        else:
            print('队列为空,无队列尾元素!')  # 对列为空时报错

    def length(self):  # 队列长度
        print('队列的长度为%s' % len(self.queue))

    def show(self):  # 显示队列
        print('队列为:')
        for i in self.queue:
            print(i, end=' ')
        print()

    def is_empty(self):  # 判断队列是否为空
        if len(self.queue) == 0:
            print('队列为空!')
        else:
            print('队列不为空!')


queue1 = Myqueue()
queue1.is_empty()
queue1.in_queue(1)
queue1.is_empty()
queue1.many_in_queue(*(list(i for i in range(20))))
queue1.show()
queue1.head()
queue1.tail()
queue1.length()
queue1.out_queue()
queue1.is_empty()
