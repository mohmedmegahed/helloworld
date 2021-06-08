#include "Cources.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<assert.h>
#include<cassert>
#include<vector>
#include<stdlib.h>
#include<string>

Admin::Admin()
{
	AdminName = "\0";
	AdminPass = "\0";
	size = 500;
	arr = new std::string[50];
	count = 0;
}


common::common()
{
	un, ps = "\0";
	AdminName, AdminPass = "\0";
	studName, studPass = "\0";
}




// a function to login for user or student


//bool common ::Login() {
//	int answer;
//	//std::cout << "\n\t\t\tWelcome! Please login below.\n\n" << std::endl;
//	//std::fstream insert("admin");
//	//insert.open("Admin.txt", std::ios::binary | std::ios::in);
//	//insert >> un >> ps;
//	//insert.close();
//	std::cout << "\n\t\t\t\t**********\n";
//
//	std::cout << "Enter username : ";
//	getline(std::cin, AdminName);
//	std::cin.ignore();
//
//	std::cout << "Enter password : ";
//	getline(std::cin, AdminPass);
//
//	if ((AdminName == un) && (AdminPass == ps))
//	{
//
//		std::cout << "\n**********\n\n";
//		std::cout << "Email are correct" << std::endl;
//		std::cout << "\n\t\t\t\t**********\n";
//
//		return true;
//	}
//	else
//	{
//		std::cout << "incorrect username and password\n";
//		return false;
//	}
//
//
//	//std::cout << "\n\nData Successfully Saved to File....\n";
//
//}

// a function to add students by the admin


void Admin::AddStud()
{
	int nostud;
	std::cout << "please enter number of students \n";
	std::cin >> nostud;
	Student stud;
	std::vector <Student> vs;
	for (int i = 0; i < nostud; i++)
	{
		std::cout << "enter studentname\n";
		std::cin >> stud.studName;
		std::cout << "enter studentid\n";
		std::cin >> stud.studID;
		std::cout << "enter accadimic year\n";
		std::cin >> stud.academicYear;
		std::cout << "enter finished courses\n";
		for (int j = 0; j < 6; j++)
		{
			std::cout << "enter coursename\n";
			std::cin >> stud.finishedCourses[j];
		}
		vs.push_back(stud);
		std::cout<<vs.size();
	}

}



// a function to add courses by the admin


void Admin::AddCourse()
{
	Cources c;
	std::vector <Cources> vc;
	int noCourse;
	std::cout << "please enter number of cources \n";
	std::cin >> noCourse;
	
	for (int i = 0; i < noCourse; i++)
	{
		std::cout << "enter coursename\n";
		std::cin >> c.CourseName;
		std::cout << "enter coursecode\n";
		std::cin >> c.CourseCode;
		std::cout << "enter maximumstudents\n";
		std::cin >> c.MaxStud;
		std::cout << "enter coursehours\n";
		std::cin >> c.CourseHours;
		vc.push_back(c);
		
		
	}

}


void Admin::ViewAllFinProCourses()
{


}

void Admin::ViewAllStudSpecifCourse(std::string CourseCode)
{

}
//
void Admin::EditCourse(std::string CourseCode)
{

	
}

bool node::isEmpty(node* head) {
	if (head == NULL)
		return true;
	else
		return false;
}

void node::insertAsFirst(node*& head, node*& last, std::string CourseCode, std::string CourseName, int MaxStud, int CourseHours) {
	node* temp = new node;
	temp->CourseCode = CourseCode;
	temp->CourseName = CourseName;
	temp->MaxStud = MaxStud;
	temp->CourseHours = CourseHours;
	temp->next = NULL;
	head = temp;
	last = temp;
}


void node::insert(node*& head, node*& last, std::string CourseCode, std::string CourseName, int MaxStud, int CourseHours) {
	if (isEmpty(head))
		insertAsFirst(head, last, CourseCode, CourseName, MaxStud, CourseHours);
	else
	{
		node* temp = new node;
		temp->CourseCode = CourseCode;
		temp->CourseName = CourseName;
		temp->MaxStud = MaxStud;
		temp->CourseHours = CourseHours;
		temp->next = NULL;
		last->next = temp;
		last = temp;

	}
}


