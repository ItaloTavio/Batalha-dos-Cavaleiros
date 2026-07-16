#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


void AnimaAtaqueEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova);
void AnimaAtaqueEsquerdoDefendido(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50]);
void AnimaPosicaoDefesaEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50]);
void AnimaCuraEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova);
void AnimaRodadaPerdida(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50]);
void AnimaAtaqueDireitoDefendido(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50]);
void AnimaAtaqueDireito(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova);
void AnimaPosicaoDefesaDireito(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50]);
void AnimaCuraDireito (int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova);
void AnimaCastelo ();
void AnimaFim (int VidaEsquerda, char NomeEsquerda[50], char NomeDireita[50]);

int Dano ();
int Cura ();
void RandonNome(int *Indice_Prefixo, int *Indice_Sufixo, int *Indice_Sobrenome, int *Indice_Titulos);




int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    srand(time(NULL));

    
    
    char prefixos[10][10] = {"Maxi", "Vale", "Aure", "Tibe", "Luci", "Flavi", "Cassi", "Octa", "Domi", "Septi"};
    char sufixos[10][10] = {"mus", "rius", "lian", "nus", "tus", "vian", "cus", "dor", "ron", "lus"};
    char sobrenome[10][15]= {" Severus", " Agrippa", " Corvus", " Aquila", " Falco", " Lupos", " Gracchus ", " Marcellus", " Trajanus", " César"};
    char titulos[10][20] = {", o Invicto!", ", o Imortal!", ", o Sanguinário!", ", o Destruidor!", ", o Colosso!", ", o Implacável!", ", o Carrasco!", ", o Temível!", ", o Glorioso!", ", o Flagelo!"};
    char Nome_Comp_Gladiador1[50]={""}, Nome_Comp_Gladiador2[50]={""};
    
    int  Indice_Prefixo, Indice_Sufixo, Indice_Sobrenome, Indice_Titulos, Vida_Gladiador1 = 100, Vida_Gladiador2 = 100, Defesa2 = 0, Defesa1 = 0, VarControl_Rodada, VarControl_Escolha, VarSwap;
    
    RandonNome(&Indice_Prefixo, &Indice_Sufixo, &Indice_Sobrenome, &Indice_Titulos);

    strcpy(Nome_Comp_Gladiador1, prefixos[Indice_Prefixo]);
    strcat(Nome_Comp_Gladiador1, sufixos[Indice_Sufixo]);
    strcat(Nome_Comp_Gladiador1, sobrenome[Indice_Sobrenome]);
    strcat(Nome_Comp_Gladiador1, titulos[Indice_Titulos]);

    RandonNome(&Indice_Prefixo, &Indice_Sufixo, &Indice_Sobrenome, &Indice_Titulos);

    strcpy(Nome_Comp_Gladiador2, prefixos[Indice_Prefixo]);
    strcat(Nome_Comp_Gladiador2, sufixos[Indice_Sufixo]);
    strcat(Nome_Comp_Gladiador2, sobrenome[Indice_Sobrenome]);
    strcat(Nome_Comp_Gladiador2, titulos[Indice_Titulos]);
    
    printf("\n\n");
    
    AnimaCastelo();
    
    printf("\n\n");

    
   Sleep(4000);

    system("cls");

    printf(" Na Batalha Sanguinária de hoje teremos duas LENDAS deste Coliseu, que lutarão até a MORTE!!\n\n");

    printf("=======================================================================\n %s VS %s\n=======================================================================\n", Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);

    printf("    O |           | O \n");
    printf("   -+-|           |-+-\n ");
    printf("  / \\|           |/ \\\n");
    
    printf("=======================================================================\n");
    Sleep(4000);
    system("cls");
 
    VarControl_Rodada= rand() % 2;

    while (Vida_Gladiador1>0 && Vida_Gladiador2>0)
    {  if (VarControl_Rodada %2 == 0)
       {   VarControl_Escolha = rand() % 5;
           
            if (VarControl_Escolha %2 == 0) /* Então teremos uma rodada de ataque*/
            {
                if (Defesa2 == 1) /* Então o gladiador dois defendeu o ataque*/
                {   
                    Defesa2 = 0;

                    AnimaAtaqueEsquerdoDefendido(Vida_Gladiador1,Vida_Gladiador2,Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);

                }
                else /* Então o gladiador 1 ataca e acerta*/
                {
                    VarSwap = Vida_Gladiador2;
                    Vida_Gladiador2 -= Dano();

                   AnimaAtaqueEsquerdo(Vida_Gladiador1, VarSwap, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2, Vida_Gladiador2);
                }
                
            }

            else if ( VarControl_Escolha == 1) /*Estão gladiador 1 assume defesa*/
            {
                Defesa1 = 1;

               AnimaPosicaoDefesaEsquerdo(Vida_Gladiador1, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);
            }

            else if ( VarControl_Escolha == 3) /* Então Gladiador 1 se cura*/
            {
                if(Vida_Gladiador1<50)
                { 
                  VarSwap = Vida_Gladiador1;
                  Vida_Gladiador1 +=  Cura();
                  if (Vida_Gladiador1>100)
                  {
                    Vida_Gladiador1 = 100;
                  }

                  AnimaCuraEsquerdo(VarSwap, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2, Vida_Gladiador1);

                }

                else /* Então Como a vida está alta para ser curada, ele vai hesitar*/
                {
                  AnimaRodadaPerdida(Vida_Gladiador1, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);
                }
            }
            

            
       }

       else
       {
           VarControl_Escolha = rand() % 5;

           if (VarControl_Escolha %2 == 0) /* Então teremos uma rodada de ataque*/

           {
              if(Defesa1 == 1) /*Então Gladiador 1 defendeu*/
              {
                 Defesa1 = 0;

                 AnimaAtaqueDireitoDefendido(Vida_Gladiador1, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);

              }

              else /*Então gladiador dois atacou*/
              {  
                  VarSwap = Vida_Gladiador1;
                  Vida_Gladiador1 -= Dano();

                  AnimaAtaqueDireito(VarSwap, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2, Vida_Gladiador1); 

              }
           } 

           else if (VarControl_Escolha == 1) /*Então gladiador dois assume posição de defesa*/
           {
              Defesa2 = 1;

              AnimaPosicaoDefesaDireito(Vida_Gladiador1,Vida_Gladiador2,Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);


           }

           else if (VarControl_Escolha == 3)
           {
              if(Vida_Gladiador2 < 50) /*Então ele se cura*/
              {  
                  VarSwap = Vida_Gladiador2;
                  Vida_Gladiador2 +=  Cura();
                  if(Vida_Gladiador2>100) 
                  {
                    Vida_Gladiador2=100;
                  }

                  AnimaCuraDireito(Vida_Gladiador1, VarSwap, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2, Vida_Gladiador2);

              }

              else
              {
                 AnimaRodadaPerdida(Vida_Gladiador1, Vida_Gladiador2, Nome_Comp_Gladiador1, Nome_Comp_Gladiador2);
              }

           }

       }
    

       VarControl_Rodada++;
    }

    AnimaFim(Vida_Gladiador1,Nome_Comp_Gladiador1,Nome_Comp_Gladiador2);

    printf("Pressione ENTER para fechar o jogo...:");
    getchar();




