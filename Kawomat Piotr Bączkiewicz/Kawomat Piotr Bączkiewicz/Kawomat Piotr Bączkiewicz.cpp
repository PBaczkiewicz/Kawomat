#include <windows.h>
#include <time.h>
#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_CTYPE, "Polish");	//polskie znaki
	int wybor, zaplata, opcja = 0;
	float cena = 0;
	char kawa[10][8];



	do {
		do {
			system("Cls");

			std::cout << "Kawomat \"Golnij se\"\nautor : Piotr Bączkiewicz\nWybierz napój:\n1)Cappuccino z czekoladą 5 zł\n2)Espresso 8 zł\n3)Mała czarna 5 zł\n4)Duża czarna 7 zł\n5)Duża z mlekiem 7 zł\n6)Mała z mlekiem 5 zł\n7)Rozpuszczalna 4 zł\n8)Gorąca czekolada 8 zł\n9)Herbata 4 zł.\n\nCukier 0,50zł za 5g\n";
			if (cena < 0)
			{
				std::cout << "Stan konta :" << abs(cena);
			}
			std::cout << ">>";
			std::cin >> wybor;

			switch (wybor)
			{
			case 1:
				cena += 5;
				break;
			case 2:
				cena += 8;
				break;
			case 3:
				cena += 5;
				break;
			case 4:
				cena += 7;
				break;
			case 5:
				cena += 7;
				break;
			case 6:
				cena += 5;
				break;
			case 7:
				cena += 4;
				break;
			case 8:
				cena += 8;
				break;
			case 9:
				cena += 4;
				break;
			default:
				std::cout << "\nBłędny wybór\n";
				system("Pause");
			}
		} while (!(wybor > 0 && wybor < 10));
		int cukier;
		do {
			system("Cls");
			std::cout << "Dodać cukru? (0,50 zł za 5g)\n1)Tak\n2)Nie\n>>";
			std::cin >> cukier;
			switch (cukier)
			{
			case 1:
				cena += 0.50;
				break;
			case 2:
				break;
			default:
				std::cout << "\nBłędna opcja.\n";
			}
		} while (cukier != 2);

		if (cena > 0)
		{
			do {
				system("Cls");
				std::cout << "Do zapłaty zostało :" << cena << " zł.";
				std::cout << "\nWrzuć monetę.\n1)5 zł.\n2)2 zł.\n3)1 zł.\n4)0.50 zł.\n5)0.20 zł.\n6)0.10 zł.\n7)Płatność banknotami.\n8)Płatność kartą.\n9)Płatność telefonem(NFC).\n>>";
				std::cin >> zaplata;
				switch (zaplata)
				{
				case 1:
					cena -= 5;
					break;
				case 2:
					cena -= 2;
					break;
				case 3:
					cena -= 1;
					break;
				case 4:
					cena -= 0.5;
					break;
				case 5:
					cena -= 0.2;
					break;
				case 6:
					cena -= 0.1;
					break;
				case 7:
					int banknot;
					std::cout << "\nWprowadź banknot.\n1)20 zł.\n2)10 zł.\n>>";
					std::cin >> banknot;
					switch (banknot)
					{
					case 1:
						cena -= 20;
						break;
					case 2:
						cena -= 10;
						break;
					default:
						std::cout << "\nNiepoprawny banknot.\nSpróbuj ponownie.\n";
						system("Pause");
					}
					break;
				case 8:
				case 9:
					Beep(1567, 1000);
					std::cout << "\nPrzyjęto płatność!\n";
					Sleep(1500);
					cena = 0;
					break;
				default:
					std::cout << "\nNie rozpoznano monety!\nWrzuć jedną z poniższych monet";


				}
			} while (cena > 0);
		}
		for (int i = 0; i < 8; i++)
		{
			kawa[0][i] = '^';
			kawa[9][i] = '=';
		}


		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 7; j++)
			{
				kawa[i][j] = ' ';
			}
			std::cout << "\n";

		}
		for (int i = 1; i < 10; i++)
		{
			kawa[i][0] = '|';
			kawa[i][7] = '|';

		}
		int lanieKawy = 9;
		do {
			system("Cls");
			//kubek do kawy
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					std::cout << kawa[i][j];
				}
				std::cout << "\n";

			}
			for (int i = 1; i < 7; i++)
			{
				kawa[lanieKawy - 1][i] = '~';
			}
			lanieKawy--;
			Sleep(1000);
		} while (lanieKawy > 0);

		std::cout << "Smacznej ";
		switch (wybor)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			std::cout << "kawusi.";
			break;
		case 9:
			std::cout << "herbatki.";
			break;
		case 8:
			std::cout << "czekoladki.";
			break;
		}
		Sleep(1000);
		std::cout << "\nCzy chcesz kolejny napój?\n1)Tak\n2)Nie\n>>";
		std::cin >> opcja;
	} while (opcja == 1);
	if (cena != 0)
	{
		std::cout << "\nWydano " << abs(cena) << " zł reszty.\n";
	}
	system("Pause");
	return 0;

}