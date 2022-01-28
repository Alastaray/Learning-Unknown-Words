#include "DataUsing.h"





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	Menu menu(CenterTop);
	menu << "Work" << "Reverse Work" << "Exit";
	menu.SetMenuParam(5, 10);	
	try
	{
		FileDataProcessing* file_data = new FileDataProcessing(filename, '*', '$');
		DataUsing data_using(file_data);
		while (true)
		{
			switch (menu.DoMenu())
			{
			case 0:
				data_using.UseData();
				break;
			case 1:
				data_using.UseData(true);
				break;
			case 2:
				delete file_data;
				return;
			}
		}				
	}
	catch (const std::exception& error)
	{
		DrawSomething(error.what());
	}
	
}