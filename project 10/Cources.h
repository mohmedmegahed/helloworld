#pragma once
#pragma once
#include<string>
	class node {
		int noCourse;
		std::string CourseCode;
		std::string CourseName;
		int MaxStud;
		int CourseHours;
		node* next;
	public:
		void EnterPrereq();
		void EnterFinCourses();
		void viewlistofavcourses();
		bool isEmpty(node* head);
		void insertAsFirst(node*& head, node*& last, std::string CourseCode, std::string CourseName, int MaxStud, int CourseHours);
		void insert(node*& head, node*& last, std::string CourseCode, std::string CourseName, int MaxStud, int CourseHours);
		void remove(node*& head, node*& last);
		void showList(node* current);
	};

	
	class common
	{
		std::string un, ps;
		std::string AdminName;
		std::string AdminPass;
		std::string studName;
		std::string studPass;
	public:
		common(void);
		//bool Login();
		~common(void);
	};




	class Admin
	{
		std::string AdminName;
		std::string AdminPass;
		std::string* arr;
		int size, count;
	public:
		Admin(void);
		void AddStud();
		void AddCourse();
		void ViewAllStudSpecifCourse(std::string CourseCode);
		void ViewAllFinProCourses();
		void EditCourse(std::string CourseCode);
		~Admin(void);
	};


	class Student
	{
	public:
		std::string studName;
		int studID;
		std::string studPass;
		std::string* finishedCourses;
		std::string coursesProgress[50];
		std::string academicYear;
	public:
		Student(void);
		void CourseDetails();
		void ViewMyCoursess();
		void CourseRegister();

		void Editdata(int studID);
		~Student(void);
	};

	
	class Cources
	{public:
		
		std::string CourseName;
		std::string CourseCode;
		int MaxStud;
		std::string *PrerequisiteCourses;
		int CourseHours;
	public:
		Cources(void);
		~Cources(void);
	};



