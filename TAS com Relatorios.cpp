#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define TAM_BUFFER 255

float cmp_bebida(){
	int bebida;
	printf("Digite o numero da bebida:\n1.Cerveja\n2.Vodka\n3.Gin\n4.Saque\n5.Absinto\n6.Rum\n7.Tequila\n8.Uisque\n9.Vinho\n10.Cachaca\n11.Jagermeister\n12.Cerveja Especial\n13.Conhaque\n14.Licor\n\n");
	scanf("%d", &bebida);
		switch (bebida){
			case 1:
				return 4;
				break;
			case 2:
				return 40;
				break;
			case 3:
				return 45;
				break;
			case 4:
				return 15;
				break;
			case 5:
				return 69;
				break;
			case 6:
				return 40;
				break;
			case 7:	
				return 42;
				break;
			case 8:
				return 40;
				break;
			case 9:
				return 14;
				break;
			case 10:
				return 45;
				break;
			case 11:
				return 35;
				break;
			case 12:
				return 9;
				break;
			case 13:
				return 32;
				break;
			case 14:
				return 20;
				break;
		}
}

void timer(float delay1) {
   if (delay1<0.001) return; 
   float inst1 = 0, inst2 = 0;
   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;
   while (inst2-inst1<delay1) inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   return;
}

float TAS(){
	int peso, qtd_copos, pm;
	float grau;
	float gramas_alcool_k = 0;
	float TA = 0;
	char resposta[4] = "sim";
	printf("Digite seu peso em kg\n");
	scanf("%d", &peso);
	while((strcmp(resposta, "sim") == 0) || (strcmp(resposta, "Sim") == 0) || (strcmp(resposta, "SIM") == 0)){
		grau = cmp_bebida();
		printf("Grau Alcoolico: %.2f por cento\n", grau);
		printf("quantos copos vc bebeu?\n");
		scanf("%d", &qtd_copos);
		gramas_alcool_k = qtd_copos * grau;
		printf("Pura ou misturada?\n1.Pura\n2.Misturada(Refrigerante, agua, etc.)\n");
		scanf("%d", &pm);
		switch (pm){
			case 1:
			gramas_alcool_k = 0.06 * gramas_alcool_k;
			TA = TA + (gramas_alcool_k / (peso * 0.7));
			case 2:
			gramas_alcool_k = 0.058 * gramas_alcool_k;
			TA = TA + (gramas_alcool_k / (peso * 0.7));
		}
		printf("bebeu mais alguma coisa?\n");
		scanf("%s", &resposta);
	}
	return TA;
}

int toma_agua(){
	int agua;
	printf("\nVai tomar uma aguazinha jovem...\n1. Belessa\n2. Va se fude\n");
	scanf("%d", &agua);
	switch(agua){
		case 1:
			printf("Bom garoto!!\n");
			break;
		case 2:
			timer(15.0);
			break;
		default:
			("Nao, nao tem essa opcao, agora vai tomar uma agua\n");
			break;
	}
	return agua;
}

