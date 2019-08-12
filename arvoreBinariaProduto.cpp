#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Produto
{
	int codigo;
	char nome[64];
	float valor;
	int quantidade;
	struct Produto *esquedo;
	struct Produto *direito;
}PR;

PR* inserir (PR *raiz, int codigo, char nome[], float valor, int quantidade)
{
	PR *novo;
	novo = new PR;
	novo->codigo = codigo;
	strcpy(novo->nome,nome);
	novo->valor = valor;
	novo->quantidade = quantidade;
	novo->esquedo = NULL;
	novo->direito = NULL;
	
	if (raiz == NULL)
	{
		raiz = novo;
	}
	else
	{
		PR *aux;
		aux = raiz;
		int inseriu = 0;
		
		while (inseriu == 0)
		{
			if (novo->codigo < aux->codigo)
			{
				if (aux->esquedo == NULL)
				{
					aux->esquedo = novo;
					inseriu = 1;
				}
				else
				{
					aux = aux->esquedo;
				}
			}
			else
			{
				if (aux->direito == NULL)
				{
					aux->direito = novo;
					inseriu = 1;
				}
				else
				{
					aux = aux->direito;
				}
			}
		}
	}
	return raiz;
}

int lerCodigo()
{
	int codigo;
	
	printf("\n Informe o Codigo do Produto: ");
	scanf("%d", &codigo);
	return codigo;
}

void lerNome(char nome[])
{	
	printf("\n Informe o nome do Produto: ");
	gets(nome);
}

int lerValor()
{
	float valor;
	
	printf("\n Informe o Valor do Produto: ");
	scanf("%f", &valor);
	return valor;
}

int lerQuantidade()
{
	int quantidade;
	
	printf("\n Informe a Quantidade de Produtos: ");
	scanf("%d", &quantidade);
	return quantidade;
}

void emOrdem (PR *raiz)
{
	if (raiz != NULL)
	{
		emOrdem(raiz->esquedo);
		printf("\n Codigo: %d", raiz->codigo);
		printf("\n Nome: %s", raiz->nome);
		printf("\n Valor: %f", raiz->valor);
		printf("\n Quantidade: %d \n", raiz->quantidade);
		emOrdem(raiz->direito);
	}
}

PR* consultar (PR *raiz, int codigo)
{
	PR *aux = raiz;
	
	
	while(aux != NULL)
	{
		if (aux->codigo == codigo)
		{
			return aux;
		}
		else
		{
			if (codigo < aux->codigo)
			{
				aux = aux->esquedo;
			}
			else
			{
				aux = aux->direito;
			}
		}
	}
	return aux;
}

int main()
{
	int opcao;
	int codigo;
	char nome[64];
	float valor;
	int quantidade;
	
	PR *raiz;
	
	raiz = NULL;
	
	printf("\n\n *** Minha primeira Arvore Binaria! :3 ***\n");
	
	do
	{
		printf("\n 1 - Iniciar Programa");
		printf("\n 2 - Em Ordem");
		printf("\n 3 - Consultar");
		printf("\n 0 - Sair");
		printf("\n Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao)
		{
			case 1: 
			{
				codigo = lerCodigo();
				fflush(stdin);
				lerNome(nome);
				fflush(stdin);
				valor = lerValor();
				fflush(stdin);
				quantidade = lerQuantidade();
				fflush(stdin);
				
				raiz = inserir (raiz, codigo, nome, valor, quantidade);
				break;
			}
			case 2:
			{
				emOrdem (raiz);
				break;
			}
			case 3:
			{
				
				if (consultar (raiz, lerCodigo()) != NULL)
				{
					printf("\n Encontrou!");
				}
				else
				{
					printf("\n Nao Encontrou :(");
				}
				break;
			}
		}
	}while (opcao != 0);
}
