#include<iostream>
#include<random>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<Windows.h>

using namespace std;

// Mini - algorytmy 
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Kolorowanie(int tekst,int kolor)
{

		HANDLE hOut;
		hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (kolor == 1) {
			
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else
		{
		
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		}
		cout <<tekst;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);


	
}

int OznaczenieKolumn(char x)
{
	switch (x)
	{
	case 'a':
	{
		return 0;
		break;
	}
	case 'b':
	{
		return 1;
		break;
	}
	case 'c':
	{
		return 2;
		break;
	}
	case 'd':
	{
		return 3;
		break;
	}
	case 'e':
	{
		return 4;
		break;
	}
	case 'f':
	{
		return 5;
		break;
	}
	case 'g':
	{
		return 6;
		break;
	}
	case 'h':
	{
		return 7;
		break;
	}
	case 'i':
	{
		return 8;
		break;
	}
	case 'j':
	{
		return 9;
		break;
	}
	default:

		return 10;
	}
}

void Instrukcja()
{
	cout << "INSTRUKCJA" << endl;
	cout << "Podaj miejsce pierwszego elementu statku, a nastepnie jego kierunek (jesli statek jest dluzszy od 1-masztowca" << endl;
	cout << "kierunki : 1-gora 2-prawo 3-dol 4-lewo" << endl;
	cout << "Przyklad prawidlowego uzupelniania : \"G5 | 2\"" << endl;
	cout << "Czyli stawiamy pierwszy element na polu G5 a nastepnie zapelniamy nim pola w prawo " << endl;
}

void TworzenieStrefyBuforu(int dlogosc_statku,int Plansza[10][10],int kierunek,int x,int y)
{
	// TWORZENIE STREFY BUFOROWEJ
	for (int i = 0; i < 3; i += 2)
	{

		for (int m = 0; m <= (dlogosc_statku + 1); m++)
		{


			switch (kierunek)
			{
			case 1:
			{

				if ((((y + 1 - m) <= 9) && ((y + 1 - m) >= 0)) && (((x - 1 + i) >= 0) && ((x - 1 + i) <= 9)))
				{
					Plansza[y + 1 - m][x - 1 + i] = -1;

				}

				break;
			}
			case 2:
			{
				if ((((y - 1 + i) <= 9) && ((y - 1 + i) >= 0)) && (((x - 1 + m) >= 0) && ((x - 1 + m) <= 9)))
				{
					Plansza[y - 1 + i][x - 1 + m] = -1;
				}

				break;

			}

			case 3:
			{

				if ((((y - 1 + m) <= 9) && ((y - 1 + m) >= 0)) && (((x - 1 + i) >= 0) && ((x - 1 + i) <= 9)))
				{
					Plansza[y - 1 + m][x - 1 + i] = -1;
				}

				break;
			}
			case 4:
			{

				if ((((y - 1 + i) <= 9) && ((y - 1 + i) >= 0)) && (((x + 1 - m) >= 0) && ((x + 1 - m) <= 9)))
				{
					Plansza[y - 1 + i][x + 1 - m] = -1;
				}

				break;
			}

			default:
			{
				break;
			}
			}



		}

	}

	// dalszy ciag tworzenia buforu

	switch (kierunek)
	{

		//kierunek gora -1
		case 1:
		{
			if (0 <= (y + 1) && (y + 1) <= 9)
			{
				Plansza[y + 1][x] = -1;
			}

			if (0 <= (y - dlogosc_statku) && (y - dlogosc_statku) <= 9)
			{
				Plansza[y - dlogosc_statku][x] = -1;
			}

			break;
		}

		//kierunek prawo -2
		case 2:
		{
			if (0 <= (x - 1) && (x - 1) <= 9)
			{
				Plansza[y][x - 1] = -1;
			}

			if (0 <= (x + dlogosc_statku) && (x + dlogosc_statku) <= 9)
			{
				Plansza[y][x + dlogosc_statku] = -1;
			}

			break;
		}
		//kierunek dol -3
		case 3:
		{
			if (0 <= (y - 1) && (y - 1) <= 9)
			{
				Plansza[y - 1][x] = -1;
			}

			if (0 <= (y + dlogosc_statku) && (y + dlogosc_statku) <= 9)
			{
				Plansza[y + dlogosc_statku][x] = -1;
			}
			break;
		}
		//kierunek lewo -4
		case 4:
		{
			if (0 <= (x + 1) && (x + 1) <= 9)
			{
				Plansza[y][x+1] = -1;
			}

			if (0 <= (x- dlogosc_statku) && (x - dlogosc_statku) <= 9)
			{
				Plansza[y][x-dlogosc_statku] = -1;
			}
			break;
		}


	}
}

