#include "calcul.h"
#include "exercise.h"
#include "YK_File.h"
#include "HJ_BST.h"
#include <iostream>
#include <conio.h>

int main(void){

	int wei;
	int hei;
	int choice=0;

	cout<<"Please enter your height : ";
	cin>>hei;
	cout<<"Please enter your weight : ";
	cin>>wei;
	
	Calcul kcal;
	exercise exer;

	kcal.initmembers(wei,hei);
	kcal.calcul_advice();

	int num;
	char new_food[30];
	char delete_food[30];
	int new_calories;
	bool select;
	int total=0;
	
	YK_File file;
	file.file_read("input.txt");

	struct CAL_TABLE table;
	tree_node* foundNode=NULL;

	HJ_BST bst;

		for(int i=0; i<file.data_num-1; i++)
		{
			bst.insert_tree(bst.p,file.table[i].food,file.table[i].calories);
		}
		cout<<"\nDo you want to see the food list?(1. yes	0. no )"<<endl;
		cin>>select;
			if(select)
			{
		bst.display_tree(bst.p);
			}
	
		cout<<"\nDo you want to delete the food in list?(1. yes 0. no)"<<endl;	
		cin>>select;
		if(select)
		{
			cout<<"Please enter to food"<<endl;
			cin>>delete_food;
			bst.delete_tree(bst.p,delete_food);
			cout<<"deleted"<<endl;
		}
		cout<<"\nEnter the number of the food you eat."<<endl;
		cin>>num;
		int a=0;
		
		if(num<0)
		{
			cout<<"You have entered a wrong."<<endl;
		}
		else
		{
	
	for(int i=0; i<num; i++)
	{
		cout<<"\nPlease enter to food"<<endl;
		cin >> new_food;
		
		foundNode = bst.searchBST(bst.p,new_food);
		
		if(foundNode == NULL)
		{
			cout<<"Add to food?(1. yes	0. no )"<<endl;
			cin>>select;
			if(select)
			{
			cout<<"\nPlease enter to food's calories."<<endl;
			cin>>new_calories;
			bst.insert_tree(bst.p ,new_food ,new_calories);
			cout<<"Saved"<<endl;
			}
		}
		else
		{
			cout<<"\nCalories of "<<new_food<<" is "<< foundNode->calories<<"."<<endl;
			total+=foundNode->calories;
			cout<<"Total calories is "<<total<<"."<<endl;
		}


	}	

	kcal.calcul_eat(total);
	
	exer.fcal = kcal.calcul_exercise();
	
	if(exer.fcal!=0){

	while(1){

	cout<<"1 : all exercise / 2 : select time / 3 : select exercise / 4 : esc"<<endl;
    cin>>choice;

	if(choice==1)
	{
		exer.all_exercise();
	}

	if(choice==2)
	{
		int temp=0;
		cout<<"Please enter the time : ";
		cin>>exer.time;
		temp=exer.select_time(exer.time); //select_time이 몇번 돌아갔는지 카운팅 한후, return값으로 돌려주어서 그만큼 프린트 되도록.
		if(temp == 0)
		{
			cout<<"Have time to exercise is not enough\n";
			cout<<"Please enter the enough time : ";
		cin>>exer.time;
		}
		else
		{
		for(int i=0;i<temp;i++)
		{
			exer.one_print(i); //각각 프린트 되도록
		}
		}
	}

	if(choice==3)
	{
		cout<<"Please select the exercise."<<endl;
	    cout<<" 0: swimming\n 1: pingpong\n 2: aerobic\n 3:bowling\n 4: basketball\n 5: baseball\n 6: cimbing\n 7: jogging\n 8: bicycle\n 9: walk\n"<<endl;
		cout<<"if you want exit, please enter the 10."<<endl;
		cin>>exer.num;

		while(exer.num!=10)
		{
			exer.select_exercise(exer.num);
			exer.one_print(exer.num); //각각 프린트 되도록
			cin>>exer.num;
		}
	}

	if(choice==4)
	{
		return 0;
	}
	}
	}
		}
		getch();
return 0;

}