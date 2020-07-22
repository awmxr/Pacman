/*
Amir Marvastti Nejad
pacman  
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mar5.h"
#include <time.h>
typedef struct  
{
    int x;
    int y;
    char h;
}struct1;
int u = 0; //where is enemy?
int score = 0;
struct1 pacman,enemy1,enemy2,enemy3,enemy4;
int v = 0;
// pacman = (struct1 *)malloc(sizeof(struct1));
void print_table(struct1 pacman,char qaza[50][50],struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4,int bscore,int cl)
{

    system("clear");
    char table[50][50];
    for(int i = 0;i < 50 ; i++)
    {
        for(int j = 0; j < 50 ; j++)
        {
            table[i][j] = '.';   
        }
    }   
    for(int i = 0 ; i < 50 ; i++)
    {
        table[i][0] = '|';
        table[i][49] = '|';
        table[0][i] = '=';
        table[49][i] = '=';
    }
    
    for(int i = 1; i < 49 ; i++)
    {
        for(int j = 1; j < 49 ; j++)
        {
            table[i][j] = qaza[i][j];
        }
    }
    table[enemy1.y][enemy1.x] = enemy1.h;
    table[enemy2.y][enemy2.x] = enemy2.h;
    table[enemy3.y][enemy3.x] = enemy3.h;
    table[enemy4.y][enemy4.x] = enemy4.h;
    table[pacman.y][pacman.x] = pacman.h;
    printf("\033[1;33m");
    printf("score : %d",score);
    printf("\033[0m");
    printf("\033[1;32m");
    printf("              best score : %d\n",bscore);
    printf("\033[0m");
    printf("\033[1m");
    printf("press 'm' for menu");
    printf("                    press 'p' for pause\n");
    printf("\033[0m");
    for(int i = 0; i < 50; i++ )
    {
        for(int j = 0; j < 50; j++)
        {
            if(table[i][j] == '@')
            {
                printf("\033[1;%dm",cl);
                printf("%c",table[i][j]);
                printf("%c",table[i][j]);
                printf("\033[0m");
            }
            else
            {
                
                if(table[i][j] == '#')
                {
                    if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    int f = rand() % 5 + 32;
                    printf("\033[1;%dm",f);
                    printf("%c",table[i][j]);
                    printf("%c",table[i][j]);
                    printf("\033[0m");
                }
                else
                {
                    printf("\033[1;31m");
                    printf("%c",table[i][j]);
                    printf("%c",table[i][j]);
                    printf("\033[0m");
                }
                }
                else
                {
                    if((table[i][j] == '|')||(table[i][j] == '='))
                    {
                        printf("\033[1;34m");
                        printf("%c",table[i][j]);
                        printf("%c",table[i][j]);
                        printf("\033[0m");
                    }
                    else
                    {
                        if(table[i][j] == '.')
                        {
                            printf("\033[1m");
                            printf("%c",table[i][j]);
                            printf(" ");
                            printf("\033[0m");
                        }
                        else
                        {
                            printf("\033[1m");
                            printf("%c",table[i][j]);
                            printf("%c",table[i][j]);
                            printf("\033[0m");
                        }

                        
                    }
                }
                
            }
            
        }
        printf("\n");
    }
}
struct1 up(struct1 pac)
{
    pac.y = (pac.y) - 1;
    return pac;
}
struct1 down(struct1 pac)
{
    pac.y = (pac.y) + 1;
    return pac;
}
struct1 right(struct1 pac)
{
    pac.x = (pac.x) + 1;
    return pac;
}
struct1 left(struct1 pac)
{
    pac.x = (pac.x) - 1;
    return pac;
}
int checkup(struct1 enemy, struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4)
{
    char qaza[50][50];
    qaza[enemy.y][enemy.x] = '#';
    qaza[enemy1.y][enemy1.x] = '#';
    qaza[enemy2.y][enemy2.x] = '#';
    qaza[enemy3.y][enemy3.x] = '#';
    qaza[enemy4.y][enemy4.x] = '#';
    if(qaza[enemy.y - 1][enemy.x] == '#')
    {
        return 1;
    }
    return 0;
}
int checkdown(struct1 enemy, struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4)
{
    char qaza[50][50];
    qaza[enemy.y][enemy.x] = '#';
    qaza[enemy1.y][enemy1.x] = '#';
    qaza[enemy2.y][enemy2.x] = '#';
    qaza[enemy3.y][enemy3.x] = '#';
    qaza[enemy4.y][enemy4.x] = '#';
    if(qaza[enemy.y + 1][enemy.x] == '#')
    {
        return 1;
    }
    return 0;
}
int checkright(struct1 enemy, struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4)
{
    char qaza[50][50];
    qaza[enemy.y][enemy.x] = '#';
    qaza[enemy1.y][enemy1.x] = '#';
    qaza[enemy2.y][enemy2.x] = '#';
    qaza[enemy3.y][enemy3.x] = '#';
    qaza[enemy4.y][enemy4.x] = '#';
    if(qaza[enemy.y][enemy.x + 1] == '#')
    {
        return 1;
    }
    return 0;
}
int checkleft(struct1 enemy, struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4)
{
    char qaza[50][50];
    qaza[enemy.y][enemy.x] = '#';
    qaza[enemy1.y][enemy1.x] = '#';
    qaza[enemy2.y][enemy2.x] = '#';
    qaza[enemy3.y][enemy3.x] = '#';
    qaza[enemy4.y][enemy4.x] = '#';
    if(qaza[enemy.y][enemy.x - 1] == '#')
    {
        return 1;
    }
    return 0;
}

struct1 enemy_move(char qaza[50][50],struct1 enemy,int r,struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4)//harekat e enemy
{
    
    
    switch(r)
                    {
                        case 0:
                        if((qaza[enemy.y - 1][enemy.x] == '|')||(qaza[enemy.y - 1][enemy.x] == '=')||(checkup(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                        {
                            if((qaza[enemy.y][enemy.x - 1] == '|')||(qaza[enemy.y][enemy.x - 1] == '=')||(checkleft(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                            {
                                if((qaza[enemy.y + 1][enemy.x]=='|')||(qaza[enemy.y + 1][enemy.x]=='=')||(checkdown(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                {
                                    if((qaza[enemy.y][enemy.x + 1] == '|')||(qaza[enemy.y][enemy.x + 1] == '=')||(checkright(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                    {
                                        break;
                                    }
                                    enemy = right(enemy);
                                    break;
                                }
                                enemy = down(enemy);
                                break;
                            }
                            enemy = left(enemy);
                            break;
                        }
                        enemy = up(enemy);
                        break;
                        case 1:
                        if((qaza[enemy.y][enemy.x - 1] == '|')||(qaza[enemy.y][enemy.x - 1] == '=')||(checkleft(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                        {
                            if((qaza[enemy.y + 1][enemy.x]=='|')||(qaza[enemy.y + 1][enemy.x]=='=')||(checkdown(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                {
                                    if((qaza[enemy.y][enemy.x + 1] == '|')||(qaza[enemy.y][enemy.x + 1] == '=')||(checkright(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                    {
                                        if((qaza[enemy.y - 1][enemy.x] == '|') || (qaza[enemy.y - 1][enemy.x] == '=')||(checkup(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                        {
                                            break;
                                        }
                                        enemy = up(enemy);
                                        break;
                                    }
                                    enemy = right(enemy);
                                    break;
                                }
                            enemy = down(enemy);
                            break;
                        }
                        enemy = left(enemy);
                        break;
                        case 2:
                        if((qaza[enemy.y + 1][enemy.x] == '|')||(qaza[enemy.y + 1][enemy.x] == '=')||(checkdown(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                        {
                            if((qaza[enemy.y][enemy.x + 1] == '|')||(qaza[enemy.y][enemy.x + 1] == '=')||(checkright(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                    {
                                        if((qaza[enemy.y - 1][enemy.x] == '|') || (qaza[enemy.y - 1][enemy.x] == '=')||(checkup(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                        {
                                            if((qaza[enemy.y][enemy.x - 1]=='|') || (qaza[enemy.y][enemy.x - 1] == '=')||(checkleft(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                            {
                                                break;
                                            }
                                            enemy = left(enemy) ;
                                            break;
                                        }
                                        enemy = up(enemy);
                                        break;
                                    }
                            enemy = right(enemy);
                            break;
                        }
                        enemy = down(enemy);
                        break;
                        case 3:
                        if((qaza[enemy.y][enemy.x + 1] == '|')||(qaza[enemy.y][enemy.x + 1] == '=')||(checkright(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                        {
                            if((qaza[enemy.y - 1][enemy.x] == '|') || (qaza[enemy.y - 1][enemy.x] == '=')||(checkup(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                        {
                                            if((qaza[enemy.y][enemy.x - 1]=='|') || (qaza[enemy.y][enemy.x - 1] == '=')||(checkleft(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                            {
                                                if((qaza[enemy.y + 1][enemy.x]=='|')||(qaza[enemy.y + 1][enemy.x]=='=')||(checkdown(enemy,enemy1,enemy2,enemy3,enemy4) == 1))
                                                {
                                                    break;
                                                }
                                                enemy = down(enemy);
                                                break;
                                            }
                                            enemy = left(enemy) ;
                                            break;
                                        }
                            enemy = up(enemy);
                            break;
                        }
                        enemy = right(enemy);
                        break;
                    }
                    return enemy;
}
struct1 taqeeb(struct1 pacman,struct1 enemy,int r,int level,char qaza[50][50],int num,int bscore)//taqeeb
{
    while(1)
                {
                    if(level >= num)
                    {
                    if((abs(pacman.x - enemy.x)) > abs((pacman.y - enemy.y)))
                    {
                        if(enemy.x > pacman.x)
                        {
                            r = 1;
                        }
                        else
                        {
                            r = 3;
                        }
                    }
                    else
                    {
                        if(enemy.y > pacman.y)
                        {
                            r = 0;
                        }
                        else
                        {
                            r = 2;
                        }
                    }
                    }
                    else
                    {
                        r = rand() % 4;
                    }
                    int a,b;
                    a = enemy.x;
                    b = enemy.y;
                    enemy = enemy_move(qaza,enemy,r,enemy1,enemy2,enemy3,enemy4);
                    if((a != enemy.x)||(b != enemy.y))
                        break;
                }
                if(check2(pacman,enemy1,enemy2,enemy3,enemy4,bscore) == -1)
                {
                    v = -1;
                }
                else
                {
                if(check2(pacman,enemy1,enemy2,enemy3,enemy4,bscore) == 1)
                {
                    v = 1;
                }
                else
                {
                    v = 0;
                }
                }
                return enemy;
}
struct1 farar(struct1 pacman,struct1 enemy,int r,int level,char qaza[50][50],int num,int bscore)//farar
{
    while(1)
                {
                    if(level >= num)
                    {
                    if((abs(pacman.x - enemy.x)) > abs((pacman.y - enemy.y)))
                    {
                        if(enemy.x > pacman.x)
                        {
                            r = 3;
                        }
                        else
                        {
                            r = 1;
                        }
                    }
                    else
                    {
                        if(enemy.y > pacman.y)
                        {
                            r = 2;
                        }
                        else
                        {
                            r = 0;
                        }
                    }
                    }
                    else
                    {
                        r = rand() % 4;
                    }
                    int a,b;
                    a = enemy.x;
                    b = enemy.y;
                    enemy = enemy_move(qaza,enemy,r,enemy1,enemy2,enemy3,enemy4);
                    if((a != enemy.x)||(b != enemy.y))
                        break;
                }
                if(check2(pacman,enemy1,enemy2,enemy3,enemy4,bscore) == -1)
                {
                    v = -1;
                }
                else
                {
                if(check2(pacman,enemy1,enemy2,enemy3,enemy4,bscore) == 1)
                {
                    v = 1;
                }
                else
                {
                    v = 0;
                }
                }
                return enemy;

}
int check1(struct1 pacman,struct1 enemy)//barkhord pacman va enemy
{
    if((pacman.x == enemy.x)&&(pacman.y == enemy.y))
    {
        return 0;
    }
    return 1;
}
int check3(int bscore)//check record
{
    if(score > bscore)
    {
        FILE * fb;
        fb = fopen("pacman.txt","w");
        fprintf(fb,"%d",score);
        fclose(fb);
    }
}
void show()//show recird
{
    char a;
    int record;
    FILE * fb;
    fb = fopen("pacman.txt","r");
    fscanf(fb,"%d",&record);
    fclose(fb);
    // printf("record : %d\n",record);
    while(1)
    {
        system("clear");
        printf("\033[1;33m");
        printf("\nRecord ");
        printf("\033[0m");
        printf("\033[1m");
        printf(": ");
        printf("\033[1;32m");
        printf("%d",record);
        system("clear");
        printf("\033[0m");
        printf("\033[1m");
        printf("\nenter 'm' for menu : ");
        scanf("%c",&a);
        if(a == 'm')
        {
        printf("\033[0m");
            break;
        }
    }
}
struct1 check4(struct1 pacman,struct1 enemy,int score)// enemy in base
{
    if((check1(pacman,enemy) == 0 ))
    {
        enemy.x = 12;
        enemy.y = 14;
        u = 1;
        // score = score + 100;
    }
    return enemy;
}
int check2(struct1 pacman,struct1 enemy1,struct1 enemy2,struct1 enemy3,struct1 enemy4,int bscore)// +100   v = 1 khord      v = -1 mord  v = 0 nothing
{
    if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                        enemy1 = check4(pacman,enemy1,score);
                        enemy2 = check4(pacman,enemy2,score);
                        enemy3 = check4(pacman,enemy3,score);
                        enemy4 = check4(pacman,enemy4,score);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        return 1;
                    }
                    else
                    {
                    if((check1(pacman,enemy1) == 0 )||(check1(pacman,enemy2)==0)||(check1(pacman,enemy3) == 0)||(check1(pacman,enemy4) == 0))
                    {
                        system("clear");
                        check3(bscore);
                        int q = 0;
    int m[7];
    while(q < 50)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                        score = 0;
                        return -1;
                    }
                    }
                    return 0;
}
int check5(char qaza[50][50])// check finish
{
    for(int i = 0;i < 50;i++)
    {
        for(int j = 0; j < 50; j++)
        {
            if(qaza[i][j] == '.')
            {
                return 1;
            }
        }
    }
    return 0;
}
int play(int level,int g,int cl)
{
    int bscore;
    FILE * fb;
    fb = fopen("pacman.txt","r");
    fscanf(fb,"%d",&bscore);
    fclose(fb);
    char qaza[50][50];
    for(int i = 0 ; i< 50 ; i++)
            {
                for(int j = 0 ; j< 50 ; j++)
                {
                    qaza[j][i] = '.';
                }
            }
            for(int i = 0 ; i < 50 ; i++)
            {
                qaza[i][0] = '|';
                qaza[i][49] = '|';
                qaza[0][i] = '=';
                qaza[49][i] = '=';
            }
            qaza[14][13] = '|';
            qaza[13][13] = '|';
            qaza[13][12] = '=';
            qaza[14][11] = '|';
            qaza[13][11] = '|'; 

    if (g == 1)
        {

        for(int i = 1; i < 20;i++)
        {
            qaza[i][5] = '|';
            qaza[i][30] = '|';
            qaza[35][i] = '=';
            qaza[i][25] = '|';
            qaza[i][20] = '|';
        }
        for(int i = 0; i < 5;i++)
        {
            qaza[i][47] = '|';
        }
        qaza[14][13] = '|';
        qaza[13][13] = '|';
        qaza[13][12] = '=';
        qaza[14][11] = '|';
        qaza[13][11] = '|';
        for(int i = 50 ; i > 30; i--)
        {
            qaza[i][30] = '|';
            qaza[21][i] = '=';
            qaza[27][i] = '=';
        }
    }
    else
    {
        if(g == 2)
        {
             
            for(int i = 20; i < 30; i++)
            {
                qaza[29][i] = '=';
                qaza[i][19] = '|';
            }
            for(int i = 0; i < 13; i++)
            {
                qaza[i][28] = '|';
                qaza[28][i] = '=';
                qaza[i][16] = '|';
            }
            for(int i = 25; i > 10 ; i--)
            {
                qaza[i][14] = '|';
                qaza[i][40] = '|';
                qaza[25][i] = '=';
                qaza[40][i] = '=';
            }
            for(int i = 10; i < 18; i++)
            {
                qaza[i][18] = '|';
                qaza[i + 6][25] = '|';
                qaza[i + 10][29] = '|';
            }
            for(int i = 0; i < 19; i++)
            {
                qaza[i + 2][4] = '|';
                qaza[4][i + 21] = '=';
            }
            for(int i = 50; i > 30;i--)
            {
                // qaza[i][20] = '|';
                qaza[40][i] = '=';
            }

        }
        else
        {
            if(g == 3)
            {
                for(int i = 0; i < 28; i++)
                {
                    qaza[i][28] = '|';
                    qaza[i][31] = '|';
                    qaza[i][34] = '|';
                    qaza[i][37] = '|';
                    qaza[i][40] = '|';
                    qaza[i][43] = '|';
                    qaza[i][46] = '|';
                    qaza[i][19] = '|';
                    // qaza[28][i] = '=';
                    qaza[31][i] = '=';
                    qaza[34][i] = '=';
                    qaza[37][i] = '=';
                    qaza[40][i] = '=';
                    qaza[43][i] = '=';
                    qaza[46][i] = '=';
                }
                // for(int i = 0; i < 28 ; i++)
                // {
                //     qaza
                // }
            }
            else
            {
                if(g == 4)
                {
                    
                    for(int i = 1; i < 49;i++)
                    {
                        qaza[i][3] = '|';
                        qaza[i][6] = '|';
                        qaza[i][9] = '|';
                        qaza[i][12] = '|';
                        qaza[i][15] = '|';
                        qaza[i][18] = '|';
                        qaza[i][21] = '|';
                        qaza[i][30] = '|';
                        qaza[i][33] = '|';
                        qaza[i][36] = '|';
                        qaza[i][39] = '|';
                        // qaza[4][39] = '.';
                        // qaza[30][39] = '.';
                        qaza[i][42] = '|';
                        // qaza[2][42] = '.';
                        // qaza[30][42] = '.';
                        qaza[i][45] = '|';
                        qaza[i][48] = '|';
                        // qaza[3][i] = '=';
                        // qaza[3][3] = '.';
                        qaza[6][i] = '=';
                        qaza[9][i] = '=';
                        qaza[12][i] = '=';
                        qaza[15][i] = '=';
                        qaza[18][i] = '=';
                        qaza[21][i] = '=';
                        qaza[24][i] = '=';
                        qaza[27][i] = '=';
                        qaza[30][i] = '=';
                        qaza[33][i] = '=';
                        qaza[36][i] = '=';
                        qaza[39][i] = '=';
                        qaza[42][i] = '=';
                        qaza[45][i] = '=';
                        qaza[48][i] = '=';
                        // qaza[i][i] = '2';
                        // qaza[-i][i] = '.';
                        // qaza[i][-i] = '.';
                        // qaza[-i][-i] = '.';
                    }
                    for(int i = 1; 3*i < 49; i++)
                    {
                        for(int j = 1; 3*j < 49; j++)
                        {
                            qaza[3*i][3*j] = '.';
                        }
                    }
                    for(int i = 1; 2*i < 49; i++)
                    {
                        qaza[2*i][3] = '.';
                        qaza[2*i][6] = '.';
                        qaza[2*i][9] = '.';
                        qaza[2*i][12] = '.';
                        qaza[2*i][15] = '.';
                        qaza[2*i][18] = '.';
                        qaza[2*i][21] = '.';
                        qaza[2*i][24] = '.';
                        qaza[2*i][27] = '.';
                        qaza[2*i][30] = '.';
                        qaza[2*i][33] = '.';
                        qaza[2*i][36] = '.';
                        qaza[2*i][39] = '.';
                        qaza[2*i][42] = '.';
                        qaza[2*i][45] = '.';
                        qaza[2*i][48] = '.';
                    }
                    

                }
            }
        }
    }
    char jahat = 'd';
    enemy1.x = 31;
    enemy1.y = 31;
    enemy2.x = 10;
    enemy2.y = 10;
    enemy3.x = 11;
    enemy3.y = 11;
    enemy4.x = 41;
    enemy4.y = 41;    
    enemy4.h = '#';
    enemy1.h = '#';
    enemy2.h = '#';
    enemy3.h = '#';
    pacman.x = 20;
    pacman.y = 20;
    pacman.h = '@';
    int r;//harekat enemy
    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
    while(1)
    {
        if(!kbhit())
        {
            switch(jahat)
            {
                case 'w':
                // srand(time(NULL)*2);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy4 = farar(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == 1)//pacman khord
                    {
                        v = 0;
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }
                }
                else
                {
                    enemy4 = taqeeb(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == -1)//game over
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*3);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                    enemy3 = farar(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy3 = taqeeb(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*4);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy1 = farar(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy1 = taqeeb(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }    
                // srand(time(NULL)*5);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy2 = farar(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy2 = taqeeb(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                if((qaza[pacman.y - 1][pacman.x] == '|')||(qaza[pacman.y - 1][pacman.x] == '='))
                {
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                    int o = 0;
                    break;
                }
                else
                {
                    pacman = up(pacman);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }

                    }
                    else
                    {
                    if((check1(pacman,enemy1) == 0 )||(check1(pacman,enemy2)==0)||(check1(pacman,enemy3) == 0)||(check1(pacman,enemy4) == 0))
                    {
                        system("clear");
                        check3(bscore);
                        int q = 0;
    int m[7];
    while(q < 50)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                        score = 0;
                        return -1;
                    }
                    }
                    if(qaza[pacman.y][pacman.x] == '.')
                    {
                        qaza[pacman.y][pacman.x] = ' ';
                        score++;
                    }  
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                }
                if(check5(qaza) == 0)
                {
                    system("clear");
                    printf("\n FINISH!");
                    return -1;
                }
                    break;
                    case 's':
                    srand(time(NULL)*6);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy4 = farar(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy4 = taqeeb(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*7);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy3 = farar(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy3 = taqeeb(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*8);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy1 = farar(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy1 = taqeeb(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*9);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy2 = farar(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy2 = taqeeb(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                    if((qaza[pacman.y + 1][pacman.x] == '|')||(qaza[pacman.y + 1][pacman.x] == '='))
                {

                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                    int o = 0;
                    break;
                }
                else
                {
                    
                    pacman = down(pacman);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }
                    else
                    {
                    if((check1(pacman,enemy1) == 0 )||(check1(pacman,enemy2)==0)||(check1(pacman,enemy3) == 0)||(check1(pacman,enemy4) == 0))
                    {
                        system("clear");
                        check3(bscore);
                        int q = 0;
    int m[7];
    while(q < 50)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
                        score = 0;
                        return -1;
                    }
                    }
                    if(qaza[pacman.y][pacman.x] == '.')
                    {
                        qaza[pacman.y][pacman.x] = ' ';
                        score++;
                    }  
                
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                }
                if(check5(qaza) == 0)
                {
                    system("clear");
                    printf("\n FINISH!");
                    return -1;
                }    
                break;
                case 'd':
                // srand(time(NULL)*10);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy4 = farar(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy4 = taqeeb(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*11);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy3 = farar(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy3 = taqeeb(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*12);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy1 = farar(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy1 = taqeeb(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*13);
                   if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy2 = farar(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy2 = taqeeb(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                if((qaza[pacman.y][pacman.x + 1] == '|')||(qaza[pacman.y][pacman.x + 1] == '='))
                {

                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                    int o = 0;
                    break;
                }
                else
                {
                    pacman = right(pacman);
                   if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }

                    }
                    else
                    {
                    if((check1(pacman,enemy1) == 0 )||(check1(pacman,enemy2)==0)||(check1(pacman,enemy3) == 0)||(check1(pacman,enemy4) == 0))
                    {
                        system("clear");
                        check3(bscore);
                        int q = 0;
    int m[7];
    while(q < 50)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                        score = 0;
                        return -1;
                    }
                    }
                    if(qaza[pacman.y][pacman.x] == '.')
                    {
                        qaza[pacman.y][pacman.x] = ' ';
                        score++;
                    }  
                
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                }
                break;
                if(check5(qaza) == 0)
                {
                    system("clear");
                    printf("\n FINISH!");
                    return -1;
                }
                case 'a':  
                // srand(time(NULL)*14); 
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy4 = farar(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy4 = taqeeb(pacman,enemy4,r,level,qaza,4,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*15);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy3 = farar(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy3 = taqeeb(pacman,enemy3,r,level,qaza,3,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                // srand(time(NULL)*16);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy1 = farar(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy1 = taqeeb(pacman,enemy1,r,level,qaza,1,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                    
                // srand(time(NULL)*17);
                if((50 < (score % 100)) &&((score % 100) < 100))
                {
                    enemy2 = farar(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == 1)
                    {
                        v = 0;
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                    }

                }
                else
                {
                    enemy2 = taqeeb(pacman,enemy2,r,level,qaza,2,bscore);
                    if(v == -1)
                    {
                        v = 0;
                        return -1;
                    }
                }
                if((qaza[pacman.y][pacman.x - 1] == '|')||(qaza[pacman.y][pacman.x - 1] == '='))
                {
                    int o = 0;
                    while(o < 100000000)
                    {
                        o++;
                    }
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                    o = 0;
                    break;
                }
                else
                {
                    pacman = left(pacman);
                    if((50 < (score % 100)) &&((score % 100) < 100))
                    {
                        enemy1 = check4(pacman,enemy1,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy2 = check4(pacman,enemy2,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy3 = check4(pacman,enemy3,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }
                        enemy4 = check4(pacman,enemy4,bscore);
                        if(u == 1)
                        {
                        score = score + 100;
                        u = 0;
                        }

                    }
                    else
                    {
                    if((check1(pacman,enemy1) == 0 )||(check1(pacman,enemy2)==0)||(check1(pacman,enemy3) == 0)||(check1(pacman,enemy4) == 0))
                    {
                        system("clear");
                        check3(bscore);
                        int q = 0;
    int m[7];
    while(q < 50)
    {
        q++;
        system("clear");
        srand(time(NULL)*2*q);
        m[0] = rand() % 5 + 31;
        printf("\033[1;%dm",m[0]);
        printf("G");
        srand(time(NULL)*3*q);
        m[1] = rand() % 5 + 31;
        printf("\033[1;%dm",m[1]);
        printf("A");
        srand(time(NULL)*4*q);
        m[2] = rand() % 5 + 31;
        printf("\033[1;%dm",m[2]);
        printf("M");
        srand(time(NULL)*5*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("E ");
        srand(time(NULL)*6*q);
        m[3] = rand() % 5 + 31;
        printf("\033[1;%dm",m[3]);
        printf("O");
        srand(time(NULL)*7*q);
        m[4] = rand() % 5 + 31;
        printf("\033[1;%dm",m[4]);
        printf("V");
        srand(time(NULL)*8*q);
        m[5] = rand() % 5 + 31;
        printf("\033[1;%dm",m[5]);
        printf("E");
        srand(time(NULL)*9*q);
        m[6] = rand() % 5 + 31;
        printf("\033[1;%dm",m[6]);
        printf("R");
        printf("\033[0m\n");
        int o = 0;

        while(o < 100000000)
        {
            o++;
        }
    }
    printf("\033[0m");
                        score = 0;
                        return -1;
                    }
                    }
                    if(qaza[pacman.y][pacman.x] == '.')
                    {
                        qaza[pacman.y][pacman.x] = ' ';
                        score++;
                    }  
                
                    print_table(pacman,qaza,enemy1,enemy2,enemy3,enemy4,bscore,cl);
                }
                if(check5(qaza) == 0)
                {
                    system("clear");
                    printf("\n FINISH!");
                    return -1;
                }
                break;
            }
        }
        else
        {
            char jahat2 = getchar();
        if(jahat2 == 'm')
        {
            score = 0;
            break;
        }
        if(jahat2 == 'p')
        {
            system("clear");
            printf("\033[1m");
            printf("press 'w' or 's' or 'd' or 'a' to continue!");
            printf("\033[0m");
            while(1)
            {
                if(kbhit())
                {
                    break;
                }
            }
        }
            jahat = jahat2;
            continue; 
        }
        int o = 0;
        while(o < 100000000)
        {
            o++;
        }
    }

}
int sath()//level
{
    int c;
    system("clear");
    printf("\033[0m");
    printf("\033[1m");
    printf("\n1.Very Easy");
    printf("\033[0m");
    printf("\033[1;33m");
    printf("\n2.Easy");
    printf("\033[0m");
    printf("\033[1;32m");
    printf("\n3.Normal");
    printf("\033[0m");
    printf("\033[1;35m");
    printf("\n4.Hard");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("\n5.Very Hard\n\n");
    printf("\033[0m");
    printf("\033[1m");
    printf("\n level : ");
    scanf("%d",&c);
    printf("\033[0m");
    switch(c)
    {
        case 1:
        return 0;
        break;
        case 2:
        return 1;
        break;
        case 3:
        return 2;
        break;
        case 4:
        return 3;
        break;
        case 5:
        return 4;
        break;
    }
}
int map(int g)//map
{
    system("clear");
    char ans;
    while(1)
    {
        printf("\033[1m");
        printf("\n 1.One");
        printf("\n 2.Two");
        printf("\n 3,Tree");
        printf("\n 4.Four");
        printf("\n choose : ");
        scanf("%d",&g);
        printf("\033[0m");
        char qaza[50][50];
    for(int i = 0 ; i< 50 ; i++)
            {
                for(int j = 0 ; j< 50 ; j++)
                {
                    qaza[j][i] = ' ';
                }
            }
            for(int i = 0 ; i < 50 ; i++)
            {
                qaza[i][0] = '|';
                qaza[i][49] = '|';
                qaza[0][i] = '=';
                qaza[49][i] = '=';
            }
            qaza[14][13] = '|';
            qaza[13][13] = '|';
            qaza[13][12] = '=';
            qaza[14][11] = '|';
            qaza[13][11] = '|'; 

    //  char qaza[50][50];
    for(int i = 0 ; i< 50 ; i++)
            {
                for(int j = 0 ; j< 50 ; j++)
                {
                    qaza[j][i] = '.';
                }
            }
            for(int i = 0 ; i < 50 ; i++)
            {
                qaza[i][0] = '|';
                qaza[i][49] = '|';
                qaza[0][i] = '=';
                qaza[49][i] = '=';
            }
            qaza[14][13] = '|';
            qaza[13][13] = '|';
            qaza[13][12] = '=';
            qaza[14][11] = '|';
            qaza[13][11] = '|'; 

    if (g == 1)
        {

        for(int i = 1; i < 20;i++)
        {
            qaza[i][5] = '|';
            qaza[i][30] = '|';
            qaza[35][i] = '=';
            qaza[i][25] = '|';
            qaza[i][20] = '|';
        }
        for(int i = 0; i < 5;i++)
        {
            qaza[i][47] = '|';
        }
        qaza[14][13] = '|';
        qaza[13][13] = '|';
        qaza[13][12] = '=';
        qaza[14][11] = '|';
        qaza[13][11] = '|';
        for(int i = 50 ; i > 30; i--)
        {
            qaza[i][30] = '|';
            qaza[21][i] = '=';
            qaza[27][i] = '=';
        }
    }
    else
    {
        if(g == 2)
        {
             
            for(int i = 20; i < 30; i++)
            {
                qaza[29][i] = '=';
                qaza[i][19] = '|';
            }
            for(int i = 0; i < 13; i++)
            {
                qaza[i][28] = '|';
                qaza[28][i] = '=';
                qaza[i][16] = '|';
            }
            for(int i = 25; i > 10 ; i--)
            {
                qaza[i][14] = '|';
                qaza[i][40] = '|';
                qaza[25][i] = '=';
                qaza[40][i] = '=';
            }
            for(int i = 10; i < 18; i++)
            {
                qaza[i][18] = '|';
                qaza[i + 6][25] = '|';
                qaza[i + 10][29] = '|';
            }
            for(int i = 0; i < 19; i++)
            {
                qaza[i + 2][4] = '|';
                qaza[4][i + 21] = '=';
            }
            for(int i = 50; i > 30;i--)
            {
                // qaza[i][20] = '|';
                qaza[40][i] = '=';
            }

        }
        else
        {
            if(g == 3)
            {
                for(int i = 0; i < 28; i++)
                {
                    qaza[i][28] = '|';
                    qaza[i][31] = '|';
                    qaza[i][34] = '|';
                    qaza[i][37] = '|';
                    qaza[i][40] = '|';
                    qaza[i][43] = '|';
                    qaza[i][46] = '|';
                    qaza[i][19] = '|';
                    // qaza[28][i] = '=';
                    qaza[31][i] = '=';
                    qaza[34][i] = '=';
                    qaza[37][i] = '=';
                    qaza[40][i] = '=';
                    qaza[43][i] = '=';
                    qaza[46][i] = '=';
                }
                // for(int i = 0; i < 28 ; i++)
                // {
                //     qaza
                // }
            }
            else
            {
                if(g == 4)
                {
                    
                    for(int i = 1; i < 49;i++)
                    {
                        qaza[i][3] = '|';
                        qaza[i][6] = '|';
                        qaza[i][9] = '|';
                        qaza[i][12] = '|';
                        qaza[i][15] = '|';
                        qaza[i][18] = '|';
                        qaza[i][21] = '|';
                        qaza[i][30] = '|';
                        qaza[i][33] = '|';
                        qaza[i][36] = '|';
                        qaza[i][39] = '|';
                        // qaza[4][39] = '.';
                        // qaza[30][39] = '.';
                        qaza[i][42] = '|';
                        // qaza[2][42] = '.';
                        // qaza[30][42] = '.';
                        qaza[i][45] = '|';
                        qaza[i][48] = '|';
                        // qaza[3][i] = '=';
                        // qaza[3][3] = '.';
                        qaza[6][i] = '=';
                        qaza[9][i] = '=';
                        qaza[12][i] = '=';
                        qaza[15][i] = '=';
                        qaza[18][i] = '=';
                        qaza[21][i] = '=';
                        qaza[24][i] = '=';
                        qaza[27][i] = '=';
                        qaza[30][i] = '=';
                        qaza[33][i] = '=';
                        qaza[36][i] = '=';
                        qaza[39][i] = '=';
                        qaza[42][i] = '=';
                        qaza[45][i] = '=';
                        qaza[48][i] = '=';
                        // qaza[i][i] = '2';
                        // qaza[-i][i] = '.';
                        // qaza[i][-i] = '.';
                        // qaza[-i][-i] = '.';
                    }
                    for(int i = 1; 3*i < 49; i++)
                    {
                        for(int j = 1; 3*j < 49; j++)
                        {
                            qaza[3*i][3*j] = '.';
                        }
                    }
                    for(int i = 1; 2*i < 49; i++)
                    {
                        qaza[2*i][3] = '.';
                        qaza[2*i][6] = '.';
                        qaza[2*i][9] = '.';
                        qaza[2*i][12] = '.';
                        qaza[2*i][15] = '.';
                        qaza[2*i][18] = '.';
                        qaza[2*i][21] = '.';
                        qaza[2*i][24] = '.';
                        qaza[2*i][27] = '.';
                        qaza[2*i][30] = '.';
                        qaza[2*i][33] = '.';
                        qaza[2*i][36] = '.';
                        qaza[2*i][39] = '.';
                        qaza[2*i][42] = '.';
                        qaza[2*i][45] = '.';
                        qaza[2*i][48] = '.';
                    }
                    

                }
            }
        }
    }
        printf("\033[1m");
        for(int i = 0; i < 50 ; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if((qaza[i][j] == '|') || ( qaza[i][j] == '='))
                {
                    printf("\033[1;34m");
                    printf("%c",qaza[i][j]);
                    printf("%c",qaza[i][j]);
                    printf("\033[0m");
                }
                else
                {
                printf("%c",qaza[i][j]);
                printf(" ");
                }
            }
            printf("\n");
        }
        printf("\033[1m");
        printf("\033[0m");
        printf("\033[1,31m");
        printf("\nSure?[Y/N]");
        printf("\033[0m");
        printf("\033[1m");
        // char ans;
        scanf("\n%c",&ans);
        printf("\033[0m");
        if((ans == 'Y') || (ans == 'y'))
        {
            return g;
            break;
        }
        if((ans == 'n')||(ans == 'N'))
        {
            system("clear");
        }
    }
}
int color()//color
{
    int c;
    system("clear");
    printf("\033[1;31m");
    printf("\n1.Red");
    printf("\033[1;34m");
    printf("\n2.Blue");
    printf("\033[1;33m");
    printf("\n3.Yellow");
    printf("\033[1;32m");
    printf("\n4.Green");
    printf("\033[1;36m");
    printf("\n5.Blue2");
    printf("\033[1;35m");
    printf("\n6.purple");
    printf("\033[0m");
    printf("\033[1m");
    printf("\nchoose : ");
    printf("\033[0m");
    printf("\033[1m");
    scanf("%d",&c);
    printf("\033[0m");
    switch(c)
    {
        case 1:
        return 31;
        break;
        case 2:
        return 34;
        break;
        case 3:
        return 33;
        break;
        case 4:
        return 32;
        break;
        case 5:
        return 36;
        case 6:
        return 35;
        break;
    }
}
int main()
{
    int cl = 33;
    int p = 0;
    int n[7];
    while(p < 50)
    {
        p++;
        system("clear");
        srand(time(NULL)*2*p);
        n[0] = rand() % 5 + 31;
        printf("\033[7;%dm",n[0]);
        printf("W");
        srand(time(NULL)*3*p);
        n[1] = rand() % 5 + 31;
        printf("\033[1;%dm",n[1]);
        printf("E");
        srand(time(NULL)*4*p);
        n[2] = rand() % 5 + 31;
        printf("\033[1;%dm",n[2]);
        printf("L");
        srand(time(NULL)*5*p);
        n[3] = rand() % 5 + 31;
        printf("\033[1;%dm",n[3]);
        printf("L");
        srand(time(NULL)*6*p);
        n[3] = rand() % 5 + 31;
        printf("\033[1;%dm",n[3]);
        printf("C");
        srand(time(NULL)*7*p);
        n[4] = rand() % 5 + 31;
        printf("\033[1;%dm",n[4]);
        printf("O");
        srand(time(NULL)*8*p);
        n[5] = rand() % 5 + 31;
        printf("\033[1;%dm",n[5]);
        printf("M");
        srand(time(NULL)*9*p);
        n[6] = rand() % 5 + 31;
        printf("\033[1;%dm",n[6]);
        printf("E");
        printf("\033[0m\n");
        int o = 0;
        while(o < 100000000)
        {
            o++;
        }
    }
    int choos;
    int level = 1;
    int g = 1;
    while(1)
    {
        char qaza[50][50];
        system("clear");
        printf("\033[1;32m");
        printf("\n%8s","MENU");
        printf("\n%9s","-----");
        printf("\033[0m");
        printf("\033[1m");
        printf("\n%10s","1.Play");
        printf("\n%18s","2.show records");
        printf("\n%11s","3.color");
        printf("\n%9s","4.Map");
        printf("\n%11s","5.Level");
        printf("\n%10s","6.Exit");
        printf("\033[1;31m");
        printf("\n    choose : ");
        printf("\033[0m");
        printf("\033[1m");
        scanf("%d",&choos);
        printf("\033[0m")
        
        ;
        switch(choos)
        {
            // int g = 1;
            case 1:
            play(level,g,cl);
            break;
            case 2:
            show();
            break;
            case 3:
            cl = color();
            break;
            case 4:
            g = map(g);
            break;
            case 5:
            level = sath();
            break;
            case 6:
            return -1;
            break;
        }
    }
    
}

