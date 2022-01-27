#include "Display.h"





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	try
	{
		FileDataProcessing* file_data = new FileDataProcessing(filename, '*', '$');
		Display display(file_data);
		display.Show();
		delete file_data;
	}
	catch (const std::exception& error)
	{
		DrawSomething(error.what());
	}
	
}