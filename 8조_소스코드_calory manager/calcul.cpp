#include "calcul.h"

void Calcul::initmembers(int wei,int hei){

weight=wei;
height=hei;
food=0; 
advice_kcal=0;
eat_kcal=0;
exercise_kcal;
}


void Calcul::calcul_advice(){ // ���� Į�θ� ���ϴ� �Լ�

double bmi = (weight/(height*height))*10000;

if(bmi>25) weight = (height * height *25) + (weight - (height * height *25))/4;

advice_kcal = weight * 30; // advice_kcal = ����Į�θ�


cout<<"Recommended calorie : "<<int(advice_kcal)<<"kcal.\n";

}


void Calcul::calcul_eat(int food){ // ���� Į�θ� ���ϴ� �Լ�

eat_kcal = food; // ���� ���� �Է¹ް�, ���Ŀ� ���� kcal ���ϱ�---> eat_kcal

}

int Calcul::calcul_exercise(){ // ��� Į�θ� ���ϴ� �Լ�
	
exercise_kcal = (advice_kcal) - (eat_kcal);

if(exercise_kcal>0) { 

	exercise_kcal = 0;
    cout<<"You don't have to exercise, you lack of calories"<<endl;
	return 0;
}
else 
	{
		cout<<"you should exercise as much as "<<abs(int(exercise_kcal))<<"kal.\n"<<endl;
	return abs(int(exercise_kcal));
}
}
