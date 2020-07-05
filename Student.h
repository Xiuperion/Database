#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
class Student {
public:
	string name_, id_,sex_, birth_, birthplace,courses;
	int schoolyear,scores,credits;
	Student(string id, string name, string sex, int schoolyear, string birthplace, string birth) :
		id_(id), sex_(sex), name_(name), schoolyear(schoolyear), birth_(birth), birthplace(birthplace) {}
	~Student(){}
	//进行信息录入
	string getBirthYear()const { return birth_; }
	string getName()const { return name_; }
	string getID()const { return id_; }
	string getBirthplace()const { return birthplace; }
	int getSchoolYear()const { return schoolyear; }
	int getScore()const { return scores; }
};

class StudentInfo {
	vector<Student>students;//保存学生个人信息
	vector<vector<string>>allCoursesInfo;//保存选课信息
	multimap<string, set<string>>idToCourse;//学号映射
	multimap<string, set<string>>courseName;//课名对人映射
	//多次排序
	map<string, Student>sortName;
	map<string, Student> sortID;
	map<string, Student> sortSex;
	map<string, Student> sortBirthPlace;
	map<string, Student> sortBirth;
	map<int, Student> sortSchoolYear;
	map<string, map<int,Student>> sortScore;
	map<int, Student> sortTotalScore;

public:
	StudentInfo(ifstream& is,map<int,Student>& st) {}
	~StudentInfo(){}
	void StudentCourse(ifstream& is,map<int,Student>& st);
	void sortByName();
	void sortById();
	void sortBySex();
	void sortBySchoolYear();
	void sortByScore();
	void sortByTotalScore();
};
#endif
