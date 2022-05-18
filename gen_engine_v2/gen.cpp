#include "gen.h"
#pragma once


//dodaæ wiêcej polulacji

gen::gen(int w, int k, int iteracja) : w(w), k(k), iteracja(iteracja), tab(w, std::vector<bool>(k)), wiek(w, std::vector<int>(k)) {} //z lista inicjalizacyjna

gen::gen(const gen& popr)
{
	w = popr.w;
	k = popr.k;
	iteracja = popr.iteracja + 1;
	tab = popr.tab;
	wiek = popr.wiek;
	max_sasiady = popr.max_sasiady;
	min_sasiady = popr.min_sasiady;
} //kopiujacy

gen::~gen() {}; //destruktor

void gen::losowanie(float p)
{
	p *= 100;
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if ((std::rand() % 100) <= p)
			{
				tab[i][j] = 1;
			}
		}
	}
}

void gen::c_show()
{
	system("cls");

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (tab[i][j])
			{
				std::cout << 'x';
			}
			else
			{
				std::cout << 'o';
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << iteracja;
}

void gen::c_show2()
{
	system("cls");

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			std::cout << tab[i][j];
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
	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)]) //lewo góra
	{
		ile++;
	}
	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd, k)]) // góra
	{
		ile++;
	}
	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)]) //prawo góra
	{
		ile++;
	}
	if (tab[spr_wylot(wd, w)][spr_wylot(kd - 1, k)]) //lewo
	{
		ile++;
	}
	if (tab[spr_wylot(wd, w)][spr_wylot(kd + 1, k)]) //prawo
	{
		ile++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)]) //lewo dó³
	{
		ile++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd, k)]) //dó³
	{
		ile++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)]) //prawo dó³
	{
		ile++;
	}
	return ile;
}

int* gen::dookola2 (int wd, int kd)
{
	int ile[8]{};
	for (int i = 0; i < 8; i++)
		ile[i] = 0;

	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)]) //lewo góra
	{
		ile[tab[spr_wylot(wd - 1, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd, k)]) // góra
	{
		ile[tab[spr_wylot(wd - 1, w)][spr_wylot(kd, k)] - 65]++;
	}
	if (tab[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)]) //prawo góra
	{
		ile[tab[spr_wylot(wd - 1, w)][spr_wylot(kd + 1, k)]-65]++;
	}
	if (tab[spr_wylot(wd, w)][spr_wylot(kd - 1, k)]) //lewo
	{
		ile[tab[spr_wylot(wd, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab[spr_wylot(wd, w)][spr_wylot(kd + 1, k)]) //prawo
	{
		ile[tab[spr_wylot(wd, w)][spr_wylot(kd + 1, k)]-65]++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)]) //lewo dó³
	{
		ile[tab[spr_wylot(wd + 1, w)][spr_wylot(kd - 1, k)]-65]++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd, k)]) //dó³
	{
		ile[tab[spr_wylot(wd + 1, w)][spr_wylot(kd, k)]-65]++;
	}
	if (tab[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)]) //prawo dó³
	{
		ile[tab[spr_wylot(wd + 1, w)][spr_wylot(kd + 1, k)]-65]++;
	}
	return ile;
}

std::vector <std::vector <bool> > gen::tabn(std::vector <std::vector <bool> > tab, int min_s, int max_s)
{
	int ilosc;
	std::vector <std::vector <bool> > robo = tab;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			ilosc = dookola(i, j);
			if ((!tab[i][j]) and (ilosc == max_s))
			{
				robo[i][j] = true;
			}
			else if ((tab[i][j]) and ((ilosc <= max_s) and (ilosc >= min_s)))
			{
				robo[i][j] = true;
			}
			else if (tab[i][j])
			{
				robo[i][j] = false;
			}
			else if (!tab[i][j])
			{
				robo[i][j] = false;
			}
		}
	}
	return robo;
}

void gen::nowy() //przygotowywyje generacje nastêpn¹
{
	tab = tabn(tab, min_sasiady, max_sasiady);
}

void gen::wymus(std::vector <std::vector <bool> > tabw)
{
	tab = tabw;
}

void gen::postarzej(int max_wiek)
{
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (tab[i][j])
			{
				wiek[i][j]++;
				if (wiek[i][j] == max_wiek)
				{
					wiek[i][j] = 0;
					tab[i][j] = 0;
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
