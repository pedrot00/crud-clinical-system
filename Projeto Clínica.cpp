/******** CONSULTA CLÍNICA ********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

#define MAX 100
#define FILE_NAME "Pacientes.txt"
#define FILE_N "Especialista.txt"
#define FILE_C "Consultas.txt"



/*-----------------------------------*/
//Struct informações de nascimento;
typedef struct {								  	  
	char dia[MAX], mes[MAX], ano[MAX];
	
} Nascimento;

/*-----------------------------------*/

//Struct infoormações de paciente;
typedef struct {								  	   
	char nome[MAX], CPF[MAX], email[MAX], tel[9];
	Nascimento nascimento;
	
} Paciente;

/*-----------------------------------*/

//Struct informações de Especialista;
typedef struct {								  	   
	char nome[MAX], registro[MAX], especialidade[MAX];
	
} Especialista;

/*-----------------------------------*/

//Struct informações de consulta
typedef struct{								  	   
	Paciente paciente;
	Especialista especialista;
	float valor;
	char dia[MAX], mes[MAX], ano[MAX], hora[MAX], minuto[MAX];
	
} Consulta;

/*-----------------------------------*/

//*CRUD PACIENTE;
int Carregar_Paciente (Paciente paciente[]);			// Carregar paciente no BDD;
int Criar_Paciente (Paciente paciente[], int);			// Cadastras um paciente;
void Ler_Pacientes (Paciente paciente[], int);			// Ler todos os pacientes;
void Buscar_Paciente (Paciente paciente[], int);		// Buscar informações paciente;
void Atualizar_Paciente(Paciente paciente[], int);		// Atualizar informações paciente;
void Apagar_Paciente (Paciente paciente[], int);		// Apagar um paciente do BDD;

//*CRUD ESPECIALISTA;
int Carregar_Especialista (Especialista especialista[]);		// Carregar Especialista no BDD;		
int Criar_Especialista (Especialista especialista[], int);		// Cadastras um especialista;
void Ler_Especialistas (Especialista especialista[], int);		// Ler todos os especialistas;
void Buscar_Especialista (Especialista especialista[], int);	// Buscar informações especialista;
void Atualizar_Especialista (Especialista especialista[], int); // Atualizar informações especialista;
void Apagar_Especialista (Especialista especialista[], int);	// Apagar um especialista do BDD;


//*CRUD CONSULTAS;
int Carregar_Consulta (Consulta consulta []);				// Carregar consulta no BDD;
int Criar_Consulta (Consulta consulta[], Paciente paciente[],
Especialista especialista[], int, int, int);				// Cadastras uma consulta;
void Ler_Consultas (Consulta consulta [], int);				// Ler todas as consultas;
void Buscar_Consulta (Consulta consulta [], int);			// Buscar consulta;
void Atualizar_Consulta (Consulta consulta [], int);		// Atualizar informações consulta;
void Apagar_Consulta (Consulta consulta [], int);			// Apagar uma consulta do BDD;

//*FUNÇÕES AUXILIARES
void Salvar_Info (Paciente paciente[], Especialista especialista [],
	Consulta consulta[], int, int, int);



