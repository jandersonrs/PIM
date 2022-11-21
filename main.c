#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int i = 2;

void clear()
{
    system("cls");
}
void tela()
{
    printf("\n*---------------------------*");
    printf("\n|         PIZZARIA          |");
    printf("\n*---------------------------*\n");
}

void menulogins()
{
    int menulogins1;
    int whilesMenulogins;
    tela();

    do
    {
        clear();
        printf("\n*---------------------------*");
        printf("\n|         PIZZARIA          |");
        printf("\n*---------------------------*");
        printf("\n| 1: Cliente                |");
        printf("\n|                           |");
        printf("\n| 2: Administrador          |");
        printf("\n*---------------------------*\n");

        scanf("%i", &menulogins1);
        switch(menulogins1){

    case 1:

        loginusuario();
        whilesMenulogins = 1;
        break;
    case 2:
        loginadm();
        whilesMenulogins = 1;
        break;
        }





}while(whilesMenulogins != 1);
}



void loginadm(){
  FILE *usuario;
  FILE *senha;
  int escolha;
  int cadastro = 0;
  int logado = 0;
  char nomepizzaria[30];
  char senhapizzaria[30];
  char Vlogin[30];
  char Vsenha[30];
  int k = 0;
  int g = 0;
  int menu2 = 0;
  char a[100];
  int ver ;


do{

  cadastro = 0;
  clear();
  tela();
  printf("\n| 1: Login ADM              |\n\n");
  printf("\n| 2: Cadastrar ADM          |\n\n");
  tela1();
  scanf("%i",&escolha);
  clear();
  switch(escolha){
  case 1:
      do{

    tela();
    printf("| Login: ");
    scanf("%s",&Vlogin);
    printf("| Senha: ");
    scanf("%s",&Vsenha);

usuario = fopen("usuario.txt","r");
	while(fscanf(usuario,"%s",a)!=EOF){
       if(strcmp(a,Vlogin) == 0){
	        k=1;
	        break;
        }
    }
    fclose(usuario);

    senha = fopen("senha.txt","r");
	while(fscanf(senha,"%s",a)!=EOF){
        if(strcmp(a,Vsenha) == 0){
	        g=1;

	        break;
        }
    }
    fclose(senha);


  if(k==1 && g==1){
    clear();


    logado = 1;


    printf("\n*---------------------------*");
    printf("\n                            |");
    printf("\n| BEM-VINDO %s              ", Vlogin);
    printf("\n\n*---------------------------*\n");


    printf("| 1: Cadastar Pizzaiolos    |\n");
    printf("| 2: Bebidas e Pizzas       |\n");
    printf("| 3: Pedidos                |\n");
    printf("| 4: Clientes               |\n");
    printf("| 5: Promoções              |\n");
    printf("| 6: Estoque                |\n");
    printf("| 7: Cadastro de Pizzaria   |\n");
    tela1();
    scanf("%i",&menu2);
    switch(menu2){
case 1:
    Tpizzaiolos();
    break;
case 2:
    BebidasEPizzas();
    break;
    }
  }
  else{
    printf(" LOGIN ou SENHA invalido tente novamente \n");
  }

  }while(logado !=1);

  break;

  case 2:
    usuario = fopen("usuario.txt","a");
        clear();
        tela();
        printf("\n| Nome da Pizzaria: ");
        getchar();
        scanf("%[^\n]s", &nomepizzaria);

        fprintf(usuario,"\n%s", nomepizzaria);
        fclose(usuario);

        senha = fopen("senha.txt","a");
        printf("| Senha para Pizzaria: ");
        getchar();
        scanf("%[^\n]s",&senhapizzaria);
        fprintf(senha,"\n%s",senhapizzaria);
    fclose(senha);
    clear();
    cadastro = 1;
    break;


  default:
    printf("Escolha invalida  tente novamente\n");
  }
}while(cadastro == 1 || escolha == 3);
}


void telalogado()
{
    printf("\n*---------------------------*");
    printf("\n|         BEM-VINDO         |");
    printf("\n*---------------------------*\n");
}


void tela1()
{
    printf("\n*---------------------------*\n");
}







