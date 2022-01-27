#include "Display.h"





void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char filename[] = "words.txt";
	FileDataProcessing* file_data = new FileDataProcessing(filename, '*', '$');
	Display display(file_data);
	while (true)
	{
		if(!display.Show(1))break;
		getch();
	}
	delete file_data;
}