/*-------------------------------------------------------------------------------*/
/*---------------------------*\ BLOCO MAIN /*------------------------------------*/
/*-------------------------------------------------------------------------------*/
int main (){
	setlocale (LC_ALL, "");
	
	Paciente paciente[MAX];					// Declaração struct de paciente;
	Especialista especialista[MAX];			// Declaração struct de especialista;
	Consulta consulta[MAX];					// Declaração struct de consulta;
	Nascimento nascimento[MAX];				// Declaração struct de nascimento;
	
	int escolha;							// Escolha da opção do menu;
	
	int n;									// Aloca o número de pacientes cadastrados;
	int r = 0;									// Aloca o número de especialistas cadastrados;
	int w;
	
	
do{
	system ("color 1F");
	system ("cls");
	
	printf ("\n|---------------------->| CLÍNICA |<----------------------|\n");
	printf ("|Bem-vindo(a) aos nossos serviços, favor inserir o atendimento que deseja:\n");
	putchar ('\n');
	
	printf ("|-----------> |MENU PACIENTE| <-----------|\n");
	printf ("|01|-> Para cadastrar um paciente.        |\n");
	printf ("|02|-> Para ler todos os pacientes.       |\n");
	printf ("|03|-> Para buscar um paciente.           |\n");
	printf ("|04|-> Para atualizar um paciente.        |\n");
	printf ("|05|-> Para apagar um paciente.           |\n");
	printf ("|-----------------------------------------|\n");
	putchar ('\n');
	
	printf ("|---------> |MENU ESPECIALISTA| <---------|\n");
	printf ("|06|-> Para cadastrar um especialista.    |\n");
	printf ("|07|-> Para ler todos os especialistas.   |\n");
	printf ("|08|-> Para buscar um especialista.       |\n");
	printf ("|09|-> Para atualizar um especialista.    |\n");
	printf ("|10|-> Para apagar um especialista.       |\n");
	printf ("|-----------------------------------------|\n");
	putchar ('\n');
	
	printf ("|----------> |MENU CONSULTAS| <-----------|\n");
	printf ("|11|-> Para agendar uma consulta.         |\n");
	printf ("|12|-> Para acessar todas as consultas.   |\n");
	printf ("|13|-> Para buscar uma consulta.          |\n");
	printf ("|14|-> Para atualizar uma consulta.       |\n");
	printf ("|15|-> Para apagar uma consulta.          |\n");
	printf ("|-----------------------------------------|\n");
	putchar ('\n');
	
	printf ("|---------------> |SAIR| <----------------|\n");
	printf ("|16|-> Para salvar as informações e sair. |\n");
	printf ("|-----------------------------------------|\n");
	putchar ('\n');
	
	printf ("|Sua escolha: ");
	scanf ("%d", &escolha);


	
		
	switch (escolha){
		
		/*-----------------------------------*/			// Paciente;
		case 1:
			n = Criar_Paciente(paciente, n);
			printf ("\nNúmero de pacientes cadastrados até o momento: %d\n", n);
			system ("pause");
			break;	
		
		case 2:
			Ler_Pacientes (paciente, n);
			system ("pause");
			break;
		
		case 3:
			Buscar_Paciente (paciente, n);
			system ("pause");
			break;
		
		case 4:
			Atualizar_Paciente (paciente, n);
			system ("pause");
			break;
		
		case 5:
			Apagar_Paciente (paciente,n);
			n--;
			printf ("\n|Número de pacientes no sistema atualmente: %d\n", n);
			system("pause");
			break;
			
		/*-----------------------------------*/			// Especialista 	
		case 6:
			r = Criar_Especialista (especialista, r);
			putchar ('\n');
			
			printf ("|Número de especialistas cadastrados até o momento: %d\n", r);
			system ("pause");
			break;
		
		case 7:
			Ler_Especialistas (especialista, r);
			system ("pause");
			break;
		
		case 8:
			Buscar_Especialista (especialista, r);
			system ("pause");
			break;	
		
		case 9:
			Atualizar_Especialista (especialista, r);
			system ("pause");
			break;
			
		case 10:
			Apagar_Especialista (especialista, r);
			r--;
			printf ("\n|Número de pacientes no sistema atualmente: %d\n", r);
			system("pause");
			break;
			
		/*-----------------------------------*/			// Consulta	
		case 11:
	
			w = Criar_Consulta (consulta, paciente, especialista, w, n, r);
			printf ("\nNúmero de consultas cadastrados até o momento: %d\n", w);
			system ("pause");
			break;
		
		case 12:
			Ler_Consultas (consulta, w);
			system ("pause");
			break;
			
		case 13:
			Buscar_Consulta(consulta, w);
			system("pause");
			break;
		
		case 14:
			Ler_Especialistas(especialista, r);
			Atualizar_Consulta(consulta, w);
			system ("pause");
			break;
		
		case 15:
			Apagar_Consulta(consulta, w);
			w--;
			printf ("Número de consultas no sistema: %d", w);
			system ("pause");
			break;
		
		
		/*-----------------------------------*/			// Salvar
		case 16:
		Salvar_Info (paciente, especialista, consulta, n, r, w);
		system ("pause");	
		break;
	}
	
} while ((escolha >= 1) && (escolha < 16)); 

	return 0;
}


/*-------------------------------------------------------------------------------*/
/*-------------------------*\ FUNÇÕES PACIENTE /*--------------------------------*/
/*-------------------------------------------------------------------------------*/

// Função que carrega o número de paciente no banco de dados;
int Carregar_Paciente (Paciente paciente[]){
	
	int i=0;
	
	FILE *fp;
	fp = fopen(FILE_NAME, "r+");
	
	if (fp == NULL){
		printf ("Problema na abertura do arquivo.");
	}
	
	while (fscanf(fp, "%s %s %s %s %s %s %s ", 
	paciente[i].nome, paciente[i].CPF,
	paciente[i].email, paciente[i].tel, paciente[i].nascimento.dia,
	paciente[i].nascimento.mes, paciente[i].nascimento.ano) != EOF)
	i++;
	
	fclose (fp);
	return i;
	
	
}

/*-------------------------------------------------------------------------------*/

// Função que cadastra um novo paciente;
int Criar_Paciente (Paciente paciente[], int n){
	
	setbuf (stdin, NULL);
	system ("cls");
	
	
	
	printf ("|----------> |CADASTRO PACIENTE| <-----------|\n");	
	if (n < MAX){
		printf ("|NOME|: ");
		gets (paciente[n].nome);
		setbuf (stdin, NULL);
		
		printf ("|CPF|: ");
		gets (paciente[n].CPF);
		setbuf (stdin, NULL);
		
		printf ("|EMAIL|: ");
		gets (paciente[n].email);
		setbuf (stdin, NULL);
		
		printf ("|TELEFONE|: ");
		gets (paciente[n].tel);
		setbuf (stdin, NULL);
	
	
	
		printf ("|DIA DE NASCIMENTO|: ");
		gets (paciente[n].nascimento.dia);
		setbuf (stdin, NULL);
		
		setbuf (stdin, NULL);
		printf ("|MES DE NASCIMENTO|: ");
		gets (paciente[n].nascimento.mes);
		setbuf (stdin, NULL);
		
		printf ("|ANO DE NASCIMENTO|: ");
		gets (paciente[n].nascimento.ano);
		setbuf (stdin, NULL);
		
		n++;
	}
	else{
		printf ("|Não há espaço no BDD para cadastro de paciente.\n");
	}
	
	return n;
	
}

