#include "DataUsing.h"





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	char right_answers[] = "right_answers.txt";
	Menu menu(CenterTop);
	menu << "Default Work" << "Reverse Work" << "Exit";
	menu.SetMenuParam(5, 10);	
	try
	{
		FileDataProcessing* file_data = new FileDataProcessing(filename, '*', '$');
		Display data_using(file_data, right_answers);
		while (true)
		{
			switch (menu.DoMenu())
			{
			case 0:
				data_using.Show();
				break;
			case 1:
				data_using.Show(true);
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