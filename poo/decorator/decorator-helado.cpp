
#include <iostream>

//Precios: Helado simple $2 / Cobertura $1 / Barquillo $0,50
// Component: Helado (Interfaz del programa)
class Helado {
public:
    virtual std::string getDescripcion() const = 0;
    virtual double getPrecio() const = 0;
};

// ConcreteComponent : Helado Base
class HeladoBase : public Helado {
public:
    std::string getDescripcion() const override {
        return "Helado simple";
    }

    double getPrecio() const override {
        return 2.0;
    }
};

// Decorator: Decorador
class DecoradorHelado : public Helado {
protected:
    Helado* _helado;

public:
    DecoradorHelado(Helado* helado) : _helado(helado) {}

    std::string getDescripcion() const override {
        return _helado->getDescripcion();
    }

    double getPrecio() const override {
        return _helado->getPrecio();
    }
};

// ConcreteComponentA: CoberturaDecorador
class CoberturaDecorador : public DecoradorHelado {
public:
    CoberturaDecorador(Helado* helado) : DecoradorHelado(helado) {}

    std::string getDescripcion() const override {
        return DecoradorHelado::getDescripcion() + " con cobertura";
    }

    double getPrecio() const override {
        return DecoradorHelado::getPrecio() + 1;
    }
};

// ConcreteComponentB: BarquilloDecorador
class BarquilloDecorador : public DecoradorHelado {
public:
    BarquilloDecorador(Helado* helado) : DecoradorHelado(helado) {}

    std::string getDescripcion() const override {
        return DecoradorHelado::getDescripcion() + " con barquillo";
    }

    double getPrecio() const override {
        return DecoradorHelado::getPrecio() + 0.5;
    }
};

int main() {

    std::cout << "Impresion de cada uno de los casos de helados"<<std::endl;
    Helado* heladoSimple = new HeladoBase();
    std::cout << "Helado 1: " << heladoSimple->getDescripcion() << ", Precio: $" << heladoSimple->getPrecio() << std::endl;

    Helado* heladoConCobertura = new CoberturaDecorador(new HeladoBase());
    std::cout << "Helado 2: " << heladoConCobertura->getDescripcion() << ", Precio: $" << heladoConCobertura->getPrecio() << std::endl;

    Helado* HeladoConBarquillo = new BarquilloDecorador(new HeladoBase());
    std::cout << "Helado 3: " << HeladoConBarquillo->getDescripcion() << ", Precio: $" << HeladoConBarquillo->getPrecio() << std::endl;

    Helado* heladoCompleto = new BarquilloDecorador(new CoberturaDecorador(new HeladoBase()));
    std::cout << "Helado 4: " << heladoCompleto->getDescripcion() << ", Precio: $" << heladoCompleto->getPrecio() << std::endl;

    delete heladoSimple;
    delete heladoConCobertura;
    delete HeladoConBarquillo;
    delete heladoCompleto;

    return 0;
}
