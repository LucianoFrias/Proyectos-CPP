#include <iostream>
#include <fstream>
using namespace std;

class Persona{
    private:
        int dni;
        string name, surname, gender;
    public:
        Persona(){};

        // Funcion para añadir una persona al registro
        void AddPersona(){
            cout << "Nombre: "; cin >> name;
            cout << "Apellido: "; cin >> surname;
            cout << "Genero: "; cin >> gender;
            cout << "DNI: "; cin >> dni;
            cout << endl;
        }

        // Funcion para guardar dicha persona en el registro
        void SavePersona(){
            ofstream archivoS;
            archivoS.open("Datos.txt", ios::app);
            archivoS << dni << " " << name << " " << surname << " " << gender << endl;
            archivoS.close();
        }

        // Funcion para leer el contenido del registro
        void ReadPersonas(){
            ifstream archivoR;
            archivoR.open("Datos.txt");
            archivoR >> dni;

            while (!archivoR.eof()){
                archivoR >> name >> surname >> gender;
                cout << "Nombre: " << name << endl;
                cout << "Apellido: " << surname << endl;
                cout << "Genero: " << gender << endl;
                cout << "DNI: " << dni << endl;
                cout << endl;

                archivoR >> dni;
            }
            archivoR.close();
        }

};



int main(){
    Persona p1; // Se instancia un objeto de la clase Persona
    int opcion;

    do{
        cout << "----Guardado y Lectura de Registros----" << endl;
        cout << "1. Añadir Persona." << endl;
        cout << "2. Leer Personas." << endl;
        cout << "3. Salir del programa." << endl;

        cin >> opcion;

        switch(opcion){
            case 1: // Opcion Añadir Persona
                p1.AddPersona(); 
                p1.SavePersona();
                break;
            case 2: // Opcion Leer Persona
                p1.ReadPersonas();
                break;
            default:
                cout << "Opcion incorrecta." << endl;
        }
    }while(opcion != 3); 
    return 0;
}