return 0;
}












/* ---------------------------------------------Modularização----------------------------------------------------------------------------------*/








void AnimaAtaqueEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNovaDireita)
{
            system("cls");
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");
    
            printf("   O |                         | O   \n");
            printf("  -+-|                         |-+-  \n");
            printf("  / \\|                         |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("Vida do %s: %d\n",  NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n",  NomeDireita, VidaDireita);
            Sleep(2000);


            system("cls"); 
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");
    
            printf("             O |               | O   \n");
            printf("            -+-|               |-+-  \n");
            printf("            / \\|               |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
            Sleep(2000); 


            system("cls"); 
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");

            printf("                           O | | O   \n");
            printf("                          -+-|>|-+-  \n");
            printf("                          / \\| |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("POW!\n");
            printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
            Sleep(2000); 


   
           system("cls"); 
           printf("\n==========================================\n");
           printf("              TURNO DE ATAQUE               \n");
           printf("==========================================\n\n");
    
           printf("             O |               | O   \n");
           printf("            -+-|               |-+-  \n");
           printf("            / \\|               |/ \\  \n");
    
           printf("\n==========================================\n");
           printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
           printf("Vida do %s: %d\n", NomeDireita, VidaNovaDireita);
           Sleep(2000);


           system("cls"); 
           printf("\n==========================================\n");
           printf("              TURNO DE ATAQUE               \n");
           printf("==========================================\n\n");
    
           printf("   O |                         | O   \n");
           printf("  -+-|                         |-+-  \n");
           printf("  / \\|                         |/ \\  \n");
    
           printf("\n==========================================\n");
           printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
           printf("Vida do %s: %d\n", NomeDireita, VidaNovaDireita);
           Sleep(2000);
           
            
}

void AnimaAtaqueEsquerdoDefendido(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50])
{
            system("cls");         
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");
    
            printf("   O |                         | O   \n");
            printf("  -+-|                         |-+-  \n");
            printf("  / \\|                         |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("Vida do %s: %d\n",  NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n",  NomeDireita, VidaDireita);
            Sleep(2000);


            system("cls"); 
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");
    
            printf("             O |               | O   \n");
            printf("            -+-|               |-+-  \n");
            printf("            / \\|               |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
            Sleep(2000); 


            system("cls"); 
            printf("\n==========================================\n");
            printf("              TURNO DE ATAQUE               \n");
            printf("==========================================\n\n");

            printf("                           O | | O   \n");
            printf("                          -+-|>|-+-  \n");
            printf("                          / \\| |/ \\  \n");
    
            printf("\n==========================================\n");
            printf("POW! Golpe defendido!!!\n");
            printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
            printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
            Sleep(2000); 


   
           system("cls"); 
           printf("\n==========================================\n");
           printf("              TURNO DE ATAQUE               \n");
           printf("==========================================\n\n");
    
           printf("             O |               | O   \n");
           printf("            -+-|               |-+-  \n");
           printf("            / \\|               |/ \\  \n");
    
           printf("\n==========================================\n");
           printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
           printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
           Sleep(2000);


           system("cls"); 
           printf("\n==========================================\n");
           printf("              TURNO DE ATAQUE               \n");
           printf("==========================================\n\n");
    
           printf("   O |                         | O   \n");
           printf("  -+-|                         |-+-  \n");
           printf("  / \\|                         |/ \\  \n");
    
           printf("\n==========================================\n");
           printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
           printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
           Sleep(2000);
           
        
}
void AnimaPosicaoDefesaEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50])
{
           system("cls");
           printf("\n==========================================\n");
           printf("          ASSUMINDO POSIÇÃO DE DEFESA               \n");
           printf("==========================================\n\n");
    
           printf("   O |                        \n");
           printf("  -+-|                        \n");
           printf("  / \\|                        \n");
    
           printf("\n==========================================\n");
           printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
           printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
           Sleep(2000);
}

