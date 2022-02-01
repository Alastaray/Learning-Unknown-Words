#include "DataUsing.h"



void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	char right_answers[] = "right_answers.txt";
	Menu main_menu(CenterTop);
	main_menu << "Adding" << "Learning" << "Exit";
	main_menu.SetMenuParam(5, 10);	
	Menu sub_menu(CenterTop);
	sub_menu << "Default Work" << "Reverse Work" << "Exit";
	sub_menu.SetMenuParam(5, 10);
	try
	{
		FileDataProcessing* file_data = new FileDataProcessing(filename, '*');
		Display display(file_data, right_answers);
		while (true)
		{		
			switch (main_menu.DoMenu())
			{
			case 0:
				display.Add();
				break;
			case 1:
			{				
				file_data->Read();
				while (true)
				{
					switch (sub_menu.DoMenu())
					{
					case 0:
						display.Show();
						break;
					case 1:
						display.Show(true);
						break;
					case 2:
						delete file_data;
						return;
					}
				}
			}
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