void node::remove(node*& head, node*& last) {
	if (isEmpty(head))
		std::cout << "this list is already empty\n";
	else if (head == last) {
		delete head;
		head = NULL;
		last = NULL;
	}
	else {
		node* temp = head;
		head = head->next;
		delete temp;
	}
}

void node::showList(node* current) {
	if (isEmpty(current))
		std::cout << "this list is empty\n";
	else {
		std::cout << "this list contains:\n";
		while (current != NULL) {
			std::cout << "Course Name:\n" << current->CourseName << "\n";
			std::cout << "Course Code:\n" << current->CourseCode << "\n";
			std::cout << "Max Student:\n" << current->MaxStud << "\n";
			std::cout << "Course Hours:\n" << current->CourseHours << "\n";
			current = current->next;

		}
	}
}
void node::EnterFinCourses() {
	node* head = NULL;
	node* last = NULL;
	std::cout << "Enter the number of finished courses that you want to add : ";
	int noCourse;
	std::cin >> noCourse;
	std::string* CourseCode = new std::string[noCourse];
	std::string* CourseName = new std::string[noCourse];
	int* MaxStud = new int[noCourse];
	int* CourseHours = new int[noCourse];
	for(int i=0;i<noCourse;i++){
		
		std::cout << "\n\t\t**********Enter Course Data**********\n";
		std::cout << " Course Name : ";
		std::cin >> CourseName[i];
		
		std::cout << "\n Course Code : ";
		std::cin >> CourseCode[i];

		std::cout << "\n Maximum number of students : ";
		std::cin >> MaxStud[i];

		std::cout << "\n Course hours : ";
		std::cin >> CourseHours[i];

		insert(head, last, CourseCode[i], CourseName[i], MaxStud[i], CourseHours[i]);

	}
	showList(head);

}


void node::EnterPrereq()
{
	
	node* head = NULL;
	node* last = NULL;
	std::cout << "Enter the number of courses that you want to add : ";
	int noCourse;
	std::cin >> noCourse;
	std::string* CourseCode = new std::string[noCourse];
	std::string* CourseName = new std::string[noCourse];
	
	int* MaxStud = new int[noCourse];
	int* CourseHours = new int[noCourse];
	for (int i = 0; i < noCourse; i++)
	{
		std::cout << "\n\t\t**********Enter Course Data**********\n";
		std::cout << " Course Name : ";
		std::cin >> CourseName[i];
		/* << CourseName[i] << std::endl;*/

		std::cout << "\n Course Code : ";
		std::cin >> CourseCode[i];
		/*Add << CourseCode[i] << std::endl;*/

		std::cout << "\n Maximum number of students : ";
		std::cin >> MaxStud[i];
		/*Add << MaxStud[i] << std::endl;*/

		std::cout << "\n Course hours : ";
		std::cin >> CourseHours[i];
		/*Add << CourseHours[i] << std::endl;*/

		insert(head, last, CourseCode[i], CourseName[i], MaxStud[i], CourseHours[i]);
		
	}
	showList(head);
	
}





Admin::~Admin()
{

}


Student::Student() {
	studName = "\0";
	studID = 0;
	studPass = "\0";
	academicYear = "\0";
}

//template<class t>
//bool Student<t>::Login(std::string studName, std::string studPass) {
//
//}


void node::viewlistofavcourses () {

	if (EnterFinCourses() == EnterPrereq())
	{

		/*std::cout << cur.CourseName;
		std::cout << cur.CourseCode;
		std::cout <<cur.CourseHours;*/
	}

}


void Student::CourseDetails() {

}