void AnimaCuraEsquerdo(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova)
{
  
          system("cls");
          printf("\n==========================================\n");
          printf("             ESTANCANDO FERIMENTO             \n");
          printf("==========================================\n\n");
    
          printf("   O |                         | O   \n");
          printf("  -+-|                         |-+-  \n");
          printf("  / \\|                         |/ \\  \n");
    
          printf("\n==========================================\n");
          printf("Vida do %s: %d\n", NomeEsquerda,VidaEsquerda);
          printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
          Sleep(2000);
          system("cls");

          printf("\n==========================================\n");
          printf("             ESTANCANDO FERIMENTO             \n");
          printf("==========================================\n\n");
          printf("   O |                         | O   \n");
          printf("  -+-|                         |-+-  \n");
          printf("  /_\\|                         |/ \\  \n");
          printf("\n==========================================\n");
          printf("Vida do %s: %d\n", NomeEsquerda,VidaEsquerda);
          printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
          Sleep(2000);
          system("cls");
 

          printf("\n==========================================\n");
          printf("             ESTANCANDO FERIMENTO             \n");
          printf("==========================================\n\n");
    
          printf("   O |                         | O   \n");
          printf("  -+-|                         |-+-  \n");
          printf("  / \\|                         |/ \\  \n");
    
          printf("\n==========================================\n");
          printf("Vida do %s: %d\n", NomeEsquerda, VidaNova);
          printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
          Sleep(2000);
          
}

void AnimaRodadaPerdida(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50])
{         
          system("cls");
          printf("\n==========================================\n");
          printf("    O GLADIADOR HESITOU...TURNO PERDIDO     \n");
          printf("==========================================\n\n");
    
          printf("   O |                         | O   \n");
          printf("  -+-|                         |-+-  \n");
          printf("  / \\|                         |/ \\  \n");
    
          printf("\n==========================================\n");
          printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
          printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
          Sleep(2000);
          
}

void AnimaAtaqueDireitoDefendido(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50])