/*-------------------------------------------------------------------------------*/

void Ler_Pacientes (Paciente paciente[], int n){
	
	int i;
	system ("cls");
	setbuf (stdin, NULL);
	
	printf ("|----------> |INFORMAÇÕES DE PACIENTES| <-----------|\n");

	
	for (i=0; i<n; i++){
		
		printf ("\n|-----------> |USUÁRIO %d| <-----------|\n", i);
		printf ("|NOME|-> %s\n", paciente[i].nome);
		printf ("|CPF|-> %s\n", paciente[i].CPF);
		printf ("|EMAIL|-> %s\n", paciente[i].email);
		printf ("|TELEFONE|-> %s\n", paciente[i].tel);
		printf ("|DIA DE NASCIMENTO|-> %s\n", paciente[i].nascimento.dia);
		printf ("|MES DE NASCIMENTO|-> %s\n", paciente[i].nascimento.mes);
		printf ("|ANO DE NASCIMENTO|-> %s\n", paciente[i].nascimento.ano);
		printf ("|--------------------------------------|\n");
		putchar('\n');
	}
	
	
}

/*-------------------------------------------------------------------------------*/

void Buscar_Paciente (Paciente paciente[], int n){
	int i;
	char busca[MAX];
	
	setbuf (stdin, NULL);
	system ("cls");
	
	printf ("|----------> |BUSCA DE PACIENTE| <-----------|\n");
	
	printf ("|Insira o CPF do paciente: ");
	gets(busca);
	system("pause");
	putchar ('\n');
	for (i=0; i<n; i++){
	
		if(strcmp(paciente[i].CPF, busca) == 0){
		
			printf ("\n|O paciente %d condiz com a busca. \n", i);
			printf ("|-----------> |USUÁRIO %d| <-----------|\n", i);
			printf ("|NOME|-> %s\n", paciente[i].nome);
			printf ("|CPF|-> %s\n", paciente[i].CPF);
			printf ("|EMAIL|-> %s\n", paciente[i].email);
			printf ("|TELEFONE|-> %s\n", paciente[i].tel);
			printf ("|DIA DE NASCIMENTO|-> %s\n", paciente[i].nascimento.dia);
			printf ("|MES DE NASCIMENTO|-> %s\n", paciente[i].nascimento.mes);
			printf ("|ANO DE NASCIMENTO|-> %s\n", paciente[i].nascimento.ano);
			printf ("|--------------------------------------|\n");	
		}	
	}
}

/*-------------------------------------------------------------------------------*/

void Atualizar_Paciente(Paciente paciente[], int n){
	
	int i;
	int u;
	
	char atualizar[MAX];
	int choise;
	char opcao;
	
	char Novo_Nome[MAX];
	char Novo_CPF[MAX];
	char Novo_Email[MAX];
	char Novo_Tel[MAX];
	
	
	
	setbuf (stdin, NULL);
	system ("cls");	
	
	printf ("|----------> |ATUALIZAR PACIENTE| <-----------|\n");
	putchar('\n');
	
	printf ("|Insira o CPF do usuário: ");
	gets(atualizar);
	system("pause");
	
	
	for (i=0; i<n; i++){
	
		if(strcmp(paciente[i].CPF, atualizar) == 0){
		
			printf ("\n|O usuário %d condiz com a busca. \n", i);
			printf ("|-----------> |USUÁRIO %d| <-----------|\n", i);
			printf ("|NOME|-> %s\n", paciente[i].nome);
			printf ("|CPF|-> %s\n", paciente[i].CPF);
			printf ("|EMAIL|-> %s\n", paciente[i].email);
			printf ("|TELEFONE|-> %s\n", paciente[i].tel);
			printf ("|DIA DE NASCIMENTO|-> %s\n", paciente[i].nascimento.dia);
			printf ("|MES DE NASCIMENTO|-> %s\n", paciente[i].nascimento.mes);
			printf ("|ANO DE NASCIMENTO|-> %s\n", paciente[i].nascimento.ano);
			printf ("|--------------------------------------|\n");
			u = i;	
		}	
	}
	
	
	
	putchar ('\n');
	printf ("|--------------------------------------|\n");
	printf ("|1|-> NOME\n");
	printf ("|2|-> CPF\n");
	printf ("|3|-> EMAIL\n");
	printf ("|4|-> TELEFONE\n");
	printf ("|--------------------------------------|\n");
	
	putchar ('\n');
	printf ("|Insira o número da informação que deseja alterar: ");
	scanf ("%d", &choise);
	
	putchar('\n');
	switch (choise){
		
		case 1:
			setbuf (stdin, NULL);
			printf ("|Insira o novo nome: ");
			gets(Novo_Nome);
			strcpy (paciente[u].nome, Novo_Nome);
			break;
		
		case 2:
			setbuf (stdin, NULL);
			printf ("|Insira o novo CPF: ");
			gets(Novo_CPF);
			strcpy (paciente[u].CPF, Novo_CPF);
			break;
			
		case 3:
			setbuf (stdin, NULL);
			printf ("|Insira o novo email: ");
			gets (Novo_Email);
			strcpy (paciente[u].email, Novo_Email);
			break;
		
		case 4:
			setbuf (stdin, NULL);
			printf ("|Insira o novo telefone: ");
			gets (Novo_Tel);
			strcpy (paciente[u].tel, Novo_Tel);
			break;
			
		default:
			printf ("|O valor inserido não existe no menu.\n");
	}
	
	putchar ('\n');
	printf ("|Informações atualizadas!\n");
	
	printf ("|-----------> |PACIENTE %d| <-----------|\n", u);
	printf ("|NOME|-> %s\n", paciente[u].nome);
	printf ("|CPF|-> %s\n", paciente[u].CPF);
	printf ("|EMAIL|-> %s\n", paciente[u].email);
	printf ("|TELEFONE|-> %s\n", paciente[u].tel);
	printf ("|DIA DE NASCIMENTO|-> %s\n", paciente[u].nascimento.dia);
	printf ("|MES DE NASCIMENTO|-> %s\n", paciente[u].nascimento.mes);
	printf ("|ANO DE NASCIMENTO|-> %s\n", paciente[u].nascimento.ano);
	printf ("|--------------------------------------|\n");
	
	
}

