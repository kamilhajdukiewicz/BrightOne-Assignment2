#include "stdafx.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int SumaLeft{ 0 };
int SumaRight{ 0 };
static int index_for_bool = 0;

bool check(int *tab, int ilosc_liczb)
{
	bool YesOrNo{};
	for (int i = 0; i<ilosc_liczb; i++)
	{

		if (i == 0)
		{
			SumaLeft = 0;
		}
		else
		{
			for (int j = 1; i - j >= 0; j++)
			{
				SumaLeft += tab[i - j];
			}
		}
		if (i == ilosc_liczb - 1)
		{
			SumaRight = 0;
		}
		else
		{
			for (int j = 1; i + j <= ilosc_liczb - 1; j++)
			{
				SumaRight += tab[i + j];
			}
		}

		if (SumaLeft == SumaRight)
		{
			YesOrNo = 1;
			break;
		}
		else
		{
			YesOrNo = 0;
			SumaLeft = 0;
			SumaRight = 0;
		}
	}
	return YesOrNo;
}

int main()
{
	int NumberOfAttempts;
	cin >> NumberOfAttempts;
	int ilosc_liczb;
	bool *tab_b = new bool[NumberOfAttempts];

	int d = NumberOfAttempts;
	while (d>0)
	{
		cin >> ilosc_liczb;
		int *tab = new int[ilosc_liczb];

		for (int i = 0; i < ilosc_liczb; i++)
		{
			cin >> tab[i];
		}
		cin.clear();
		cin.ignore(numeric_limits < streamsize >::max(), '\n');
		tab_b[index_for_bool] = check(tab, ilosc_liczb);
		index_for_bool++;
		d--;
		delete[]tab;
	}

	for (int i = 0; i < NumberOfAttempts; i++)
	{
		if (tab_b[i])
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	delete[]tab_b;

	getchar();
	return 0;
}

