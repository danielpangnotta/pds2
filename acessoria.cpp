#include <string>
#include <iostream>
#include <locale>
#include <ctype.h>
#include <math.h>
#include "acessoria.h"

std::string dv_cpf(std::string cpf)
{
    std::string str = cpf.substr(0,9);
    int soma = 0, j = 0,resto = 0,d1 = 0, d2 = 0;
    for(j=0;j<9;++j)
        soma+=(str[j]-48)*(10-j);
    resto = soma%11;
    if(resto==0 || resto==1)
        d1 = 0;
    else
        d1 = 11-resto;
    resto=0;
    for(j=0;j<9;++j)
        resto+=str[j];
    soma=soma+resto-432+2*d1;
    resto = soma%11;
    if(resto==0 || resto==1)
        d2 = 0;
    else
        d2 = 11-resto;
    return std::to_string(d1)+std::to_string(d2);
};

std::string dv_cnpj(std::string)
{

};

std::string completa_id(std::string id,bool pj)
{
   int tam;
   std::string str = id;
   if(pj)
       tam=14;
   else
       tam=11;
   while(str.size()<tam)
   {
       str = '0'+str;
   };
   return str;
}

int cta_espacos(std::string str)//Conta quantos espaços existem no string.
{
    int n = 0;
    for(int i=0;i<str.length();i++)
        if(str[i] == ' ')
            n++;
    return n;
}
//------------------------------------------------------------------------------------------
int cta_non_zeros(std::string str)//Conta quantos algarismos diferentes de zero existem no string.
{
    int n = 0;
    for(int i=0;i<=str.size();i++)
        if(str[i]>48&&str[i]<58)
            n++;
    return n;
}
//------------------------------------------------------------------------------------------
bool e_alpha(std::string str)
{
    int i,test;
    for(i=0;i<=str.length();i++)
    {
        test = (int)str[i];
        if((test>0&&test<32)||(test>32&&test<65)||(test>90&&test<97)||test>122)
        {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------------------
bool e_num(std::string str)
{
    int i,test;
    for(i=0;i<=str.length();i++)
    {
        test = (int)str[i];
        if(test>0&&(test<48||test>57))
        {
            return false;
        }
    }
    return true;
}
//------------------------------------------------------------------------------------------
char valida_tp_pessoa()
{
    char resp;
    do
    {
        fflush(stdin);
        std::cout<<">>>>>>>>>>> Digite \"1\" para Pessoa Física ou \"2\" para Pessoa Jurídica >> ";
        std::cin>>resp;
    }while(resp!='1' && resp!='2');
}
//------------------------------------------------------------------------------------------
std::string valida_nome(bool tp)
{
    bool erro = false;
    std::string temp = " ";
    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite o nome: >> ";
        fflush(stdin);
        std::getline(std::cin, temp,'\n');

        if(e_alpha(temp)==false)
        {
            std::cout<<"\nO nome não deve conter número(s) nem caracteres especiais! <== "<<std::endl;
            erro = true;
        }
        else
        {
                int it = cta_espacos(temp);
                if(it==0)
                {
                    if(tp)
                    {
                        std::cout<<"\nDeve haver ao menos a qualificação da pessoa jurídica(LTDA,SA,EIRELI,\"Prefeitura de\",etc) <== "<<std::endl;
                        erro = true;

                    }
                    else
                    {
                        std::cout<<"\nDeve haver ao menos um sobrenome para a pessoa! <== "<<std::endl;
                        erro = true;
                    }

                };
        }
    }while(erro == true);
    return temp;
}
//------------------------------------------------------------------------------------------
std::string valida_cad_receita(bool tp)
{
    std::string tipo = " ";
    bool erro = false;
    std::string temp;
    int it = 0;
    bool test = false;
    tipo = (tp==true)?"CNPJ":"CPF";
    do
    {
        std::cout<<">>>>>>>>>>> Digite o número do "<<tipo<<" de forma direta: >> ";
        fflush(stdin);
        std::cin>>temp;
        erro = false;
        it = cta_non_zeros(temp);
        test = e_num(temp);
        if(test==false)
        {
            erro = true;
            std::cout<<"\nA entrada deve ser numérica! <== ";
        }
        else
        {
            int soma=0;
            for(int i=0;i<=temp.size();i++)
            {
                if(temp[i]>47&&temp[i]<58)
                    soma++;
            }
            if(tp==false)
            {
                if(it<4||soma>11)
                {
                    erro = true;
                    std::cout<<"\nO CPF deve conter pelo menos um algarismo não nulo,além do código para Estado e DV,tendo no máximo 11 algarismos ao todo. <== "<<std::endl;
                }
                else{
                    temp = completa_id(temp,0);
                    std::string dv = dv_cpf(temp);
                    if(temp.substr(9,2)!=dv)
                    {
                        erro = true;
                        std::cout<<"\nDigito de CPF incorrreto. >> "<<std::endl;
                    }
                }
            }
        }
    }while(erro == true);
    return temp;
}
//------------------------------------------------------------------------------------------
ender valida_ender()
{
    ender aux;
    bool erro = false;
    std::string temp = " ";
    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite a sigla do Estado: >> ";
        fflush(stdin);
        std::cin>>temp;

        if(e_alpha(temp)==false)
        {
            std::cout<<"\n\"Estado\" não deve conter número(s) nem caracteres especiais! <== "<<std::endl;
            erro = true;
        }
        else if(temp.size() !=2)
        {
            std::cout<<"\nDigite a sigla do estado com duas letras. Ex.: para São Paulo, digite \"SP\"! >> "<<std::endl;
            erro = true;
        }
        else {
            erro = true;
            temp[0] = std::toupper(temp[0]);
            temp[1] = std::toupper(temp[1]);
            std::string estados[27];
            estados[0] = "AC";
            estados[1] = "AL";
            estados[2] = "AM";
            estados[3] = "AP";
            estados[4] = "BA";
            estados[5] = "CE";
            estados[6] = "DF";
            estados[7] = "ES";
            estados[8] = "GO";
            estados[9] = "MA";
            estados[10] = "MG";
            estados[11] = "MS";
            estados[12] = "MT";
            estados[13] = "PA";
            estados[14] = "PB";
            estados[15] = "PE";
            estados[16] = "PI";
            estados[17] = "PR";
            estados[18] = "RJ";
            estados[19] = "RN";
            estados[20] = "RO";
            estados[21] = "RR";
            estados[22] = "RS";
            estados[23] = "SC";
            estados[24] = "SE";
            estados[25] = "SP";
            estados[26] = "TO";
            for(int i = 0;i < 27;++i)
            {
                if(temp.compare(estados[i])==0)
                {
                    erro = false;
                    aux.estado = temp;
                    break;
                }
            }
            if(erro == true)
                    std::cout<<"\nSigla de Estado inválida. Tente novamente: <== "<<std::endl;
        }
    }while(erro == true);

    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite a cidade: >> ";
        fflush(stdin);
        std::getline(std::cin, temp,'\n');

        if(e_alpha(temp)==false)
        {
            std::cout<<"\nO nome não deve conter número(s) nem caracteres especiais! <== "<<std::endl;
            erro = true;
        }

    }while(erro == true);
    aux.cidade = temp;
    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite o bairro: >> ";
        fflush(stdin);
        std::getline(std::cin, temp,'\n');

        if(e_alpha(temp)==false)
        {
            std::cout<<"\nO nome do bairro não deve conter número(s) nem caracteres especiais! <== "<<std::endl;
            erro = true;
        }

    }while(erro == true);
    aux.bairro = temp;

    do
    {
        erro = false;
        std::cout<<">>>>>>>>>>> Digite o nome da rua ou avenida: >> ";
        fflush(stdin);
        std::getline(std::cin, temp,'\n');

        if(e_alpha(temp)==false)
        {
            std::cout<<"\nO nome não deve conter número(s) nem caracteres especiais! <== "<<std::endl;
            erro = true;
        }

    }while(erro == true);
    aux.rua_av = temp;
    int num;

    do
    {
        std::cout<<">>>>>>>>>>> Digite o número de seu endereço: >> ";
        fflush(stdin);
        std::cin>>num;
        erro = false;
        if(std::cin.fail())
        {
            erro = true;
            std::cout<<"\nA entrada deve ser numérica! <== "<<std::endl;
            std::cin.clear();
        }
        else if(num<=0 || num > 40000)
        {
            erro = true;
            std::cout<<"\nO número deve ser maior que zero e menor que 40.000. <== "<<std::endl;
        }
    }while(erro == true);
    aux.num = num;
    return aux;
}
//------------------------------------------------------------------------------------------
std::string valida_contato()
{
    bool erro = false;
    int ddd = 0,tel = 0;
    std::string aux_num = " ";
    do
    {
        erro = false;
        fflush(stdin);
        std::cout<<">>>>>>>>>>> Digite um código \"DDD\" válido com dois algarismos: >> ";
        std::cin>>ddd;
        if(std::cin.fail())
        {
            erro = true;
            std::cout<<"\nA entrada deve ser numérica! <== "<<std::endl;
            std::cin.clear();
        }
        else if(ddd<11 || ddd>99)
        {
            erro = true;
            std::cout<<"\nDigite um número válido de DDD entre 11 e 99. >> "<<std::endl;
        }
        else{
            switch(ddd){
                case(20):
                case(23):
                case(25):
                case(26):
                case(29):
                case(30):
                case(36):
                case(39):
                case(40):
                case(50):
                case(52):
                case(56):
                case(57):
                case(58):
                case(59):
                case(60):
                case(70):
                case(72):
                case(76):
                case(78):
                case(80):
                case(90):
                {
                    erro = true;
                    std::cout<<"\nO número de DDD deve estar validado na lista da ANATEL. <== "<<std::endl;
                }
            }
        }
    }while(erro==true);
    do
    {
        erro = false;
        fflush(stdin);
        std::cout<<">>>>>>>>>>> Digite o número de telefone com oito ou nove algarismos: >> ";
        std::cin>>tel;
        if(std::cin.fail())
        {
            erro = true;
            std::cout<<"\nA entrada deve ser numérica! <== "<<std::endl;
            std::cin.clear();
        }
        else
        {
            aux_num = std::to_string(tel);
            if(aux_num.size()!=8 && aux_num.size()!=9)
            {
                erro = true;
                std::cout<<"\nO número deve ter de oito ou nove dígitos. <== "<<std::endl;
            }
        }
    }while(erro==true);
    if(aux_num.size()==8)
        return '(' + std::to_string(ddd) + ')' + aux_num.substr(0,4) + '-' + aux_num.substr(4,4);
    else
        return '(' + std::to_string(ddd) + ')' + aux_num.substr(0,5) + '-' + aux_num.substr(5,4);
}
