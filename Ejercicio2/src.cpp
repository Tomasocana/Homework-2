#include "curso.h"

//a.
// Clase estudiante

Student::Student(string fullName, int f, vector<Course*> cl){
    full_name = fullName;
    file = f;
    course_list = cl;
}

Student::Student(const Student& other) {
    full_name = other.full_name;
    file = other.file;
    course_list = other.course_list; 
}

Student& Student::operator=(const Student& other) {
    if (this != &other) { 
        full_name = other.full_name;
        file = other.file;
        course_list = other.course_list; 
    }
    return *this;
}

string Student::get_fullName(){return full_name;}

int Student::get_file(){return file;}

float Student::get_average(){
    float av = 0;
    if(!grade_list.empty()){
        float cont = 0;
        for(int i = 0; i < (int)grade_list.size(); i++){
            av += grade_list[i];
            cont++;
        }
        av /= cont;
    }
    return av;
}

void Student::addCourse(string courseName) {course_list.push_back(new Course(courseName));}

void Student::addGrade(int grade){grade_list.push_back(grade);}

vector<Course*> Student::get_course_list(){return course_list;}

vector<int> Student::get_grade_list(){return grade_list;}

ostream& operator<<(ostream& os, Student* S){
    os << "  Nombre completo: " << S->get_fullName() << "\n" << "  Legajo: " << S->get_file() << "\n" << "  Promedio" << S->get_average() << endl;
    return os;
}


//b.
// Clase Curso

Course::Course(string name){course_name = name;}

Course::Course(const Course& cs, bool deepCopy){
    course_name = cs.course_name;
    if(deepCopy){
        for(auto student : cs.students){
            students.push_back(new Student(*student));
            delete student;
        }
    }else students = cs.students;
}

///i
void Course::enroll(Student* st){
    if(students.size() == 20){
        cout << "Curso completo, no se puede inscribir." << endl;
    }else if(isEnrolled(st->get_file())){
        cout << "El estudiante ya está inscripto en este curso." << endl;
    }else{
        int nota;
        cout << "Introduzca la nota del curso: ";
        cin >> nota;
        students.push_back(st);
        st->addCourse(course_name);
        st->addGrade(nota);
    }
}

void Course::deEnroll(Student* st) {
    if (students.empty()) {
        cout << "Curso vacío, no se puede desinscribir el estudiante." << endl;
    } else {
        auto it = find(students.begin(), students.end(), st);
        if (it != students.end()) {
            students.erase(it);
        }
    }
}

///ii
bool Course::isEnrolled(int f){
    for(auto i : students){
        if(i->get_file() == f){
            return true;
        }
        delete i;
    }
    return false;
}

///iii
void Course::isFull(){
    int n = students.size();
    if(n == 20) cout << "El curso está completo." << endl;
    else cout << "El curso no está completo, cuenta con " << n << " alumnos" << endl;
}

///iv
void Course::printStudents(){
    sort(students.begin(), students.end());
    if(students.empty()){
        cout << "El curso está vacío." << endl;
        return;
    }
    for(int i = 0; i < (int)students.size(); i++){
        cout << "Estudiante N° " << i + 1 << ": " << endl;;
        cout<<students[i];
        cout << endl;
    }
}

string Course::getCourseName(){return course_name;}



//Menú para evaluar lo pedido

