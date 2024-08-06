/* Una Empresa que vende “productos de seguridad industrial NicTech” nos convoca para la realización 
de una App que permita registrar los Pedidos de Artículos de los clientes. 
En esta etapa del desarrollo, solo deberemos realizar el módulo “Clientes”
La misma debe permitir:

1.	Gestionar los Clientes
a.	Dar de alta el cliente (el código del cliente se obtiene sumando 100 al índice del Array).
b.	Dar de Baja los clientes x código de cliente.
c.	Modificar los clientes, ingresar el código, mostrarlo y editarlo.

2.	Listar los Clientes
a.	Listar todos los Clientes.
b.	Buscar un Clientes x código y mostrarlo (imprimir cartel de no encontrado).

3.	Todo esto mediante un Menú, Modularizando en Funciones, utilizando Archivos, arreglos y estructuras.

La aplicación deberá realizarse Implementando los Conceptos Correspondientes.
Deberá mostrar por consola los pedidos de los clientes.
Se aconseja usar Array, estructuras y archivos.
*/

#include <iostream>
#include <fstream> 
#include <cstring>

using namespace std;

const int MAX_CLIENTES = 100;

struct Cliente 
    {
        int codigo;
        char nombre[50];
        char direccion[100];
        char telefono[20];
        bool activo;
    };

void menu();
void altaCliente(Cliente clientes[], int &contador);
void bajaCliente(Cliente clientes[], int &contador);
void modificarCliente(Cliente clientes[], int contador);
void listarClientes(const Cliente clientes[], int contador);
void buscarClientePorCodigo(const Cliente clientes[], int contador);
void cargarClientes(Cliente clientes[], int &contador);
void guardarClientes(const Cliente clientes[], int contador);

int main() 
    {
        Cliente clientes[MAX_CLIENTES];

        int contador = 0;

        cargarClientes(clientes, contador);

        menu();

        int opcion;

        do 
            {   
                cout << "Ingrese una opcion: ";
                cin >> opcion;
                switch (opcion) 
                    {
                        case 1:
                            altaCliente(clientes, contador);
                            break;

                        case 2:
                            bajaCliente(clientes, contador);
                            break;

                        case 3:
                            modificarCliente(clientes, contador);
                            break;

                        case 4:
                            listarClientes(clientes, contador);
                            break;

                        case 5:
                            buscarClientePorCodigo(clientes, contador);
                            break;

                        case 0:
                            guardarClientes(clientes, contador);
                            cout << endl;
                            cout << "Saliendo del programa..." << endl;
                            cout << endl;
                            break;

                        default:
                            cout << endl;
                            cout << "Opcion no valida." << endl;
                            cout << endl;
                    }
            } while (opcion != 0);

        return 0;
    }

void menu() 
    {   
        cout << "*********************************************" << endl;
        cout << "PRODUCTOS DE (IN)SEGURIDAD INDUSTRIAL NICTECH  <-- ReCheto El Nombre Papaaa!!!!" << endl;
        cout << "*********************************************" << endl;
        cout << endl;
        cout << "MENU DE OPCIONES: " << endl;
        cout << "----------------" << endl;
        cout << "1. Dar de alta un cliente" << endl;
        cout << "2. Dar de baja un cliente" << endl;
        cout << "3. Modificar un cliente" << endl;
        cout << "4. Listar todos los clientes" << endl;
        cout << "5. Buscar un cliente por codigo" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
    }

void altaCliente(Cliente clientes[], int &contador) 
    {
        if (contador >= MAX_CLIENTES) 
            {
                cout << endl;
                cout << "No se pueden agregar más clientes." << endl;
                return;
            }

        clientes[contador].codigo = 100 + contador;
        cout << endl;
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore();
        cin.getline(clientes[contador].nombre, 50);
        cout << endl;
        cout << "Ingrese la direccion del cliente: ";
        cin.getline(clientes[contador].direccion, 100);
        cout << endl;
        cout << "Ingrese el telefono del cliente: ";
        cin.getline(clientes[contador].telefono, 20);
        clientes[contador].activo = true;
        contador++;
        cout << endl;
        cout << "Cliente agregado con exito." << endl;
    }

