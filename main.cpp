
#include <iostream>
#include <string>
#include <vector>
#include<ctime>
#include <algorithm>

using namespace std;

class Cliente {
private:
    string nombre;
    string telefono;
    string direccion;

public:
    Cliente() {
        // Default constructor with no arguments
        nombre = "";
        telefono = "";
        direccion = "";
    }
    Cliente(string nombre, string telefono, string direccion) {
        this->nombre = nombre;
        this->telefono = telefono;
        this->direccion = direccion;
    }

    string getNombre() const {
        return nombre;
    }

    string getTelefono() const {
        return telefono;
    }

    string getDireccion() const {
        return direccion;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setTelefono(string telefono) {
        this->telefono = telefono;
    }

    void setDireccion(string direccion) {
        this->direccion = direccion;
    }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Teléfono: " << telefono << endl;
        cout << "Dirección: " << direccion << endl;
    }
};

class Mascota {
private:
    string nombre;
    int edad;
    string raza;
    string enfermedades;
    string otro;
    string tipoServicio;

public:
    Mascota() {
        // Default constructor with no arguments
        nombre = "";
        edad = 0;
        raza = "";
        enfermedades="";
        otro="";
        tipoServicio="";
    }
    Mascota(string nombre, int edad, string raza, string enfermedades, string otro, string tipoServicio) {
        this->nombre = nombre;
        this->edad = edad;
        this->raza = raza;
        this->enfermedades = enfermedades;
        this->otro = otro;
        this->tipoServicio = tipoServicio;
    }

    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    string getRaza() const {
        return raza;
    }

    string getEnfermedades() const {
        return enfermedades;
    }

    string getOtro() const {
        return otro;
    }

    string getTipoServicio() const {
        return tipoServicio;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    void setEdad(int edad) {
        this->edad = edad;
    }

    void setRaza(string raza) {
        this->raza = raza;
    }

    void setEnfermedades(string enfermedades) {
        this->enfermedades = enfermedades;
    }

    void setOtro(string otro) {
        this->otro = otro;
    }

    void setTipoServicio(string tipoServicio) {
        this->tipoServicio = tipoServicio;
    }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Raza: " << raza << endl;
        cout << "Enfermedades: " << enfermedades << endl;
        cout << "Otro: " << otro << endl;
        cout << "Tipo de servicio: " << tipoServicio << endl;
    }
};

class Registro {
private:
    Cliente cliente;
    Mascota mascota;
    string fechaIngreso;
    string fechaSalida;

public:
    Registro(Cliente cliente, Mascota mascota, string fechaIngreso) {
        this->cliente = cliente;
        this->mascota = mascota;
        this->fechaIngreso = fechaIngreso;
        fechaSalida = "";
    }

    Cliente getCliente() const {
        return cliente;
    }

    Mascota getMascota() const {
        return mascota;
    }

    string getFechaIngreso() const {
        return fechaIngreso;
    }

    string getFechaSalida() const {
        return fechaSalida;
    }

    void setFechaSalida(std::time_t fechaSalida) {
        this->fechaSalida = fechaSalida;
    }

    void mostrarDatos() const {
        cout << "Datos del cliente:" << endl;
        cliente.mostrarDatos();
        cout << endl;
        cout << "Datos de la mascota:" << endl;
        mascota.mostrarDatos();
        cout << endl;
        cout << "Fecha de ingreso: " << fechaIngreso << endl;
        cout << "Fecha de salida: " << fechaSalida << endl;
    }
};
class Veterinaria {
    private:
    std::vector<Registro> registros;

    public:
    // Método para capturar un nuevo registro
    void capturar() {
    std::string nombreCliente, telefonoCliente, direccionCliente;
    std::string nombreMascota, razaMascota, enfermedadesMascota, otroMascota, tipoServicio;
    int edadMascota;
    std::string fechaIngreso; // Obtener la fecha y hora actual
        // Capturar los datos del cliente
        std::cout << "Ingrese los datos del cliente:" << std::endl;
        std::cout << "Nombre: ";
        std::getline(std::cin.ignore(), nombreCliente);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefonoCliente);
        std::cout << "Direccion: ";
        std::getline(std::cin, direccionCliente);
        std::cout << "Fecha Ingreso: ";
        std::getline(std::cin, fechaIngreso);

        // Capturar los datos de la mascota
        std::cout << "Ingrese los datos de la mascota:" << std::endl;
        std::cout << "Nombre: ";
        std::getline(std::cin, nombreMascota);
        std::cout << "Edad: ";
        std::cin >> edadMascota;
        std::cin.ignore(); // Ignorar el salto de línea
        std::cout << "Raza: ";
        std::getline(std::cin, razaMascota);
        std::cout << "Enfermedades: ";
        std::getline(std::cin, enfermedadesMascota);
        std::cout << "Otro: ";
        std::getline(std::cin, otroMascota);
        std::cout << "Tipo de Servicio (hotel/hospital): ";
        std::getline(std::cin, tipoServicio);

