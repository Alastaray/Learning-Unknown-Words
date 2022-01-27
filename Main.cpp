#include "DataUsing.h"





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	try
	{
		FileDataProcessing* file_data = new FileDataProcessing(filename, '*', '$');
		DataUsing data_using(file_data);
		data_using.UseData();
		data_using.GetStatistics();
		delete file_data;
	}
	catch (const std::exception& error)
	{
		DrawSomething(error.what());
	}
	
}