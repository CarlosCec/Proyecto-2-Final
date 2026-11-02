#include <sstream>
#include <iostream>
using namespace std;

class Paquete;
class Celda {
private:
    Paquete* paquete;
public:
    void destruir();
    ~Celda();
    Celda();
    void setPaquete(Paquete* nuevo);
    Paquete* getPaquete() const;
};

