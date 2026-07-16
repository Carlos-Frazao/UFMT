#include "Vetor2D.h"

Vetor2D::Vetor2D(float x, float y) : x(x), y(y) {}

Vetor2D Vetor2D::operator+(const Vetor2D& outro) const {
    return Vetor2D(x + outro.x, y + outro.y);
}

bool Vetor2D::operator==(const Vetor2D& outro) const {
    return x == outro.x && y == outro.y;
}

std::ostream& operator<<(std::ostream& os, const Vetor2D& vetor) {
    os << "(" << vetor.x << ", " << vetor.y << ")";
    return os;
}