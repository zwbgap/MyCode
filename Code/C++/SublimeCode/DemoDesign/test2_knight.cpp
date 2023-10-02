#include<iostream>
#include<iomanip>

using namespace std;
int cal = 0;//统计移动的顺序
//棋盘进行初始化
//int chess[8][8] = {0};
int chess[8][8] = 
{
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

//判断是否出界
bool ifOut(int x, int y){//传入坐标
    if(x < 0 || x > 7 || y < 0 || y > 7)
        return true;
    return false;
}

//判断是否已经被访问
bool ifVisited(int x, int y){//数组元素初始化为0
    if(chess[x][y] != 0)
        return true;
    return false;
}

void dfs(int x, int y){
    if(cal == 64)
        return;//棋盘一共64个位置，遍历完则退出
    if(!ifVisited(x, y) && !ifOut(x, y)){
        //没有被访问且没有出界
        cal++;
        chess[x][y] = cal;//做标记
        //骑士的走法有八个方位
        dfs(x + 2, y + 1);
        dfs(x - 2, y - 1);
        dfs(x + 2, y - 1);
        dfs(x - 2, y + 1);
        dfs(x - 1, y - 2);
        dfs(x + 1, y - 2);
        dfs(x + 1, y + 2);
        dfs(x - 1, y + 2);
    }
    return;//出界则退出
}

int main(){
    int x, y;
    cout << "Please input the knight's initial position:" << endl;
    while(true){
        cin >> x >> y;
        if(ifOut(x, y))
            cout << "Wrong initial position. Please input again:" << endl;
        else
            break;
    }
    dfs(x, y);
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
            cout << setw(2) << chess[i][j] << " ";
        cout << endl;
    }

    return 0;
}