#pragma once

#include <vector>
#include <iostream>

using namespace std;

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
};

class Course{
    private:
        vector<Student> students; 
    public:
        Course(vector<Student> st);
        void enroll(Student st);
        void Course::deEnroll(Student st);
        void isEnrolled(int f);
        void isFull();
        void printStudents();
        // funcion para copiar
};