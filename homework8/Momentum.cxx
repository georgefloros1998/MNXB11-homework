#include "Momentum.h"
#include <cmath>

ClassImp(Momentum)

// Default constructor - initializes everything to 0 (ROOT needs it)
Momentum::Momentum() : 
px{0},
py{0},
pz{0},
p{0}
{
}
// Other constructor - initializes everything to given values
Momentum::Momentum(Double_t px, Double_t py, Double_t pz) : 
px{px},
py{py},
pz{pz},
p{0}
{
    p = magnitude();
}
// Destructor
Momentum::~Momentum(){
}
// Member function that calculates the magnitude of momentum
Double_t Momentum::magnitude(){
    return sqrt(px*px + py*py + pz*pz);
}
// Getters for px, py and pz
Double_t Momentum::Getpx(){
    return px; 
}
Double_t Momentum::Getpy(){
    return py;
}
Double_t Momentum::Getpz(){
    return pz;
}