// losowanie od 0 do 9
int Wybieranie_Miejsca_Losowo()
{
	mt19937 generator(time(nullptr));
	uniform_int_distribution<int> distribution(0, 9);

	int wylosowane_miejsce= distribution(generator);

	return wylosowane_miejsce;
}

// losowanie od 1 do 4
int Wybieranie_Kierunku_Losowo()
{
	mt19937 generator(time(nullptr));
	uniform_int_distribution<int> distribution(1, 4);

	int wylosowany_kierunek = distribution(generator);

	return wylosowany_kierunek;
}

// ALGORYTMY DO GRY
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------


void WyswietlStatki(int Plansza[10][10])
{


	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			if (Plansza[i][j] != 0 && Plansza[i][j] != -1)
				cout << "X";
			else {
				cout << "O";
			}


		}
		cout << endl;
	}
}

void WyswietlStatkiDokladnie(int Plansza[10][10])
{
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{
			cout.width(3);
			if(Plansza[i][j]!=0 && Plansza[i][j]!=-1)
			{
				Kolorowanie(Plansza[i][j],1); // kolor seledynowy [miejsca polozenia statku]
			}
			else if(Plansza[i][j] == -1)
			{
				Kolorowanie(Plansza[i][j], 2); // kolor czerwony [miejsca buforu statku]
			}
			else
			{
				cout << Plansza[i][j]; // zwykle wyswietlanie pustych miejsc
			}
			
		}
		cout << endl;
	}
}