/*-------------------------------------------------------------------------------*/

void Apagar_Paciente (Paciente paciente[], int n){
	
	int i, u, k;
	char apagar[MAX];
	
	setbuf(stdin, NULL);
	system ("cls");
	
	printf ("|-----------> |APAGAR USUÁRIO| <------------|\n");
	
	for (i=0; i<n; i++){
		
		putchar ('\n');
		printf ("\n|-----------> |USUÁRIO %d| <-----------|\n", i);
		printf ("|NOME|-> %s\n", paciente[i].nome);
		printf ("|CPF|-> %s\n", paciente[i].CPF);
		printf ("|--------------------------------------|\n");
	}
	
	printf ("\n|Insira o CPF do usuário que deseja apagar do sistema: ");
	gets(apagar);
	
	for (i=0; i<n; i++){
		
		if(strcmp (paciente[i].CPF, apagar) == 0){
			for (u = i; u < n; u++){
				
			    k = u+1;
				strcpy(paciente[u].nome, paciente[k].nome);
				strcpy(paciente[u].CPF, paciente[k].CPF);
				strcpy(paciente[u].email, paciente[k].email);
				strcpy(paciente[u].tel, paciente[k].tel);
				strcpy(paciente[u].nascimento.dia, paciente[k].nascimento.dia);
				strcpy(paciente[u].nascimento.mes, paciente[k].nascimento.mes);
				strcpy(paciente[u].nascimento.ano, paciente[k].nascimento.ano);	
			}
		}
	}	
	
}

/*-------------------------------------------------------------------------------*/
/*-------------------------*\ FUNÇÕES ESPECIALISTA /*----------------------------*/
/*-------------------------------------------------------------------------------*/
int Carregar_Especialista (Especialista especialista[]){
	
	int i;
	setbuf (stdin, NULL);
	
	FILE *arq;
	arq = fopen (FILE_N, "r+");
	
	if (arq == NULL)
	{	
		printf ("Problema na abertura do arquivo.");
	}
	
	while (fscanf (arq, "%s %s %s", especialista[i].nome, especialista[i].registro,
	especialista[i].especialidade) != EOF)
	i++;
	
	fclose (arq);
	return i;
	
}

/*-------------------------------------------------------------------------------*/

int Criar_Especialista (Especialista especialista[], int r){
	
	setbuf (stdin, NULL);
	system ("cls");
	
	
	
	printf ("|----------> |CADASTRO ESPECIALISTA| <-----------|\n");	
	if (r < MAX){
		printf ("\n|NOME|: ");
		gets(especialista[r].nome);
		setbuf (stdin, NULL);
		
		printf ("|REGISTRO|: ");
		gets(especialista[r].registro);
		setbuf (stdin, NULL);
		
		printf ("|ESPECIALIDADE|: ");
		gets(especialista[r].especialidade);
		setbuf (stdin, NULL);
		
		r++;
	}
		else{
		printf ("|Não há espaço no BDD para cadastro de especialista.\n");
	}
	

	return r;
	
}

/*-------------------------------------------------------------------------------*/

void Ler_Especialistas (Especialista especialista[], int r){
	
	int i;
	system ("cls");
	setbuf (stdin, NULL);
	
	printf ("|----------> |INFORMAÇÕES DE ESPECIALISTAS| <-----------|\n");

	
	for (i=0; i<r; i++){
		
		printf ("\n|-----------> |USUÁRIO %d| <-----------|\n", i);
		printf ("|NOME|-> %s\n", especialista[i].nome);
		printf ("|REGISTRO|-> %s\n", especialista[i].registro);
		printf ("|ESPECIALIDADE-> %s\n", especialista[i].especialidade);
		printf ("|--------------------------------------|\n");
		putchar('\n');
	}
	
	
}

/*-------------------------------------------------------------------------------*/

