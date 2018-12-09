#include <set>
#include <string>
#include <iostream>
#include <locale>
#include "cad_usr.h"
#include "acessoria.h"


Cad_usr::Cad_usr()
{
    std::cout<<"\n";
    std::cout<<">>>>>>>> PARA REALIZAR O CADASTRO INFORME OS DADOS A SEGUIR: <<<<<<<<\n"<<std::endl;

    if(valida_tp_pessoa()=='2')
    {
        this->pj = true;
    }
    else
    {
        this->pj = false;
    }

//------------------------------------------------------------------------------------------
    this->nome  = valida_nome(this->pj);
//------------------------------------------------------------------------------------------
    this->cad_receita = valida_cad_receita(this->pj);

//------------------------------------------------------------------------------------------
    this->endereco = valida_ender();
//------------------------------------------------------------------------------------------
    this->contato = valida_contato();
};

Cad_usr::~Cad_usr()
{
}

bool Cad_usr::pega_tp_pessoa()
{
    return pj;
}

std::string Cad_usr::pega_contato()
{
    return contato;
};

std::string Cad_usr::pega_nome()
{
    return nome;
}

std::string Cad_usr::pega_id()
{
    return cad_receita;
}

ender Cad_usr::pega_endereco()
{
    return endereco;
};
