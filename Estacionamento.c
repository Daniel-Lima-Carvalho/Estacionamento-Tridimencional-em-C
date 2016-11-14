#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct
{
	char placa[15];
	int mes;
	int dia;
	int ano;
	int hora;
	int minuto;
	double telefone;	
	
}Tcadastro;


void remover(Tcadastro cadastro[][10][8],int andar,int coluna,int vaga)
{
	strcpy(cadastro[andar][coluna][vaga].placa,"0");
	cadastro[andar][coluna][vaga].dia = 0;
	cadastro[andar][coluna][vaga].mes = 0;
	cadastro[andar][coluna][vaga].ano = 0;
	cadastro[andar][coluna][vaga].hora = 0;
	cadastro[andar][coluna][vaga].minuto = 0;
	cadastro[andar][coluna][vaga].telefone = 0;
}
void atualizar_mes(Tcadastro cadastro[][10][8], int mes, int andar, int coluna, int vaga)
{
	cadastro[andar][coluna][vaga].mes = mes;
}
void copiar_mensalista(int andar,int coluna, int vaga,Tcadastro cadastro[][10][8], char placa[], int mes, int dia, int ano,int hora, int minuto, double tel)
{
	strcpy(cadastro[andar][coluna][vaga].placa,placa);
	cadastro[andar][coluna][vaga].mes = mes;
	cadastro[andar][coluna][vaga].dia = dia;
	cadastro[andar][coluna][vaga].ano = ano;
	cadastro[andar][coluna][vaga].hora = hora;
	cadastro[andar][coluna][vaga].minuto = minuto;
	cadastro[andar][coluna][vaga].telefone = tel;
	
}
void copiar_rotativo(int andar,int coluna, int vaga,Tcadastro cadastro[][10][8], char placa[], int mes, int dia, int ano,int hora, int minuto)
{
	strcpy(cadastro[andar][coluna][vaga].placa,placa);
	cadastro[andar][coluna][vaga].mes = mes;
	cadastro[andar][coluna][vaga].dia = dia;
	cadastro[andar][coluna][vaga].ano = ano;
	cadastro[andar][coluna][vaga].hora = hora;
	cadastro[andar][coluna][vaga].minuto = minuto;
}

void ler_arquivo(FILE *arq,Tcadastro cadastro[][10][8])
{
	int i,j,k;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
					
				fscanf(arq,"%s   ",cadastro[i][j][k].placa);
				fscanf(arq,"%i ",&cadastro[i][j][k].dia);
				fscanf(arq,"%i ",&cadastro[i][j][k].mes);
				fscanf(arq,"%i   ",&cadastro[i][j][k].ano);
				fscanf(arq,"%i ",&cadastro[i][j][k].hora);
				fscanf(arq,"%i   ",&cadastro[i][j][k].minuto);
				fscanf(arq,"%d \n",&cadastro[i][j][k].telefone);
			}
		}
	}
}


int buscar_mensalista(char placa[],Tcadastro cadastro[][10][8],int *andar,int *coluna,int *vaga)
{
	int i,j,k; 
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
				if(strcmp(placa,cadastro[i][j][k].placa) == 0)
				{
					*andar = i;
					*coluna = j;
					*vaga = k;
					return 1;
				}
			}
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
				if(strcmp("0",cadastro[i][j][k].placa) == 0)
				{
					*andar = i;
					*coluna = j;
					*vaga = k;
					return 0;
				}
			}
		}
	}
	
}
int buscar_rotativo(char placa[],Tcadastro cadastro[][10][8],int *andar,int *coluna,int *vaga)
{
	int i,j,k;

	for(i=4;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
				if(strcmp(placa,cadastro[i][j][k].placa) == 0)
				{
					*andar = i;
					*coluna = j;
					*vaga = k;
					return 0;
				}
			}
		}
	}
	for(i=4;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
				if(strcmp("0",cadastro[i][j][k].placa) == 0)
				{
					*andar = i;
					*coluna = j;
					*vaga = k;
					return 1;
				}
			}
		}
	}
	
}

void escrever(Tcadastro cadastro[][10][8], FILE *arq)
{
	int i,j,k;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
		 	for(k=0;k<8;k++)
			{
				
				fprintf(arq,"%s   ",cadastro[i][j][k].placa);
				fprintf(arq,"%i ",cadastro[i][j][k].dia);
				fprintf(arq,"%i ",cadastro[i][j][k].mes);
				fprintf(arq,"%i   ",cadastro[i][j][k].ano);
				fprintf(arq,"%i ",cadastro[i][j][k].hora);
				fprintf(arq,"%i   ",cadastro[i][j][k].minuto);
				fprintf(arq,"%d \n",cadastro[i][j][k].telefone);	
			}
		}
	}

}

void apresentacao()
{
	printf("\n	   ESTACIONAMENTO PARK AL2 - Daniel Lima e Caio Felipe\n");
	printf("--------------------------------------------------------------------------------\n");
}

