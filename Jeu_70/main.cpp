/*
1)
Efface l'écran

2)
Affiche un écran d'accueil

3) 
Lance le programme

  ##########    IA          0
  0123456789    HUMAIN      0
  ----------
0|          
1|          
2| WELCOME  
3|          
4|          
  ##########
  Joueur Humain x, y : 2,3

Le jeu va faire un random de 9 chiffres qu'il va mettre partout sur la grille et les cacher sur la grille de jeu.

Quand un jour tombe sur une coordonnée juste, il gagne le nombre de point affiché.
L'IA joue aussi aléatoirement.
Il est impossible de rejouer une case déjà jouée

Le gagnant est celui qui arrive le premier à la moitié + 1 de la somme des nombres en jeu. (23)
A chaque fois qu'un joueur joue, la ligne du bas est complètement réecrite.

Utiliser des couleurs pour les 0 et de plus en plus chaud quand on arrive à 9
*/

#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <windows.h>
#include <iomanip>
#include <ctype.h>
using namespace std;

// Déplacement du curseur
void gotoxy(HANDLE h, int x, int y){
    COORD c;
    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

// Affichage du chiffre en lui attribuant une couleur
void printNumber(HANDLE d, int nombre)
{
    switch (nombre)
    {
        case 0:
            SetConsoleTextAttribute(d, 15);
            break;
        case 1:
            SetConsoleTextAttribute(d, 8);
            break;
        case 2:
            SetConsoleTextAttribute(d, 1);
            break;
        case 3:
            SetConsoleTextAttribute(d, 3);
            break;
        case 4:
            SetConsoleTextAttribute(d, 11);
            break;
        case 5:
            SetConsoleTextAttribute(d, 10);
            break;
        case 6:
            SetConsoleTextAttribute(d, 14);
            break;
        case 7:
            SetConsoleTextAttribute(d, 6);
            break;
        case 8:
            SetConsoleTextAttribute(d, 12);
            break;
        case 9:
            SetConsoleTextAttribute(d, 4);
            break;
    }

    cout << nombre;
    SetConsoleTextAttribute(d, 15);

}

void magnifiqueAurevoir(HANDLE d){
    /*
   00000000001
   01234567890
13 * & * & * &                                                   
14  VICTOIRE! 
15 & * & * & *
    */

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 0, 13);
    cout << "*";
    gotoxy(d, 2, 15);
    cout << "*";
    gotoxy(d, 8, 13);
    cout << "*";
    gotoxy(d, 10, 15);
    cout << "*";
    gotoxy(d, 4, 13);
    cout << "*";
    gotoxy(d, 6, 15);
    cout << "*";

    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    gotoxy(d, 0, 13);
    cout << " ";
    gotoxy(d, 2, 15);
    cout << " ";
    gotoxy(d, 8, 13);
    cout << " ";
    gotoxy(d, 10, 15);
    cout << " ";
    gotoxy(d, 4, 13);
    cout << " ";
    gotoxy(d, 6, 15);
    cout << " ";

    SetConsoleTextAttribute(d, 13);

    gotoxy(d, 0, 15);
    cout << "*";
    gotoxy(d, 2, 13);
    cout << "*";
    gotoxy(d, 4, 15);
    cout << "*";
    gotoxy(d, 6, 13);
    cout << "*";
    gotoxy(d, 8, 15);
    cout << "*";
    gotoxy(d, 10, 13);
    cout << "*";

    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    gotoxy(d, 0, 15);
    cout << " ";
    gotoxy(d, 2, 13);
    cout << " ";
    gotoxy(d, 4, 15);
    cout << " ";
    gotoxy(d, 6, 13);
    cout << " ";
    gotoxy(d, 8, 15);
    cout << " ";
    gotoxy(d, 10, 13);
    cout << " ";

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 0, 13);
    cout << "*";
    gotoxy(d, 2, 15);
    cout << "*";
    gotoxy(d, 8, 13);
    cout << "*";
    gotoxy(d, 10, 15);
    cout << "*";
    gotoxy(d, 4, 13);
    cout << "*";
    gotoxy(d, 6, 15);
    cout << "*";

    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    gotoxy(d, 0, 13);
    cout << " ";
    gotoxy(d, 2, 15);
    cout << " ";
    gotoxy(d, 8, 13);
    cout << " ";
    gotoxy(d, 10, 15);
    cout << " ";
    gotoxy(d, 4, 13);
    cout << " ";
    gotoxy(d, 6, 15);
    cout << " ";

    SetConsoleTextAttribute(d, 13);
    gotoxy(d, 0, 15);
    cout << "*";
    gotoxy(d, 2, 13);
    cout << "*";
    gotoxy(d, 4, 15);
    cout << "*";
    gotoxy(d, 6, 13);
    cout << "*";
    gotoxy(d, 8, 15);
    cout << "*";
    gotoxy(d, 10, 13);
    cout << "*";


    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    gotoxy(d, 0, 15);
    cout << " ";
    gotoxy(d, 2, 13);
    cout << " ";
    gotoxy(d, 4, 15);
    cout << " ";
    gotoxy(d, 6, 13);
    cout << " ";
    gotoxy(d, 8, 15);
    cout << " ";
    gotoxy(d, 10, 13);
    cout << " ";

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 0, 13);
    cout << "*";
    gotoxy(d, 2, 15);
    cout << "*";
    gotoxy(d, 8, 13);
    cout << "*";
    gotoxy(d, 10, 15);
    cout << "*";
    gotoxy(d, 4, 13);
    cout << "*";
    gotoxy(d, 6, 15);
    cout << "*";

    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    gotoxy(d, 0, 13);
    cout << " ";
    gotoxy(d, 2, 15);
    cout << " ";
    gotoxy(d, 8, 13);
    cout << " ";
    gotoxy(d, 10, 15);
    cout << " ";
    gotoxy(d, 4, 13);
    cout << " ";
    gotoxy(d, 6, 15);
    cout << " ";

    SetConsoleTextAttribute(d, 13);
    gotoxy(d, 0, 15);
    cout << "*";
    gotoxy(d, 2, 13);
    cout << "*";
    gotoxy(d, 4, 15);
    cout << "*";
    gotoxy(d, 6, 13);
    cout << "*";
    gotoxy(d, 8, 15);
    cout << "*";
    gotoxy(d, 10, 13);
    cout << "*";

    gotoxy(d, 1, 14);
    cout << "VICTOIRE!";
    Sleep(500);

    SetConsoleTextAttribute(d, 15);
}

