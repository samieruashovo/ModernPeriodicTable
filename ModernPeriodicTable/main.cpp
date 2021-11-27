#include <iostream>
//#include <fstream>
#include <string.h>
#include <conio.h>
#include<windows.h>

using namespace std;
FILE *fp;
char another, choice;
int i,j,g,t;

void gotoxy(short x, short y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct atm
{
    char aname[40];
    int an;
    int aen;
    char symbol[5];
};

struct atm a;
char aname[40];
int an;
char symbol[5];


long int recsize;
void element(int i, int j);
void frame();
void display();
//void input();
void output();
int main()
{


    fp = fopen("atom1.DAT", "rb+");
    if (fp == NULL)
    {
        fp = fopen("atom1.DAT", "wb+");
        if (fp == NULL)
        {
            printf("Connot open file");
            exit(1);
        }
    }
    recsize = sizeof(a);
    // input();
    display();


    return 0;
}
/*
void input()
{
    cout <<" \n  ::::::::::::::::::::::::::  Input element info :::::::::::::::::::::::::: \n";
    fseek(fp, 0, SEEK_END); /// search the file and move cursor to end of the file
    /// here 0 indicates moving 0 distance from the end of the file
    int anfound = 0;
    another = 'y';
    int ch = 'n';
    while (another == 'y')
    {
        anfound = 0;
        rewind(fp);
        if (another == 'y')
        {
            cout <<"atm number"<<endl;
            cin >> an;
            while (fread( & a, recsize, 1, fp) == 1) /// fetch all record from file
            {

                if (a.an == an)
                {

                    cout <<"Element already exists"<<endl;
                    ch = getche();
                    anfound = 1;
                    break;
                }

            }
        }

        if (anfound == 1 && ch == 'n') continue;
        if (anfound == 1 && ch == 'y')
        {

        }

        fseek(fp, 0, SEEK_END);
        a.an = an;

        if (another == 'n')
        {
        }
       cout<< "Enter name: ";
       cin>> a.aname ;
       cout << "Enter  Atomic Radius(pm): ";
       cin>> a.aen;
       cout<< "Enter symbol:";
       cin>> a.symbol;

        fwrite( & a, recsize, 1, fp); /// write the record in the file

       cout <<"\nAdd another recording(y/n)";
       cout <<"\npress e for exit";
        fflush(stdin);
        another = getche();
        if(another=='e')
        {
            system("cls");
            display();
        }
    }

}
*/

void output()
{
    system("cls");
    system("color 74");
    cout<<" \n\t\t\t ::::::::::::::::::::::::::  Element Info  :::::::::::::::::::::::::: \n";
    while ( 1)
    {
        rewind(fp);
        bool found = false;
        while (fread( & a, recsize, 1, fp) == 1) // fetch all record from file
        {
            if (a.an == an)
            {

                gotoxy(45,5);
                cout<<"Name : ";
                cout<< a.aname;

                gotoxy(45,7);
                cout<<"Atomic No : ";
                cout<< a.an;

                gotoxy(45,9);
                cout<<"Atomic Radius(pm) :";
                cout<<a.aen ;

                gotoxy(45,11);
                cout<<"Symbol: ";
                cout<< a.symbol;

                found = true;
                break;
            }
        }

        if (found == false)
        {
            printf("Sorry,The Element is not found.Please enter the correct id...");
        }
        gotoxy(45, 13);
        cout<<"Enter e for exit";
        fflush(stdin);

        another = getche();
        if(another=='e')
        {
            system("cls");
            display();
        }

    }
}
void frame()
{
    gotoxy(6,1);
    cout<<"#";
    for(i=6; i<=74; i++)
    {
        gotoxy(i,1);
        cout<<"#";
    }
    gotoxy(14,25);
    cout<<"#";
    for(i=6; i<=74; i++)
    {
        gotoxy(i,25);
        cout<<"#";
    }
    for(i=2; i<=24; i++)
    {
        gotoxy(74,i);
        cout<<"#";
    }
    for(i=2; i<=24; i++)
    {
        gotoxy(6,i);
        cout<<"#";
    }

}

void display()
{
    system("cls");
    system("color 71");
    frame();
    gotoxy(33,2);
    cout<<"PERIODIC TABLE";
    gotoxy(6,26);
    cout<<"USE ARROWS TO SCROLL. ENTER TO SELECT. ESC TO EXIT. S TO QUICK SEARCH";


    gotoxy(13,5);
    cout<<"H";
    gotoxy(13,7);
    cout<<"Li";
    gotoxy(13,9);
    cout<<"Na";
    gotoxy(13,11);
    cout<<"K";
    gotoxy(13,13);
    cout<<"Rb";
    gotoxy(13,15);
    cout<<"Cs";
    gotoxy(13,17);
    cout<<"Fr";
    gotoxy(16,7);
    cout<<"Be";
    gotoxy(16,9);
    cout<<"Mg";
    gotoxy(16,11);
    cout<<"Ca";
    gotoxy(16,13);
    cout<<"Sr";
    gotoxy(16,15);
    cout<<"Ba";
    gotoxy(16,17);
    cout<<"Ra";
    gotoxy(19,11);
    cout<<"Sc";
    gotoxy(19,13);
    cout<<"Y";
    gotoxy(19,15);
    cout<<"La";
    gotoxy(19,17);
    cout<<"Ac";
    gotoxy(22,11);
    cout<<"Ti";
    gotoxy(22,13);
    cout<<"Zr";
    gotoxy(22,15);
    cout<<"Hf";
    gotoxy(22,17);
    cout<<"Rf";
    gotoxy(25,11);
    cout<<" V";
    gotoxy(25,13);
    cout<<"Nb";
    gotoxy(25,15);
    cout<<"Ta";
    gotoxy(25,17);
    cout<<"Db";
    gotoxy(28,11);
    cout<<"Cr";
    gotoxy(28,13);
    cout<<"Mo";
    gotoxy(28,15);
    cout<<"W";
    gotoxy(28,17);
    cout<<"Sg";
    gotoxy(31,11);
    cout<<"Mn";
    gotoxy(31,13);
    cout<<"Tc";
    gotoxy(31,15);
    cout<<"Re";
    gotoxy(31,17);
    cout<<"Bh";
    gotoxy(34,11);
    cout<<"Fe";
    gotoxy(34,13);
    cout<<"Ru";
    gotoxy(34,15);
    cout<<"Os";
    gotoxy(34,17);
    cout<<"Hs";
    gotoxy(37,11);
    cout<<"Co";
    gotoxy(37,13);
    cout<<"Rh";
    gotoxy(37,15);
    cout<<"Ir";
    gotoxy(37,17);
    cout<<"Mt";
    gotoxy(40,11);
    cout<<"Ni";
    gotoxy(40,13);
    cout<<"Pd";
    gotoxy(40,15);
    cout<<"Pt";
    gotoxy(40,17);
    cout<<"Ds";
    gotoxy(43,17);
    cout<<"Rg";
    gotoxy(46,17);
    cout<<"Cn";
    gotoxy(49,17);
    cout<<"Nh";
    gotoxy(52,17);
    cout<<"Fl";
    gotoxy(55,17);
    cout<<"Mc";
    gotoxy(58,17);
    cout<<"Lv";
    gotoxy(61,17);
    cout<<"Ts";
    gotoxy(64,17);
    cout<<"Og";
    gotoxy(43,11);
    cout<<"Cu";
    gotoxy(43,13);
    cout<<"Ag";
    gotoxy(43,15);
    cout<<"Au";
    gotoxy(46,11);
    cout<<"Zn";
    gotoxy(46,13);
    cout<<"Cd";
    gotoxy(46,15);
    cout<<"Hg";
    gotoxy(49,7);
    cout<<"B";
    gotoxy(49,9);
    cout<<"Al";
    gotoxy(49,11);
    cout<<"Ga";
    gotoxy(49,13);
    cout<<"In";
    gotoxy(49,15);
    cout<<"Tl";
    gotoxy(52,7);
    cout<<"C";
    gotoxy(52,9);
    cout<<"Si";
    gotoxy(52,11);
    cout<<"Ge";
    gotoxy(52,13);
    cout<<"Sn";
    gotoxy(52,15);
    cout<<"Pb";
    gotoxy(55,7);
    cout<<"N";
    gotoxy(55,9);
    cout<<"P";
    gotoxy(55,11);
    cout<<"As";
    gotoxy(55,13);
    cout<<"Sb";
    gotoxy(55,15);
    cout<<"Bi";
    gotoxy(58,7);
    cout<<"O";
    gotoxy(58,9);
    cout<<"S";
    gotoxy(58,11);
    cout<<"Se";
    gotoxy(58,13);
    cout<<"Te";
    gotoxy(58,15);
    cout<<"Po";
    gotoxy(61,7);
    cout<<"F";
    gotoxy(61,9);
    cout<<"Cl";
    gotoxy(61,11);
    cout<<"Br";
    gotoxy(61,13);
    cout<<"I";
    gotoxy(61,15);
    cout<<"At";
    gotoxy(64,5);
    cout<<"He";
    gotoxy(64,7);
    cout<<"Ne";
    gotoxy(64,9);
    cout<<"Ar";
    gotoxy(64,11);
    cout<<"Kr";
    gotoxy(64,13);
    cout<<"Xe";
    gotoxy(64,15);
    cout<<"Rn";
    gotoxy(13,21);
    cout<<"Lanthanides";
    gotoxy(25,21);
    cout<<"Ce";
    gotoxy(28,21);
    cout<<"Pr";
    gotoxy(31,21);
    cout<<"Nd";
    gotoxy(34,21);
    cout<<"Pm";
    gotoxy(37,21);
    cout<<"Sm";
    gotoxy(40,21);
    cout<<"Eu";
    gotoxy(43,21);
    cout<<"Gd";
    gotoxy(46,21);
    cout<<"Tb";
    gotoxy(49,21);
    cout<<"Dy";
    gotoxy(52,21);
    cout<<"Ho";
    gotoxy(55,21);
    cout<<"Er";
    gotoxy(58,21);
    cout<<"Tm";
    gotoxy(61,21);
    cout<<"Yb";
    gotoxy(64,21);
    cout<<"Lu";
    gotoxy(13,23);
    cout<<"Actinides";
    gotoxy(25,23);
    cout<<"Th";
    gotoxy(28,23);
    cout<<"Pa";
    gotoxy(31,23);
    cout<<"U";
    gotoxy(34,23);
    cout<<"Np";
    gotoxy(37,23);
    cout<<"Pu";
    gotoxy(40,23);
    cout<<"Am";
    gotoxy(43,23);
    cout<<"Cm";
    gotoxy(46,23);
    cout<<"Bk";
    gotoxy(49,23);
    cout<<"Cf";
    gotoxy(52,23);
    cout<<"Ea";
    gotoxy(55,23);
    cout<<"Fm";
    gotoxy(58,23);
    cout<<"Md";
    gotoxy(61,23);
    cout<<"No";
    gotoxy(64,23);
    cout<<"Lr";
    gotoxy(10,5);
    i=13;
    j=5;
    gotoxy(i,j);

    do
    {
        g=getch();
        if(g==80)
        {
            if(j==23) j=1;
            gotoxy(i,++j);
        }
        else if(g==77)
        {
            if(i==79) i=1;
            gotoxy(++i,j);
        }
        else if(g==75)
        {
            if(i==2) i=80;
            gotoxy(--i,j);
        }
        else if(g==72)
        {
            if(j==2) j=24;
            gotoxy(i,--j);
        }
        if(g==13)
            element(i,j);

        if(g==115)
        {
            system("cls");
            gotoxy(45, 2);
            cout <<" Welcome to quick search"<<endl;
            gotoxy(45, 3);
            cout <<" ======================= ";
            gotoxy(42, 5);
            cout <<"Enter Atomic no. to search: ";
            scanf("%d", &an);
            rewind(fp);
            bool found = false;
            while(an != 0)
            {
                output();
            };

            if (found == false)
            {
                printf("Sorry,The Id is not found.Please enter the correct id...");
            }
            printf("\nSearch another record(y/n)");
            fflush(stdin);
            another = getche();

        }

    }
    while(g!=27);
}
void element(int i,int j)
{

    if(((i==13)||(i==14))&&(j==5))
    {
        an = 1;
        output();
    }
    else if(((i==64)||(i==65))&&(j==5))
    {
        an = 2;
        output();
    }
    else if(((i==13)||(i==14))&&(j==7))
    {
        an = 3;
        output();
    }

    else if(((i==16)||(i==17))&&(j==7))
    {
        system("cls");
        an = 4;
        output();
    }


    else if(((i==49)||(i==50))&&(j==7))
    {
        system("cls");
        an = 5;
        output();
    }

    else if(((i==52)||(i==53))&&(j==7))
    {
        system("cls");
        an = 6;
        output();
    }

    else if(((i==55)||(i==56))&&(j==7))
    {
        system("cls");
        an = 7;
        output();
    }

    else if(((i==58)||(i==59))&&(j==7))
    {
        system("cls");
        an = 8;
        output();
    }

    else if(((i==61)||(i==62))&&(j==7))
    {
        system("cls");
        an = 9;
        output();
    }

    else if(((i==64)||(i==65))&&(j==7))
    {
        system("cls");
        an = 10;
        output();;
    }

    else if(((i==13)||(i==14))&&(j==9))
    {
        system("cls");
        an = 11;
        output();
    }

    else if(((i==16)||(i==17))&&(j==9))
    {
        system("cls");
        an = 12;
        output();
    }

    else if(((i==49)||(i==50))&&(j==9))
    {
        system("cls");
        an = 13;
        output();
    }

    else if(((i==52)||(i==53))&&(j==9))
    {
        system("cls");
        an = 14;
        output();
    }

    else if(((i==55)||(i==56))&&(j==9))
    {
        system("cls");
        an = 15;
        output();
    }

    else if(((i==58)||(i==59))&&(j==9))
    {
        system("cls");
        an = 16;
        output();
    }

    else  if(((i==61)||(i==62))&&(j==9))
    {
        system("cls");
        an = 17;
        output();
    }



    else if(((i==64)||(i==65))&&(j==9))
    {
        system("cls");
        an = 18;
        output();
    }

    else if(((i==13)||(i==14))&&(j==11))
    {
        system("cls");
        an = 19;
        output();
    }

    else if(((i==16)||(i==17))&&(j==11))
    {
        system("cls");
        an = 20;
        output();
    }

    else if(((i==13)||(i==14))&&(j==13))
    {
        system("cls");
        an = 37;
        output();
    }

    else if(((i==13)||(i==14))&&(j==15))
    {
        system("cls");
        an = 55;
        output();
    }

    else if(((i==13)||(i==14))&&(j==17))
    {
        system("cls");
        an = 87;
        output();
    }

    else if(((i==64)||(i==65))&&(j==23))
    {
        system("cls");
        an = 103;
        output();
    }


    else if(((i==16)||(i==17))&&(j==8))
    {
        system("cls");
        an = 4;
        output();
    }
    else if(((i==16)||(i==17))&&(j==10))
    {
        system("cls");
        an = 12;
        output();
    }
    else if(((i==16)||(i==17))&&(j==11))
    {
        system("cls");
        an = 20;
        output();
    }
    else if(((i==16)||(i==17))&&(j==14))
    {
        system("cls");
        an = 38;
        output();
    }
    else if(((i==16)||(i==17))&&(j==15))
    {
        system("cls");
        an = 56;
        output();
    }
    else if(((i==16)||(i==17))&&(j==17))
    {
        system("cls");
        an = 88;
        output();
    }
    else if(((i==19)||(i==20))&&(j==11))
    {
        system("cls");
        an = 21;
        output();
    }
    else if(((i==19)||(i==20))&&(j==14))
    {
        system("cls");
        an = 39;
        output();
    }
    else if(((i==19)||(i==20))&&(j==15))
    {
        system("cls");
        an = 57;
        output();
    }
    else if(((i==19)||(i==20))&&(j==17))
    {
        system("cls");
        an = 89;
        output();
    }
    else if(((i==22)||(i==23))&&(j==11))
    {
        system("cls");
        an = 22;
        output();
    }

    else if(((i==22)||(i==23))&&(j==13))
    {
        system("cls");
        an = 40;
        output();
    }
    else if(((i==22)||(i==23))&&(j==15))
    {
        system("cls");
        an = 72;
        output();
    }
    else if(((i==22)||(i==23))&&(j==17))
    {
        system("cls");
        an = 104;
        output();
    }
    else if(((i==25)||(i==26))&&(j==11))
    {
        system("cls");
        an = 23;
        output();
    }
    else if(((i==25)||(i==26))&&(j==13))
    {
        system("cls");
        an = 41;
        output();
    }
    else if(((i==25)||(i==26))&&(j==15))
    {
        system("cls");
        an = 73;
        output();
    }
    else if(((i==25)||(i==26))&&(j==17))
    {
        system("cls");
        an = 105;
        output();
    }
    else if(((i==28)||(i==29))&&(j==11))
    {
        system("cls");
        an = 24;
        output();
    }
    else if(((i==28)||(i==29))&&(j==13))
    {
        system("cls");
        an = 42;
        output();
    }
    else if(((i==28)||(i==29))&&(j==15))
    {
        system("cls");
        an = 74;
        output();
    }
    else if(((i==28)||(i==29))&&(j==17))
    {
        system("cls");
        an = 106;
        output();
    }
    else if(((i==31)||(i==32))&&(j==11))
    {
        system("cls");
        an = 25;
        output();
    }
    else if(((i==31)||(i==32))&&(j==13))
    {
        system("cls");
        an = 43;
        output();
    }
    else if(((i==31)||(i==32))&&(j==15))
    {
        system("cls");
        an = 75;
        output();
    }
    else if(((i==31)||(i==32))&&(j==17))
    {
        system("cls");
        an = 107;
        output();
    }
    else if(((i==34)||(i==35))&&(j==11))
    {
        system("cls");
        an = 26;
        output();
    }
    else if(((i==34)||(i==35))&&(j==13))
    {
        system("cls");
        an = 44;
        output();
    }
    else if(((i==34)||(i==35))&&(j==15))
    {
        system("cls");
        an = 76;
        output();
    }
    else if(((i==34)||(i==35))&&(j==17))
    {
        system("cls");
        an = 108;
        output();
    }
    else if(((i==37)||(i==38))&&(j==11))
    {
        system("cls");
        an = 27;
        output();
    }
    else if(((i==37)||(i==38))&&(j==13))
    {
        system("cls");
        an = 45;
        output();
    }
    else if(((i==37)||(i==38))&&(j==15))
    {
        system("cls");
        an = 77;
        output();
    }
    else if(((i==37)||(i==38))&&(j==17))
    {
        system("cls");
        an = 109;
        output();
    }
    else if(((i==40)||(i==41))&&(j==11))
    {
        system("cls");
        an = 28;
        output();
    }
    else if(((i==40)||(i==41))&&(j==13))
    {
        system("cls");
        an = 46;
        output();
    }
    else if(((i==40)||(i==41))&&(j==15))
    {
        system("cls");
        an = 78;
        output();
    }
    else if(((i==40)||(i==41))&&(j==17))
    {
        system("cls");
        an = 110;
        output();
    }
    else if(((i==43)||(i==44))&&(j==11))
    {
        system("cls");
        an = 29;
        output();
    }
    else if(((i==43)||(i==44))&&(j==13))
    {
        system("cls");
        an = 47;
        output();
    }
    else if(((i==43)||(i==44))&&(j==15))
    {
        system("cls");
        an = 79;
        output();
    }
    else if(((i==46)||(i==47))&&(j==11))
    {
        system("cls");
        an = 30;
        output();
    }
    else if(((i==46)||(i==47))&&(j==13))
    {
        system("cls");
        an = 48;
        output();
    }
    else if(((i==46)||(i==47))&&(j==15))
    {
        system("cls");
        an = 80;
        output();
    }
    else if(((i==46)||(i==47))&&(j==17))
    {
        system("cls");
        an = 112;
        output();
    }
    else if(((i==49)||(i==50))&&(j==7))
    {
        system("cls");
        an = 5;
        output();
    }
    else if(((i==49)||(i==50))&&(j==9))
    {
        system("cls");
        an = 13;
        output();
    }
    else if(((i==49)||(i==50))&&(j==11))
    {
        system("cls");
        an = 31;
        output();
    }
    else if(((i==49)||(i==50))&&(j==13))
    {
        system("cls");
        an = 49;
        output();
    }
    else if(((i==49)||(i==50))&&(j==15))
    {
        system("cls");
        an = 81;
        output();
    }
    else if(((i==52)||(i==53))&&(j==11))
    {
        system("cls");
        an = 32;
        output();
    }
    else if(((i==52)||(i==53))&&(j==13))
    {
        system("cls");
        an = 50;
        output();;
    }
    else if(((i==52)||(i==53))&&(j==15))
    {
        system("cls");
        an = 82;
        output();
    }
    else if(((i==52)||(i==53))&&(j==17))
    {
        system("cls");
        an = 114;
        output();
    }
    else if(((i==55)||(i==56))&&(j==11))
    {
        system("cls");
        an = 33;
        output();
    }
    else if(((i==58)||(i==59))&&(j==13))
    {
        system("cls");
        an = 52;
        output();
    }
    else if(((i==58)||(i==59))&&(j==15))
    {
        system("cls");
        an = 84;
        output();
    }
    else if(((i==61)||(i==62))&&(j==11))
    {
        system("cls");
        an = 35;
        output();
    }
    else if(((i==61)||(i==62))&&(j==13))
    {
        system("cls");
        an = 53;
        output();
    }
    else if(((i==61)||(i==62))&&(j==15))
    {
        system("cls");
        an = 85;
        output();
    }
    else if(((i==64)||(i==65))&&(j==11))
    {
        system("cls");
        an = 36;
        output();
    }
    else if(((i==64)||(i==65))&&(j==13))
    {
        system("cls");
        an = 54;
        output();
    }
    else if(((i==64)||(i==65))&&(j==15))
    {
        system("cls");
        an = 86;
        output();
    }
    else if(((i==55)||(i==56))&&(j==13))
    {
        system("cls");
        an = 51;
        output();
    }
    else if(((i==55)||(i==56))&&(j==15))
    {
        system("cls");
        an = 83;
        output();
    }
    else if(((i==58)||(i==59))&&(j==11))
    {
        system("cls");
        an = 34;
        output();
    }
    else if(((i==25)||(i==26))&&(j==21))
    {
        system("cls");
        an = 58;
        output();
    }
    else if(((i==28)||(i==29))&&(j==21))
    {
        system("cls");
        an = 59;
        output();
    }
    else if(((i==31)||(i==32))&&(j==21))
    {
        system("cls");
        an = 60;
        output();
    }
    else if(((i==34)||(i==35))&&(j==21))
    {
        system("cls");
        an = 61;
        output();
    }
    else if(((i==37)||(i==38))&&(j==21))
    {
        system("cls");
        an = 62;
        output();
    }
    else if(((i==40)||(i==41))&&(j==21))
    {
        system("cls");
        an = 63;
        output();
    }
    else if(((i==43))&&(j==21))
    {
        system("cls");
        an = 64;
        output();
    }
    else if(((i==46)||(i==47))&&(j==21))
    {
        system("cls");
        an = 65;
        output();
    }
    else if(((i==49)||(i==50))&&(j==21))
    {
        system("cls");
        an = 66;
        output();
    }
    else if(((i==52)||(i==53))&&(j==21))
    {
        system("cls");
        an = 67;
        output();
    }
    else if(((i==55)||(i==56))&&(j==21))
    {
        system("cls");
        an = 68;
        output();
    }
    else if(((i==58)||(i==59))&&(j==21))
    {
        system("cls");
        an = 69;
        output();
    }
    else if(((i==61)||(i==62))&&(j==21))
    {
        system("cls");
        an = 70;
        output();
    }
    else if(((i==64)||(i==65))&&(j==21))
    {
        system("cls");
        an = 71;
        output();
    }
    else if(((i==25)||(i==26))&&(j==23))
    {
        system("cls");
        an = 90;
        output();
    }
    else if(((i==28)||(i==29))&&(j==23))
    {
        system("cls");
        an = 91;
        output();
    }
    else if(((i==31)||(i==32))&&(j==23))
    {
        system("cls");
        an = 92;
        output();
    }
    else if(((i==34)||(i==35))&&(j==23))
    {
        system("cls");
        an = 93;
        output();
    }
    else if(((i==37)||(i==38))&&(j==23))
    {
        system("cls");
        an = 94;
        output();
    }
    else if(((i==40)||(i==41))&&(j==23))
    {
        system("cls");
        an = 95;
        output();
    }


    else if(((i==43))&&(j==23))
    {
        system("cls");
        an = 96;
        output();
    }

    else if(((i==46)||(i==47))&&(j==23))
    {
        system("cls");
        an = 97;
        output();
    }
    else if(((i==49)||(i==50))&&(j==23))
    {
        system("cls");
        an = 98;
        output();
    }
    else if(((i==52)||(i==53))&&(j==23))
    {
        system("cls");
        an = 99;
        output();
    }
    else if(((i==55)||(i==56))&&(j==23))
    {
        system("cls");
        an = 100;
        output();
    }

    else if(((i==58)||(i==59))&&(j==23))
    {
        system("cls");
        an = 101;
        output();
    }

    else if(((i==61)||(i==62))&&(j==23))
    {
        system("cls");
        an = 102;
        output();
    }

    else if(((i==64)||(i==65))&&(j==23))
    {
        system("cls");
        an = 103;
        output();
    }
    else if(((i==43)||(i==44))&&(j==17))
    {
        system("cls");
        an = 111;
        output();
    }
    else if(((i==46)||(i==47))&&(j==17))
    {
        system("cls");
        an = 112;
        output();
    }
    else if(((i==49)||(i==50))&&(j==17))
    {
        system("cls");
        an = 113;
        output();
    }
    else if(((i==52)||(i==53))&&(j==17))
    {
        system("cls");
        an = 114;
        output();
    }
    else if(((i==55)||(i==56))&&(j==17))
    {
        system("cls");
        an = 115;
        output();
    }
    else if(((i==58)||(i==59))&&(j==17))
    {
        system("cls");
        an = 116;
        output();
    }
    else if(((i==61)||(i==62))&&(j==17))
    {
        system("cls");
        an = 117;
        output();
    }
    else if(((i==64)||(i==65))&&(j==17))
    {
        system("cls");
        an = 118;
        output();
    }

    char key;
    key=getch();
    if(key==27) exit(0);
    else display();
}

