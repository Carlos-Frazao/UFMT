#ifndef VETOR2D_H
#define VETOR2D_H

#include <ostream>

class Vetor2D {
private:
    float x;
    float y;

public:
    Vetor2D(float x = 0.0f, float y = 0.0f);

    Vetor2D operator+(const Vetor2D& outro) const;
    bool operator==(const Vetor2D& outro) const;

    friend std::ostream& operator<<(std::ostream& os, const Vetor2D& vetor);
};

#endif