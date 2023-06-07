#ifndef FISICASPORTIPO_H
#define FISICASPORTIPO_H

enum Tipo {
    circulo,
    aabb,
    obb
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
