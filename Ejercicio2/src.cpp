#include "curso.h"

//a.
// Clase estudiante

Student::Student(string fullName, int f, vector<void> cl){
    full_name = fullName;
    file = f;
    course_list = cl;
}

string Student::get_fullName(){return full_name;}

int Student::get_file(){return file;}

float Student::get_average(){
    float av = 0;
    if(!course_list.empty()){
        float cont = 0;
        for(int i = 0; i < course_list.size(); i+=2){
            av += course_list[i];
            cont++;
        }
        av /= cont;
    }
    return av;
}

ostream& operator<<(ostream& os, Student S){
    os << "  Nombre completo: " << S.get_fullName() << "\n" << "  Legajo: " << S.get_file() << "\n" << "  Promedio" << S.get_average() << endl;
    return os;
}


//b.
// Clase Curso

Course::Course(vector<Student> st){
    students = st;
}

///i
void Course::enroll(Student st){
    if(students.size() == 20){
        cout << "Curso completo, no se puede inscribir." << endl;
    }else students.push_back(st);
}

void Course::deEnroll(Student st){
    if(students.empty()) cout << "Curso vacío, no se puede desinscribir el estudiante." << endl;
    else{
        vector<Student>::iterator pos = students.begin();
        int f = st.get_file();
        for(int i = 0; i < students.size(); i++){
            if(students[i].get_file() == f) break;
            pos++;
        }
        students.erase(pos);
    }
}

///ii
void Course::isEnrolled(int f){
    for(int i = 0; i < students.size(); i++){
        if(students[i].get_file() == f){
            cout << "El alumno se encuentra inscripto en el curso." << endl;
        }
    }
    cout << "El alumno no se encuentra inscripto en el curso." << endl;
}

///iii
void Course::isFull(){
    int n = students.size();
    if(n == 20) cout << "El curso está completo." << endl;
    else cout << "El curso no está completo, cuenta con " << n << "alumnos" << endl;
}

///iv
void Course::printStudents(){
    sort(students.begin(), students.end());
    if(students.empty()){
        cout << "El curso está vacío, terminando proceso." << endl;
        return;
    }
    for(int i = 0; i < students.size(); i++){
        cout << "Estudiante N° " << i << endl;
        cout<<students[i];
    }
}

///v



