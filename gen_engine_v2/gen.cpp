#include "gen.h"
#pragma once


//dodaæ wiêcej polulacji

gen::gen(int w, int k, int iteracja) : w(w), k(k), iteracja(iteracja), tab2(w, std::vector<char>(k)), wiek(w, std::vector<int>(k)) {} //z lista inicjalizacyjna

gen::gen(const gen& popr)
{
	w = popr.w;
	k = popr.k;
	iteracja = popr.iteracja + 1;
	tab2 = popr.tab2;
	wiek = popr.wiek;
	max_sasiady = popr.max_sasiady;
	min_sasiady = popr.min_sasiady;
} //kopiujacy

gen::~gen() {}; //destruktor

void gen::losowanie(float p,int g)
{
	p *= 100;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if ((std::rand() % 100) <= p)
			{
				tab2[i][j] = std::rand() % g + 65;
			}
			else
			{
				tab2[i][j] = '0';
			}
		}
	}
}



void gen::c_show2()
{
	system("cls");

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << tab2[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << iteracja;
}

int gen::spr_wylot(int sprawdzana, int maksymalna)
{
	if (sprawdzana < 0)
	{
		return (maksymalna - 1);
	}
	else if (sprawdzana > maksymalna - 1)
	{
		return 0;
	}
	else
	{
		return sprawdzana;
	}
}

int gen::dookola(int wd, int kd)
{
	int ile = 0;
	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)] !='0') //lewo góra
	{
		ile++;
	}
	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd, k)] != '0') // góra
	{
		ile++;
	}
	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)] != '0') //prawo góra
	{
		ile++;
	}
	if (tab2[spr_wylot(wd, w)][spr_wylot(kd - 1, k)] != '0') //lewo
	{
		ile++;
	}
	if (tab2[spr_wylot(wd, w)][spr_wylot(kd + 1, k)] != '0') //prawo
	{
		ile++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)] != '0') //lewo dó³
	{
		ile++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd, k)] != '0') //dó³
	{
		ile++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)] != '0') //prawo dó³
	{
		ile++;
	}
	return ile;
}

char gen::dookola2 (int wd, int kd)
{
	int ile[8]{};
	for (int i = 0; i < 8; i++)
		ile[i] = 0;

	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)] != '0') //lewo góra
	{
		ile[tab2[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd, k)] != '0') // góra
	{
		ile[tab2[spr_wylot(wd - 1, w)][spr_wylot(kd, k)] - 65]++;
	}
	if (tab2[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)] != '0') //prawo góra
	{
		ile[tab2[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)]-65]++;
	}
	if (tab2[spr_wylot(wd, w)][spr_wylot(kd - 1, k)] != '0') //lewo
	{
		ile[tab2[spr_wylot(wd, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab2[spr_wylot(wd, w)][spr_wylot(kd + 1, k)] != '0') //prawo
	{
		ile[tab2[spr_wylot(wd, w)][spr_wylot(kd + 1, k)]-65]++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)] != '0') //lewo dó³
	{
		ile[tab2[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd, k)] != '0') //dó³
	{
		ile[tab2[spr_wylot(wd + 1, w)][spr_wylot(kd, k)]-65]++;
	}
	if (tab2[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)] != '0') //prawo dó³
	{
		ile[tab2[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)]-65]++;
	}

	int max_pos = 0;
	int max = 0;

	for (int i = 0; i < 8; i++)
	{
		if (ile[i] > max)
		{
			max = ile[i];
			max_pos = i;
		}
	}

	return (char) max_pos+65;
}

std::vector <std::vector <char> > gen::tabn(std::vector <std::vector <char> > tab, int min_s, int max_s)
{
	int ilosc;
	std::vector <std::vector <char> > robo = tab;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			ilosc = dookola(i, j);

			if ((tab[i][j]=='0') and (ilosc == max_s))
			{
				robo[i][j] = dookola2(i,j);
			}
			else if ((tab[i][j]!='0') and ((ilosc <= max_s) and (ilosc >= min_s)))
			{
				robo[i][j] = dookola2(i,j);
			}
			else if (tab[i][j] != '0')
			{
				robo[i][j] = '0';
			}
			else if (tab[i][j] == '0')
			{
				robo[i][j] = '0';
			}
		}
	}
	return robo;
}

void gen::nowy() //przygotowywyje generacje nastêpn¹
{
	tab2 = tabn(tab2, min_sasiady, max_sasiady);
}

void gen::wymus(std::vector <std::vector <char> > tabw)
{
	tab2 = tabw;
}

void gen::postarzej(int max_wiek)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (tab2[i][j]!='0')
			{
				wiek[i][j]++;
				if (wiek[i][j] == max_wiek)
				{
					wiek[i][j] = 0;
					tab2[i][j] = '0';
				}
			}
			else
			{
				wiek[i][j] = 0;
			}
		}
	}
}

void gen::w_show()
{
	//system("cls");
	std::cout << std::endl << std::endl;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << wiek[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << iteracja;
}

void gen::set_min_max(int min, int max)
{
	max_sasiady = max;
	min_sasiady = min;
}
