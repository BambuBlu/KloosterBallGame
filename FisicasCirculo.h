#ifndef FISICASCIRCULO_H
#define FISICASCIRCULO_H

#include "FisicasPorTipo.h"


class FisicasCirculo : public FisicasPorTipo {
private:
    float radio;
public:
    FisicasCirculo() {tipo = Tipo::circulo; };
    FisicasCirculo(const float _radio) { tipo = Tipo::circulo; radio = _radio; };
    void setRadio(const float _radio) { radio = _radio; };
    float getRadio() const { return radio; };
};

#endif
