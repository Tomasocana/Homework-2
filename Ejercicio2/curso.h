#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void menu();

class Course;

class Student{
    private:
        string full_name;
        int file;
        vector<Course*> course_list; // Lista de cursos a los que esta inscripto
        vector<int> grade_list;      // Lista de las notas de los cursos 
    public:
        Student(string fullName, int f, vector<Course*> cl); // Constructor default
        Student(const Student& other);  // Constructor de la copia
        Student& operator=(const Student& other); // Sobrecarga del operador "="
        string get_fullName(); // Función para obtener el nombre completo
        int get_file(); // Función para obtener el legajo
        float get_average(); // Función para obtener promedio
        void addCourse(string courseName); // Función para agregar curso a la lista de cursos
        void addGrade(int grade); // Función para agregar la nota del curso a la lista de notas
        void popCourse(string courseName); // Función para quitar un curso 
        void popGrade(vector<int>::iterator pos); // Función para que quitar una nota ligada a un curso
        vector<Course*> get_course_list(); // Función para obtener la lista de cursos
        vector<int> get_grade_list(); // Función para obtener la lista de notas
        friend ostream& operator<<(ostream& os, const Course& c); // Función friend de la sobrecarga del operador "<<" para imprimir el objeto estudiante
};

class Course{
    private:
        vector<Student*> students; 
        string course_name;
    public:
        Course(string name); // Constructor default
        Course(const Course& cs, bool deepCopy); // Construtor de la copia
        void enroll(Student* st); // Función para inscribir
        void deEnroll(Student* st); // Función para desinscribir
        bool isEnrolled(int f); // Función para saber si un estudiante está inscripto o no pasandole el legajo
        void isFull(); // Función para saber si el curso esta lleno
        void printStudents(); // Función para impimir estudiantes del curso
        string getCourseName(); // Función para adquirir el nombre del curso
};