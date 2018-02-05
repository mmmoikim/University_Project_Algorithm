#include "exercise.h"


exercise::exercise()
{
	num=0;
	time=0;
	fcal=0;
	ecal=0;
}

void exercise::all_exercise()//��� � �Լ� ȣ��
{
exer1();
exer2();
exer3();
exer4();
exer5();
exer6();
exer7();
exer8();
exer9();
exer10();
all_print(); //��� � �Լ� ����Ʈ
}

void exercise::exer1()  //���� ��Լ�
{
a[0].name="swimming";
ecal=100.2;
a[0].minute = fcal/ecal;
}
void exercise::exer2()
{
a[1].name="PingPong";
ecal=80.3;
a[1].minute = fcal/ecal;
}

void exercise::exer3()
{
a[2].name="aerobic";
ecal=72.1;
a[2].minute = fcal/ecal;
}
void exercise::exer4()
{
a[3].name="bowling";
ecal=65;
a[3].minute = fcal/ecal;
}
void exercise::exer5()
{
a[4].name="Basketball";
ecal=50.25;
a[4].minute = fcal/ecal;
}
void exercise::exer6()
{
a[5].name="Baseball";
ecal=40.33;
a[5].minute = fcal/ecal;
}
void exercise::exer7()
{
a[6].name="climbing";
ecal=30.15;
a[6].minute  = fcal/ecal;
}
void exercise::exer8()
{
a[7].name="Jogging";
ecal=20.33;
a[7].minute  = fcal/ecal;
}
void exercise::exer9()
{
a[8].name="bicycle";
ecal=10;
a[8].minute = fcal/ecal;
}
void exercise::exer10()
{
a[9].name="Walking";
ecal=5.25;
a[9].minute = fcal/ecal;
}

void exercise::select_exercise(int num) //��Լ� �������! �ϳ����� ȣ���ϴ°�
{
	switch(num){
	case 0:
	exer1();	
	break;
	case 1:
	 exer2();
	 break;
	case 2:
	 exer3();
	 break;
	case 3:
	 exer4();
	 break;
	case 4:
	 exer5();
	 break;
	case 5:
	 exer6();
	 break;
	case 6:
	 exer7();
	 break;
	case 7:
	 exer8();
	 break;
	case 8:
	 exer9();
	break;
	case 9:
	exer10();
	 break;
			}
}


int exercise::select_time(float time) //�ð�������� 
{
	int i=0;
	while(i<=10)
	{
		select_exercise(i);	
		if(time<a[i].minute)
			break;
		else
			i++;
	}
	return i;
}

void exercise::all_print() // ��ü ����Ʈ
{
 for (int i=0;i<10;i++)
	 cout<< a[i].name.c_str() << " : " << abs(a[i].minute)<<" minutes"<<endl;
}

void exercise::one_print(int num) //�ϳ��� ����Ʈ. select_time���� select_exercise�� ���� �ֱ⶧����, ��ȣ��Ǿ� ����Ʈ�Ǵ°��� ������ main���� ���� ����Ʈ�Լ� ȣ���ϰ� �ٲ�.
{
 cout<< a[num].name.c_str() <<" : "<<abs(a[num].minute)<<" minutes"<<endl;
}

