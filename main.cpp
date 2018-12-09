#include <iostream>
#include <string>
#include <locale>
#include "cad_residuos.h"
#include "cad_usr.h"



using namespace std;


int main()
{
    std::setlocale(LC_ALL,"Portuguese_Brazil");
    Cad_residuos r;
    r.imprime();
    bool c =  r.consulta_residuo(44100);
    cout<<"consulta: "<<c<<endl;
    Cad_usr user;
    string b = user.pega_id();
    cout<<"numero cpf/cnpj: "<<b<<endl;
    string n = user.pega_nome();
    cout<<"nome: "<<n<<endl;
    ender e = user.pega_endereco();
    cout<<"Estado: "<<e.estado<<endl;
    cout<<"Cidade: "<<e.cidade<<endl;
    cout<<"Bairro: "<<e.bairro<<endl;
    cout<<"Rua/Avenida: "<<e.rua_av<<endl;
    cout<<"Número da rua/av: "<<e.num<<endl;
    cout<<"Número do telefone: "<<user.pega_contato()<<endl;

    return 0;
}
