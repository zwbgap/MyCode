#include<iostream>
#include<iomanip>

using namespace std;
int cal = 0;//ͳ���ƶ���˳��
//���̽��г�ʼ��
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

//�ж��Ƿ����
bool ifOut(int x, int y){//��������
    if(x < 0 || x > 7 || y < 0 || y > 7)
        return true;
    return false;
}

//�ж��Ƿ��Ѿ�������
bool ifVisited(int x, int y){//����Ԫ�س�ʼ��Ϊ0
    if(chess[x][y] != 0)
        return true;
    return false;
}

void dfs(int x, int y){
    if(cal == 64)
        return;//����һ��64��λ�ã����������˳�
    if(!ifVisited(x, y) && !ifOut(x, y)){
        //û�б�������û�г���
        cal++;
        chess[x][y] = cal;//�����
        //��ʿ���߷��а˸���λ
        dfs(x + 2, y + 1);
        dfs(x - 2, y - 1);
        dfs(x + 2, y - 1);
        dfs(x - 2, y + 1);
        dfs(x - 1, y - 2);
        dfs(x + 1, y - 2);
        dfs(x + 1, y + 2);
        dfs(x - 1, y + 2);
    }
    return;//�������˳�
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