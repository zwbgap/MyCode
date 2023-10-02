#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
using namespace std;

class point{
public:
	point(){
		this->x = 0;
		this->y = 0;
	}
	point(double x1, double y1){
		this->x = x1;
		this->y = y1;
	}
	double x;
	double y;
};

class polar{
public:
	polar(){
		this->r = 0;
		this->theta = 0;
	}
	polar(double r1, double angle){
		this->r = r1;
		this->theta = angle;
	}
	double r;
	double theta;
};

class solution{
public:
	void init();
	void cal();
	polar p1, p2;
	string point1, point2;
	map<string, point>m;
	double X0, Y0, X, Y, X1, Y1, X2, Y2;
	double r1,r2,theta1, theta2;
};

void solution::init(){
	point C(0, 0), P1(-52.5, -32), P2(-52.5, 32), P3(52.5, 32), P4(52.5, -32), P5(0, -32),
	P6(0, 32), P7(-30, -7), P8(-30, 7), P9(30, 7), P10(30, -7), G1(-52.5, 0), G2(52.5, 0);
	m.insert(make_pair("C", C)); m.insert(make_pair("P1", P1)); m.insert(make_pair("P2", P2));
	m.insert(make_pair("P3", P3)); m.insert(make_pair("P4", P4)); m.insert(make_pair("P5", P5));
	m.insert(make_pair("P6", P6)); m.insert(make_pair("P7", P7)); m.insert(make_pair("P8", P8));
	m.insert(make_pair("P9", P9)); m.insert(make_pair("P10", P10)); m.insert(make_pair("G1", G1));
	m.insert(make_pair("G2", G2));
	string str1, str2;
	str1 = "(P8 14 -30)"; str2 = "(P7 14 30)";
	vector<int>v1, v2;
	for (int i = 0;i < str1.size(); i++)
	{
		if (str1[i] == ' ')
		{
			v1.push_back(i);
		}
		continue;
	}
	for (int j = 0; j < str2.size(); j++)
	{
		if (str2[j] == ' ')
		{
			v2.push_back(j);
		}
		continue;
	}
	point1 = str1.substr(1, v1[0] - 1);point2 = str2.substr(1, v2[0] - 1);
	X1 = m[point1].x; Y1 = m[point1].y; X2 = m[point2].x; Y2 = m[point2].y;
	istringstream iss(str1.substr(v1[0] + 1, v1[1] - v1[0] - 1)); iss >> r1;
	istringstream iss1(str2.substr(v2[0] + 1, v2[1] - v2[0] - 1)); iss1 >> r2;
	istringstream iss2(str1.substr(v1[1] + 1, str1.size() - v1[1] - 2)); iss2 >> theta1;
	istringstream iss3(str2.substr(v2[1] + 1, str2.size() - v2[1] - 2)); iss3 >> theta2;
    p1 = polar(r1, theta1); p2 = polar(r2, theta2);
}

void solution::cal(){
	double A1, A2, A3, B1, B2, B3, C3,theta_value=theta2 - theta1;
	A1 = (r1 * r1 - r2 * r2) + (X2 * X2 - X1 * X1) + (Y2 * Y2 - Y1 * Y1);
	A2 = A1 / (2 * (Y2 - Y1));
	B2 = (X2 - X1) / (Y2 - Y1);
	A3 = 1 + B2 * B2;
	B3 = (-1) * (2 * X1 + 2 * (A2 - Y1) * B2);
	C3 = X1 * X1 + pow((A2 - Y1), 2) - r1 * r1;
	X0 = (-B3 + sqrt(B3 * B3 - 4 * A3 * C3)) / (2 * A3);
	Y0 = A2 - B2 * X0;
	X = (-B3 - sqrt(B3 * B3 - 4 * A3 * C3)) / (2 * A3);
	Y = A2 - B2 * X;
	if (theta_value < 0)
	{
		if (Y == -0)
			Y = 0;
		if (X == -0)
			X = 0;
		cout<<"机器人自身坐标点为：(" << X << "," << Y<<')' << endl;
	}
	else
	{
		if (Y0 == -0)
			Y0 = 0;
		if (X0 == -0)
			X0 = 0;
		cout <<"机器人自身坐标点为：(" << X0 << "," << Y0 << ')' << endl;
	}
}
int main()
{
	solution s;
	s.init();
	s.cal();
	return 0;
}