void Buscar_Especialista (Especialista especialista[], int r) {

	int i;
	char busca[MAX];
	
	setbuf (stdin, NULL);
	system ("cls");
	
	printf ("|----------> |BUSCA DE ESPECIALISTA| <-----------|\n");
	
	printf ("|Insira a especialidade do especialista: ");
	
	gets(busca);
	system("pause");
	
	putchar ('\n');
	for (i=0; i<r; i++){
	
		if(strcmp(especialista[i].especialidade, busca) == 0){
		
			printf ("\n|O especialista %d condiz com a busca. \n", i);
			printf ("|-----------> |USUÁRIO %d| <-----------|\n", i);
			printf ("|NOME|-> %s\n", especialista[i].nome);
			printf ("|REGISTRO|-> %s\n", especialista[i].registro);
			printf ("|ESPECIALIDADE|-> %s\n", especialista[i].especialidade);
			printf ("|--------------------------------------|\n");	
		}		
	}

}

/*-------------------------------------------------------------------------------*/

void Atualizar_Especialista (Especialista especialista[], int r){
	int i;
	int u;
	
	char atualizar[MAX];
	int choise;
	char opcao;
	
	char Novo_Nome[MAX];
	char Novo_Registro[MAX];
	char Novo_Especialidade[MAX];

	
	setbuf (stdin, NULL);
	system ("cls");	
	
	printf ("|----------> |ATUALIZAR ESPECIALISTA| <-----------|\n");
	putchar('\n');
	
	printf ("|Insira o registro do especialista: ");
	gets(atualizar);
	system("pause");
	
	
	for (i=0; i<r; i++){
	
		if(strcmp(especialista[i].registro, atualizar) == 0){
		
			printf ("\n|O usuário %d condiz com a busca. \n", i);
			printf ("|-----------> |ESPECIALISTA %d| <-----------|\n", i);
			printf ("|NOME|-> %s\n", especialista[i].nome);
			printf ("|REGISTRO|-> %s\n", especialista[i].registro);
			printf ("|ESPECIALIDADE|-> %s\n", especialista[i].especialidade);
			printf ("|--------------------------------------|\n");
			u = i;	
		}	
	}
	
	
	
	putchar ('\n');
	printf ("|--------------------------------------|\n");
	printf ("|1|-> NOME\n");
	printf ("|2|-> REGISTRO\n");
	printf ("|3|-> ESPECIALIDADE\n");
	printf ("|--------------------------------------|\n");
	
	putchar ('\n');
	printf ("|Insira o número da informação que deseja alterar: ");
	scanf ("%d", &choise);
	
	putchar('\n');
	switch (choise){
		
		case 1:
			setbuf (stdin, NULL);
			printf ("|Insira o novo nome: ");
			gets(Novo_Nome);
			strcpy (especialista[u].nome, Novo_Nome);
			break;
		
		case 2:
			setbuf (stdin, NULL);
			printf ("|Insira o novo número de registro: ");
			gets(Novo_Registro);
			strcpy (especialista[u].registro, Novo_Registro);
			break;
			
		case 3:
			setbuf (stdin, NULL);
			printf ("|Insira a nova especialidade: ");
			gets (Novo_Especialidade);
			strcpy (especialista[u].especialidade, Novo_Especialidade);
			break;
		
		default:
			printf ("|O valor inserido não existe no menu.\n");
	}
	
	
	
	printf ("|-----------> |ESPECIALISTA %d| <-----------|\n", u);
	printf ("|NOME|-> %s\n", especialista[u].nome);
	printf ("|REGISTRO|-> %s\n", especialista[u].registro);
	printf ("|ESPECIALIDADE|-> %s\n", especialista[u].especialidade);
	printf ("|--------------------------------------|\n");
	printf ("\n|Informações atualizadas!\n");
	
}

/*-------------------------------------------------------------------------------*/

void Apagar_Especialista (Especialista especialista[], int r){
	
	int i, u, k;
	char apagar[MAX];
	
	setbuf(stdin, NULL);
	system ("cls");
	
	printf ("|-----------> |APAGAR ESPECIALISTA| <------------|\n");
	
	for (i=0; i<r; i++){
		
		putchar ('\n');
		printf ("\n|-----------> |ESPECIALISTA %d| <-----------|\n", i);
		printf ("|NOME|-> %s\n", especialista[i].nome);
		printf ("|REGISTRO|-> %s\n", especialista[i].registro);
		printf ("|------------------------------------------|\n");
	}
	
	printf ("\n|Insira o registro do especialista que deseja apagar do sistema: ");
	gets(apagar);
	
	for (i=0; i<r; i++){
		
		if(strcmp (especialista[i].registro, apagar) == 0){
			for (u = i; u < r; u++){
				
			    k = u+1;
				strcpy (especialista[u].nome, especialista[k].nome);
				strcpy (especialista[u].registro, especialista[k].registro);
				strcpy (especialista[u].especialidade, especialista[k].especialidade);
				
				r--;
			}
		}
	}
	
		
}

/*-------------------------------------------------------------------------------*/

int Carregar_Consulta (Consulta consulta []){
	
	
	int i=0;
	
	FILE *arch;
	arch = fopen(FILE_C, "r+");
	
	if (arch == NULL){
		printf ("Problema na abertura do arquivo consulta.\n");
	}
	
	while (fscanf(arch, "%s %s %s %s %f %s %s %s %s %s  ", 
	consulta[i].paciente.nome, consulta[i].paciente.CPF,
	consulta[i].especialista.nome, consulta[i].especialista.registro, consulta[i].valor,
	consulta[i].hora, consulta[i].minuto, consulta[i].dia, consulta[i].mes, consulta[i].ano ) != EOF)
	i++;
	
	
	fclose (arch);
	return i;
	
	
}