void BebidasEPizzas()
{

    FILE *Sabores;
    FILE *Bebidas;
    int menu;
    int menu2;
    int menu3;
    char ListaSabores[100];
    char NomeSabores [20];
    char ListaBebidas[200];
    char NomeBebidas [30];
    float precopizza,precobebida;
    int whiles;
    int whilesP = 1 ;
    int whilesB;
    do
    {
        clear();
        whiles = 0;
        printf("\n*---------------------------*");
        printf("\n|         PIZZARIA          |");
        printf("\n*---------------------------*");
        printf("\n| 1: Menu de Pizzas         |");
        printf("\n|                           |");
        printf("\n| 2: Menu de Bebidas         |");
        printf("\n*---------------------------*\n");

        scanf("%i",&menu);
        switch(menu)
        {
        case 1:
            do
            {
                clear();
                printf("\n*---------------------------*");
                printf("\n|         PIZZARIA          |");
                printf("\n*---------------------------*");
                printf("\n| 1: Lista de pizzas        |");
                printf("\n| 2: Adicionar pizza        |");
                printf("\n| 3: Voltar                 |");

                printf("\n*---------------------------*\n");


                scanf("%i",&menu2);
                switch(menu2)
                {
                case 1:
                    Sabores = fopen("Sabores.txt","r");
                    if(fgets(ListaSabores, 100, Sabores) == NULL)
                    {
                        printf("NENHUMA SABOR ADICIONADO APERTE ENTER PARA VOLTAR");
                        getch();
                    }
                    else
                    {
                        printf("\n");
                        while(fgets(ListaSabores, 100, Sabores) != NULL)
                            printf("%s", ListaSabores);

                        fclose(Sabores);
                    }
                    getch();
                    break;
                case 2:
                    Sabores = fopen("Sabores.txt","a");

                    clear();
                    tela();
                    printf("| Digite o sabor da pizza: ");
                    getchar();
                    scanf("%[^\n]s", NomeSabores);

                    printf("| Digite o valor da pizza: ");
                    scanf("%f", &precopizza);



                    fprintf(Sabores,"\n - %s - Valor R$: %.2f", NomeSabores, precopizza);
                    fclose(Sabores);

                      whilesP = 2;
                    break;
                case 3:
                    whilesP = 2;
                    break;
                default:
                    clear();
                    printf("numero invalido!!!! tente novamente \n");
                }
            }
            while(whilesP == 1);
            break;
        case 2:
            do
            {
                clear();
                tela();
                printf(" 1 = ver lista de bebidas \n");
                printf(" 2 = Adicionar uma bebida \n");
                printf(" 3 = voltar\n");
                tela();
                scanf("%i",&menu3);
                switch(menu3)
                {
                case 1:

                    Bebidas = fopen("Bebidas.txt","r");
                    if(fgets(ListaBebidas, 100, Bebidas) == NULL)
                    {
                        printf("NENHUMA BEBIDA ADICIONADA APERTE ENTER PARA VOLTAR");
                        getch();
                    }
                    else
                    {
                        while(fgets(ListaBebidas, 100, Bebidas) != NULL)
                            printf("%s", ListaBebidas);
                        fclose(Bebidas);
                        getch();
                    }
                    break;
                case 2:
                    Bebidas = fopen("Bebidas.txt","a");
                    printf("Digite o Nome da bebida \n");
                    getchar();
                    scanf("%[^\n]s",NomeBebidas);
                    printf("Preço da Bebida \n");
                    scanf("%f",&precobebida);

                    fprintf(Bebidas,"\n - %s - Valor R$: %.2f",NomeBebidas,precobebida);

                    fclose(Bebidas);

                    break;
                case 3 :
                    whilesB =1;
                    break;
                default:
                    printf("numero invalido!!!! tente novamente \n");

                }
                break;
            default:
                printf("numero invalido!!!! tente novamente \n");


            }
            while(whilesB = 1);
        }

    }
    while(whiles != 1);
}
void Tpizzaiolos()
{
    FILE *pizzaiolos;
    char Npizzaiolos[100];
    char ListaPizzaiolos[100];

    char Ntpizzaiolos[100];
    int menu;
    int voltar;
    do
    {
        clear();
        tela();
        printf("1- cadastrar pizzaiolo \n");
        printf("2- ver pizzaiolos \n");
        scanf("%i",&menu);

        switch(menu)
        {
            voltar = 0;
        case 1 :
            pizzaiolos = fopen("Pizzaiolos.txt","a");
            clear();
            printf(" Digite o Nome do pizzaiolo \n");
            scanf("%s",&Npizzaiolos);

            printf(" Digite o número de telefone do pizzaiolo: \n");
            scanf("%s",&Ntpizzaiolos);

            fprintf(pizzaiolos,"\nNome: %s - Telefone: %s", Npizzaiolos, Ntpizzaiolos);
            fclose(pizzaiolos);
            break;
        case 2 :
            pizzaiolos = fopen("pizzaiolos.txt","r");
            if(fgets(ListaPizzaiolos, 100, pizzaiolos) == NULL)
            {
                printf("NENHUM PIZZAIOLO ADICIONADO APERTE ENTER PARA VOLTAR");
                getch();
            }
            else
            {
                clear();
                tela();
                printf("os pizzaiolos cadastrados são \n");
                while(fgets(ListaPizzaiolos, 100, pizzaiolos) != NULL)
                    printf("%s", ListaPizzaiolos);
                fclose(pizzaiolos);
                getch();
            }

            break;
        case 3 :
            voltar =1;
        default:
            tela();
            printf("valor invalido,tente novamente \n");

        }
    }
    while(voltar != 1);
}



