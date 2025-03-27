#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void menu();

class Student{
    private:
        string full_name;
        int file;
        vector<void> course_list;
    public:
        Student(string fullName, int f, vector<void> cl);
        string get_fullName();
        int get_file();
        float get_average();
        friend ostream& operator<<(ostream& os, const Course& c);
};

class Course{
    private:
        vector<Student> students; 
    public:
        Course();
        Course(const Course& cs) : Course(new Course(cs.students)){}
        void enroll(Student st);
        void deEnroll(Student st);
        void isEnrolled(int f);
        void isFull();
        void printStudents();
};