/*-------------------------------------------------------------------------------*/

int Criar_Consulta (Consulta consulta[], Paciente paciente[], Especialista especialista[],
					int w, int n, int r){
	
	system ("cls");
	setbuf (stdin, NULL);

	
	int u, i;
	int k = 101;
	int j = 101;
	char Novo_CPF[MAX];
	char Novo_Registro[MAX];
	
	printf ("|----------> |CADASTRO CONSULTA| <-----------|\n");
	
	if (w < MAX){
		
		printf ("\n|-------> |LISTA DE PACIENTES| <--------|\n");
	
		for (int i=0; i<n; i++){
			printf ("|-----------> |PACIENTE %d| <-----------|\n", i);
			printf ("|NOME|: %s\n", paciente[i].nome);
			printf ("|CPF|: %s\n", paciente[i].CPF);
			printf ("|---------------------------------------|\n");
		}
	
		setbuf (stdin, NULL);
		putchar ('\n');
	
		printf ("|Insira o CPF do paciente que deseja realizar a consulta: ");
		gets (Novo_CPF);
	
		for ( u = 0; u<n; u++){
			if(strcmp(Novo_CPF, paciente[u].CPF) == 0){
				printf ("\n|O CPF inserido condiz com o paciente %d\n", u);
				k = u;
				
			}
		}
		
		if (k == 101){
			printf ("\nO CPF inserido não se encontra no BDD.\n");
			goto final;
		}
		strcpy(consulta[w].paciente.CPF, paciente[k].CPF);
		strcpy(consulta[w].paciente.nome, paciente[k].nome);
	
	
	
		system ("pause");
		system ("cls");
	
		printf ("|----------> |CADASTRO CONSULTA| <-----------|\n");
		printf ("\n|-------> |LISTA DE ESPECIALISTAS| <--------|\n");
		
			for (i=0; i<r; i++){
				printf ("|-----------> |ESPECIALISTA %d| <-----------|\n", i);
				printf ("|NOME|: %s\n", especialista[i].nome);
				printf ("|REGISTRO|: %s\n", especialista[i].registro);
				printf ("|ESPECIALIDADE|: %s\n", especialista[i].especialidade);
				printf ("|---------------------------------------|\n");
			}
	
	
		printf ("|Insira o REGISTRO do especialista desejado: ");
		gets (Novo_Registro);
	
		for (int y = 0; y<r; y++){
			if(strcmp(Novo_Registro, especialista[y].registro) == 0){
				printf ("\n|O registro inserido condiz com o especialista %d\n", y);
				j = y;
				
			}
		}
		
		if (j == 101){
			printf ("\nO registro inserido não se encontra no BDD.\n");
			goto final;
		}	
		strcpy(consulta[w].especialista.registro, especialista[j].registro);
		strcpy(consulta[w].especialista.nome, especialista[j].nome);
		
		
		
		system ("pause");
		system ("cls");
	
		printf ("|-------------> |INFORMAÇÕES| <-------------|\n");
		
		setbuf(stdin, NULL);
		printf ("|VALOR|: ");
		scanf ("%f", &consulta[w].valor);
	
		setbuf(stdin, NULL);
		printf ("|DIA|: ");
		gets (consulta[w].dia);
	
		setbuf(stdin, NULL);
		printf ("|MES|: ");
		gets (consulta[w].mes);
	
		setbuf(stdin, NULL);
		printf ("|ANO|: ");
		gets (consulta[w].ano);
	
		setbuf(stdin, NULL);
		printf ("|HORA|: ");
		gets (consulta[w].hora);
	
		setbuf(stdin, NULL);
		printf ("|MINUTO|: ");
		gets (consulta[w].minuto);
	
		putchar ('\n');
		printf ("\n|Consulta marcada, confira as informações:\n");
		printf ("|----------------> |CONSULTA %d| <----------------|\n", w);
		printf ("|NOME|: %s\n", consulta[w].paciente.nome);
		printf ("|CPF|: %s\n", consulta[w].paciente.CPF);
		printf ("|ESPECIALISTA|: %s\n", consulta[w].especialista.nome);
		printf ("|REGISTRO|: %s\n", consulta[w].especialista.registro);
		printf ("|VALOR|: %.2f R$\n", consulta[w].valor);
		printf ("|HORÁRIO|: %s:%s\n", consulta[w].hora, consulta[w].minuto);
		printf ("|DATA|: %s/%s/%s  \n", consulta[w].dia, consulta[w].mes, consulta[w].ano);
		printf ("|---------------------------------------|\n");
	
		w++;
	}
	
	final:;
	return w;
}

/*-------------------------------------------------------------------------------*/

