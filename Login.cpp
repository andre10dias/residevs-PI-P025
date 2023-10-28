#include "include/Login.h"

void menu()
{
    Usuario usuario;
    int opcao;
    
    vector<string> menu = {
        "[ 1 ] Cadastre-se", 
        "[ 2 ] Login",
        "[ 3 ] Sair"
    };

    while(true)
    {
        systemClear();
        titulo_principal(); 

        monta_menu(menu, "Selecione uma opção: \n");
        opcao = obter_opcao(3);

        switch (opcao)
        {
            case 1: 
                int cadastro = tela_cadastre_se(usuario);
                if (cadastro == 1)
                {
                    cout << "Teste cadastro Ok";
                    systemPause();
                }
                
                break;

            case 2: 
                // ctrl_turma::exclui_aluno(turma);
                break;

            case 3: 
                sair();
                break;

            // case 4: ctrl_turma::mostra_alunos(turma);
            //         break;
            
            // case 5: ctrl_turma::mostra_aprovados(turma, 60);
            //         break;
            // case 6: ctrl_turma::mostra_reprovados(turma, 60);
            //         break;
        }
    }
}

void titulo_principal() {
    cout << TRACO;
    cout << "\nBem vindo ao Twitter - Sua rede social\n";
    cout << TRACO;
}

int tela_cadastre_se(Usuario &usuario)
{
    string nome = "";
    string nome_usuario = "";
    int opcao = -1;

    do
    {
        systemClear();

        cout << TRACO;
        cout << "\nCadastro de Usuários\n";
        cout << TRACO;

        cout << "Informe um nome de usuário: ";
        cin >> nome_usuario;

        usuario = RedeSocial::buscar_usuario(nome_usuario);
        if (usuario.getNome_usuario() != "")
        {
            cout << "\nNome de usuário já cadastrado\n" << endl;
            cout << "[ 1 ] Tentar novamente \t [ 2 ] Voltar" << endl;
            cout << "Selecione uma opcao: ";
            cin >> opcao;
        }
        
    } while (usuario.getNome_usuario() != "" || opcao != 2);

    if (opcao == 2)
    {
        return 0;
    }

    cout << "Informe seu nome: ";
    cin.sync();
    getline(cin, nome);

    RedeSocial::registrar_usuario(nome_usuario, nome);
    usuario.setNome(nome);
    usuario.setNome_usuario(nome_usuario);

    cout << "\nUsuário cadastrado com sucesso.\n";
    systemPause();
    return 1;
}