void rozmiescStatkiAutomatycznie(int Plansza[10][10])
{

	//-------------------------------------------
	int ilosc_statkow;
	int x, y; // x-kolumny y-wiersze
	int kierunek; // 1gora 2prawo 3dol 4lewo
	bool Sprawdzanie_Przestrzeni; 
	int Plansza_Optymalizacja[10][10]{};
	//-------------------------------------------
	 
	/*
	//ekran ladowania planszy
	for (int i = 0; i < 7; i++)
	{
		cout << endl;
	}
	cout.width(80);
	cout << "Ladowanie planszy trwa, prosze czekac.. Arr..";
	*/


	// petla od dlogosci statkow
	for (int dlogosc_statku = 4; dlogosc_statku >= 1; dlogosc_statku--)
	{
		// Ilosc statkow danego typu : 4-masztowiec=1 | 3-masztowiec=2 | 2-masztowiec=3 | 1-masztowiec=4 

		if (dlogosc_statku == 4)
		{
			ilosc_statkow = 1;
		}
		if (dlogosc_statku == 3)
		{
			ilosc_statkow = 2;
		}
		if (dlogosc_statku == 2)
		{
			ilosc_statkow = 3;
		}
		if (dlogosc_statku == 1)
		{
			ilosc_statkow = 4;
		}


		// petla od ilosci statkow
		for (ilosc_statkow; ilosc_statkow > 0; ilosc_statkow--)
		{

			


			// PROGRAM POWTARZA SIE JESLI NAPOTKA PRZESZKODE I WYBIERA INNE MIEJSCE
			do {


				// WYBIERANIE KIERUNKU

				bool Sprawdzanie_Miejsca = false;
				while (Sprawdzanie_Miejsca == false)
				{

					//generator wybierania miejsca (losowo)

					// X - kolumny
					// Y - wiersze
					x = Wybieranie_Miejsca_Losowo();
					y = Wybieranie_Miejsca_Losowo();




					//SPRAWDZANIE MIEJSCA
					if (Plansza[y][x] == 0 && Plansza_Optymalizacja[y][x] == 0)
					{
						Sprawdzanie_Miejsca = true;
					}
					
				}


				

				
				//jesli dlugosc statku jest wieksza niz 1 musimy wybrac kierunek
				if (dlogosc_statku != 1)
				{
					//Tablica do optymalizacji | jesli kierunek bedzie zly to nie sprawdzamy go wiecej
					int Pozostale_Kierunki[4] = { 1,1,1,1 };
					bool Sprawdzanie_Kierunku;

					// SPRAWDZANIE Potencjalnie mo¿liwych kierunków
					for (int i = 1; i <= 4; i++)// i - to w tym przypadku kierunki które testujemy
					{
						if (i == 1)
						{
							if (y - (dlogosc_statku - 1) < 0)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;

						}


						if (i == 2)
						{
							if (x + (dlogosc_statku - 1) > 9)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}


						if (i == 3)
						{
							if (y + (dlogosc_statku - 1) > 9)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}


						if (i == 4)
						{
							if (x - (dlogosc_statku - 1) < 0)
							{
								Sprawdzanie_Kierunku = false;
							}
							else
								Sprawdzanie_Kierunku = true;
						}

						//jesli kierunek byl zly - pozbywamy sie go z puli
						if (Sprawdzanie_Kierunku == false)
						{
							Pozostale_Kierunki[i - 1] = 0;
						}
					}



					// Wybieranie kierunku (z tych co pozostaly)
					do 
					{
						kierunek = Wybieranie_Kierunku_Losowo();

					} while (Pozostale_Kierunki[kierunek - 1] == 0);


					// sprawdzanie przestrzeni w tym kierunku
					Sprawdzanie_Przestrzeni = true;


					// petla sprawdza czy w danym kierunku nie znajdzie sie przeszkoda
					for (int i = 1; i <= dlogosc_statku - 1; i++)
					{

						//losowanie nowego kierunku
						while (Pozostale_Kierunki[kierunek - 1] == 0)
						{
							kierunek = Wybieranie_Kierunku_Losowo();
						}

						// Jesli podczas sprawdzania napotkamy przeszkode, [sprawdzanie przestrzeni] bedzie falszywe

						// do gory
						if (kierunek == 1)
						{
							if (Plansza[y - i][x] != 0)
							{
								bool Sprawdzanie_Przestrzeni = false;

							}
						}

						// w prawo
						if (kierunek == 2)
						{
							if (Plansza[y][x + i] != 0)
							{
								bool Sprawdzanie_Przestrzeni = false;

							}
						}

						// w dol
						if (kierunek == 3)
						{
							if (Plansza[y + i][x] != 0)
							{
								bool Sprawdzanie_Przestrzeni = false;

							}
						}

						// w lewo
						if (kierunek == 4)
						{
							if (Plansza[y][x - i] != 0)
							{
								bool Sprawdzanie_Przestrzeni = false;

							}
						}

						//jesli w przestrzeni pojawil sie obiekt - pozbywamy sie kierunku z puli
						if (Sprawdzanie_Przestrzeni == false)
						{
							Pozostale_Kierunki[kierunek - 1] = 0;
							i = 0; // reset petli for (bo nowy kierunek musimy sprawdzaæ od nowa)
						}

						//jesli nic nie zostalo z kierunkow musimy wybrac inne miejce [ WA¯NY ELEMENT W FUNKCJI ]
						int suma_kierunkow = 0;
						for (int j = 0; j < 4; j++)
						{
							suma_kierunkow += Pozostale_Kierunki[j];
						}
						if (suma_kierunkow == 0)
							break;

					}

				}
				else
				{
					Sprawdzanie_Przestrzeni = true;
				}

				// jesli sprawdzanie przestrzeni nie powiodlo sie
				if(Sprawdzanie_Przestrzeni==false)
				Plansza_Optymalizacja[y][x] = 1; // to puste pole nie jest warte ponownego sprawdzania poniewaz nie ma wlasciwego kierunku
			}
			while (Sprawdzanie_Przestrzeni == false);

				//-------------------------------------------------------------------------------------


				TworzenieStrefyBuforu(dlogosc_statku,Plansza,kierunek,x,y);


				// WPISYWANIE STATKU

				for (int i = 0; i < dlogosc_statku; i++)
				{
					if (kierunek == 1) // do gory
					{
						Plansza[y - i][x] = dlogosc_statku;

					}

					if (kierunek == 2) // w prawo
					{
						Plansza[y][x + i] = dlogosc_statku;
					}

					if (kierunek == 3) // w dol
					{
						Plansza[y + i][x] = dlogosc_statku;
					}

					if (kierunek == 4) // w lewo
					{
						Plansza[y][x - i] = dlogosc_statku;
					}
				}

				system("cls");
				WyswietlStatkiDokladnie(Plansza);//do testu
				


		}


	}


















}

