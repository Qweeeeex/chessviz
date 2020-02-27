#include<iostream>
#include <string>
using namespace std; 
 
string buff; 
bool flag_buff = false;   
string doska[9][9];
bool doska_b[9][9];
int sum_hod = 0;
 
struct Figura 
{   
    string Kw, Kb, Qw, Qb, Rw, Rb, Nw, Nb, Bw, Bb, Pw, Pb;  
    Figura()
        : Kw{ "Kw" }, Kb{ "Kb" }, Qw{ "Qw" }, Qb{ "Qb" }, Rw{ "Rw" }, Rb{ "Rb" }, Nw{ "Nw" },
        Nb{ "Nb" }, Bw{ "Bw" }, Bb{ "Bb" }, Pw{ "Pw" }, Pb{ "Pb" }
    {
    }
};
 
void doska_print() 
{
    system("cls"); 
    char num = 'a'; 
    cout << "\n\n";
    for (int i = 0; i < 8; i++)
    {
        cout << "\t\t\t" << 8 - i;
        for (int j = 0; j < 9; j++)
        {
            cout << doska[i][j];
        }
        cout << endl;
    }
    cout << "\t\t\t";
    for (int i = 1; i < 9; i++)
    {
        cout << "   " << num;
        ++num;
    }
    
    }

 
void doska_default() {  
    Figura f;
    for (int i = 0; i < 8; i++)
    {   
        for (int j = 1; j < 9; j++)
        {           
            doska[i][j] = "|__|";
            doska_b[i][j] = 0;
        }   
    }
    for (int i = 1; i < 9; i++)
    {                                                       
        doska[1][i] = "|" + f.Pb + "|"; doska_b[1][i] = 1;
        doska[6][i] = "|" + f.Pw + "|"; doska_b[6][i] = 1;
    }
    doska[0][1] = doska[0][8] = "|" + f.Bb + "|"; doska_b[0][1] = doska_b[0][8] = 1;
    doska[7][1] = doska[7][8] = "|" + f.Bw + "|"; doska_b[7][1] = doska_b[7][8] = 1;
    doska[0][2] = doska[0][7] = "|" + f.Nb + "|"; doska_b[0][2] = doska_b[0][7] = 1;
    doska[7][2] = doska[7][7] = "|" + f.Nw + "|"; doska_b[7][2] = doska_b[7][7] = 1;
    doska[0][3] = doska[0][6] = "|" + f.Rb + "|"; doska_b[0][3] = doska_b[0][6] = 1;
    doska[7][3] = doska[7][6] = "|" + f.Rw + "|"; doska_b[7][3] = doska_b[7][6] = 1;
    doska[0][4] = "|" + f.Qb + "|"; doska_b[0][4] = 1;
    doska[0][5] = "|" + f.Kb + "|"; doska_b[0][5] = 1;
    doska[7][4] = "|" + f.Qw + "|"; doska_b[7][4] = 1;
    doska[7][5] = "|" + f.Kw + "|"; doska_b[7][5] = 1;
    
    doska_print();
}
 
void doska_figura_remove(int x, int y)
{
    doska[8 - y][8 - (104 - x)] = "|__|";
}
 
void doska_hod(int x, int y)
{           
    if (doska_b[8 - y][8 - (104 - x)] == 1) {
        buff = doska[8 - y][8 - (104 - x)]; 
        doska_figura_remove(x, y);
        doska_b[8 - y][8 - (104 - x)] = 0;
        flag_buff = true;  
    }
    else {                
        doska[8 - y][8 - (104 - x)] = buff;
        doska_b[8 - y][8 - (104 - x)] = 1;
        buff = "";             
        flag_buff = false;      
        doska_print();          
    }   
    ++sum_hod; 
}
 
int main() {
    setlocale(0, "Russian");
    doska_default();
    std::cout << std::endl;
	return 0;    
}