int calcular_rotativo(int dia,int mes,int ano,int hora,int minuto,int andar,int coluna,int vaga, Tcadastro cadastro[][10][8])
{
	int total, d_ano, d_mes, d_dias, d_hora, d_min,aux;
	
	d_ano = (ano - cadastro[andar][coluna][vaga].ano);
	d_mes =  (mes - cadastro[andar][coluna][vaga].mes);
	d_dias = (dia - cadastro[andar][coluna][vaga].dia);
	d_hora = (hora - cadastro[andar][coluna][vaga].hora);
	
	// Calculo do tempo de permanencia
	if(d_ano > 0)
	{
		d_mes = (d_ano - 1) * 12 + ((12 - cadastro[andar][coluna][vaga].mes) + mes);	
		
		d_dias = (d_mes - 1) * 30 + ((30 - cadastro[andar][coluna][vaga].dia) + dia);
		
		d_hora = (d_dias - 1) * 24 + ((24 - cadastro[andar][coluna][vaga].hora) + hora);
		
		d_min = (d_hora - 1) * 60 +  ((60 - cadastro[andar][coluna][vaga].minuto) + minuto);
	}
	else if(d_mes > 0)
	{
		d_dias = (d_mes - 1) * 30 + ((30 - cadastro[andar][coluna][vaga].dia) + dia);
		
		d_hora = (d_dias - 1) * 24 + ((24 - cadastro[andar][coluna][vaga].hora) + hora);
		
		d_min = (d_hora - 1) * 60 +  ((60 - cadastro[andar][coluna][vaga].minuto) + minuto);	
	}
	else if(d_dias > 0)
	{
		d_hora = (d_dias - 1) * 24 + ((24 - cadastro[andar][coluna][vaga].hora) + hora);
		
		d_min = (d_hora - 1) * 60 +  ((60 - cadastro[andar][coluna][vaga].minuto) + minuto);
	}
	else if(d_hora > 0)
	{
		d_min = (d_hora - 1) * 60 +  ((60 - cadastro[andar][coluna][vaga].minuto) + minuto);
	}
	else
	{
		d_min = (minuto - cadastro[andar][coluna][vaga].minuto);
	}
	
	// Calculo do preço de acordo com o tempo.
	if(d_min <= 30) // até 30 min
	{
		total = 4;
	}
	else if(d_min <= 60) // até 1 hora
	{
		total = 7;
	}
	else if(d_min <= 120) // até 2 horas
	{
		total = 12;
	}
	else if(d_min <= 240)// até 4 horas
	{
		total = 20;
	}
	else if(d_min <= 360)// até 6 horas
	{
		total = 30;
	}
	else if(d_min <= 480)// até 8 horas
	{
		total = 40;
	}
	else if(d_min <= 1440)// até 24 horas
	{
		total = 75;
	}
	else
	{
		aux = d_min / 1440;
		if(d_min % 1440 != 0)
		{
			total = 75 + (aux * 60);
		}
		else
		{
			total = 75 + ((aux-1) * 60);
		}	
	}
	return total;
}

