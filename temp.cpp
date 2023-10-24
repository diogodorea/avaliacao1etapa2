#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Paciente {

    string cpf, nome, dt_nascimento;

    public:
    Paciente(string _nome, string _cpf, string _dt_nascimento) : nome(_nome), cpf(_cpf), dt_nascimento(_dt_nascimento) {}

    string getNome() {
        return nome;
    }
    string getCpf() {
        return cpf;
    }
    string getDt_nascimento() {
        return dt_nascimento;
    }
    void setDt_nascimento(string _Dt_nascimento) {
        dt_nascimento = _Dt_nascimento;
    }
    void setCpf(string _cpf) {
        cpf = _cpf;
    }
    void setNome(string _nome) {
        nome = _nome;
    }

    static void incluirPaciente(vector<Paciente>&pacientes){

        string aux_nome, aux_cpf, aux_dt_nascimento;
        cout << "Informe o nome: " << endl;
            std::cin.ignore();
            getline(std::cin, aux_nome);

            cout << "Informe o CPF: " << endl;
            getline(std::cin, aux_cpf);

            cout << "Informe a data de Nascimento: ";
            getline(std::cin, aux_dt_nascimento);

            Paciente novoPaciente(aux_nome, aux_cpf, aux_dt_nascimento);
            pacientes.push_back(novoPaciente);
    }

    static void excluirPaciente(vector<Paciente> &pacientes){
        
        string aux_cpf;
        bool pacienteEncontrado = false;

        cout << "Informe o CPF do paciente que deseja Excluir...";
        std::cin.ignore();
        getline(std::cin, aux_cpf);

        for (int i = 0; i < pacientes.size(); i++) {
            if (aux_cpf == pacientes[i].getCpf()) {
                pacientes.erase(pacientes.begin() + i);
                cout << "Paciente removido com sucesso" << endl;
                pacienteEncontrado = true;
                break;
            }
        }
        if (!pacienteEncontrado) {
            cout << "Paciente com o CPF:  " << aux_cpf << "  Nao encontrado!" << endl;
        }
    }

    static void editarPaciente(vector<Paciente> &pacientes){
        
        string aux_cpf, aux_nome, aux_dt_nascimento;
        string valida;

        cout << "Informe o CPF do paciente que deseja alterar os dados." << endl;
        std::cin.ignore();
        getline(std::cin, aux_cpf);

        for (int i = 0; i < pacientes.size(); i++) {
            if (aux_cpf == pacientes[i].getCpf()) {
                cout << "Nome: " << pacientes[i].getNome()<< endl;
                cout << "CPF: " << pacientes[i].getCpf() << endl;
                cout << "Data Nascimento: " << pacientes[i].getDt_nascimento() << endl;

                cout << "Deseja alterar o nome? (1-SIM / 2-NAO)" << endl;
                if (!(std::cin >> valida) || (valida != "1" && valida != "2")) {
                    cout << "Entrada inválida. Por favor, escolha 1 para SIM ou 2 para NAO." << endl;
                return;
                }
            
                if(valida == "1"){
                    cout << "Digite o novo nome: " << endl;
                    std::cin.ignore();
                    getline(std::cin, aux_nome);
                    pacientes[i].setNome(aux_nome);
                }

                cout << "Deseja alterar a data de nascimento? (1-SIM/2-NAO)" << endl;
                if (!(std::cin >> valida) || (valida != "1" && valida != "2")) {
                    cout << "Entrada inválida. Por favor, escolha 1 para SIM ou 2 para NAO." << endl;
                return;
            }

                if(valida == "1"){
                    cout << "Digite a nova data de nascimento: " << endl;
                    std::cin.ignore();
                    getline(std::cin, aux_dt_nascimento);
                    pacientes[i].setDt_nascimento(aux_dt_nascimento);
                }
                cout << "Dados alterados com sucesso...";
            }
        }
    }

    static void listarPacientes(vector<Paciente> &pacientes) {
    cout << "Listando pacientes..." << endl;

    for (int i = 0; i < pacientes.size(); i++) {
        cout << "Paciente " << i + 1 << endl;
        cout << pacientes[i].getNome() << endl;
        cout << pacientes[i].getCpf() << endl;
        cout << pacientes[i].getDt_nascimento() << endl;
        cout << " - - - - - - - - - - - - -" << endl;
    }
}

    static void buscarApartirPacientes(vector<Paciente>&pacientes){
        string aux_cpf;
        bool aux_flag = false;

        cout << "Insira o cpf para buscar a pessoa" << endl;
        std::cin.ignore();
        getline(std::cin, aux_cpf);

        for(int i = 0;i < pacientes.size(); i++){
            if(pacientes[i].getCpf() == aux_cpf){
                cout << "Os dados do Paciente " << endl;
                cout << "Paciente: " << pacientes[i].getNome()<< endl;
                cout << "Cpf: " << pacientes[i].getCpf() << endl;
                cout << "Data Nascimento: " << pacientes[i].getDt_nascimento() << endl;
                aux_flag = true;
            }
        }if(aux_flag == false){
        cout << "cpf nao corresponde!" << endl;
        }
    }
};