void bajaCliente(Cliente clientes[], int &contador) 
    {
        int codigo;
        cout << endl;
        cout << "Ingrese el codigo del cliente a dar de baja: ";
        cin >> codigo;
        for (int i = 0; i < contador; i++) 
            {
                if (clientes[i].codigo == codigo && clientes[i].activo) 
                    {
                        clientes[i].activo = false;
                        cout << endl;
                        cout << "Cliente dado de baja." << endl;
                        return;
                    }
            }

        cout << endl;
        cout << "Cliente no encontrado." << endl;
        cout << endl;
    }

void modificarCliente(Cliente clientes[], int contador) 
    {
        int codigo;
        cout << endl;
        cout << "Ingrese el codigo del cliente a modificar: ";
        cin >> codigo;
        for (int i = 0; i < contador; i++) 
            {
                if (clientes[i].codigo == codigo && clientes[i].activo) 
                    {
                        cout << endl;
                        cout << "Nombre actual: " << clientes[i].nombre << endl;
                        cout << endl;
                        cout << "Ingrese el nuevo nombre del cliente: ";
                        cin.ignore();
                        cin.getline(clientes[i].nombre, 50);
                        cout << endl;
                        cout << "Direccion actual: " << clientes[i].direccion << endl;
                        cout << endl;
                        cout << "Ingrese la nueva direccion del cliente: ";
                        cin.getline(clientes[i].direccion, 100);
                        cout << endl;
                        cout << "Telefono actual: " << clientes[i].telefono << endl;
                        cout << endl;
                        cout << "Ingrese el nuevo telefono del cliente: ";
                        cin.getline(clientes[i].telefono, 20);
                        cout << endl;
                        cout << "Cliente modificado con exito." << endl;
                        return;
                    }
            }
        cout << endl;
        cout << "Cliente no encontrado." << endl;
        cout << endl;
    }

void listarClientes(const Cliente clientes[], int contador) 
    {
        for (int i = 0; i < contador; i++) 
            {
                if (clientes[i].activo) 
                    {
                        cout << endl;
                        cout << "Codigo: " << clientes[i].codigo << endl;
                        cout << "Nombre: " << clientes[i].nombre << endl;
                        cout << "Direccion: " << clientes[i].direccion << endl;
                        cout << "Telefono: " << clientes[i].telefono << endl;
                        cout << "----------------------------" << endl;
                    }
            }
        cout << "THIS IS THE END MY FRIEND..." << endl;
        cout << "----------------------------" << endl;
        cout << endl;
    }

void buscarClientePorCodigo(const Cliente clientes[], int contador) 
    {
        int codigo;
        cout << endl;
        cout << "Ingrese el codigo del cliente a buscar: ";
        cin >> codigo;
        for (int i = 0; i < contador; i++) 
            {
                if (clientes[i].codigo == codigo && clientes[i].activo) 
                    {   
                        cout << endl;
                        cout << "Codigo: " << clientes[i].codigo << endl;
                        cout << "Nombre: " << clientes[i].nombre << endl;
                        cout << "Direccion: " << clientes[i].direccion << endl;
                        cout << "Telefono: " << clientes[i].telefono << endl;
                        return;
                    }
            }
        cout << endl;
        cout << "Cliente no encontrado." << endl;
        cout << endl;
    }

void cargarClientes(Cliente clientes[], int &contador) 
    {
        ifstream archivo("clientes.dat", ios::binary);
        if (archivo) 
            {
                archivo.read(reinterpret_cast<char*>(&contador), sizeof(contador));
                archivo.read(reinterpret_cast<char*>(clientes), sizeof(Cliente) * contador);
                archivo.close();
            }
    }

void guardarClientes(const Cliente clientes[], int contador) 
    {
        ofstream archivo("clientes.dat", ios::binary);
        archivo.write(reinterpret_cast<const char*>(&contador), sizeof(contador));
        archivo.write(reinterpret_cast<const char*>(clientes), sizeof(Cliente) * contador);
        archivo.close();
    }