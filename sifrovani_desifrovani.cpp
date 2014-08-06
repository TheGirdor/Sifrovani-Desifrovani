#include <iostream>                                                                          
#include <windows.h>                                                                         // knihovny
#include <conio.h>
using namespace std;

int main()
{
int delka,d,i,p=0;   
char zn[100]="",text[100]="";
cout << "Pro sifrovani stisknete   [1]";                                                     // menu
cout << "\nPro desifrovani stisknete [2]";
if (getch()=='1')                                                                            // ceka na stisk klavesy, pokud se zmackne 1 spusti se sifrovani
{   
   system("cls");                                                                            // vymaze predely text
   SetConsoleTitle("Sifrovani");                                                             // zmeni titul konzole
   cout << "Zadej text na zasifrovani(pri delsi zprave nepouzivejte spec. znaky prosim):\n " ;
   cin.getline(text,100);
   delka=strlen(text);                                                                       // urci delku retezce
   cout << "\n Zasifrovana zprava: ";
   for (i=0;i<delka;i++)                                                                     
        text[i]=text[i]+i-delka;                                                             // zasifruje retezec
   cout << text;
   cout << "\n Ulozeno do souboru sifra.txt";                                                // vypise retezec
   FILE *sou;
        sou = fopen ("sifra.txt","w");                                                       
        fprintf (sou, "%s", text);                                                           // ulozi retezec do souboru
        fclose(sou);
}
else if (getch()=='2')                                                                       // ceka na stisk klavesy, pokud se zmackne 2 spusti se desifrovani
{
     system("cls");
     SetConsoleTitle("Desifrovani");
     FILE *sou2;
     sou2=fopen("sifra.txt","r");
     while (!feof(sou2))
     {
           fgets(zn,100,sou2);
           putchar(zn[p]);
           p++;
     }
     fclose(sou2);
     system("cls");      
     cout << "\n Sifrovana zprava: ";
     cout << zn;    
     delka=strlen(zn);
     for (i=delka;i>=0;i--)                                                                 // udela opacny postup, tudiz desifruje retezec
        zn[i]=zn[i]-i+delka;
     cout << "\n Desifrovana zprava: ";     
     cout << zn;
     cout << "\n Otevreno ze souboru sifra.txt";
}
else                                                                                       // pokud se nezmackne 1,2 tak vypise text
{
    system("cls");
    cout << "Spatny stisk klavesy, prosim opakujte restartovanim programu.";
    system("PAUSE > NUL");
    return 0;
}
     
system("PAUSE > NUL");
return 0;
}