class Medico {
    string crm, nome, especialidade;

public:
    Medico(string _crm, string _nome, string _especialidade) : crm(_crm), nome(_nome), especialidade(_especialidade) {}

    void setNome(string _nome){
        nome = _nome;
    }
    void setCrm(string _crm){
        crm = _crm;
    }
    void setEspecialidade(string _especialidade){
        especialidade = _especialidade;
    }
    string getCrm(){
        return crm;
    }
    string getNome(){
        return nome;
    }
    string getEspecialidade(){
        return especialidade;
    }

    static void incluirMedico(vector<Medico>&medicos){
        string aux_nome, aux_especialidade, aux_crm;
        cout << "Digite o nome do Medico" << endl;
                std::cin.ignore();
                getline(std::cin, aux_nome);

                cout << "Digite a especialidade: " << endl;
                getline(std::cin, aux_especialidade);

                cout << "Digite o CRM do profissional: " << endl;
                getline(std::cin, aux_crm);

                Medico novoMedico(aux_crm, aux_nome, aux_especialidade);
                medicos.push_back(novoMedico);
    }

    static void excluirMedico(vector<Medico>&medicos){
        string aux_crm;

        cout << "Digite o CRM do medico que deseja excluir" << endl;
                std::cin.ignore();
                getline(std::cin, aux_crm);

                for(int i = 0; i < medicos.size(); i++){
                    if(aux_crm == medicos[i].getCrm()){
                        cout << "Excluindo Medico: " << medicos[i].getNome() << endl;
                        medicos.erase(medicos.begin() + i);
                    }
                }
    }

    static void editarDadosMedico(vector<Medico>&medicos){
                string aux_crm, aux_especialidade, aux_nome;
                string valida;

                cout << "Informe O CRM do médico que deseja alterar os dados." << endl;
                std::cin.ignore();
                getline(std::cin, aux_crm);

                for(int i = 0; i < medicos.size(); i++){
                    if(aux_crm == medicos[i].getCrm()){
                        cout << "Nome: " << medicos[i].getNome()<< endl;
                        cout << "CRM: " << medicos[i].getCrm() << endl;
                        cout << "Especialidade: " << medicos[i].getEspecialidade() << endl;

                        cout << "Deseja alterar o nome do Medico?  (1-SIM / 2-NAO)";
                        if (!(std::cin >> valida) || (valida != "1" && valida != "2")) {
                        std::cout << "Entrada inválida. Por favor, escolha 1 para SIM ou 2 para NAO." << std::endl;
                        break;
                        }
                        if(valida == "1"){
                            cout << "Digite o novo nome do medico: " << endl;
                            std::cin.ignore();
                            getline(std::cin, aux_nome);
                            medicos[i].setNome(aux_nome);
                        }

                        cout << "Deseja alterar a especialidade do Medico? (1-SIM/2-NAO)";
                        if (!(std::cin >> valida) || (valida != "1" && valida != "2")) {
                        std::cout << "Entrada inválida. Por favor, escolha 1 para SIM ou 2 para NAO." << std::endl;
                        break;
                        }
                        if(valida == "1"){
                            cout << "Digite a nova especialidade do medico: " << endl;
                            std::cin.ignore();
                            getline(std::cin, aux_especialidade);
                            medicos[i].setEspecialidade(aux_especialidade);
                        }
                        cout << "Dados alterados com sucesso..." << endl;
                    }
                }
    }

