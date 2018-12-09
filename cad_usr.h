#ifndef CAD_USR_H_INCLUDED
#define CAD_USR_H_INCLUDED
#include <set>
#include <vector>
#include <map>
#include <string>

typedef struct ender{
    std::string estado;
    std::string cidade;
    std::string bairro;
    std::string rua_av;
    int num;
    };

class Cad_usr
{
    private:
        bool pj;    //Indica se � pessoa jur�dica.
        std::string cad_receita;    //C.P.F. ou C.N.P.J. da pessoa.
        std::string nome;
        ender endereco;  //Estado,cidade,bairro,logradouro e n�mero, nesta ordem.
        std::string contato;
        std::vector<int>tipos_residuo;
        std::map<std::string,std::string>locais_coleta;/*Um "map" de endere�os onde o doador/receptor
        aceita doar/receber o material*/
    public:
        Cad_usr();
        ~Cad_usr();
        bool pega_tp_pessoa();
        std::string pega_contato();
        std::string pega_nome();
        std::string pega_id();//CPF OU CNPJ
        ender pega_endereco();
        bool acha_local(std::string*); //Verifica se o local � de interesse da pessoa
        bool acha_res(std::string); //Verifica se o res�duo � de interesse para a pessoa
        void adiciona_res();
        void adiciona_local();
        void exclui_res();
        void exclui_local();
};
#endif // CAD_USR_H_INCLUDED
