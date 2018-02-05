#ifndef _YK_FILE_
#define _YK_FILE_


#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

typedef struct CAL_TABLE{
	char food[30];
	int calories;
}CAL_TABLE;

class YK_File
{
public:

	YK_File();
	~YK_File();

	ifstream infile;
	int data_num;
	
	void file_read(char *file_name);

	CAL_TABLE *table;
};

#endif