    static void listarMedicos(vector<Medico>&medicos){
        cout << "Lista dos medicos: " << endl;

                for(int i = 0; i < medicos.size(); i++){
                    cout << "Medico: " << medicos[i].getNome() << endl;
                    cout << "Especialidade: " << medicos[i].getEspecialidade() << endl;
                    cout << "CRM: " << medicos[i].getCrm() << endl;
                    cout << " " << endl;
                }
    }

    static void buscarApartirMedicos(vector<Medico>&medicos){
        string aux_crm;
        bool aux_flag = false;

        cout << "Informe o CRM do medico oara realizar a busca." << endl;
        std::cin.ignore();
        getline(std::cin, aux_crm);

        for(int i = 0;i < medicos.size(); i++){
            if(medicos[i].getCrm() == aux_crm){
                cout << "Medico: " << medicos[i].getNome() << endl;
                    cout << "Especialidade: " << medicos[i].getEspecialidade() << endl;
                    cout << "CRM: " << medicos[i].getCrm() << endl;
                    cout << " " << endl;
                    aux_flag = true;
            }
        }if(aux_flag == false){
        cout << "O CRM informado nao foi localizado." << endl;
        }
    }
};



int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    int op, opcao;

    do{
    cout << "Seja bem ao Sistema de Gestão" << endl << "Clinica Médica Sem Dodói Ltda." << endl << endl;
    cout << "Escolha uma opção de gerenciamento" << endl << endl;
    cout << "1. Gestão de Pacientes." << endl;
    cout << "2. Gestão de Medicos" << endl;
    cout << "3. Gestão de Consultas. " << endl;
    cout << "0. Sair do Programa. " << endl;
    std::cin >> opcao;

    if(opcao == 1){
        do {
            cout << "---------Menu--------" << endl;
            cout << "1. Incluir paciente" << endl;
            cout << "2. Excluir Paciente" << endl;
            cout << "3. Alterar dados paciente" << endl;
            cout << "4. Listar pacientes" << endl;
            cout << "5. Buscar paciente especifico" << endl;
            cout << "0. Sair" << endl;
            std::cin >> op;

            if (op == 1) {
            Paciente::incluirPaciente(pacientes);
            }
            if (op == 2) {
            Paciente::excluirPaciente(pacientes);
            }
            if (op == 3) {
                Paciente::editarPaciente(pacientes);
            }
            if(op == 4){
                Paciente::listarPacientes(pacientes);
            }
            if(op == 5){
                Paciente::buscarApartirPacientes(pacientes);
            }
        } while (op != 0);
    }
    
    if(opcao == 2){
        do {
            cout << "---------Menu--------" << endl;
            cout << "1. Incluir Medico" << endl;
            cout << "2. Excluir Medico" << endl;
            cout << "3. Alterar dados Medico" << endl;
            cout << "4. Listar Medicos" << endl;
            cout << "5. Buscar medico especifico" << endl;
            cout << "0. Sair" << endl;
            std::cin >> op;

            if(op == 1){
                Medico::incluirMedico(medicos);
            }
            if(op == 2){
                Medico::excluirMedico(medicos);
            }
            if(op == 3){
                Medico::editarDadosMedico(medicos);
            }
            if(op == 4){
                Medico::listarMedicos(medicos);
            }
            if(op == 5){
                Medico::buscarApartirMedicos(medicos);
            }
        } while(op != 0);
    }

    if(opcao == 3){
        do {
            cout << "---------Menu de Consultas--------" << endl;
            cout << "1. Criar Consulta" << endl;
            cout << "2. Listar Consultas" << endl;
            cout << "3. Excluir Consulta" << endl;
            cout << "4. Alterar Consulta" << endl;
            std::cin >> op;

            if (op == 1) {
               
            }
            if(op == 2){
               
            }
            if(op == 3){
              
            }
            if(op == 4){
               
            }
                
        } while (op != 0);
    }
    }while(opcao != 0);
}