void pedido(char nome[100])
{
    FILE *Total;
    FILE *Sabores;
    FILE *Pedidos;
    float Valor;
    FILE *Bebidas;
    FILE *PedidosB;
    FILE *TotalB;
    float totalB;
    float valorB;
    float ValorB;
    char bebida[100];
    char ListaSabores [100];
    char ListarBebidas [100];
    char sabor [100];
    char saborValor [100];
    char bebidaValor [100];
    char a [100];
    char aB [100];
    char str[255];
    int contador = 1 ;
    int quantidade = 0;
    int quantidadeB = 0;
    int verificar ;
    int VerificarB = 0;
    int Vverificar ;
    int k = 0;
    float valor;
    int voltar = 0;
    float total;
    do
    {
        Vverificar = 0;
        int opcao;
        clear();
        tela();
        printf("|1: Fazer pedido de Pizza   |\n");
        printf("|2: Fazer pedido de Bebida  |\n");
        printf("|3: Sair                    | \n");
        scanf("%i",&opcao);
        switch(opcao){
    case 1:
        Sabores = fopen("Sabores.txt","r");
        if(fgets(ListaSabores, 100, Sabores) == NULL)
        {
            printf("\nPizzaria não tem nenhuma pizza cadastrada! TECLE PARA VOLTAR! ");
            getch();
            break;
            voltar = 1;
        }
        else
        {
            printf("\n");
            tela();
            while(fgets(ListaSabores, 100, Sabores) != NULL)
                printf("%s", ListaSabores);
            fclose(Sabores);
        }
        printf("\n| Digite o nome do sabor que deseja conforme os sabores acima: ");
        scanf("%s",&sabor);

        Sabores = fopen("Sabores.txt","r");
        while(fscanf(Sabores,"%s",a)!=EOF)
        {
            if(strcmp(a,sabor) == 0)
            {
                fgets(sabor, 255, Sabores);
                k=1;
                break;
            }
        }
        fclose(Sabores);
        if(k == 0 )
        {
            printf("| Sabor digitado nao existe \n");
            getch();
            clear();
            voltar = 1 ;
        }
        else
        {
            clear();
            tela();
            printf("| Quantas pizzas o senhor(a) deseja?: ");
            scanf("%i",&quantidade);
            clear();
            printf("| Entao Senhor %s \n",nome);
            printf("Sao %i pizzas de %s %s cada \n", quantidade,a, sabor);
            printf("1= sim \n");
            printf("2= nao \n");
            scanf("%i",&verificar);
            switch(verificar)
            {
            case 1:
                Pedidos = fopen("Pedidos.txt","a");
                fprintf(Pedidos,"\nUsuario: %s",nome);
                fprintf(Pedidos,"\nSabor: %s %s",a,sabor);
                fprintf(Pedidos,"\nQuantidade : %i",quantidade);
                fclose(Pedidos);
                clear();
                tela();
                Sabores = fopen("Sabores.txt", "r");
                while(fscanf(Sabores, " - %s - Valor R$: %f",&saborValor, &valor)!= EOF){
                        if(strcmp(a,saborValor) == 0)
                        {
                        Valor = valor;
                        }
                        getch();
                }
                 fclose(Sabores);
                printf("pedido realizado com sucesso,aperte enter para voltar para a tela de usuario \n");
                total = (valor * quantidade);
                printf("Valor total do pedido: %.2f", total);
                Total =fopen("TotalPedidos.txt","a");
                fprintf(Total,"\n Cliente: %s",nome);
                fprintf(Total,"\n Valor total do pedido %f \n",total);
                fclose(Total);
                getch();
                break;
            case 2:
                printf("voce ira voltar para o inicio do pedido,aperte enter para continuar \n");
                getch();
                Vverificar = 1;
                break;
            default:
                printf("valor invalido");
                Vverificar = 1;
            }
        }

    while(Vverificar == 1);
        break;
    case 2:
        Bebidas = fopen("Bebidas.txt","r");
        if(fgets(ListarBebidas, 100,Bebidas) == NULL)
        {
            printf("\nPizzaria não tem nenhuma Bebida cadastrada! TECLE PARA VOLTAR! ");
            getch();
            break;
            voltar = 1;
        }
        else
        {
            printf("\n");
            tela();
            while(fgets(ListarBebidas, 100, Bebidas) != NULL)
                printf("%s", ListarBebidas);
            fclose(Bebidas);
        }
        printf("\n| Digite o nome da bebida que deseja conforme as bebidas acima: ");
        scanf("%s",&bebida);

        Bebidas = fopen("Bebidas.txt","r");
        while(fscanf(Bebidas,"%s",aB)!=EOF)
        {
            if(strcmp(aB,bebida) == 0)
            {
                fgets(bebida, 255, Bebidas);
                k=1;
                break;
            }
        }
        fclose(Bebidas);
        if(k == 0 )
        {
            printf("| Bebida digitado nao existe \n");
            getch();
            clear();
            voltar = 1 ;
        }
        else
        {
            clear();
            tela();
            printf("| Quantas Bebidas o senhor(a) deseja?: ");
            scanf("%i",&quantidadeB);
            clear();
            printf("| Entao Senhor %s \n",nome);
            printf("Sao %i Bebidas de %s %s  cada \n", quantidadeB,aB,bebida);
            printf("1= sim \n");
            printf("2= nao \n");
            scanf("%i",&VerificarB);
            switch(VerificarB)
            {
            case 1:
                PedidosB = fopen("PedidosB.txt","a");
                fprintf(PedidosB,"\nUsuario: %s",nome);
                fprintf(PedidosB,"\nBebida: %s %s",aB,bebida);
                fprintf(PedidosB,"\nQuantidade : %i",quantidadeB);
                fclose(PedidosB);
                clear();
                tela();
                Bebidas= fopen("Bebidas.txt", "r");
                while(fscanf(Bebidas, " - %s - Valor R$: %f",&bebidaValor, &valorB)!= EOF){
                        if(strcmp(aB,bebidaValor) == 0)
                        {
                        ValorB =valorB;
                        printf("fazendo isso");
                        break;
                        }
                        getch();
                }
                 fclose(Bebidas);
                printf("pedido realizado com sucesso,aperte enter para voltar para a tela de usuario \n");
                totalB = (ValorB * quantidadeB);
                printf("Valor total do pedido: %.2f", totalB);
                TotalB  =fopen("TotalPedidosBebidas.txt","a");
                fprintf(TotalB,"\n Cliente: %s",nome);
                fprintf(TotalB,"\n Valor total do pedido %f \n",totalB);
                fclose(TotalB);
                getch();
                break;
            case 2:
                printf("voce ira voltar para o inicio do pedido,aperte enter para continuar \n");
                getch();
                Vverificar = 1;
                break;
            default:
                printf("valor invalido");
                Vverificar = 1;
            }
        }

    while(Vverificar == 1);
        break;
    case 3:
        Vverificar = 2;
        break;
    default:
         printf("valor invalido\n");
                Vverificar = 1;
        break;
        }

        }while(Vverificar == 1);

}