        // Crear objetos Cliente y Mascota
        Cliente cliente(nombreCliente, telefonoCliente, direccionCliente);
        Mascota mascota(nombreMascota, edadMascota, razaMascota, enfermedadesMascota, otroMascota, tipoServicio);

        // Crear objeto Registro y agregarlo al vector de registros
        Registro registro(cliente, mascota, fechaIngreso);
        registros.push_back(registro);

        std::cout << "Registro de mascota capturado exitosamente." << std::endl;
    }

    // Método para mostrar los registros activos
    void mostrar() {
        std::cout << "Registros activos:" << std::endl;
        for (const auto& registro : registros) {
            if (registro.getFechaSalida() != "0") { // Verificar si el registro está activo
                Cliente cliente = registro.getCliente();
                Mascota mascota = registro.getMascota();

                std::cout << "Nombre del cliente: " << cliente.getNombre() << std::endl;
                std::cout << "Telefono del cliente: " << cliente.getTelefono() << std::endl;
                std::cout << "Direccion del cliente: " << cliente.getDireccion() << std::endl;
                std::cout << "Nombre de la mascota: " << mascota.getNombre() << std::endl;
                std::cout << "Edad de la mascota: " << mascota.getEdad() << std::endl;
                std::cout << "Raza de la mascota: " << mascota.getRaza() << std::endl;
                std::cout << "Enfermedades de la mascota: " << mascota.getEnfermedades() << std::endl;
                std::cout << "Otro de la mascota: " << mascota.getOtro() << std::endl;
                std::cout << "Tipo de servicio: " << mascota.getTipoServicio() << std::endl;
                std::cout << "Fecha de ingreso: " << registro.getFechaIngreso() << std::endl;
                std::cout << std::endl;
            }
        }
    }

    // Método para marcar la salida de una mascota
    void eliminar() {
        std::string nombreMascota;
        std::cout << "Ingrese el nombre de la mascota que desea marcar como salida: ";
        std::getline(std::cin, nombreMascota);

        for (auto& registro : registros) {
            if (registro.getFechaSalida() == "0" && registro.getMascota().getNombre() == nombreMascota) {
                std::time_t fechaSalida = std::time(nullptr);
                registro.setFechaSalida(fechaSalida);
                std::cout << "Salida de mascota marcada exitosamente." << std::endl;
                return;
            }
        }

        std::cout << "No se encontró ninguna mascota con ese nombre." << std::endl;
    }

    // Método para buscar una mascota por su nombre
    void buscar() {
        std::string nombreMascota;
        std::cout << "Ingrese el nombre de la mascota que desea buscar: ";
        std::getline(std::cin, nombreMascota);

        std::cout << "Registros de la mascota \"" << nombreMascota << "\":" << std::endl;
        for (const auto& registro : registros) {
            if (registro.getMascota().getNombre() == nombreMascota) {
                Cliente cliente = registro.getCliente();
                Mascota mascota = registro.getMascota();

                std::cout << "Nombre del cliente: " << cliente.getNombre() << std::endl;
                std::cout << "Telefono del cliente: " << cliente.getTelefono() << std::endl;
                std::cout << "Direccion del cliente: " << cliente.getDireccion() << std::endl;
                std::cout << "Nombre de la mascota: " << mascota.getNombre() << std::endl;
                std::cout << "Edad de la mascota: " << mascota.getEdad() << std::endl;
                std::cout << "Raza de la mascota: " << mascota.getRaza() << std::endl;
                std::cout << "Enfermedades de la mascota: " << mascota.getEnfermedades() << std::endl;
                std::cout << "Otro de la mascota: " << mascota.getOtro() << std::endl;
                std::cout << "Tipo de servicio: " << mascota.getTipoServicio() << std::endl;
                std::cout << "Fecha de ingreso: " << registro.getFechaIngreso() << std::endl;
                std::cout << std::endl;
                return;
            }
        }

        std::cout << "No se encontró ninguna mascota con ese nombre." << std::endl;
    }

    // Método para modificar los datos de una mascota
    void modificar() {
        std::string nombreMascota;
        std::cout << "Ingrese el nombre de la mascota que desea modificar: ";
        std::getline(std::cin, nombreMascota);

        for (auto& registro : registros) {
            if (registro.getMascota().getNombre() == nombreMascota) {
                Mascota mascota = registro.getMascota();

                std::cout << "Campos que se pueden modificar:" << std::endl;
                std::cout << "1. Nombre" << std::endl;
                std::cout << "2. Edad" << std::endl;
                std::cout << "3. Raza" << std::endl;
                std::cout << "4. Enfermedades" << std::endl;
                std::cout << "5. Otro" << std::endl;
                std::cout << "6. Tipo de servicio" << std::endl;

                int opcion;
                std::cout << "Seleccione el campo que desea modificar: ";
                std::cin >> opcion;
                std::cin.ignore(); // Ignorar el salto de línea

                std::string nuevoValor;

                switch (opcion) {
                    case 1:
                        std::cout << "Ingrese el nuevo nombre: ";
                        std::getline(std::cin, nuevoValor);
                        mascota.setNombre(nuevoValor);
                        break;
                    case 2:
                        std::cout << "Ingrese la nueva edad: ";
                        std::cin >> nuevoValor;
                        mascota.setEdad(std::stoi(nuevoValor));
                        break;
                    case 3:
                        std::cout << "Ingrese la nueva raza: ";
                        std::getline(std::cin.ignore(), nuevoValor);
                        mascota.setRaza(nuevoValor);
                        break;
                    case 4:
                        std::cout << "Ingrese las nuevas enfermedades: ";
                        std::getline(std::cin, nuevoValor);
                        mascota.setEnfermedades(nuevoValor);
                        break;
                    case 5:
                        std::cout << "Ingrese el nuevo valor para otro: ";
                        std::getline(std::cin, nuevoValor);
                        mascota.setOtro(nuevoValor);
                        break;
                    case 6:
                        std::cout << "Ingrese el nuevo tipo de servicio (hotel/hospital): ";
                        std::getline(std::cin, nuevoValor);
                        mascota.setTipoServicio(nuevoValor);
                        break;
                    default:
                        std::cout << "Opción inválida." << std::endl;
                        return;
                }

                std::cout << "Campo modificado exitosamente." << std::endl;
                return;
            }
        }

        std::cout << "No se encontró ninguna mascota con ese nombre." << std::endl;
    }

    // Método para ordenar los registros por nombre de mascota
    void ordenar() {
        std::sort(registros.begin(), registros.end(), [](const Registro& a, const Registro& b) {
            return a.getMascota().getNombre() < b.getMascota().getNombre();
        });

        std::cout << "Registros ordenados por nombre de mascota." << std::endl;
    }

    // Método para mostrar el historial de una mascota
    void consultarHistorial() {
        std::string nombreMascota;
        std::cout << "Ingrese el nombre de la mascota: ";
        std::getline(std::cin, nombreMascota);

        std::cout << "Historial de la mascota \"" << nombreMascota << "\":" << std::endl;
        for (const auto& registro : registros){
                if (registro.getMascota().getNombre() == nombreMascota) {
                Cliente cliente = registro.getCliente();
                Mascota mascota = registro.getMascota();

                std::cout << "Nombre del cliente: " << cliente.getNombre() << std::endl;
                std::cout << "Telefono del cliente: " << cliente.getTelefono() << std::endl;
                std::cout << "Direccion del cliente: " << cliente.getDireccion() << std::endl;
                std::cout << "Nombre de la mascota: " << mascota.getNombre() << std::endl;
                std::cout << "Edad de la mascota: " << mascota.getEdad() << std::endl;
                std::cout << "Raza de la mascota: " << mascota.getRaza() << std::endl;
                std::cout << "Enfermedades de la mascota: " << mascota.getEnfermedades() << std::endl;
                std::cout << "Otro de la mascota: " << mascota.getOtro() << std::endl;
                std::cout << "Tipo de servicio: " << mascota.getTipoServicio() << std::endl;
                std::cout << "Fecha de ingreso: " << registro.getFechaIngreso() << std::endl;
                if (registro.getFechaSalida() != "0") {
                    std::cout << "Fecha de salida: " << registro.getFechaSalida() << std::endl;
                }
                std::cout << std::endl;
            }
        }

        std::cout << "Fin del historial." << std::endl;
    }
};
int main() {
    Veterinaria veterinaria;

    int opcion;
    do {
        system("cls");
        cout << "=== Menú ===" << endl;
        cout << "1. Capturar registro" << endl;
        cout << "2. Mostrar registros" << endl;
        cout << "3. Eliminar registro" << endl;
        cout << "4. Buscar mascota" << endl;
        cout << "5. Modificar registro" << endl;
        cout << "6. Ordenar registros" << endl;
        cout << "7. Consultar historial" << endl;
        cout << "8. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                veterinaria.capturar();
                system("pause");
                break;
            case 2:
                veterinaria.mostrar();
                system("pause");
                break;
            case 3:
                veterinaria.eliminar();
                system("pause");
                break;
            case 4:
                veterinaria.buscar();
                system("pause");
                break;
            case 5:
                veterinaria.modificar();
                system("pause");
                break;
            case 6:
                veterinaria.ordenar();
                system("pause");
                break;
            case 7:
                veterinaria.consultarHistorial();
                system("pause");
                break;
            case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}




