#ifndef FISICASPORTIPO_H
#define FISICASPORTIPO_H

/*
    Clase proveniente de PhysicsShape
*/

enum Tipo 
{
    circulo,
    aabb,
    HitBox
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
