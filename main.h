#pragma once
 
#include "ISet.h"
#include "MySet.h"

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

void menu_show()
{
	cout << "1.Add to set" << endl;
	cout << "2.Remove from set" << endl;
	cout << "3.Contains?" << endl;
	cout << "4.Size of set" << endl;
	cout << "5.Print the set" << endl;
	cout << "6.Exit" << endl;
}

template <class T>
void execution(MySet<T> m)
{
	int menu = 0;
	T temp;
	do
	{
		system("cls");
		menu = 0;
		menu_show();
		while (menu > 6 || menu < 1)
		{
			cout << "\nChoose the menu item: ";
			cin >> menu;
			cout << endl;
			if (!cin || menu > 6 || menu < 1)
			{
				cout << "\nError: invalid operation number!" << endl;
				cout << "Please enter the number of operation(1-6)" << endl;
				_flushall();
				cin.clear();
			}
			if (menu == 1)
			{
				cout << "Enter the element that add: ";
				cin >> temp;
				m.add(temp);
				cout << "\nPress any key to continue.." << endl;
				_getch();
			}
			else if (menu == 2)
			{
				if (m.size() == 0)
					cout << "Set is empty" << endl;
				else
				{
					cout << "Enter the element that remove: ";
					cin >> temp;
					m.remove(temp);

				}
				cout << "\nPress any key to continue.." << endl;
				_getch();
			}
			else if (menu == 3)
			{
				if (m.size() == 0)
					cout << "Set is empty" << endl;
				else
				{
					cout << "Whether the element in the set?" << endl;
					cout << "\nEnter the element for check: ";
					cin >> temp;
					if (m.contains(temp))
						cout << "\nElement is contained" << endl;
					else cout << "\nElement is not contained" << endl;
				}
				cout << "\nPress any key to continue.." << endl;
				_getch();
			}
			else if (menu == 4)
			{
				if (m.size() == 0)
					cout << "Set is empty" << endl;
				else
					cout << "Set size = " << m.size() << endl;
				cout << "\nPress any key to continue.." << endl;
				_getch();
			}
			else if (menu == 5)
			{
				cout << "Set: ";
				m.print();
				cout << "\nPress any key to continue.." << endl;
				_getch();
			}
			else if (menu == 6)
			{
				cout << "Shutdown program ..." << endl;
				break;
			}
		}
	} while (menu != 6);
}