void rozmiescStatkiRecznie(int Plansza[10][10])
{
	int ilosc_statkow;
	int x, y;
	int kierunek; // 1gora 2prawo 3dol 4lewo


	for (int dlogosc_statku = 4; dlogosc_statku >= 1; dlogosc_statku--)
	{

		if (dlogosc_statku == 4)
		{
			ilosc_statkow = 1;
		}
		if (dlogosc_statku == 3)
		{
			ilosc_statkow = 2;
		}
		if (dlogosc_statku == 2)
		{
			ilosc_statkow = 3;
		}
		if (dlogosc_statku == 1)
		{
			ilosc_statkow = 4;
		}

		for (ilosc_statkow; ilosc_statkow > 0; ilosc_statkow--)
		{
			bool sprawdzanie_miejsca = false;
			bool sprawdzanie_kierunku = false;


			// Wyswietlanie ekranu na nowo ---
			system("CLS");
			WyswietlStatkiDokladnie(Plansza);
			Instrukcja();
			//--------------------------------

			// WYBIERANIE MIEJSCA
			while (sprawdzanie_miejsca != true)
			{
				system("CLS");
				WyswietlStatkiDokladnie(Plansza);
				Instrukcja();


				// kolumny oznaczamy literami 
				char kolumna;
				int wiersz;
				cout << endl;
				cout << "Typ statku ktory stawiasz -> [" << dlogosc_statku << " - masztowiec]" << endl;
				if(ilosc_statkow!=1)
					cout << "Pozostalo -> [" << ilosc_statkow << "] statki tego typu" << endl;
				else
					cout << "Pozostal " << ilosc_statkow << " statek tego typu" << endl;

				cout << "\nKolumna : ";
				kolumna = _getch();
				cout << kolumna;
				cout << endl;
				cout << "Wiersz : ";
				cin >> wiersz;
				

				if ((((wiersz-1) <= 9) && (0 <= (wiersz-1))) && ((0 <= OznaczenieKolumn(kolumna)) && (OznaczenieKolumn(kolumna) <= 9)))
				{
					if (Plansza[wiersz-1][OznaczenieKolumn(kolumna)] == 0)
					{
						sprawdzanie_miejsca = true;
						x = OznaczenieKolumn(kolumna);
						y = wiersz - 1;
						break;
					}
					else
					{
						cout << "Miejsce jest juz zajete lub niedozwolone !" << endl;
						Sleep(1500);
						
					}
				}
				else
				{
					cout << "Kolumny oznaczamy od A do J a wiersze od 1 do 10 ! Jeszcze raz" << endl;
					Sleep(2900);
					
				}

			}



			// KIERUNEK

			if (dlogosc_statku == 1)
			{

				sprawdzanie_kierunku = true;
			}

			while (sprawdzanie_kierunku != true)
			{
			kierunek_1:
				system("CLS");
				WyswietlStatkiDokladnie(Plansza);
				Instrukcja();
				cout << "Kierunek : ";

				cin >> kierunek;


				//sprawdzanie kierunku 1

				if (kierunek == 1)
				{
					if (y - (dlogosc_statku - 1) < 0)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;

				}


				if (kierunek == 2)
				{
					if (x + (dlogosc_statku - 1) > 9)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}


				if (kierunek == 3)
				{
					if (y + (dlogosc_statku - 1) > 9)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}


				if (kierunek == 4)
				{
					if (x - (dlogosc_statku - 1) < 0)
						sprawdzanie_kierunku = false;
					else
						sprawdzanie_kierunku = true;
				}

				if (sprawdzanie_kierunku == false)
				{
					cout << "Wybrales zly kierunek, sproboj jeszcze raz !";
					Sleep(2500);
				}
			}


			//sprawdzanie kierunku 2

			for (int i = 1; i <= dlogosc_statku - 1; i++)
			{
				if (kierunek == 1) // do gory
				{
					if (Plansza[y - i][x] != 0)
					{
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 2) // w prawo
				{
					if (Plansza[y][x + i] != 0)
					{
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 3) // w dol
				{
					if (Plansza[y + i][x] != 0)
					{
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}

				if (kierunek == 4) // w lewo
				{
					if (Plansza[y][x - i] != 0)
					{
						cout << "W kierunku ktory wybrales znajduja sie pola niedozwolone !";
						Sleep(1500);
						goto kierunek_1;
					}
				}
			}



			// TWORZENIE STREFY BUFOROWEJ
			TworzenieStrefyBuforu(dlogosc_statku, Plansza, kierunek, x, y);

			// WPISYWANIE STATKU

			for (int i = 0; i < dlogosc_statku; i++)
			{
				if (kierunek == 1) // do gory
				{
					Plansza[y - i][x] = dlogosc_statku;



				}

				if (kierunek == 2) // w prawo
				{
					Plansza[y][x + i] = dlogosc_statku;



				}

				if (kierunek == 3) // w dol
				{
					Plansza[y + i][x] = dlogosc_statku;



				}

				if (kierunek == 4) // w lewo
				{
					Plansza[y][x - i] = dlogosc_statku;

				}
			}







		}
	}


	// CZYSZCZENIE KONSOLI Z WIDOKU USTAWIANIA STATKOW PO ZAKONCZENIU

	system("CLS");

}



void WyswietlStatkiObokSiebie(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{
	cout << endl;
	cout << "                   ";
	for (int i = 1; i <= 10; i++)
	{
		cout << " ";
		switch (i)
		{
		case 1:
		{
			cout << "A";
			break;
		}
		case 2:
		{
			cout << "B";
			break;
		}
		case 3:
		{
			cout << "C";
			break;
		}
		case 4:
		{
			cout << "D";
			break;
		}
		case 5:
		{
			cout << "E";
			break;
		}
		case 6:
		{
			cout << "F";
			break;
		}
		case 7:
		{
			cout << "G";
			break;
		}
		case 8:
		{
			cout << "H";
			break;
		}
		case 9:
		{
			cout << "I";
			break;
		}
		case 10:
		{
			cout << "J";
			break;
		}
		default:
			break;
		}
		cout << " ";
	}
	cout << "                  ";

	for (int i = 1; i <= 10; i++)
	{
		cout << " ";
		switch (i)
		{
		case 1:
		{
			cout << "A";
			break;
		}
		case 2:
		{
			cout << "B";
			break;
		}
		case 3:
		{
			cout << "C";
			break;
		}
		case 4:
		{
			cout << "D";
			break;
		}
		case 5:
		{
			cout << "E";
			break;
		}
		case 6:
		{
			cout << "F";
			break;
		}
		case 7:
		{
			cout << "G";
			break;
		}
		case 8:
		{
			cout << "H";
			break;
		}
		case 9:
		{
			cout << "I";
			break;
		}
		case 10:
		{
			cout << "J";
			break;
		}
		default:
			break;
		}
		cout << " ";
	}


	cout << endl;

	for (int i = 0; i < 10; i++)
	{

		//wyswietlanie statkow komputera - po lewej stronie 
		if (i != 9) {
			cout << "               ";
		}
		else
			cout << "              ";

		cout << "[" << i + 1 << "]";
		for (int j = 0; j < 10; j++)
		{
			cout.width(3);

			if (PlanszaKomputera[i][j] != 0 && PlanszaKomputera[i][j] != -1)
			{

				cout << (char)0xFE;

			}
			else {
				cout << (char)0x9E;
			}

		}




		//wyswietlanie statkow gracza - po prawej stronie
		if (i != 9)
		{
			cout << "               ";
		}
		else
			cout << "              ";
		cout << "[" << i + 1 << "]";
		for (int k = 0; k < 10; k++)
		{

			cout.width(3);
			if (PlanszaKomputera[i][k] != 0 && PlanszaKomputera[i][k] != -1)
			{
				cout << (char)0xFE;

			}
			else {
				cout << (char)0x9E;
			}

		}


		cout << endl;
	}



}

// Zagraj albo wyjdz z gry
int EkranStartowy()
{
	int CzyStart = 0;

	while (CzyStart != 1 && CzyStart != 2)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(90);

		cout << "Gra W Statki by Dominik  \"domixx\" Szczepanik,  VERSION 1.00 | 2021" << endl;

		cout.width(90);
		cout << "------------------------------------------------------------------" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << endl;
		}
		cout.width(60);

		cout << "1 - ZAGRAJ" << endl;


		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(61);
		cout << "2 - ZAKONCZ";
		CzyStart = _getch();
		switch (CzyStart)
		{
		case '1':
		{
			CzyStart = 1;
			break;
		}
		case '2':
		{
			CzyStart = 2;
			break;
		}

		default:
			break;
		}
		system("cls");
	}

	return CzyStart;
}

// Pytanie o ustawianie wlasnej planszy statkami (losowo lub recznie)
int EkranStartowy2()
{
	int Odpowiedz = 0;

	while (Odpowiedz != 1 && Odpowiedz != 2) {

		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(90);
		cout << "Chcesz rozmiescic swoje statki automatycznie czy wlasnorecznie ? ";
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(65);


		cout << "1 - AUTOMATYCZNIE " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << endl;
		}
		cout.width(65);


		cout << "2 - WLASNORECZNIE " << endl;


		Odpowiedz = _getch();

		switch (Odpowiedz)
		{
		case '1':
		{
			Odpowiedz = 1;
			break;
		}
		case '2':
		{
			Odpowiedz = 2;
			break;
		}

		default:
			break;
		}


		system("cls");
	}


	return Odpowiedz;

}


// Ekran podczas wlasciwej rozgrywki
void EkranGry(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{
	//naglowki


	cout << "               ";
	for (int i = 0; i < 35; i++)
	{
		cout << "-";
	}

	cout << "             ";
	for (int i = 0; i < 35; i++)
	{
		cout << "-";
	}


	cout << endl;
	cout << "               ";
	cout << "|";
	cout << "         ";
	cout << "Plansza Komputera";
	cout << "       ";
	cout << "|";
	cout << "             ";
	cout << "|";
	cout << "         ";
	cout << "Plansza Gracza";
	cout << "          ";
	cout << "|";
	cout << endl;
	cout << "               ";
	for (int i = 0; i < 35; i++)
	{
		cout << "-";
	}
	cout << "             ";
	for (int i = 0; i < 35; i++)
	{
		cout << "-";
	}
	cout << endl;

	//WyswietlStatkiObokSiebie(PlanszaGracza,PlanszaGracza);

	WyswietlStatkiDokladnie(PlanszaGracza);


}




// GRA - Gra W Statki
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
void gra(int PlanszaGracza[10][10], int PlanszaKomputera[10][10])
{

	// ekranstarwowy=1 (graj) | ekranstartowy=2 (wyjdz z gry)
	if (EkranStartowy() == 2)
		exit(1);

	// ekranstartowy2=1 (rozmiesc swoje statki losowo) | ekranstartowy2=2 (rozmiesc swoje statki recznie)
	if (EkranStartowy2() == 1)
	{
		rozmiescStatkiAutomatycznie(PlanszaGracza);
	}
	else
	{
		rozmiescStatkiRecznie(PlanszaGracza);
	}
		
	// TU ROZMIESC STATKI AUTOMATYCZNIE KOMPUTERA <<<<<
	
	EkranGry(PlanszaGracza, PlanszaGracza);















}



// w main tylko wywolujemy gre i przekazujemy jej odpowiednie parametry
int main()
{
	int PlanszaKomputera[10][10]{};
	int PlanszaGracza[10][10]{};



	// FUNKCJA GRY W STATKI 

	gra(PlanszaGracza, PlanszaKomputera);




	system("pause");
}