int main() {
	
	
	Tcadastro cadastro[10][10][8];

	int opcao,tipo,res,andar,coluna,vaga,pagar,mensa,mes,dia,ano,hora,minuto,tot_rota;
	char placa[15];
	double tel;


	FILE *arq = fopen("cadastro.txt","r");

	ler_arquivo(arq,cadastro);
	
	apresentacao();

	printf("\n	(1)ENTRADA (2)SAIDA (3)FINALIZAR: ");
	scanf("%i",&opcao);
	while(opcao != 3)
	{
		if(opcao == 1) //ENTRADA
		{
			printf("\n	INFORME A DATA E HORA ATUAL DE ENTRADA.\n");
			printf("\n 	DIA, MES E ANO: ");
			scanf("%i %i %i",&dia, &mes, &ano);
			printf("\n 	HORA E MINUTO: ");
			scanf("%i %i", &hora, &minuto);
			system("cls");
			
			apresentacao();
			
			printf("\n 	(1)ROTATIVO (2)MENSALISTA: ");
			scanf("%i",&tipo);
			if(tipo == 1)// rotativo
			{
				printf("\n 	PLACA DO CARRO:  ");
				scanf("%s",placa);
				system("cls");
				
				apresentacao();
				
				res = buscar_rotativo(placa,cadastro,&andar,&coluna,&vaga);
				if(res == 0)
				{
					printf("\n        O CARRO JA SE ENCONTRA NO ESTACIONAMENTO! TENTE DENOVO!\n");
				}
				else
				{
					printf("\n         DISPONIVEL NO ANDAR %i COLUNA %i VAGA %i\n",andar+1,coluna+1,vaga+1);
					
					copiar_rotativo(andar,coluna,vaga,cadastro,placa,mes,dia,ano,hora,minuto);
				}
			}
			else if(tipo == 2)//mensalista
			{
				printf("\n	PLACA DO CARRO: ");
				scanf("%s",placa);
				
				res = buscar_mensalista(placa,cadastro,&andar,&coluna,&vaga);
				
				if(res == 1)
				{
					
					if( (cadastro[andar][coluna][vaga].mes < mes || cadastro[andar][coluna][vaga].ano < ano)  && cadastro[andar][coluna][vaga].dia == dia)
					{
						printf("\n        SUA FATURA VENCEU!");
						printf("\n\n        (1)PAGAR 500$ (0)DEIXAR DE SER MENSALISTA: ");
						scanf("%i",&pagar);
						system("cls");
						
						apresentacao();
						if(pagar == 1)
						{
							printf("\n	FATURA PAGA!");
							printf("\n\n        DISPONIVEL NO ANDAR %i COLUNA %i VAGA %i\n",andar+1,coluna+1,vaga+1);
							atualizar_mes(cadastro,mes,andar,coluna,vaga);
						}
						else
						{	printf("\n	CONTA DO MENSALISTA REMOVIDA\n!");
							remover(cadastro,andar,coluna,vaga);
						}
					}
					else
					{
						printf("\n         DISPONIVEL NO ANDAR %i COLUNA %i VAGA %i\n",andar+1,coluna+1,vaga+1);
					}
					
				}
				else
				{	
					printf("\n	NOVO CADASTRO");
					printf("\n\n	DIGITE O TELEFONE: ");
					scanf("%d",&tel);
					printf("\n	MENSALIDADE 500$. (1)PAGAR ou (0)DESISTIR: ");
					scanf("%i",&mensa);
					system("cls");
					apresentacao();
					if(mensa == 1)
					{
						
						printf("\n	DISPONIVEL NO ANDAR %i COLUNA %i VAGA %i\n",andar+1,coluna+1,vaga+1);
						copiar_mensalista(andar,coluna,vaga,cadastro,placa,mes,dia,ano,hora,minuto,tel);
						
					}
				}
			}
			
		}
		else // SAIDA
		{
			printf("\n	INFORME - A DATA E HORA ATUAL DE SAIDA.\n");
			printf("\n 	DIA, MES E ANO: ");
			scanf("%i %i %i",&dia, &mes, &ano);
			printf("\n 	HORA E MINUTO: ");
			scanf("%i %i", &hora, &minuto);
			system("cls");
			
			apresentacao();
			
			printf("\n 	(1)ROTATIVO (2)MENSALISTA: ");
			scanf("%i",&tipo);
			
			printf("\n 	PLACA DO CARRO:  ");
			scanf("%s",placa);
				
			system("cls");
			apresentacao();
			
			if(tipo == 1)
			{	
				res = buscar_rotativo(placa,cadastro,&andar,&coluna,&vaga);
				if(res == 0)
				{
					tot_rota = calcular_rotativo(dia,mes,ano,hora,minuto,andar,coluna,vaga,cadastro);
					printf("\n\n 	ENTRADA DO ROTATIVO: %i/%i/%i  %ih %im",cadastro[andar][coluna][vaga].dia,
																  cadastro[andar][coluna][vaga].mes,
																  cadastro[andar][coluna][vaga].ano,
																  cadastro[andar][coluna][vaga].hora,
																  cadastro[andar][coluna][vaga].minuto);
					printf("\n\n 	SAIDA DO ROTATIVO: %i/%i/%i  %ih %im",dia,mes,ano,hora,minuto);
					printf("\n\n 	TOTAL A PAGAR: %i $\n", tot_rota);
					remover(cadastro,andar,coluna,vaga);
				}
				else
				{
					printf("\n\n 	CARRO NAO ENCONTRADO NO ESTACIONAMENTO. TENTE NOVAMENTE!\n");
				}
			}
			else if(tipo == 2)
			{
				res = buscar_mensalista(placa,cadastro,&andar,&coluna,&vaga);
				
				if(res == 1)
				{
					if( (cadastro[andar][coluna][vaga].mes < mes || cadastro[andar][coluna][vaga].ano < ano)  && cadastro[andar][coluna][vaga].dia == dia)
					{
						printf("\n        SUA FATURA VENCEU!");
						printf("\n\n        (1)PAGAR 500$ (0)DEIXAR DE SER MENSALISTA: ");
						scanf("%i",&pagar);
						system("cls");
						
						apresentacao();
						if(pagar == 1)
						{
							printf("\n	FATURA PAGA!");
							atualizar_mes(cadastro,mes,andar,coluna,vaga);
						}
						else
						{	printf("\n	CONTA DO MENSALISTA REMOVIDA!");
							remover(cadastro,andar,coluna,vaga);
						}
					}
					printf("\n\n 	CARRO DO MENSALISTA RETIRADO!\n");
				}
				else
				{
						printf("\n\n 	CARRO NAO ENCONTRADO NO ESTACIONAMENTO. TENTE NOVAMENTE!\n");
				}	
			}
		}
		printf("\n 	(1)ENTRADA (2)SAIDA (3)FINALIZAR: ");
		scanf("%i",&opcao);
	}

	fclose(arq);	

	//escrever no arquivo
	arq = fopen("cadastro.txt","w");
	escrever(cadastro,arq);
	fclose(arq);
	
	printf("\n\n");
	system("pause");
	return 0;
}


