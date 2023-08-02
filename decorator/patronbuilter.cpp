#include <iostream>
#include <string>
#include <vector>

class Computadora {
public:
    std::vector<std::string> components;

    void ShowDetails() const {
        std::cout << "\n\n";
        std::cout << "----Resultado-------\n";
        std::cout << "Configuración de la computadora:\n";
        for (const auto& component : components) {
            std::cout << component << "\n";
        }
        std::cout << "\n";
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void BuildCPU() = 0;
    virtual void BuildRAM() = 0;
    virtual void BuildGraphicsCard() = 0;
    virtual void BuildStorage() = 0;
    virtual Computadora* GetComputer() = 0;
};

class ConcreteBuilderGaming : public Builder {
private:
    Computadora* computer;

public:
    ConcreteBuilderGaming() {
        computer = new Computadora();
    }

    void BuildCPU() override {
        computer->components.push_back("CPU para juegos");
    }

    void BuildRAM() override {
        computer->components.push_back("Memoria RAM para juegos");
    }

    void BuildGraphicsCard() override {
        computer->components.push_back("Tarjeta gráfica para juegos");
    }

    void BuildStorage() override {
        computer->components.push_back("Almacenamiento para juegos");
    }

    Computadora* GetComputer() override {
        return computer;
    }
};

class ConcreteBuilderOffice : public Builder {
private:
    Computadora* computer;

public:
    ConcreteBuilderOffice() {
        computer = new Computadora();
    }

    void BuildCPU() override {
        computer->components.push_back("CPU para tareas de oficina");
    }

    void BuildRAM() override {
        computer->components.push_back("Memoria RAM para tareas de oficina");
    }

    void BuildGraphicsCard() override {
        computer->components.push_back("Tarjeta gráfica para tareas de oficina");
    }

    void BuildStorage() override {
        computer->components.push_back("Almacenamiento para tareas de oficina");
    }

    Computadora* GetComputer() override {
        return computer;
    }
};

class ConcreteBuilderDevelopment : public Builder {
private:
    Computadora* computer;

public:
    ConcreteBuilderDevelopment() {
        computer = new Computadora();
    }

    void BuildCPU() override {
        computer->components.push_back("CPU para desarrollo de software");
    }

    void BuildRAM() override {
        computer->components.push_back("Memoria RAM para desarrollo de software");
    }

    void BuildGraphicsCard() override {
        computer->components.push_back("Tarjeta gráfica para desarrollo de software");
    }

    void BuildStorage() override {
        computer->components.push_back("Almacenamiento para desarrollo de software");
    }

    Computadora* GetComputer() override {
        return computer;
    }
};

class Director {
private:
    Builder* builder;

public:
    Director(Builder* builder) : builder(builder) {}

    void BuildComputer() {
        builder->BuildCPU();
        builder->BuildRAM();
        builder->BuildGraphicsCard();
        builder->BuildStorage();
    }
};

int main() {
    setlocale(LC_ALL, "");

    int option;
    std::cout << "-------Seleccione la especialización de la computadora:\n---";
    std::cout << "1. Juegos\n";
    std::cout << "2. Tareas de Oficina\n";
    std::cout << "3. Desarrollo de Software\n";
    std::cout << "Opción: ";
    std::cin >> option;

    Builder* builder = nullptr;
    switch (option) {
        case 1:
            builder = new ConcreteBuilderGaming();
            break;
        case 2:
            builder = new ConcreteBuilderOffice();
            break;
        case 3:
            builder = new ConcreteBuilderDevelopment();
            break;
        default:
            std::cout << "Opción inválida. Saliendo del programa.\n";
            break;
    }

    Director director(builder);
    director.BuildComputer();
    Computadora* computer = builder->GetComputer();
    computer->ShowDetails();
    delete computer;
    delete builder;

    return 0;
}