int quest_ress(){
	int pontos = 0;
	int opcao = 15;
	while(opcao !=0){
		printf("\nO que vc tem fera?\n\n0. To bao\n1. Dor de cabeca\n2. Dor no corpo\n3. Dor de estomago\n4. Nausea\n5. Vomito\n6. Palpitacao\n7. Cansaco\n8. Sede\n9. Tontura\n10. Depressivo\n11. Ansioso\n12. Puto\n13. Ainda to locasso\n14. So isso\n\n");
		scanf("%d", &opcao);
		switch(opcao){
			case 0:
				opcao = 0;
				break;
			case 1:
				pontos = pontos + 5;
				break;
			case 2:
				pontos = pontos + 2;
				break;
			case 3:
				pontos = pontos + 3;
				break;
			case 4:
				pontos = pontos + 5;
				break;
			case 5:
				pontos = pontos + 8;
				break;
			case 6:
				pontos = pontos + 4;
				break;
			case 7:
				pontos = pontos + 1;
				break;
			case 8:
				pontos = pontos + 1;
				break;
			case 9:
				pontos = pontos + 4;
				break;
			case 10:
				pontos = pontos + 10;
				break;
			case 11:
				pontos = pontos + 2;
				break;
			case 12:
				pontos = pontos + 7;
				break;
			case 13:
				pontos = pontos + 12;
				break;
			case 14:
				opcao = 0;
				break;
			default:
				printf("\nNao, nao tem essa opcao\n\n");
				break;
		}
	}
	printf("\nVc ja tem %d pontos\n\n", pontos);
	printf("\nMisturou mais de uma bebida??\n1. Sim\n2. Nao\n\n");
	scanf("%d", &opcao);
	if(opcao == 1) pontos = pontos + 10;
	else if(opcao == 2) pontos = pontos - 5;
	printf("\nBebeu agua fera??\n1. Sim\n2. Nao\n\n");
	scanf("%d", &opcao);
	if(opcao == 1) pontos = pontos - 10;
	else if(opcao == 2) pontos = pontos + 15;
	printf("\nSe lembra de ter pego mulher feia??\n1. Nao\n2. Parecia um dragao\n3. Nao lembro se era mulher\n4. Mais feia que bater com o piru na mae\n\n");
	scanf("%d", &opcao);
	if(opcao == 1) pontos = pontos - 5;
	else if(opcao == 2) pontos = pontos + 8;
	else if(opcao == 3) pontos = pontos + 15;
	else if(opcao == 4) pontos = pontos + 20;
	return pontos;
}

void relatorio(FILE *arquivo){
	char buffer[TAM_BUFFER];
	if(arquivo != NULL){
		while(fgets(buffer, TAM_BUFFER, arquivo)) printf("%s", buffer);
	}
	else printf("Nao foi possivel abrir o arquivo.\n");
}

