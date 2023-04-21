/*
* 1)
* Efface l'écran

* 2)
* ##########################################################
*
*
*
*
*
*                  Welcome in my game
*
*
*
*
*
*
* ###########################################################
*
* 3) Lance
*
  ##########    IA          0
  0123456789    HUMAIN      0
  ----------
0|                                                               
1|                                                            
2| WELCOME
3|   
4|
  ##########
* Joueur Humain x, y : 2,3
*
*
* Le jeux va faire un random de 9 chiffres qu'il va mettre partout sur la grille et les cacher sur la grille de jeux
*
* quand un jour tombe sur une coordonnée juste il gagne le nombre de point affiché
*
* L'IA joue aussi aleatoirement
*
* Il est impossible de rejouer une case deja joué
*
*
* Le gagnant est celui qui arrive le premier à la moitié + 1 de la moyenne de la somme des nombres en jeu. (23)
*
*
* A chaque qu'un jouer joue la ligne du bas est complement reecrite
*
* Utilisé des couleurs pour les 0 et de plus en plus chaud quand on arrive à 9
* ****************************
*/

#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <windows.h>
#include <iomanip>
#include <ctype.h>
using namespace std;

void gotoxy(int x, int y){
    COORD c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

void printNumber(HANDLE d, int nombre)
{
    switch (nombre)
    {
        case 0:
            SetConsoleTextAttribute(d, 15);
            break;
        case 1:
            SetConsoleTextAttribute(d, 14);
            break;
        case 2:
            SetConsoleTextAttribute(d, 13);
            break;
        case 3:
            SetConsoleTextAttribute(d, 12);
            break;
        case 4:
            SetConsoleTextAttribute(d, 11);
            break;
        case 5:
            SetConsoleTextAttribute(d, 9);
            break;
        case 6:
            SetConsoleTextAttribute(d, 8);
            break;
        case 7:
            SetConsoleTextAttribute(d, 7);
            break;
        case 8:
            SetConsoleTextAttribute(d, 6);
            break;
        case 9:
            SetConsoleTextAttribute(d, 5);
            break;
    }

    cout << nombre;
    SetConsoleTextAttribute(d, 15);

}

int main()
{
    default_random_engine moteur(time(0));
    uniform_int_distribution<int> maxX{ 2, 11 };
    uniform_int_distribution<int> maxY{ 3, 7 };
    HANDLE d = GetStdHandle(STD_OUTPUT_HANDLE);

    const int taille = 9;
    const int largeur = 12;
    const int longueur = 9;
    const int SCORE_VICTOIRE = 23;

    int tab[taille] = {};
    COORD tabCoords[taille];
    int x(0), y(0), scoreJ1(0), scoreIa(0);

    COORD shoot;
    int charRead = 0;
    DWORD useless;
    bool isOk = false;

    // Efface le contenur de la console
    system("cls");

    // Affiche le plateau de jeu

    for(int i=0; i<taille; i++){
        tab[i] = i+1;
        tabCoords[i].X = maxX(moteur);
        tabCoords[i].Y = maxY(moteur);
    }

    for(int i=0; i<largeur; i++){
        gotoxy(i, 0);
        cout << '#';

        if (i >= 2)
        {
            gotoxy(i, 1);
            cout << i-2;
            gotoxy(i, 2);
            cout << '-';
        }

        if(i<8 && i>=3){
            gotoxy(0, i);
            cout << i-3 << '|';
        }

        gotoxy(i, 8);
        cout << '#';
    }

    SetConsoleTextAttribute(d, 10);
    gotoxy(3, 5);
    cout << "WELCOME";

    //Sleep(3000);
    Sleep(1000);
    SetConsoleTextAttribute(d, 15);

    gotoxy(3, 5);
    cout << "       ";

    gotoxy(15,0);
    cout << "IA";
    gotoxy(15, 1);
    cout << "HUMAIN";
    gotoxy(25, 0);
    cout << scoreIa;
    gotoxy(25, 1);
    cout << scoreJ1;


    while (scoreJ1 < SCORE_VICTOIRE && scoreIa < SCORE_VICTOIRE)
    {
        isOk = false;

        // Joueur humain
        do {
            gotoxy(0, 9);
            cout << "                                       ";
            gotoxy(0, 9);
            cout << "Joueur Humain x, y : ";
            cin >> x >> y;
            
            shoot.X = x + 2;
            shoot.Y = y + 3;
            
            // On traite les coordonnées
            if (ReadConsoleOutputCharacter(d, (LPTSTR)&charRead, 1, shoot, (LPDWORD)&useless) != 0)
            {
                //if (charRead == " " || charRead == "" || charRead == NULL)
                if (!isdigit(charRead))
                {
                    for (int i = 0; i < taille; i++)
                    {
                        if (tabCoords[i].X == shoot.X && tabCoords[i].Y == shoot.Y)
                        {
                            gotoxy(shoot.X, shoot.Y);
                            printNumber(d, tab[i]);

                            isOk = true;
                            scoreJ1 += tab[i];
                            break;
                        }
                    }
                    
                    if (!isOk)
                    {
                        gotoxy(shoot.X, shoot.Y);
                        printNumber(d, 0);
                        isOk = true;
                    }
                }
            }

        } while (!isOk);

        gotoxy(15, 0);
        cout << "IA";
        gotoxy(15, 1);
        cout << "HUMAIN";
        gotoxy(25, 0);
        cout << scoreIa;
        gotoxy(25, 1);
        cout << scoreJ1;

        gotoxy(0, 10);

        // On attend pour permettre la lecture
        Sleep(500);

        // On efface l'affichage
        gotoxy(0, 9);
        cout << "                                            ";
        isOk = false;

        // Joueur IA
        do
        {
            gotoxy(0, 9);
            x = maxX(moteur);
            y = maxY(moteur);
            cout << "Joueur IA x, y : " << x << " " << y;

            shoot.X = x;
            shoot.Y = y;

            // On traite les coordonnées
            if (ReadConsoleOutputCharacter(d, (LPTSTR)&charRead, 1, shoot, (LPDWORD)&useless) != 0)
            {
                //if (charRead == " " || charRead == "" || charRead == NULL)
                if (!isdigit(charRead))
                {
                    for (int i = 0; i < taille; i++)
                    {
                        if (tabCoords[i].X == shoot.X && tabCoords[i].Y == shoot.Y)
                        {
                            gotoxy(shoot.X, shoot.Y);
                            printNumber(d, tab[i]);

                            isOk = true;
                            scoreIa += tab[i];
                            break;
                        }
                    }

                    if (!isOk)
                    {
                        gotoxy(shoot.X, shoot.Y);
                        printNumber(d, 0);
                        isOk = true;
                    }
                }
            }

        } while (!isOk);

        gotoxy(15, 0);
        cout << "IA";
        gotoxy(15, 1);
        cout << "HUMAIN";
        gotoxy(25, 0);
        cout << scoreIa;
        gotoxy(25, 1);
        cout << scoreJ1;

        gotoxy(0, 10);

        // On attend pour permettre la lecture
        Sleep(500);

        // On efface l'affichage
        gotoxy(0, 9);
        cout << "                                            ";

    }
    

    
    gotoxy(0, 15);
    cout << " ";
    system("pause");
    return 0;
}
