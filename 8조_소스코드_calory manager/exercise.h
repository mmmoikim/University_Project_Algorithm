#ifndef _exercise_h_
#define _exercise_h_
#include <iostream>
#include <string>
using namespace std;

typedef struct exerstruct
{
   string name;
   float minute;
}exerstruct;

class exercise
{
public:

int num, time, fcal, ecal;

exerstruct a[10];

exercise();

void all_exercise();
void select_exercise(int num);
int select_time(float time);
void exer1();
void exer2();
void exer3();
void exer4();
void exer5();
void exer6();
void exer7();
void exer8();
void exer9();
void exer10();
void all_print();
void one_print(int num);
};

#endif 
