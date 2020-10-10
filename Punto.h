#ifndef PARTICLESWARMOPTIMIZATION_PUNTO_H
#define PARTICLESWARMOPTIMIZATION_PUNTO_H

class Punto {
private:
    float x;
    float y;

public:
    Punto(float x, float y) : x(x), y(y) {}

    virtual ~Punto() {}

    float getX() const {
        return x;
    }

    void setX(float x) {
        Punto::x = x;
    }

    float getY() const {
        return y;
    }

    void setY(float y) {
        Punto::y = y;
    }
};

#endif //PARTICLESWARMOPTIMIZATION_PUNTO_H