void Student::ViewMyCoursess() {
	int studID;
	std::cout << "Please Enter Your ID: \n";
	std::cin >> studID;
	switch (studID) {
	case 1:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Communication and Negotiation skills\n";
		std::cout << "Data Structures\n";
		std::cout << "Computer Organization & Architecture\n";
		std::cout << "Linear Algebra\n";
		std::cout << "Logic Design\n";
		std::cout << "Molecular Genetics\n";
		std::cout << "\n*********\n";
		break;
	case 2:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Object Oriented Programming\n";
		std::cout << "Electronics\n";
		std::cout << "Operations Research\n";
		std::cout << "Database Management SystemsArtificial Intelligence\n";
		std::cout << "Mathematics(1)\n";
		std::cout << "Biophysics\n";
		std::cout << "\n*********\n";
		break;
	case 3:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Discrete Mathematics\n";
		std::cout << "Physics \n";
		std::cout << "Introduction to Biochemistry\n";
		std::cout << "Operating Systems\n";
		std::cout << "English language II\n";
		std::cout << "Introduction to Computer and Information sciences\n";
		std::cout << "\n*********\n";
		break;
	case 4:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Calculus II\n";
		std::cout << "Structured Programming\n";
		std::cout << "Report Writing\n";
		std::cout << "Database Management SystemsArtificial Intelligence\n";
		std::cout << "Object Oriented Programming\n";
		std::cout << "Human Rights and Combating Corruption\n";
		std::cout << "\n*********\n";
		break;
	case 5:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Mathematics 3\n";
		std::cout << "Fundamentals of Economics\n";
		std::cout << "Physics II\n";
		std::cout << "Biology\n";
		std::cout << "Assembly & Embedded System\n";
		std::cout << "Computer Organization & Architecture\n";
		std::cout << "\n*********\n";
		break;
	case 6:
		std::cout << "\n*********\n";
		std::cout << "\t\t Your Courses:\n";
		std::cout << "\n*********\n";
		std::cout << "Mathematics 4\n";
		std::cout << "Software Engineering\n";
		std::cout << "Introduction to Biochemistry\n";
		std::cout << "Computer Graphics\n";
		std::cout << "psychology \n";
		std::cout << "Logic Design\n";
		std::cout << "\n*********\n";
		break;
	default:
		std::cout << "Wrong ID\n";

	}
}
//
void Student::CourseRegister()
 {
	/*Student st;
	Cources cu;
	viewlistofavcourses();
	for (int i = 0; i < 6; i++) {

		std::cin >> st.coursesProgress[i];
	}*/
}


void Student::Editdata(int studID) {

}


Student::~Student() {

}


Cources::Cources() {
	MaxStud = 0;
	/*PrerequisiteCourses ="\0" ;*/
	CourseHours = 0;
}

Cources::~Cources() {

}


common::~common()
{

}
/*
	std::ofstream insert;
	insert.open("Admin.txt", std::ios::binary | std::ios::out | std::ios::app);
	std::cout << "Enter the number of courses that you want to add : ";
	int noCourse;
	std::cin >> noCourse;
	insert << noCourse << std::endl;
	std::string* CourseCode = new std::string[noCourse];
	std::string* CourseName = new std::string[noCourse];
	int* MaxStud = new int[noCourse];
	int* CourseHours = new int[noCourse];
	for (int i = 0; i < noCourse; i++)
	{
		std::cout << "\n\t\t**********Enter Course Data**********\n";
		std::cout << " Course Name : ";
		std::cin >> CourseName[i];
		insert << CourseName[i] << std::endl;
		std::cout << "\n Course Code : ";
		std::cin >> CourseCode[i];
		insert << CourseCode[i] << std::endl;
		std::cout << "\n Maximum number of students : ";
		std::cin >> MaxStud[i];
		std::cin >> CourseHours[i];
		insert << CourseHours << std::endl;
		insert << MaxStud[i] << std::endl;
		std::cout << "\n Course hours : ";
	}
	std::cout << "\n\t\t**********Data you entered**********\n";
	for (int i = 0; i < noCourse; i++)
	{
		std::cout << " Course name :" << CourseName[i] << "\n";
		std::cout << " Course code : " << CourseCode[i] << "\n";
		std::cout << " Maximum number of student : " << MaxStud[i] << "\n";
		std::cout << " Course hours : " << CourseHours[i] << "\n";
	}
	insert.close();
	std::cout << "\n\nData Successfully Saved to File....\n";*/