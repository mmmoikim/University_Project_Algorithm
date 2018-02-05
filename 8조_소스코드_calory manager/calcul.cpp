#include "calcul.h"

void Calcul::initmembers(int wei,int hei){

weight=wei;
height=hei;
food=0; 
advice_kcal=0;
eat_kcal=0;
exercise_kcal;
}


void Calcul::calcul_advice(){ // 권장 칼로리 구하는 함수

double bmi = (weight/(height*height))*10000;

if(bmi>25) weight = (height * height *25) + (weight - (height * height *25))/4;

advice_kcal = weight * 30; // advice_kcal = 권장칼로리


cout<<"Recommended calorie : "<<int(advice_kcal)<<"kcal.\n";

}


void Calcul::calcul_eat(int food){ // 먹은 칼로리 구하는 함수

eat_kcal = food; // 먹은 음식 입력받고, 음식에 대한 kcal 더하기---> eat_kcal

}

int Calcul::calcul_exercise(){ // 운동할 칼로리 구하는 함수
	
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
