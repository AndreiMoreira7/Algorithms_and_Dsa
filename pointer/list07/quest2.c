#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Paciente{
	int numAtendimento;
	int idade;
	char nome[50];
	struct Paciente* proximo;
	struct Paciente* anterior;
}Paciente;

typedef struct{
	Paciente* inicio;
	Paciente* fim;
	int tamanho;
}Clinica;

void limparQuebraLinha(char *str){
	str[strcspn(str, "\n")] = '\0';
}

void inicializar(Clinica* clinica){
	clinica->fim = NULL;
	clinica->inicio = NULL;
	clinica->tamanho = 0;
}

bool clinicaVazia(Clinica* clinica){
	return clinica->inicio == NULL;
}

void adicionarPaciente(Clinica* clinica){
	Paciente* novo = (Paciente*) malloc(sizeof(Paciente));
	if(novo == NULL){
		printf("ERRO AO ALOCAR MEMÓRIA");
		exit(EXIT_FAILURE);
	}
	
	printf("Digite a idade do paciente %d: ", clinica->tamanho + 1);
	scanf("%d", &novo->idade);
	getchar();
	
	printf("Digite o nome do paciente %d: ", clinica->tamanho + 1);
	fgets(novo->nome, sizeof(novo->nome), stdin);
	limparQuebraLinha(novo->nome);
	
	novo->numAtendimento = clinica->tamanho + 1;
	novo->anterior = NULL;
	novo->proximo = NULL;
	
	if(clinicaVazia(clinica)){
		clinica->inicio = novo;
		clinica->fim = novo;
	}
	else{
		clinica->fim->proximo = novo;
		novo->anterior = clinica->fim;
		clinica->fim = novo;
	}
	clinica->tamanho++;
}

void atenderPaciente(Clinica* clinica){
	if(clinicaVazia(clinica)) printf("A clinica está vazia!");
	else{
		printf("O paciente %s, da senha %d foi atendido com sucesso!", clinica->inicio->nome, clinica->inicio->numAtendimento);
		
		clinica->inicio = clinica->inicio->proximo;
		free(clinica->inicio->anterior);
		clinica->inicio->anterior = NULL;
	}
}

void removerPorSenha(Clinica* clinica){
	if(clinicaVazia(clinica)) printf("A clinica está vazia!");
	else{
		int senha;
		printf("Digite a senha do paciente que deseja remover: ");
		scanf("%d", &senha);
		
		Paciente* aux = clinica->inicio;
		
		while(aux != NULL){
			if(aux->numAtendimento == senha){
				if(aux == clinica->inicio){
					if(aux->proximo != NULL){
						clinica->inicio = aux->proximo;
						free(aux);
						aux->proximo->anterior = NULL;
					}
					else{
						clinica->inicio = NULL;
						clinica->fim = NULL;
						free(aux);
					}
				}
				else{
					if(aux == clinica->fim){
						clinica->fim = aux->anterior;
						free(aux);
						aux->anterior->proximo = NULL;
					}
					else{
						aux->anterior->proximo = aux->proximo;
						aux->proximo->anterior = aux->anterior;
						free(aux);
					}
				}
				
				clinica->tamanho--;
				
				printf("Paciente removido com sucesso!");
				return;
			}
			else{
				aux = aux->proximo;
			}
		}
		
		printf("Não existe paciente com essa senha!");
	}
}

void imprimir(Clinica* clinica){
	if(clinicaVazia(clinica)) printf("A clinica está vazia!");
	else{
		Paciente* aux = clinica->inicio;
		
		printf("\n====== PACIENTES ======\n");
		while(aux != NULL){
			printf("\nNOME: %s\nIDADE: %d\nSENHA: %d\n", aux->nome, aux->idade, aux->numAtendimento);
			aux = aux->proximo;
		}
	}
}

void imprimirInvertido(Clinica* clinica){
	if(clinicaVazia(clinica)) printf("A clinica está vazia!");
	else{
		Paciente* aux = clinica->fim;
		
		printf("\n====== PACIENTES ======\n");
		while(aux != NULL){
			printf("\nNOME: %s\nIDADE: %d\nSENHA: %d\n", aux->nome, aux->idade, aux->numAtendimento);
			aux = aux->anterior;
		}
	}
}

int main(){
	setlocale(LC_ALL, "");
	
	Clinica clinica;
	inicializar(&clinica);
	
	int opcao = 0;
	bool validar = true; 
	
	while(validar){
		printf("\n\n======= CLINICA =======\n");
		printf("1) Adicionar novo paciente\n");
		printf("2) Pacientes esperando\n");
		printf("3) Atender paciente\n");
		printf("4) Remover paciente por senha\n");
		printf("5) Lista de pacientes (invertida)\n");
		printf("6) Sair\n");
		printf("Digite uma opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				adicionarPaciente(&clinica);
				break;
			case 2:
				imprimir(&clinica);
				break;
			case 3:
				atenderPaciente(&clinica);
				break;
			case 4:
				removerPorSenha(&clinica);
				break;
			case 5:
				imprimirInvertido(&clinica);
				break;
			case 6:
				validar = false;
				break;
			default:
				printf("Opção inválida, digite uma nova opção!");
				break;
		}
	}
	
	return 0;
}