void menu(){
    vector<Course*> cc;
    vector<Student*> cs;
    bool first_cond = true;
    while(first_cond){
        int opt;
        cout << "Qué quiere hacer?" << endl;
        cout << "1. Crear nuevo curso" << endl;
        cout << "2. Crear nuevo estudiante" << endl;
        cout << "3. Abrir la interfaz del estudiante deseado" << endl;
        cout << "4. Abrir la interfaz del curso deseado" << endl;
        cout << "5. Salir" << endl;
        cout << "Respuesta: ";
        cin >> opt;
        switch(opt){
            case 1:{
                string n;
                cout << "Introduzca el nombre del curso: ";
                cin >> n;
                Course* cs1 = new Course(n);
                cout << "Curso creado con éxito." << endl;
                cc.push_back(cs1);
                break;
            }
            case 2:{
                string name;
                int file;
                vector<Course*> courselist;
                cout << "Introduzca el nombre del alumno: ";
                cin >> name;
                cout << "Introduzca el legajo del alumno: ";
                cin >> file;
                cout << "Estudiante creado con éxito." << endl;
                Student* s1 = new Student(name, file, courselist);
                cs.push_back(s1);
                break;
            }
            case 3:{
                cout << "Abriendo nueva interfaz..." << endl;
                bool cond1 = true;
                while(cond1){
                    int file;
                    cout << "Introduzca el legajo del estudiante al que desea acceder: ";
                    cin >> file;
                    int cont = 0;
                    int j = 0;
                    for(int i = 0; i < (int)cs.size(); i++){
                        if(cs[i]->get_file() == file){
                            j = 1;
                            break;
                        }
                        cont++;

                    }
                    Student* s;
                    if (j == 1) s = cs[cont];
                    else{
                        cout << "No existe estudiante con ese legajo" << endl;
                        continue;
                    }
                    bool cond2 = true;
                    while(cond2){
                        int option;
                        cout << "¿Qué desea hacer?" << endl;
                        cout << "1. ¿Cuál es el nombre completo del estudiante??" << endl;
                        cout << "2. ¿Cuál es el promedio del estudiante?" << endl;
                        cout << "3. ¿A que cursos está inscripto el estudiante?" << endl;
                        cout << "4. Cambiar de estudiante" << endl;
                        cout << "5. Salir" << endl;
                        cout << "Respuesta: " << endl;
                        cin >> option;
                        switch(option){
                            case 1:{
                                cout << "El nombre completo del estudiante es " << s->get_fullName() << "." << endl;
                                break;
                            }
                            case 2:{
                                cout << "El promedio del estudiante es de: " << s->get_average() << "." << endl;
                                break;
                            }
                            case 3:{
                                vector<Course*> l = s->get_course_list();
                                if(l.empty()){
                                    cout << "El estudiante no esta inscripto a ningun curso" << endl;
                                    break;
                                }
                                cout << "El estudiante está insripto a los cursos de: ";
                                for(auto i : l){
                                    cout << i->getCourseName() << " ";
                                    delete i;
                                }   
                                cout << endl;
                                break;
                            }
                            case 4:{
                                cond2 = false;
                                break;
                            }
                            case 5:{
                                cond2 = false;
                                cond1 = false;
                                break;
                            }
                            default:{
                                cout << "Opción no contemplada." << endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 4:{
                cout << "Abriendo nueva interfaz..." << endl;
                bool cond1 = true;
                while(cond1){
                    string n;
                    cout << "Introduzca el nombre del curso: ";
                    cin >> n;
                    int cont = 0;
                    int j = 0;
                    for(auto i : cc){
                        if(i->getCourseName() == n){
                            j = 1;
                            break;
                        }
                        delete i;
                        cont++;
                    }
                    Course* course_copy;
                    if(j == 1) course_copy = new Course(*cc[cont], true);
                    else{
                        cout << "No existe curso con ese nombre" << endl;
                        continue;
                    }
                    bool cond2 = true;
                    while(cond2){
                        int option;
                        cout << "¿Qué desea hacer?" << endl;
                        cout << "1. Inscribir un estudiante" << endl;
                        cout << "2. Desinscribir un estudiante" << endl;
                        cout << "3. Verificar si un estudiante forma parte del curso o no" << endl;
                        cout << "4. Verificar si el curso está lleno o no" << endl;
                        cout << "5. Imprimir estudiantes del curso" << endl;
                        cout << "6. Imprimir nota del curso de cierto estudiante" << endl;
                        cout << "7. Cambiar de curso" << endl;
                        cout << "8. Salir" << endl;
                        cout << "Respuesta: ";
                        cin >> option;
                        int file;
                        int j = 0;
                        switch(option){
                            case 1:{
                                cout << "Introducir el legajo del estudiante: ";
                                cin >> file;
                                for(auto i : cs){
                                    if(i->get_file() == file){
                                        course_copy->enroll(i);
                                        j = 1;
                                        break;
                                    }
                                    delete i;
                                }
                                if(j == 0)cout << "No existe estudiante con ese legajo" << endl;
                                break;
                            }
                            case 2:{
                                cout << "Introducir el legajo del estudiante: ";
                                cin >> file;
                                for(auto i : cs){
                                    if(i->get_file() == file){
                                        course_copy->deEnroll(i);
                                        j = 1;
                                        break;
                                    }
                                    delete i;
                                }
                                if(j == 0) cout << "No existe estudiante con ese legajo" << endl;
                                break;
                            }
                            case 3:{
                                cout << "Introducir el legajo del estudiante: ";
                                cin >> file;
                                for(auto i : cs){
                                    if(i->get_file() == file){
                                        if(course_copy->isEnrolled(file)) cout << "El alumno forma parte del curso." << endl;
                                        else cout << "El alumno no forma parte del curso." << endl;
                                        j = 1;
                                        break;
                                    }
                                    delete i;
                                }
                                if(j == 0) cout << "No existe estudiante con ese legajo" << endl;
                                break;
                            }
                            case 4:{
                                course_copy->isFull();
                                break;
                            }
                            case 5:{
                                course_copy->printStudents();
                                break;
                            }
                            case 6:{
                                cout << "Introducir el legajo del estudiante: ";
                                cin >> file;
                                for(auto i : cs){
                                    if(i->get_file() == file){
                                        j = 1;
                                        break;
                                    }
                                    cont++;
                                    delete i;
                                }
                                Student* student_copy;
                                if(j == 1) student_copy = cs[cont];
                                else{
                                    cout << "No existe estudiante con ese legajo" << endl;
                                    break;
                                }
                                vector<Course*> student_course_list = student_copy->get_course_list();
                                vector<int> student_grade_list = student_copy->get_grade_list();
                                for(int i = 0; i < (int)student_grade_list.size(); i++){
                                    if(student_course_list[i]->getCourseName() == n){
                                        cout << "La nota de " << student_copy->get_fullName() << " del curso de " << n << " es " << student_grade_list[i] << endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            case 7:{
                                cond2 = false;
                                break;
                            }
                            case 8:{
                                cond2 = false;
                                cond1 = false;
                                break;
                            }
                            default:{
                                cout << "Opción no contemplada" << endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            case 5:{
                first_cond = false;
                break;
            }
            default:{
                cout << "Opción no contemplada" << endl;
                break;
            }
        }
    }
}

