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
	//������Ϣ¼��
	string getBirthYear()const { return birth_; }
	string getName()const { return name_; }
	string getID()const { return id_; }
	string getBirthplace()const { return birthplace; }
	int getSchoolYear()const { return schoolyear; }
	int getScore()const { return scores; }
};

class StudentInfo {
	vector<Student>students;//����ѧ��������Ϣ
	vector<vector<string>>allCoursesInfo;//����ѡ����Ϣ
	multimap<string, set<string>>idToCourse;//ѧ��ӳ��
	multimap<string, set<string>>courseName;//��������ӳ��
	//�������
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
