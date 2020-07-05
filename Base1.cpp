#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include"Student.h"

using namespace std;

StudentInfo::StudentInfo(ifstream&is1,map<int,Student>& st)
{

}
template<class T>
void SortbyItem(vector<T>item, map<string, T>name_item) {
	sort(item.begin(), item.end());
	for (int i = 0; i < 6; i++)
		for (map<string, T>::iterator it = name_item.begin(); it != name_item.end(); it++)
			if (it->second == item[i])cout << it->first << endl;
}


void StudentInfo::StudentCourse(ifstream& is2, map<int, Student>& st) {
	int id_;
	string s, courseName;
	while (getline(is2, s)) {
		if (s[0] == '#')
			getline(is2, s);//跳过注释内容

		auto order1 = s.find_first_of('\t');
		auto order2 = s.find_first_of('\t', order1 + 1);//删除课程名单
		courseName = s.substr(order1 + 1, order2 - order1);
		s = s.erase(order1, order2 - order1);
		istringstream str(s);
		str >> id_ >> st[id_].credits[courseName] >> st[id_].scores[courseName];//录入id，用id查询信息(来不及重载了，抱歉）
	}	st[id_].courses.push_back(courses);
}

int main()
{
	map<int, Student>st;
	ifstream is1("StudentInfo.txt");
	ifstream is2("StudentCourse.txt");
	if (!is1 || !is2) {
		cout << "open file error!" << endl;
		return -1;
	}
	StudentInfo si(is1, st);
	si.StudentCourse(is2, st);
	cout << st[10919].schoolyear << endl;
	map<string, int>mp = st[10919].scores;
	string s = "CPP Language";
	cout << mp[s] << endl;
	return 0;
}
//时间不够了，写不完全部定义了，抱歉