int main(){
	FILE *arq_in, *arq_ress;
	float teor, TA;
	char data[10];
	int func, agua;
	int cont_func = 0;
	printf("Que dia e hoje fera?\n");
	scanf("%s", &data);
		while(cont_func != 5){
			arq_in	= fopen("arquivo_i.txt", "a+");
			arq_ress = fopen("arquivo_ressaca.txt", "a+");
			printf("\nDigite a funcionalidade:\n1. Bebidas e Porcentagem de Alcool\n2. Descubra quanto alcool tem no seu sangue!(TAS)\n3. Questionario de Ressaca\n4. Relatorio de Bebedeira\n5. Relatorio de Ressaca\n6. Limpar Historico de Bebedeira\n7. Limpar Historico de Ressaca\n\n");
			scanf("%d", &func);
			system("cls");
			switch(func){
				case 1: //Banco de Dados de Bebidas
					cont_func = 0;
					teor = cmp_bebida();
					printf("Esta bebida possui um teor alcoolico de %.1f por cento\n", teor);
					fclose(arq_in);
					fclose(arq_ress);
					timer(2.5);
					system("cls");
					break;
				case 2: //TAS
					cont_func = 0;
					TA = TAS();
					//Arquivo
					fprintf(arq_in, "%s\n", data);
					fprintf(arq_in, "Voce tem %.3f g/L de alcool no seu sangue\n", TA);
					if(TA <= 0.2) fprintf(arq_in, "Voce ainda ta legal\n");
					else if(0.2 < TA && TA <= 0.7) fprintf(arq_in, "Voce ja ta ficando meio cego fera... cuidado pra nao pegar um dragao!\n");
					else if(0.7 < TA && TA <= 1.5) fprintf(arq_in, "Axo q vc ja pegou akele dragao faz tempo...\n");
					else if(1.5 < TA &&TA <= 2.0) fprintf(arq_in, "Ja ta enxergando dobrado ne... Vai pra casa moleque solto.\n");
					else if(2.0 < TA && TA <= 5.0) fprintf(arq_in, "Nenem ta dumindo, ta??\n");
					else if(TA > 5.0) fprintf(arq_in, "No ceu tem pao?? E morreu.\n");
					if(TA/7.5 > 0.05) fprintf(arq_in, "E voce estaria 1.915 reais mais fudido no bafometro a essa hora!!\n\n");
					fprintf(arq_in, "-------------------------------------\n");
					//Usuario
					printf("Voce tem %.3f g/L de alcool no seu sangue\n", TA);
					if(TA <= 0.2) printf("Voce ainda ta legal\n");
					else if(0.2 < TA && TA <= 0.7) printf("Voce ja ta ficando meio cego fera... cuidado pra nao pegar um dragao!\n");
					else if(0.7 < TA && TA <= 1.5) printf("Axo q vc ja pegou akele dragao faz tempo...\n");
					else if(1.5 < TA &&TA <= 2.0) printf("Ja ta enxergando dobrado ne... Vai pra casa moleque solto.\n");
					else if(2.0 < TA && TA <= 5.0) printf("Nenem ta dumindo, ta??\n");
					else if(TA > 5.0) printf("No ceu tem pao?? E morreu.\n");
					if(TA/7.5 > 0.05) printf("E voce estaria 1.915 reais mais fudido no bafometro a essa hora!!\n\n");
					timer(2.5);
					if(TA > 0.6){
						agua = 2;
						while(agua != 1){
							agua = toma_agua();
						}
					}
					fclose(arq_in);
					fclose(arq_ress);
					timer(2.5);
					system("cls");
					break;
				case 3: //Questionario de Ressaca
					cont_func = 0;
					int pontos;
					pontos = quest_ress();
					//Arquivo
					fprintf(arq_ress, "%s\n", data);
					fprintf(arq_ress, "\nVc fez %d pontos\n\n", pontos);
					if(pontos <= 0) fprintf(arq_ress, "Isso que e um rapaz de deus!\n");
					else if(0 < pontos && pontos <= 32) fprintf(arq_ress, "Toma um engov que sara\n");
					else if(32 < pontos && pontos <= 67) fprintf(arq_ress, "Vamo beber menos na proxima ne champs?\n");
					else if(67 < pontos && pontos <= 93) fprintf(arq_ress, "Desse jeito teu figado vai ficar igual voce.. seu fudido\n");
					else if(93 < pontos && pontos <= 124) fprintf(arq_ress, "CACETE, tem certeza que teu cu ainda é virgem a uma hora dessas?\n\n");
					fprintf(arq_ress, "-------------------------------------\n");
					//Usuario
					printf("\nVc fez %d pontos\n\n", pontos);
					if(pontos <= 0) printf("Isso que e um rapaz de deus!\n");
					else if(0 < pontos && pontos <= 32) printf("Toma um engov que sara\n");
					else if(32 < pontos && pontos <= 67) printf("Vamo beber menos na proxima ne champs?\n");
					else if(67 < pontos && pontos <= 93) printf("Desse jeito teu figado vai ficar igual voce.. seu fudido\n");
					else if(93 < pontos && pontos <= 124) printf("CACETE, tem certeza que teu cu ainda é virgem a uma hora dessas?\n\n");
					fclose(arq_in);
					fclose(arq_ress);
					timer(2.5);
					system("cls");
					break;
				case 4: //Relatorio de Bebedeira
					cont_func = 0;
					relatorio(arq_in);
					fclose(arq_in);
					fclose(arq_ress);
					timer(10.0);
					system("cls");
					break;
				case 5: //Relatorio de Ressaca
					cont_func = 0;
					relatorio(arq_ress);
					fclose(arq_in);
					fclose(arq_ress);
					timer(10.0);
					system("cls");
					break;
				case 6: //Limpar Historico de Bebedeira
					cont_func = 0;
					printf("Sua vergonha foi limpa com sucesso\n");
					remove("arquivo_i.txt");
					fclose(arq_ress);
					timer(2.5);
					system("cls");
					break;
				case 7: //Limpar Historico de Ressaca
					cont_func = 0;
					printf("Sua vergonha foi limpa com sucesso\n");
					fclose(arq_in);
					remove("arquivo_ress.txt");
					timer(2.5);
					system("cls");
					break;
				default:
					printf("\nNao, nao tem essa opcao, seu bebado otario\n");
					cont_func++;
					system("cls");
					if(cont_func == 4){
						printf("\nSEU TROXA, MAIS UMA E O APP VAI FEXAR!\n\n");
					}
					else if(cont_func == 5) printf("\nFESSOU!\n\n");
					fclose(arq_in);
					fclose(arq_ress);
			}
			fclose(arq_in);
			fclose(arq_ress);
		}
		return 0;
}
