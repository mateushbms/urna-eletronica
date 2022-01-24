/*  Urna eletrônica em linguagem C. 
    Data de finalização: 05/12/2021*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int senha, voto, vseiya, vash, vgoku, vbranco, vnulo, vtotal, vvalidos, resposta, M[5][4], i, j, aux, aux1, pcanduniverso, pcandvalidos;
    
    voto=0;//inicialização de variáveis em zero
    senha=0;
    vseiya=0;
    vash=0;
    vgoku=0;
    vbranco=0;
    vnulo=0;
    vtotal=0;
    vvalidos=0;
    aux=0;
    aux1=0;
    pcanduniverso=0;
    pcandvalidos=0;
    
    //inserindo o id dos candidatos, valores branco e nulos na primeira coluna da matriz
    M[0][0]=13;//seiya (idade)
    M[1][0]=10;//ash (idade)
    M[2][0]=8000;//goku (mais de 8000)
    M[3][0]=0;//votos branco
    M[4][0]=-1;//votos nulos
    
    M[0][1]=0;//iniciando os valores em zero para a coluna dos valores de votos que será necessário iniciar em 0 para computar
    M[1][1]=0;
    M[2][1]=0;
    M[3][1]=0;
    M[4][1]=0;
    
    do
    {
        printf("Bem-vindo, eleitor, ao algoritmo em linguagem C de uma urna eletronica!\n");
        printf("Informe a senha para proseguir: ");
        scanf("%d", &senha);
        
        while(senha!=1234)//solicitação da senha com laço de repetição
        {
            printf("Senha incorreta. Informe a senha: ");
            scanf("%d", &senha);
        }
        system("clear");//limpar a tela da senha
        printf("Votação iniciada:\n");
        printf("Para votar no candidato 'Seiya', digite: '13'\nPara votar no candidato 'Ash Ketchum', digite: '10'\nPara votar no candidato 'Goku' digite: '8000'\n");//apresentar os candidatos e seus id' de votação
        printf("Para votar em branco digite '0', quaisquer outros valores serão considerados nulo.\n");
        scanf("%d", &voto);
        switch (voto)//Contabilizar cada voto dos candidatos, votos brancos e votos nulos
        {
            case 13://voto para o seiya
                printf("Você votou no Seiya!");
                vseiya=vseiya+1;
                M[0][1]=M[0][1]+1;
            break;
            case 10://voto para o ash
                printf("Você votou no Ash!");
                vash=vash+1;
                M[1][1]=M[1][1]+1;
            break;
            case 8000://voto para o goku
                printf("Você votou no Goku!");
                vgoku=vgoku+1;
                M[2][1]=M[2][1]+1;
            break;
            case 0://voto em branco
                printf("Você votou branco!");
                vbranco=vbranco+1;
                M[3][1]=M[3][1]+1;
            break;
            default://voto nulo
                printf("Você votou nulo!");
                vnulo=vnulo+1;
                M[4][1]=M[4][1]+1;
        }
        
        //limpar a tela de voto
        system("clear");
        
        //computação de votos totais e votos válidos
        vtotal=vseiya+vash+vgoku+vbranco+vnulo;
        vvalidos=vseiya+vash+vgoku;
        
        //opção de realizar outro voto ou terminar a votação
        printf("\nGostaria de realizar outro voto? Digite '1' para continuar ou '0' para parar? ");
        scanf("%d", &resposta);
        
        //Verificar se a resposta é 1 ou 0, além de garantir que o 0 será o valor de parada
        if(resposta != 1 && resposta != 0)
        {
            while(resposta!=1 && resposta!=0)
            {
                printf("\nAviso: digite 1 para realizar mais um voto ou 0 para encerrar a votação: ");
                scanf("%d", &resposta);
            }
        }
        system("clear");
    }while(resposta==1 && resposta!=0);
    
    //solicitação de senha para encerrar a votação
    printf("Informe a senha para encerrar a votação: ");
    scanf("%d", &senha);
    
    //validação da senha
    while(senha!=1234)
    {
        printf("Senha incorreta. Informe a senha: ");
        scanf("%d", &senha);
    }
    
    //ordenação por seleção decrescente dos candidatos com maiores votos
    for(i=0; i<=3; i++)
    {
        for(j=i+1; j<=4; j++)
        {
            if(M[i][1]<M[j][1])
            {
                aux=M[i][0];
                aux1=M[i][1];
                M[i][0]=M[j][0];
                M[i][1]=M[j][1];
                M[j][0]=aux;
                M[j][1]=aux1;
            }
        }
    }
    system("clear");
    for(i=0; i<=4; i++)
    {
        //cálculo da porcentagem de universo de votos, votos válidos e armazenamento na coluna 3 e 4
        pcanduniverso=(M[i][1]*100)/vtotal;
        pcandvalidos=(M[i][1]*100)/vvalidos;
        M[i][2]=pcanduniverso;
        M[i][3]=pcandvalidos;
    }
    
    //correção da porcentagem de votos válidos, zerando as posições de votos brancos e nulos
    for(i=0; i<=4; i++)
    {
        if(M[i][0]==0 || M[i][0]==-1)
        {
            M[i][3]=0;
        }
    }
    
    //exibição dos nomes das colunas
    printf("candidato - votos absolutos - porcentagem do universo de votos - porcentagem de votos validos (sem brancos e nulos)\n");
    
    //exibição ordenada dos candidatos - votos
    for(i=0; i<=4; i++)
    {
        printf("%d        -      %d          -         %d%%                  -          %d%%\n", M[i][0], M[i][1], M[i][2], M[i][3]);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("Obs: -1 = votos nulos!");
    // printf de teste de contagem de votos por candidato --  printf("vtotal= %d\nvseiya= %d \nvash= %d \nvgoku= %d\nvbranco= %d \nvnulo= %d\nvvalido= %d ", vtotal, vseiya, vash, vgoku, vbranco, vnulo, vvalidos);
    return 0;
}