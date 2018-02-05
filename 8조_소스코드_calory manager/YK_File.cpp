#include "YK_File.h"

YK_File::YK_File()
{
	
}

void YK_File::file_read(char *file_name)
{
	string str_line;
	int count=0;
	char* p = NULL;
	
	
	infile.open(file_name);
    if( !infile.is_open() )  // ������ �����ִ��� üũ
    {    cout << file_name << " ������ �� �� �����ϴ�." << endl;
         cout << "���α׷��� �����մϴ�.\n";
         exit(EXIT_FAILURE);
    }
	while(!infile.eof())
	{
		getline(infile,str_line);
		if(count==0)
		{
			data_num = atoi(str_line.data());
			table = (CAL_TABLE *)malloc(atoi(str_line.data())*sizeof(CAL_TABLE));
			count++;
		}
		else
		{
			p = strtok((char*)(str_line.c_str()),",");
			if((strlen(p))>=30)
			{	
				p[27]='*';	
				p[28]='*';	
				p[29]='\0';//30������
			}
			strcpy(table[count-1].food,p);
			p = strtok(NULL,",");
			table[count-1].calories = atoi(p);
			count++;
		}
	}
    infile.close();
	data_num = count;
	
}


YK_File::~YK_File()
{
	free(table);
}