void CadastarUsuario()
{
    FILE *Cliente;
    FILE *ClienteSenha;
    FILE *ClienteLogin;
    char nomesb[100];
    char login [100];
    char senha2 [100];
    char CPF [100];
    char celular [100];
    char endereco[100];
    char bairro[100];
    char cep[100];
    char cidade[100];
    char numero[100];


    tela();

    Cliente = fopen("Cliente.txt","a");

    printf("| Digite o seu nome e sobrenome: ");
    getchar();
    scanf("%[^\n]s",&nomesb);
    fprintf(Cliente,"\n \nNome: %s", nomesb);


    printf("| Digite o seu CPF: ");
    getchar();
    scanf("%[^\n]s",&CPF);
    fprintf(Cliente,"\nCPF: %s", CPF);

    printf("| Digite o seu número de celular: ");
    getchar();
    scanf("%[^\n]s", &celular);
    fprintf(Cliente,"\nCelular: %s", celular);

    printf("| Digite sua cidade: ");
    getchar();
    scanf("%[^\n]s", &cidade);
    fprintf(Cliente,"\nCidade: %s", cidade);

    printf("| Digite o seu bairro: ");
    getchar();
    scanf("%[^\n]s", &bairro);
    fprintf(Cliente,"\nBairro: %s", bairro);

    printf("| Digite o seu endereço: ");
    getchar();
    scanf("%[^\n]s", &endereco);
    fprintf(Cliente,"\nEndereço: %s", endereco);

    printf("| Digite o número: ");
    getchar();
    scanf("%[^\n]s", &numero);
    fprintf(Cliente,"\nNúmero: %s", numero);

    printf("| Digite o CEP: ");
    getchar();
    scanf("%[^\n]s", &cep);
    fprintf(Cliente,"\nCEP: %s", cep);
    fclose(Cliente);

    ClienteLogin=fopen("ClienteLogin.txt","a");
    printf("| Login: ");
    getchar();
    scanf("%[^\n]s",&login);
    fprintf(ClienteLogin, "\nLogin: %s", login);
    fclose(ClienteLogin);

    ClienteSenha = fopen("ClienteSenha.txt","a");

    printf("| Senha: ");
    getchar();
    scanf("%[^\n]s",&senha2);
    fprintf(ClienteSenha,"\nUsuario %s - Senha: %s", login, senha2);

    fclose(ClienteSenha);



    clear();
}
void loginusuario()
{

    FILE *cliente;
    FILE *ClienteLogin;
    FILE *ClienteSenha;
    FILE *Avaliacao;
    char Vlogin [100];
    char Vsenha [100];
    int avaliacao;
    int escolha;
    int k =0;
    int g= 0;
    char a [100];
    int voltar = 0;
    do
    {
        clear();
        voltar = 0;
        tela();
        printf("| Login: ");
        scanf("%s",&Vlogin);
        printf("| Senha: ");
        scanf("%s",&Vsenha);

        if(strcmp(Vlogin,"Login:") == 0 || strcmp(Vlogin,"CPF:") == 0 || strcmp(Vlogin,"Celular:") == 0 || strcmp(Vsenha,"Senha:") == 0 )
        {
            printf(" login ou senha invalido \n");
            getch();
            clear();
            voltar = 1;

        }
        else
        {
            ClienteLogin = fopen("ClienteLogin.txt","r");
            while(fscanf(ClienteLogin,"%s",a)!=EOF)
            {
                if(strcmp(a,Vlogin) == 0)
                {
                    k=1;
                    break;
                }
            }
            fclose(ClienteLogin);

            ClienteSenha = fopen("ClienteSenha.txt","r");
            while(fscanf(ClienteSenha,"%s",a)!=EOF)
            {
                if(strcmp(a,Vsenha) == 0)
                {
                    g=1;

                    break;
                }
            }
            fclose(ClienteSenha);
        }
    }
    while(k==0 && g==0);


    if(k==1 && g==1)
    {
        clear();
        tela();
        do
        {
            clear();
            voltar = 0;
            tela();
            printf("| 1: Fazer Pedido \n");
            printf("| 2: Avaliação \n");
            tela1;


            scanf("%i",&escolha);
            switch(escolha)
            {
            case 1:
                pedido(Vlogin);
                voltar = 1;
                break;
            case 2:
    clear();
    tela();
    printf("| Avalie a pizzaria com uma nota de 0 a 5: ");
    fflush(stdin);
    scanf("%d", &avaliacao);



    Avaliacao = fopen("Avaliação.txt", "a");
    fprintf(Avaliacao, "\nAvaliação do %s: %d", Vlogin, avaliacao);




    fclose(Avaliacao);
    break;






            default:
                printf("numero invalido tente novamente ");
                getch();
                voltar = 1 ;
            }
        }
        while(voltar = 1);
    }
}













void main()
{
    FILE *usuario;
    FILE *senha;
    FILE *cliente;
    FILE *ClienteSenha;
    int escolha;
    int cadastro = 0;
    int logado = 0;
    char login[30];
    char senha2[30];
    char Vlogin[30];
    char Vsenha[30];
    int k = 0;
    int g = 0;
    int menu2 = 0;
    int voltar = 0;
    char a[100];
    int ver ;

    system("color b");
    setlocale(LC_ALL, "Portuguese");


    do
    {

        cadastro = 0;
        tela();
        printf("\n| 1- Login                  |\n\n");
        printf("| 2- Cadastrar              |\n");
        tela1();
        scanf("%i",&escolha);
        clear();
        switch(escolha)
        {
        case 2:
            CadastarUsuario();
        case 1:
            menulogins();
        }
    }while(cadastro == 1 || escolha == 3);
}