{
              system("cls");
              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
     
              printf("   O |               | O   \n");
              printf("  -+-|               |-+-  \n");
              printf("  / \\|               |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O | | O   \n");
              printf("  -+-|<|-+-  \n");
              printf("  / \\| |/ \\  \n");
    
              printf("\n==========================================\n");
              printf( "POW!! GOLPE DEFENDIDO!");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |               | O   \n");
              printf("  -+-|               |-+-  \n");
              printf("  / \\|               |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              
              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
}

void AnimaAtaqueDireito(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova)
{
              system("cls"); 
              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
     
              printf("   O |               | O   \n");
              printf("  -+-|               |-+-  \n");
              printf("  / \\|               |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O | | O   \n");
              printf("  -+-|<|-+-  \n");
              printf("  / \\| |/ \\  \n");
    
              printf("\n==========================================\n");
              printf( "POW!");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |               | O   \n");
              printf("  -+-|               |-+-  \n");
              printf("  / \\|               |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaNova);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              
              printf("\n==========================================\n");
              printf("              TURNO DE ATAQUE               \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaNova);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(3000);
              
}

void AnimaPosicaoDefesaDireito(int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50])
{

              system("cls"); 
              printf("\n==========================================\n");
              printf("         ASSUMINDO POSIÇÃO DE DEFESA           \n");
              printf("==========================================\n\n");
    
              printf("                           | O   \n");
              printf("                           |-+-  \n");
              printf("                            |/ \\  \n");
    
              printf("\n==========================================\n");
              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);

}

void AnimaCuraDireito (int VidaEsquerda, int VidaDireita, char NomeEsquerda[50], char NomeDireita[50], int VidaNova)
{
              system("cls"); 
              printf("\n==========================================\n");
              printf("              ESTACANDO FERIMENTOS             \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");

              printf("\n==========================================\n");
    
              printf("Vida do %s: %d\n",NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("             ESTACANDO FERIMENTOS             \n");
              printf("==========================================\n\n");
              
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/_\\  \n");

              printf("\n==========================================\n");

              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaDireita);
              Sleep(2000);
              system("cls");

              printf("\n==========================================\n");
              printf("              ESTACANDO FERIMENTOS             \n");
              printf("==========================================\n\n");
    
              printf("   O |                         | O   \n");
              printf("  -+-|                         |-+-  \n");
              printf("  / \\|                         |/ \\  \n");

              printf("\n==========================================\n");

              printf("Vida do %s: %d\n", NomeEsquerda, VidaEsquerda);
              printf("Vida do %s: %d\n", NomeDireita, VidaNova);
              Sleep(2000);
}

void AnimaCastelo ()
{
        printf("                                  |>>>                    \n");
    printf("                                  |                       \n");
    printf("                    |>>>      _  _|_  _         |>>>      \n");
    printf("                    |        |;| |;| |;|        |         \n");
    printf("                _  _|_  _    \\\\.    .  /    _  _|_  _     \n");
    printf("               |;|_|;|_|;|    \\\\:  .  /    |;|_|;|_|;|    \n");
    printf("               \\\\..      /    ||:   |      \\\\..      /    \n");
    printf("                \\\\.  ,  /     ||:   |       \\\\.  ,  /     \n");
    printf("                 ||:+  |_   _ ||_ . _ | _   _||:+  |      \n");
    printf("                 ||:   | ||| ||| ||| ||| ||| ||:   |      \n");
    printf("                 ||:   | ||| ||| ||| ||| ||| ||:   |      \n");
    printf("                 ||:   |                     ||:   |      \n");
    printf("                 ||:   |   BATTLE OF THE     ||:   |      \n");
    printf("                 ||:   |      KNIGHTS        ||:   |      \n");
    printf("                 ||:   |                     ||:   |      \n");
    printf("                 ||:   |      _______        ||:   |      \n");
    printf("                 ||:   |     /       \\\\      ||:   |      \n");
    printf("                 ||:   |    /         \\\\     ||:   |      \n");
    printf("                 ||:   |   |  |   |   | |    ||:   |      \n");
    printf("                 ||:   |   |  |   |   | |    ||:   |      \n");
    printf("        _________||:___|___|__|___|___|_|____||:___|_________\n");

}

void AnimaFim (int VidaEsquerda, char NomeEsquerda[50], char NomeDireita[50])
{
    system("cls");
    printf("\n==========================================\n");
    printf("               FIM DE BATALHA               \n");
    printf("==========================================\n\n");

    if (VidaEsquerda > 0) {
        printf("   O |                         | o   \n"); 
        printf("  -+-|      V E N C E U !      |-+-  \n");
        printf("  / \\|                         |/_\\  \n"); 
        
        printf("\n==========================================\n");
        printf(" GRANDE CAMPEAO E %s!\n", NomeEsquerda); 
    } 
   
    else {
        printf("   o |                         | O   \n"); 
        printf("  -+-|      V E N C E U !      |-+-  \n");
        printf("  /_\\|                         |/ \\  \n"); 
        
        printf("\n==========================================\n");
        printf(" GRANDE CAMPEAO E %s\n",NomeDireita); 
    }
}

int Dano ()
{
    int Dano =  ((rand() % 16) + 15);
    
    return Dano;
}

int Cura()
{
    int Cura = ((rand() % 10) + 1);

    return Cura;
}

void RandonNome (int *Indice_Prefixo, int *Indice_Sufixo, int * Indice_Sobrenome, int * Indice_Titulos)
{
   *Indice_Prefixo = rand() % 10;
   *Indice_Sufixo = rand() % 10;
   *Indice_Sobrenome = rand() % 10;
   *Indice_Titulos = rand() % 10;

    
}

