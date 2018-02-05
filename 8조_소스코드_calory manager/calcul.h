#ifndef __Calcul_h__
#define __Calcul_h__
#include <iostream>
using namespace std;

class Calcul
{
public:
double height;
double weight;
int food;
int advice_kcal;
int eat_kcal;
double exercise_kcal;

void initmembers(int wei,int hei);
void calcul_advice();
void calcul_eat(int food);
int calcul_exercise();

};

#endif 



