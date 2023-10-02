#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;

/*(1) 缁冧� vector � list 鐨勪娇鐢�
   瀹氫箟涓涓┖鐨 vector锛屽厓绱犵被鍨嬩� int锛岀敓鎴 10 涓殢鏈烘暟鎻掑叆鍒 
   vector 涓紝鐢ㄨ凯浠ｅ櫒閬嶅巻 vector 骞惰緭鍑哄叾涓殑鍏冪礌鍊笺傚湪 vector 
   澶撮儴鎻掑叆涓涓殢鏈烘暟锛�敤杩唬鍣ㄩ亶鍘 vector骞惰緭鍑哄叾涓殑鍏冪礌鍊笺傜敤
   娉涘瀷绠楁硶 find 鏌ユ壘鏌愪釜闅忔�鏁帮紝濡傛灉鎵惧埌渚胯緭鍑猴紝鍚�垯灏嗘鏁版彃鍏 
   vector 灏鹃儴銆傜敤娉涘瀷绠楁硶 sort � vector 鎺掑簭锛�敤杩唬鍣ㄩ亶鍘 vector 
   骞惰緭鍑哄叾涓殑鍏冪礌鍊笺傚垹� vector 灏鹃儴鐨勫厓绱狅紝鐢ㄨ凯浠ｅ櫒閬嶅巻 vector 
   骞惰緭鍑哄叾涓殑鍏冪礌鍊笺傚皢 vector 娓呯�*/


void DisplayVector(vector<int> &vec){
   vector<int>::iterator it;//杩唬鍣
   //vector<int> vec;
   for (it = vec.begin(); it != vec.end(); it++)
      cout << *it << "\t";//杩唬鍣ㄨ緭�
    cout << endl;
}

int main(){
   vector<int>::iterator it;//杩唬鍣
   vector<int> vec;
   srand((unsigned)time(NULL));//鍒涘缓鏃堕棿绉嶅�
    for (int i = 0; i < 10; ++i)
    {
      vec.push_back(rand() % 100);
    }
    cout << "size:" << vec.size() << endl;
    cout << "elements�" << endl;
    DisplayVector(vec);

    //澶撮儴鎻掑叆闅忔��
    cout << "鍦╲ector澶撮儴鎻掑叆涓涓殢鏈烘暟锛";
    int num_insert = rand() % 100;
    cout << num_insert << endl;
    it = vec.begin();
    vec.insert(it,num_insert);
    cout << "鎻掑叆鍚巚ector涓殑鍏冪礌涓猴�" << endl;
    DisplayVector(vec);
    cout << "�始测�" << endl;

    //鏌ユ�
    int num_seek = rand() % 100;
    cout << "鏌ユ壘闅忔満鏁帮�" << num_seek << endl;
    it = find(vec.begin(),vec.end(),num_seek);
    if(it != vec.end())
      cout << "宸叉煡鎵惧埌:" << num_seek <<  endl;
    else{
      cout << "鏈煡鎵惧埌:" << num_seek << ",灏嗗叾鎻掑叆vector灏鹃儴銆" << endl;
      vec.push_back(num_seek); //鍏冪礌鎻掑叆鍒板熬閮
    }
    DisplayVector(vec);
    cout << "��ʼ���� " << endl;
    
    //杩涜鎺掑簭
    sort(vec.begin(),vec.end());
    cout << "娉涘瀷绠楁硶sort鎺掑簭锛" << endl;
    DisplayVector(vec);

    //鍒犻櫎鎺掑簭鍚巚ector灏鹃儴鐨勫厓�
    it = vec.end() - 1;
    cout << "鎵ц鍒犻櫎vector灏鹃儴鍏冪礌�" << *it << endl;
    vec.pop_back();
    cout << "鍒犻櫎鍚巚ector涓厓绱犱负�" << endl;
    DisplayVector(vec);

    //娓呯┖vector
    cout << "鎵ц娓呯┖vector�" << endl;
    vec.clear();
    cout << "娓呯┖鎴愬姛�" << endl;
    //DisplayVector(vec);
   return 0;
}