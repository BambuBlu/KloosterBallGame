#ifndef FISICASPORTIPO_H
#define FISICASPORTIPO_H

//Tipos de Forma
enum Tipo 
{
    circulo,
    aabb,
    Obb
};

class FisicasPorTipo
{
    protected:
        Tipo tipo;

    public:
        FisicasPorTipo();

        void setTipo(Tipo _tipo);

        Tipo getTipo();
};
#endif
