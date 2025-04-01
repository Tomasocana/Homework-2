#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void menu();

class Course;

class Student{
    private:
        string full_name;
        int file;
        vector<Course*> course_list;
        vector<int> grade_list;
    public:
        Student(string fullName, int f, vector<Course*> cl);
        Student(const Student& other);
        Student& operator=(const Student& other);
        string get_fullName();
        int get_file();
        float get_average();
        void addCourse(string courseName);
        void addGrade(int grade);
        vector<Course*> get_course_list();
        vector<int> get_grade_list();
        friend ostream& operator<<(ostream& os, const Course& c);
};

class Course{
    private:
        vector<Student*> students; 
        string course_name;
    public:
        Course(string name);
        Course(const Course& cs, bool deepCopy);
        void enroll(Student* st);
        void deEnroll(Student* st);
        bool isEnrolled(int f);
        void isFull();
        void printStudents();
        string getCourseName();
};