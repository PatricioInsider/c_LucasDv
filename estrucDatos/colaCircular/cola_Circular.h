typedef int tipo; // Definición del tipo de datos que contendrá la cola
#define EXT 3

class ColaCircular
{
private:
    int frente;
    int maximo;
    int n;
    int []vcola;
public:
    ColaCircular(int tamanio);
    ~ColaCircular();
};

ColaCircular::ColaCircular(int tamanio)
{
    maximo = tamanio;
    vcola = new int[maximo];
    frente =0;
    n=0;

}

ColaCircular::~ColaCircular()
{
}
