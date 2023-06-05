#ifndef FISICASCIRCULO_H
#define FISICASCIRCULO_H

#include "FisicasPorTipo.h"


class FisicasCirculo : public FisicasPorTipo {
private:
    float radio;
public:
    FisicasCirculo() { tipo = Tipo::ciruclo; };
    FisicasCirculo(const float _radio) { tipo = Tipo::ciruclo; radio = _radio; };
    void setRadio(const float _radio) { radio = _radio; };
    float getRadio() const { return radio; };
};

#endif