// Affichage du message de bienvenue
void magnifiqueBonjour(HANDLE d)
{

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 2, 4);
    cout << "*";
    gotoxy(d, 2, 6);
    cout << "*";
    gotoxy(d, 10, 4);
    cout << "*";
    gotoxy(d, 10, 6);
    cout << "*";
    gotoxy(d, 6, 4);
    cout << "*";
    gotoxy(d, 6,6);
    cout << "*";

    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    gotoxy(d, 2, 4);
    cout << " ";
    gotoxy(d, 2, 6);
    cout << " ";
    gotoxy(d, 10, 4);
    cout << " ";
    gotoxy(d, 10, 6);
    cout << " ";
    gotoxy(d, 6, 4);
    cout << " ";
    gotoxy(d, 6, 6);
    cout << " ";

    SetConsoleTextAttribute(d, 13);

    gotoxy(d, 4, 4);
    cout << "*";
    gotoxy(d, 4, 6);
    cout << "*";
    gotoxy(d, 8, 4);
    cout << "*";
    gotoxy(d, 8, 6);
    cout << "*";
    gotoxy(d, 2, 5);
    cout << "*";
    gotoxy(d, 10, 5);
    cout << "*";

    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    gotoxy(d, 4, 4);
    cout << " ";
    gotoxy(d, 4, 6);
    cout << " ";
    gotoxy(d, 8, 4);
    cout << " ";
    gotoxy(d, 8, 6);
    cout << " ";
    gotoxy(d, 2, 5);
    cout << " ";
    gotoxy(d, 10, 5);
    cout << " ";

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 2, 4);
    cout << "*";
    gotoxy(d, 2, 6);
    cout << "*";
    gotoxy(d, 10, 4);
    cout << "*";
    gotoxy(d, 10, 6);
    cout << "*";
    gotoxy(d, 6, 4);
    cout << "*";
    gotoxy(d, 6, 6);
    cout << "*";

    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    gotoxy(d, 2, 4);
    cout << " ";
    gotoxy(d, 2, 6);
    cout << " ";
    gotoxy(d, 10, 4);
    cout << " ";
    gotoxy(d, 10, 6);
    cout << " ";
    gotoxy(d, 6, 4);
    cout << " ";
    gotoxy(d, 6, 6);
    cout << " ";

    SetConsoleTextAttribute(d, 13);
    gotoxy(d, 4, 4);
    cout << "*";
    gotoxy(d, 4, 6);
    cout << "*";
    gotoxy(d, 8, 4);
    cout << "*";
    gotoxy(d, 8, 6);
    cout << "*";
    gotoxy(d, 2, 5);
    cout << "*";
    gotoxy(d, 10, 5);
    cout << "*";


    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    
    gotoxy(d, 4, 4);
    cout << " ";
    gotoxy(d, 4, 6);
    cout << " ";
    gotoxy(d, 8, 4);
    cout << " ";
    gotoxy(d, 8, 6);
    cout << " ";
    gotoxy(d, 2, 5);
    cout << " ";
    gotoxy(d, 10, 5);
    cout << " ";

    SetConsoleTextAttribute(d, 10);
    gotoxy(d, 2, 4);
    cout << "*";
    gotoxy(d, 2, 6);
    cout << "*";
    gotoxy(d, 10, 4);
    cout << "*";
    gotoxy(d, 10, 6);
    cout << "*";
    gotoxy(d, 6, 4);
    cout << "*";
    gotoxy(d, 6, 6);
    cout << "*";

    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    gotoxy(d, 2, 4);
    cout << " ";
    gotoxy(d, 2, 6);
    cout << " ";
    gotoxy(d, 10, 4);
    cout << " ";
    gotoxy(d, 10, 6);
    cout << " ";
    gotoxy(d, 6, 4);
    cout << " ";
    gotoxy(d, 6, 6);
    cout << " ";

    SetConsoleTextAttribute(d, 13);
    gotoxy(d, 4, 4);
    cout << "*";
    gotoxy(d, 4, 6);
    cout << "*";
    gotoxy(d, 8, 4);
    cout << "*";
    gotoxy(d, 8, 6);
    cout << "*";
    gotoxy(d, 2, 5);
    cout << "*";
    gotoxy(d, 10, 5);
    cout << "*";

    gotoxy(d, 3, 5);
    cout << "WELCOME";
    Sleep(500);

    SetConsoleTextAttribute(d, 15);

    gotoxy(d, 2, 4);
    cout << " ";
    gotoxy(d, 2, 5);
    cout << "         ";
    gotoxy(d, 2, 6);
    cout << " ";
    gotoxy(d, 4, 4);
    cout << " ";
    gotoxy(d, 4, 6);
    cout << " ";
    gotoxy(d, 6, 4);
    cout << " ";
    gotoxy(d, 6, 6);
    cout << " ";
    gotoxy(d, 8, 4);
    cout << " ";
    gotoxy(d, 8, 6);
    cout << " ";
    gotoxy(d, 10, 4);
    cout << " ";
    gotoxy(d, 10, 6);
    cout << " ";

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
    COORD tabCoords[taille] = {};
    int x(0), y(0), scoreJ1(0), scoreIa(0);

    COORD shoot;
    int charRead = 0;
    DWORD useless;
    bool isOk = false;

    // Efface le contenur de la console
    system("cls");

    // Génération des coordonnées des chiffres de 1 à 9
    for(int i=0; i<taille; i++){
        tab[i] = i+1;
        tabCoords[i].X = maxX(moteur);
        tabCoords[i].Y = maxY(moteur);

        for (int j = 0; j < i; j++)
        {
            if (tabCoords[i].X == tabCoords[j].X && tabCoords[i].Y == tabCoords[j].Y)
                i--;
        }
    }

    // Affiche le plateau de jeu
    for(int i=0; i<largeur; i++){
        gotoxy(d, i, 0);
        cout << '#';

        if (i >= 2)
        {
            gotoxy(d, i, 1);
            cout << i-2;
            gotoxy(d, i, 2);
            cout << '-';
        }

        if(i<8 && i>=3){
            gotoxy(d, 0, i);
            cout << i-3 << '|';
        }

        gotoxy(d, i, 8);
        cout << '#';
    }

    // Affichage de l'écran d'accueil
    magnifiqueBonjour(d);

    // Affichage du score
    gotoxy(d, 15,0);
    cout << "IA";
    gotoxy(d, 15, 1);
    cout << "HUMAIN";
    gotoxy(d, 25, 0);
    cout << scoreIa;
    gotoxy(d, 25, 1);
    cout << scoreJ1;


    while (scoreJ1 < SCORE_VICTOIRE && scoreIa < SCORE_VICTOIRE)
    {
        isOk = false;

        // Joueur humain
        do {
            gotoxy(d, 0, 9);
            cout << "                                       ";
            gotoxy(d, 0, 9);
            cout << "Joueur Humain x, y : ";
            cin >> x >> y;
            
            shoot.X = x + 2;
            shoot.Y = y + 3;

            if (shoot.X>11 || shoot.X < 2 || shoot.Y > 7 || shoot.Y < 3){
                continue;
            }
            
            // On traite les coordonnées
            if (ReadConsoleOutputCharacter(d, (LPTSTR)&charRead, 1, shoot, (LPDWORD)&useless) != 0)
            {
                //if (charRead == " " || charRead == "" || charRead == NULL)
                if (!isdigit(charRead))
                {
                    // Chiffre trouvé
                    for (int i = 0; i < taille; i++)
                    {
                        if (tabCoords[i].X == shoot.X && tabCoords[i].Y == shoot.Y)
                        {
                            gotoxy(d, shoot.X, shoot.Y);
                            printNumber(d, tab[i]);

                            isOk = true;
                            scoreJ1 += tab[i];
                            break;
                        }
                    }
                    
                    // Chiffre non trouvé
                    if (!isOk)
                    {
                        gotoxy(d, shoot.X, shoot.Y);
                        printNumber(d, 0);
                        isOk = true;
                    }
                }
            }

        } while (!isOk);

        // Affichage du score
        /*gotoxy(d, 15, 0);
        cout << "IA";
        gotoxy(d, 15, 1);
        cout << "HUMAIN";*/
        gotoxy(d, 25, 0);
        cout << scoreIa;
        gotoxy(d, 25, 1);
        cout << scoreJ1;

        gotoxy(d, 0, 10);

        // On attend pour permettre la lecture
        Sleep(1000);

        // On efface l'affichage
        gotoxy(d, 0, 9);
        cout << "                                            ";
        isOk = false;

        // Joueur IA
        do
        {
            gotoxy(d, 0, 9);
            x = maxX(moteur);
            y = maxY(moteur);
            cout << "Joueur IA x, y : " << x-2 << " " << y-3;

            shoot.X = x;
            shoot.Y = y;

            // On traite les coordonnées
            if (ReadConsoleOutputCharacter(d, (LPTSTR)&charRead, 1, shoot, (LPDWORD)&useless) != 0)
            {
                //if (charRead == " " || charRead == "" || charRead == NULL)
                if (!isdigit(charRead))
                {
                    // Chiffre trouvé
                    for (int i = 0; i < taille; i++)
                    {
                        if (tabCoords[i].X == shoot.X && tabCoords[i].Y == shoot.Y)
                        {
                            gotoxy(d, shoot.X, shoot.Y);
                            printNumber(d, tab[i]);

                            isOk = true;
                            scoreIa += tab[i];
                            break;
                        }
                    }

                    // Chiffre non trouvé
                    if (!isOk)
                    {
                        gotoxy(d, shoot.X, shoot.Y);
                        printNumber(d, 0);
                        isOk = true;
                    }
                }
            }

        } while (!isOk);

        // Affichage du score
        /*gotoxy(d, 15, 0);
        cout << "IA";
        gotoxy(d, 15, 1);
        cout << "HUMAIN";*/
        gotoxy(d, 25, 0);
        cout << scoreIa;
        gotoxy(d, 25, 1);
        cout << scoreJ1;

        gotoxy(d, 0, 10);

        // On attend pour permettre la lecture
        Sleep(1000);

        // On efface l'affichage
        gotoxy(d, 0, 9);
        cout << "                                            ";

    }

    // On affiche qui gagne
    gotoxy(d, 0, 14);
    if (scoreJ1 > scoreIa)
    {
        magnifiqueAurevoir(d);
    }
    else
    {
        cout << "Aie, coup dur pour Guillaume..." << endl;
        cout << "Allez Guillaume, il faut surtout pas se laisser abattre, la soiree ne fait que commencer.";
    }

    // On attend que l'utilisateur veuille quitter le programme
    gotoxy(d, 0, 16);
    system("pause");
    return 0;
}