void Ler_Consultas (Consulta consulta [], int w){
	
	int i;
	system ("cls");
	setbuf (stdin, NULL);
	
	printf ("|----------> |INFORMAÇÕES DE PACIENTES| <-----------|\n");

	
	for (i=0; i<w; i++){
		
		printf ("\n|-----------> |CONSULTA %d| <-----------|\n", i);
		printf ("|NOME|: %s\n", consulta[i].paciente.nome);
		printf ("|CPF|: %s\n", consulta[i].paciente.CPF);
		printf ("|ESPECIALISTA|: %s\n", consulta[i].especialista.nome);
		printf ("|REGISTRO|: %s\n", consulta[i].especialista.registro);
		printf ("|VALOR|: %.2f R$\n", consulta[i].valor);
		printf ("|HORÁRIO|: %s:%s\n", consulta[i].hora, consulta[i].minuto);
		printf ("|DATA|: %s/%s/%s  \n", consulta[i].dia, consulta[i].mes, consulta[i].ano);
		printf ("|--------------------------------------|\n");
		putchar('\n');
		
	 }
	
	
}

/*-------------------------------------------------------------------------------*/

void Buscar_Consulta (Consulta consulta [], int w){
	int i;
	char busca[MAX];
	

	system ("cls");
	printf ("|----------> |BUSCA DE CONSULTAS| <-----------|\n");
	
	setbuf (stdin, NULL);
	printf ("|Insira o CPF do paciente: ");
	gets(busca);
	
	system("pause");
	
	putchar ('\n');
	for (i=0; i<w; i++){
	
		if(strcmp(consulta[i].paciente.CPF, busca) == 0){
		
		printf ("\n|O paciente %d condiz com a busca. \n", i);
		printf ("\n|-----------> |CONSULTA %d| <-----------|\n", i);
		printf ("|NOME|: %s\n", consulta[i].paciente.nome);
		printf ("|CPF|: %s\n", consulta[i].paciente.CPF);
		printf ("|ESPECIALISTA|: %s\n", consulta[i].especialista.nome);
		printf ("|REGISTRO|: %s\n", consulta[i].especialista.registro);
		printf ("|VALOR|: %.2f R$\n", consulta[i].valor);
		printf ("|HORÁRIO|: %s:%s\n", consulta[i].hora, consulta[i].minuto);
		printf ("|DATA|: %s/%s/%s  \n", consulta[i].dia, consulta[i].mes, consulta[i].ano);
		printf ("|--------------------------------------|\n");	
		}		
	}
	
}

/*-------------------------------------------------------------------------------*/

void Atualizar_Consulta (Consulta consulta [], int w){
	
	int i;
	int u = 101;
	int k = 101;
	
	
	int choise;
	char opcao;
	
	char Novo_Registro[MAX];
	char Novo_CPF[MAX];
	char Novo_Hora[MAX];
	char Novo_Minuto[MAX];
	char Novo_Dia[MAX];
	char Novo_Mes[MAX];
	char Novo_Ano[MAX];
	float Novo_Valor;
	
	
	system ("cls");	
	
	printf ("|----------> |ATUALIZAR CONSULTA| <-----------|\n");
	putchar('\n');
	
	setbuf (stdin, NULL);
	printf ("|Insira o CPF do paciente: ");
	gets(Novo_CPF);
	
	setbuf (stdin, NULL);
	printf ("|Insira o registro do especialista: ");
	gets(Novo_Registro);
	
	
	system("pause");
	putchar ('\n');
	
	for (i=0; i<w; i++){
	
		if(strcmp(consulta[i].paciente.CPF, Novo_CPF) == 0){
			printf ("\n|O paciente %d condiz com a busca. \n", i);
			u = i;
		}
	}
	
	if (u == 101){
		putchar ('\n');
		printf ("\n|Não foi encontrado nenhuma consulta desse paciente.");
		goto final;
		system ("pause");
	}
	
	
	
	putchar ('\n');
	printf ("|--------------------------------------|\n");
	printf ("|1|-> HORÁRIO\n");
	printf ("|2|-> DATA\n");
	printf ("|3|-> VALOR\n");
	printf ("|--------------------------------------|\n");
	
	putchar ('\n');
	printf ("|Insira o número da informação que deseja alterar: ");
	scanf ("%d", &choise);
	
	putchar('\n');
	
do{	
	switch (choise){
		
		case 1:
			setbuf (stdin, NULL);
			printf ("|Insira a nova hora: ");
			gets(Novo_Hora);
			strcpy (consulta[u].hora, Novo_Hora);
			
			setbuf (stdin, NULL);
			printf ("|Insira o novo minuto: ");
			gets(Novo_Minuto);
			strcpy (consulta[u].minuto, Novo_Minuto);
			
			break;
		
		case 2:
			setbuf (stdin, NULL);
			printf ("|Insira o novo dia: ");
			gets(Novo_Dia);
			strcpy (consulta[u].dia, Novo_Dia);
			
			setbuf (stdin, NULL);
			printf ("|Insira o novo mes: ");
			gets(Novo_Mes);
			strcpy (consulta[u].mes, Novo_Mes);
			
			setbuf (stdin, NULL);
			printf ("|Insira o novo ano: ");
			gets(Novo_Ano);
			strcpy (consulta[u].ano, Novo_Ano);
			break;
			
		case 3:
			setbuf (stdin, NULL);
			printf ("|Insira o novo valor: ");
			scanf ("%f", &Novo_Valor);
			consulta[u].valor = Novo_Valor;
			break;
		
		default:
			printf ("|O valor inserido não existe no menu.\n");
			system ("pause");
			break;
	}
	
} while ((choise > 3) || (choise < 1));
	
	
	printf ("\n|Informações atualizadas!\n");
	printf ("\n|-----------> |CONSULTA %d| <-----------|\n", u);
	printf ("|NOME|: %s\n", consulta[u].paciente.nome);
	printf ("|CPF|: %s\n", consulta[u].paciente.CPF);
	printf ("|ESPECIALISTA|: %s\n", consulta[u].especialista.nome);
	printf ("|REGISTRO|: %s\n", consulta[u].especialista.registro);
	printf ("|VALOR|: %.2f R$\n", consulta[u].valor);
	printf ("|HORÁRIO|: %s:%s\n", consulta[u].hora, consulta[u].minuto);
	printf ("|DATA|: %s/%s/%s  \n", consulta[u].dia, consulta[u].mes, consulta[u].ano);
	printf ("|--------------------------------------|\n");	
	
	
	
	final:;
}

