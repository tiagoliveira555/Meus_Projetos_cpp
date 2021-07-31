#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

vector <string> nome, endereco, cpf;
string n, e, c, r;
char s;

void cadastrar();

void relatorio();

void pesquisar();

void editar();

void excluir();

int main() {
    int opc;
    do{
        system("clear");
        cout << "-------------------------" << endl;
        cout << "      MENU PRINCIPAL     " << endl;
        cout << "-------------------------" << endl;
        cout << "[ 1 ] - CADASTRAR" << endl;
        cout << "[ 2 ] - RELATORIO" << endl;
        cout << "[ 3 ] - PESQUISAR" << endl;
        cout << "[ 4 ] - EDITAR" << endl;
        cout << "[ 5 ] - EXCLUIR" << endl << endl;
        cout << "[ 0 ] - SAIR" << endl;
        cout << "-------------------------" << endl;
        cout << "Sua opção: ";
        cin >> opc;

        switch(opc){
            case 0:
                cout << "Deseja sair realmente? [S/N]: ";
                cin >> s;
                if(s == 'S' || s == 's'){
                    s = 's';
                    break;
                }else{
                    cout << "Opção inválida!" << endl;
                    sleep(1);
                }

            case 1:
                cadastrar();
                break;

            case 2:
                relatorio();
                break;

            case 3:
                pesquisar();
                break;

            case 4:
                editar();
                break;

            case 5:
                excluir();
                break;

            default:
                cout << "Opção inválida!" << endl;
                sleep(1);
                break;
        }

    }while(s != 's');

    cout << "\nSaindo do sistema... Volte Sempre!" << endl;

    return 0;
}

void cadastrar(){
    do{
        inicioCadastro:
        system("clear");
        cout << "-------------------------" << endl;
        cout << "         CADASTRAR       " << endl;
        cout << "-------------------------" << endl;

        cout << "Nome....: ";
        cin.ignore();
        getline(cin, n);
        cout << "Endereço: ";
        getline(cin, e);
        cout << "CPF.....: ";
        getline(cin, c);

        nome.push_back(n);
        endereco.push_back(e);
        cpf.push_back(c);

        cout << n << " cadastrado com sucesso!" << endl;

        sair_cadastro:

        cout << "Deseja cadastrar outra pessoa? [S/N]: ";
        cin >> s;
        if(s == 'S' || s == 's'){
            goto inicioCadastro;
        }else if(s == 'N' || s == 'n'){
            s = 'N';
        }else{
            cout << "Opção inválida!" << endl;
            goto sair_cadastro;
        }

    }while(s != 'N');
}

void relatorio(){
    do{
        inicioRelatorio:
        system("clear");
        cout << "-------------------------" << endl;
        cout << "         RELATORIO       " << endl;
        cout << "-------------------------" << endl;

        if(nome.empty()){
            cout << "\nNenhum cadastro!\n" << endl;
        }

        for(int i = 0; i < nome.size(); i++){
            cout << "Nome....: " << nome[i] << endl;
            cout << "Endereço: " << endereco[i] << endl;
            cout << "CPF.....: " << cpf[i] << endl;
            cout << "-------------------------" << endl;
        }

        cout << "[M] Menu Principal: ";
        cin >> s;
        if(s == 'M' || s == 'm'){
            s = 'n';
        }else{
            cout << "Opção inválida!" << endl;
            sleep(1);
            goto inicioRelatorio;
        }

    }while(s != 'n');
}

void pesquisar(){
    do{
        inicioPesquisar:
        system("clear");
        cout << "-------------------------" << endl;
        cout << "         PESQUISAR       " << endl;
        cout << "-------------------------" << endl;

        cout << "Nome ou CPF de quem deseja pesquisar: ";
        cin.ignore();
        getline(cin, r);

        for(int i = 0; i < cpf.size(); i++){
            if(r == nome[i] || r == cpf[i]){
                cout << "Nome....: " << nome[i] << endl;
                cout << "Endereço: " << endereco[i] << endl;
                cout << "CPF.....: " << cpf[i] << endl;
                cout << "-------------------------" << endl;
            }else{
                cout << "Cadastro não encontrado!" << endl;
                sleep(1);
            }
        }
        cout << "\n[P] Pesquisar | [M] Menu Principal: ";
        sair_pesquisar:
        cin >> s;

        if(s == 'P' || s == 'p'){
            goto inicioPesquisar;
        }else if(s == 'M' || s == 'm'){
            s = 'n';
        }else{
            cout << "Opção invalida!\nEscolha P ou M: ";
            goto sair_pesquisar;
        }

    }while(s != 'n');
}

void editar(){
    do{
        inicioEditar:
        system("clear");
        cout << "-------------------------" << endl;
        cout << "           EDITAR        " << endl;
        cout << "-------------------------" << endl;

        cout << "Nome ou CPF de quem deseja editar: ";
        cin.ignore();
        getline(cin, r);

        for(int i = 0; i < cpf.size(); i++){
            if(r == nome[i] || r == cpf[i]){
                cout << "Nome....: " << nome[i] << endl;
                cout << "Endereço: " << endereco[i] << endl;
                cout << "CPF.....: " << cpf[i] << endl;
                cout << "-------------------------" << endl;

                string novo_nome, novo_endereco, novo_cpf;

                cout << "[ENTER] para permanecer o valor atual" << endl;

                cout << "Novo Nome....: ";
                getline(cin, novo_nome);
                cout << "Novo Endereço: ";
                getline(cin, novo_endereco);
                cout << "Novo CPF.....: ";
                getline(cin, novo_cpf);

                if(novo_nome != ""){
                    nome[i] = novo_nome;
                }
                if(novo_endereco != ""){
                    endereco[i] = novo_endereco;
                }
                if(novo_cpf != ""){
                    cpf[i] = novo_cpf;
                }

                cout << "\nDados editados com sucesso!" << endl;
            }
        }
        cout << "\n[E] Editar | [M] Menu Principal: ";
        sair_editar:
        cin >> s;

        if(s == 'E' || s == 'e'){
            goto inicioEditar;
        }else if(s == 'M' || s == 'm'){
            s = 'n';
        }else{
            cout << "Opção invalida!\nEscolha E ou M: ";
            goto sair_editar;
        }
    }while(s != 'n');

}

void excluir(){
    do{
        system("clear");
        cout << "-------------------------" << endl;
        cout << "          EXCLUIR        " << endl;
        cout << "-------------------------" << endl;

        cout << "Nome ou CPF de quem deseja excluir: ";
        cin.ignore();
        getline(cin, r);

        for(int i = 0; i < cpf.size(); i++){
            if(r == nome[i] || r == cpf[i]){
                cout << "Nome....: " << nome[i] << endl;
                cout << "Endereço: " << endereco[i] << endl;
                cout << "CPF.....: " << cpf[i] << endl;
                cout << "-------------------------" << endl;

                char s;
                cout << "\nTem certeza quer deseja excluir? [S/N]: ";
                cin >> s;

                if(s == 'S' || s == 's'){
                    nome.erase(nome.begin() + i);
                    endereco.erase(endereco.begin() + i);
                    cpf.erase(cpf.begin() + i);
                    cout << "Dados excluidos com sucesso!" << endl;
                    sleep(1);
                    s = 'n';
                }else{
                    s = 'n';
                }
            }
        }

    }while(s != 'n');
}
