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

Course::Course(){}

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
        cout << "El curso está vacío." << endl;
        return;
    }
    for(int i = 0; i < students.size(); i++){
        cout << "Estudiante N° " << i << endl;
        cout<<students[i];
    }
}

///v








//Menú para evaluar lo pedido

void menu(Course cs){
    cout << "Generando estudiantes aleatorios:" << endl;
    vector<void> l1;
    Student s1((string)"Tomás Ocaña", 100, l1);
    cout << s1;     // Utilizo el operador sobrecargado "<<" para imprimir a los estudiantes
    vector<void> l2;
    Student s2((string)"Nacho Rodriguez", 200, l2);
    cout << s2;
    vector<void> l3;
    Student s3((string)"Roberto Carlos", 300, l3);
    cout << s3;

    Course cs();
    cout << "imprimiendo el curso... " << endl;
    cs.printStudents();
    cout << "Inscribiendo a los estudiantes;" << endl;
    cs.enroll(s1);
    cs.printStudents();
    cs.enroll(s2);
    cs.printStudents();
    cs.enroll(s3);
    cs.printStudents();
    cs.isFull();
    cout << "Tomás está inscripto en el curso?" << endl;
    cs.isEnrolled(s1.get_file());
    cout << "Tomás se dio de baja, desinscribiendo del curso" << endl;
    cout << "Tomás está inscripto en el curso?" << endl;
    cs.isEnrolled(s1.get_file());
    cs.isFull();
    cs.printStudents();

    cout << "Creando nuevo curso..." << endl;
    Course cos;
    cout << "Copiando el curso 1 en el curso 2..." << endl;
    cos = cs;
    cout << "Imprimiendo alumnos del curso 2:" << endl;
    cos.printStudents();
}