/*-------------------------------------------------------------------------------*/

void Apagar_Consulta (Consulta consulta [], int w){
	
	int i, u, k, t=101;
	char Novo_Registro[MAX];
	char Novo_CPF[MAX];
	
	setbuf(stdin, NULL);
	system ("cls");
	
	printf ("|-----------> |APAGAR CONSULTA| <------------|\n");
	
	for (i=0; i<w; i++){
		
		putchar ('\n');
		printf ("\n|-----------> |CONSULTA %d| <-----------|\n", i);
		printf ("|NOME|: %s\n", consulta[i].paciente.nome);
		printf ("|CPF|: %s\n", consulta[i].paciente.CPF);
		printf ("|ESPECIALISTA|: %s\n", consulta[i].especialista.nome);
		printf ("|REGISTRO|: %s\n", consulta[i].especialista.registro);
		printf ("|VALOR|: %.2f R$\n", consulta[i].valor);
		printf ("|HORÁRIO|: %s:%s\n", consulta[i].hora, consulta[i].minuto);
		printf ("|DATA|: %s/%s/%s  \n", consulta[i].dia, consulta[i].mes, consulta[i].ano);
		printf ("|------------------------------------------|\n");
	}
	
	setbuf (stdin, NULL);
	printf ("\n|Insira o CPF do paciente: ");
	gets(Novo_CPF);
	
	setbuf (stdin, NULL);
	printf ("|Insira o registro do especialista: ");
	gets(Novo_Registro);
	
	
	for (i=0; i<w; i++){
		
		if ((strcmp (consulta[i].especialista.registro, Novo_Registro) == 0)
		 && (strcmp (consulta[i].paciente.CPF, Novo_CPF) == 0)){
			for (u = i; u < w; u++){
				
			    k = u+1;
			    
			    strcpy (consulta[u].paciente.nome, consulta[k].paciente.nome);
			    strcpy (consulta[u].paciente.CPF, consulta[k].paciente.CPF);
			    strcpy (consulta[u].especialista.nome, consulta[k].especialista.nome);
			    strcpy (consulta[u].especialista.registro, consulta[k].especialista.registro);
			    consulta[u].valor = consulta[k].valor;
			    strcpy (consulta[u].hora, consulta[k].hora);
			    strcpy (consulta[u].minuto, consulta[k].minuto);
			    strcpy (consulta[u].dia, consulta[k].dia);
			    strcpy (consulta[u].mes, consulta[k].mes);
			    strcpy (consulta[u].ano, consulta[k].ano);	
			 
			}
		}
	}

	
}

/*-------------------------------------------------------------------------------*/

void Salvar_Info (Paciente paciente[], Especialista especialista [],
	Consulta consulta[], int n, int r, int w){
		
	system ("cls");
	setbuf (stdin, NULL);
	int i;
	FILE *fp;
	FILE *arq;
	FILE *arch;
	
	while (fgetc(stdin) != '\n');
	printf("\n|Insira [s] para salvar \n");	
	printf ("|Insira qualquer tecla para fechar.\n");
	
	if (getchar() == 's'){
		printf ("\n|Salvando alterações...\n");
		
		
		fp = fopen (FILE_NAME, "w");
		for(i=0; i<n; i++){
			fprintf (fp, "%s %s %s %s %s %s %s\n", paciente[i].nome,  paciente[i].CPF, paciente[i].email,
			paciente[i].tel, paciente[i].nascimento.dia, paciente[i].nascimento.mes, 
			paciente[i].nascimento.ano);
		}
		fclose(fp);
		
		
		arq = fopen (FILE_N, "w");
		for(i=0; i<r; i++){
			fprintf (arq, "%s %s %s \n", especialista[i].nome, especialista[i].registro, 
			especialista[i].especialidade);	
		}
		fclose(arq);
		
		
		arch = fopen (FILE_N, "w");
		for(i=0; i<r; i++){
			fprintf (arch, "%s %s %s %s %f %s %s %s %s %s \n", consulta[i].paciente.nome,  
			consulta[i].paciente.CPF, consulta[i].especialista.nome, consulta[i].especialista.registro,
			consulta[i].valor, consulta[i].hora, consulta[i].minuto, consulta[i].dia, consulta[i].mes,
			consulta[i].ano);	
		}
		fclose(arch);
		
		
		printf ("|Alterações feitas!\nObrigado pela paciência ^^\n");
	}
	else{
		printf ("|As alterações não foram salvas.\n");
	}
	
		
		
	}
