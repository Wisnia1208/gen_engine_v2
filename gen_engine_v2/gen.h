#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

//dodaæ wiêcej polulacji

class gen
{
private:
	int w;
	int k;
	std::vector <std::vector <bool> > tab;
	std::vector <std::vector <int> > wiek;
	std::vector <std::vector <char> > tab2;
	int iteracja;
	int max_sasiady;
	int min_sasiady;



public:
	gen(int w, int k, int iteracja); //z lista inicjalizacyjna

	gen(const gen& popr);

	~gen();//destruktor

	void losowanie(float p);//to do prawdopodobienstwo

	void c_show();

	void c_show2();

	int spr_wylot(int sprawdzana, int maksymalna);

	int dookola(int wd, int kd);

	int* dookola2(int wd, int kd);

	std::vector <std::vector <bool> > tabn(std::vector <std::vector <bool> > tab, int max_s, int min_s);

	void nowy(); //przygotowywyje generacje nastêpn¹

	void wymus(std::vector <std::vector <bool> > tabw);

	void postarzej(int max_wiek);

	void w_show();

	void set_min_max(int min, int max);

	/*
	to do

	bool zapis();

	enabej klany

	void symulacja();
	*/
};
