#include <iostream>
#include <string>
using namespace std;
class Course{
public:
	Course(const string& courseName, int capacity);
	~Course();
	Course(const Course&);
	string getCourseName() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudents() const;
	int getNumberOfStudent() const;
private:
	string courseName;
	string* students;
	int numberOfStudent;
	int capacity;
};
Course::Course(const string& courseName, int capacity){
	numberOfStudent = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}
Course::~Course(){
	delete [] students;
}
string Course::getCourseName() const{
	return courseName;
}

void Course::addStudent(const string& name){
	if(numberOfStudent > capacity){
		cout << "The maximum size of array exceeded" << endl;
		cout << "Program terminates now" << endl;
		exit(0);
	}
	students[numberOfStudent++] = name;
}
void Course::dropStudent(const string& name){
	for(int i = 0; i < numberOfStudent;i++){
		if(students[i] == name){
			for(int j = i+1; j < numberOfStudent;j++)
				students[j-1] = students[j];
		}
	}
	numberOfStudent--;
}
string* Course::getStudents() const{
	return students;
}
int Course::getNumberOfStudent() const{
	return numberOfStudent;
}
Course::Course(const Course& course){
	courseName = course.courseName;
	numberOfStudent = course.numberOfStudent;
	capacity = course.capacity;
	students = new string[capacity];
	for(int i = 0; i < numberOfStudent;i++)
		students[i] = course.students[i];
}


int main(){
	Course course1("C++ Programming", 10);
	Course course2(course1);

	course1.addStudent("zhangsan");
	course2.addStudent("lisi");

	cout << "Students in course1: " << course1.getStudents()[0] << endl;
	cout << "Students in course2: " << course2.getStudents()[0] << endl;
	cout << course1.getCourseName() << endl;
	cout << course2.getCourseName() << endl;
	return 0;
	
}