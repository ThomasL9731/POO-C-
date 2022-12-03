#include "tour.h"

tour::tour(const couleur &C, const position &P) : piece(C, P){}

void tour::deplacementPossibles()
{
    viderDeplacement();
    int j = 0;
    int i = 0;
    for (int k = 0; k < 4; k++) {
        while (position(P().horizontal()+i,P().vertical()+j).estValide()) {
            if(position(P().horizontal()+i,P().vertical()+j) != P())ajouterDeplacement(position(P().horizontal()+i,P().vertical()+j));
            switch (k) {
            case 0: j++; break;
            case 1: j--; break;
            case 2: i++; break;
            case 3: i--; break;
            default: break;
            }
        }
        j = 0;
        i = 0;
    }
}

char tour::name() const
{
    return 'T';
}

std::unique_ptr<piece> tour::clone() const
{
    return std::make_unique<tour>(*this);
}

unsigned short tour::valeur() const
{
    return 5;
}
