#ifndef MOMENTUM_H
#define MOMENTUM_H

#include <TObject.h>

class Momentum : public TObject {
    public:
        // Default constructor
        Momentum();
        // Other constructor
        Momentum(Double_t px, Double_t py, Double_t pz);
        // Destructor 
        virtual ~Momentum();
        // Member function that calculates the magnitude of momentum
        Double_t magnitude();
        // Getters for px, py and pz
        // I need them since I made px, py and pz private
        Double_t Getpx();
        Double_t Getpy();
        Double_t Getpz();
    private:
        Double_t px;
        Double_t py;
        Double_t pz;
        Double_t p;
    ClassDef(Momentum, 1);
};

#endif //MOMENTUM_H