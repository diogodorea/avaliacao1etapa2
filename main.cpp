#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
    string cpf;
    string nome;
    string dt_nascimento;

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

    static void editarPaciente(vector<Paciente> &pacientes){
         
         string aux_cpf,aux_nome,aux_dt_nascimento;
         int op2;

            cout << "Informe o paciente que deseja alterar pelo CPF: " << endl;
            cin.ignore();
            getline(cin, aux_cpf);

            for (int i = 0; i < pacientes.size(); i++) {
                if (aux_cpf == pacientes[i].getCpf()) {
                    cout << "Nome: " << pacientes[i].getNome()<< endl;
                    cout << "CPF: " << pacientes[i].getCpf() << endl;
                    cout << "Data Nascimento: " << pacientes[i].getDt_nascimento() << endl;

                    cout << "Deseja alterar o nome? (1-Sim/2-Nao)" << endl;
                    cin >> op2;
                
                    if(op2 == 1){
                        cout << "Digite o novo nome: " << endl;
                        cin.ignore();
                        getline(cin, aux_nome);
                        pacientes[i].setNome(aux_nome);
                    }

                    cout << "Deseja alterar a data de nascimento? (1-Sim/2-Nao)" << endl;
                    cin >> op2;

                    if(op2 == 1){
                        cout << "Digite a nova data de nascimento: " << endl;
                        cin.ignore();
                        getline(cin, aux_dt_nascimento);
                        pacientes[i].setDt_nascimento(aux_dt_nascimento);
                    }

                    cout << "Dados alterados com sucesso...";
                }
            }
    }


    static void excluirPaciente(vector<Paciente> &pacientes){
         
         string aux_cpf;
         bool pacienteEncontrado = false;

            cout << "Informe o CPF do paciente que deseja Excluir..." << endl;
            cin.ignore();
            getline(cin, aux_cpf);

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

    static void incluirPaciente(vector<Paciente>&pacientes){
         string aux_nome, aux_cpf, aux_dt_nascimento;
         cout << "Informe o nome: " << endl;
            cin.ignore();
            getline(cin, aux_nome);

            cout << "Informe o cpf: " << endl;
            getline(cin, aux_cpf);

            cout << "Informe a data de Nascimento: " << endl;
            getline(cin, aux_dt_nascimento);

            Paciente novoPaciente(aux_nome, aux_cpf, aux_dt_nascimento);
            pacientes.push_back(novoPaciente);
    }

    static void buscarApartirPacientes(vector<Paciente>&pacientes){
        string aux_cpf;
        bool aux_flag = false;

        cout << "Insira o cpf para buscar a pessoa" << endl;
        cin.ignore();
        getline(cin, aux_cpf);

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
    string crm;
    string nome;
    string especialidade;
public:

    Medico(string _crm, string _nome, string _especialidade) : crm(_crm), nome(_nome), especialidade(_especialidade) {}

    void setNome(string _nome){
        nome = _nome;
    };

    string getNome(){
        return nome;
    }

    void setCrm(string _crm){
        crm = _crm;
    }

    string getCrm(){
        return crm;
    }

    void setEspecialidade(string _especialidade){
        especialidade = _especialidade;
    }

    string getEspecialidade(){
        return especialidade;
    }

    static void excluirMedico(vector<Medico>&medicos){
            string aux_crm;

         cout << "Digite o crm do medico que deseja ecluir" << endl;
                cin.ignore();
                getline(cin, aux_crm);

                for(int i = 0; i < medicos.size(); i++){
                    if(aux_crm == medicos[i].getCrm()){
                        cout << "Excluindo Medico: " << medicos[i].getNome() << endl;
                        medicos.erase(medicos.begin() + i);
                    }
                }
    }

    static void editarDadosMedico(vector<Medico>&medicos){
                string aux_crm, aux_especialidade, aux_nome;
        
                int valida;
                cout << "Selecione o medico que deseja alterar a partir do CRM";
                cin.ignore();
                getline(cin, aux_crm);

                for(int i = 0; i < medicos.size(); i++){
                    if(aux_crm == medicos[i].getCrm()){
                        cout << medicos[i].getNome()<< endl;
                        cout << medicos[i].getCrm() << endl;
                        cout << medicos[i].getEspecialidade() << endl;

                        cout << "Deseja alterar o nome do Medico?  (1-SIM/2-NAO)" << endl;
                        cin >> valida;
                        if(valida == 1){
                            cout << "Digite o novo nome do medico: " << endl;
                            cin.ignore();
                            getline(cin, aux_nome);
                            medicos[i].setNome(aux_nome);
                        }

                        cout << "Deseja alterar a especialidade do Medico? (1-SIM/2-NAO)" << endl;
                        cin >> valida;
                        if(valida == 1){
                            cout << "Digite a nova especialidade do medico: " << endl;
                            cin.ignore();
                            getline(cin, aux_especialidade);
                            medicos[i].setEspecialidade(aux_especialidade);
                        }
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

    static void adcionarMedicos(vector<Medico>&medicos){
        string aux_nome, aux_especialidade, aux_crm;
        cout << "Digite o nome do Medico" << endl;
                cin.ignore();
                getline(cin, aux_nome);

                cout << "Digite a especialidade: " << endl;
                getline(cin, aux_especialidade);

                cout << "Digite o CRM do profissional: " << endl;
                getline(cin, aux_crm);

                Medico novoMedico(aux_crm, aux_nome, aux_especialidade);
                medicos.push_back(novoMedico);
    }

    static void buscarApartirMedicos(vector<Medico>&medicos){
        string aux_crm;
        bool aux_flag = false;

        cout << "Insira o crm para buscar a pessoa" << endl;
        cin.ignore();
        getline(cin, aux_crm);

        for(int i = 0;i < medicos.size(); i++){
            if(medicos[i].getCrm() == aux_crm){
                cout << "Medico: " << medicos[i].getNome() << endl;
                    cout << "Especialidade: " << medicos[i].getEspecialidade() << endl;
                    cout << "CRM: " << medicos[i].getCrm() << endl;
                    cout << " " << endl;
                    aux_flag = true;
            }
        }if(aux_flag == false){
        cout << "cpf nao corresponde!" << endl;
        }
    }

};

class Consulta{

    Paciente* paciente;
    Medico* medico;

    char valida = 'n';
    string data, hora, duracao, convenio;

public:

    char getValida() {
        return valida;
    }

    void setValida(char _valida) {
        valida = _valida;
    }

    string getConvenio() {
        return convenio;
    }

    void setConvenio(char _convenio) {
        convenio = _convenio;
    }

    string getData() {
        return data;
    }

    void setData(string _data) {
        data = _data;
    }

    string getHora() {
        return hora;
    }

    void setHora(string _hora) {
        hora = _hora;
    }

    string getDuracao() {
        return duracao;
    }

    void setDuracao(string _duracao) {
        duracao = _duracao;
    }

    void setConvenio(string _convenio) {
        convenio = _convenio;
    }

    Consulta(Paciente* _paciente, Medico* _medico, string _data, string _hora, string _duracao, char _valida, string _convenio) : paciente(_paciente), medico(_medico), data(_data), hora(_hora), duracao(_duracao), valida(_valida), convenio(_convenio) {}

    static Consulta criarConsulta(Paciente* paciente, Medico* medico, string data, string hora, string duracao, char valida, string convenio) {
        return Consulta(paciente, medico, data, hora, duracao, valida, convenio);
    }

    static void incluirConsulta(vector<Paciente>&pacientes, vector<Medico>&medicos, vector<Consulta>&consultas){
        
        string aux_cpf, aux_crm, aux_dataConsulta, aux_horaConsulta, aux_duracaoConsulta, aux_convenio = "Dindin Para Viver";
        char  aux_realizada = 'n';

        cout << "Informe o CPF do paciente: ";
        cin.ignore();
        getline(cin, aux_cpf);

        cout << "Informe o CRM do medico: ";
        getline(cin, aux_crm);

       
        Paciente* paciente = nullptr;
        Medico* medico = nullptr;

        for (Paciente &p : pacientes) {
            if (p.getCpf() == aux_cpf) {
                paciente = &p;
                break;
            }
        }
        for (Medico &m : medicos) {
            if (m.getCrm() == aux_crm) {
                medico = &m;
                break;
            }
        }
        if (paciente && medico) {
            
            cout << "Informe a data da consulta: ";
            getline(cin, aux_dataConsulta);

            cout << "Informe a hora da consulta: ";
            getline(cin, aux_horaConsulta);

            cout << "Informe a duracao da consulta que deseja: ";
            getline(cin, aux_duracaoConsulta);

            Consulta novaConsulta(paciente, medico, aux_dataConsulta, aux_horaConsulta, aux_duracaoConsulta, aux_realizada, aux_convenio);
            consultas.push_back(novaConsulta);
            cout << "Consulta criada com sucesso!" << endl;
        } else {
            cout << "Paciente ou medico não encontrado. Verifique o CPF e o CRM." << endl;
        }
    }

    static void imprimirInformacoesConsulta(vector<Consulta> &consultas) {

        if (consultas.empty()) {
            cout << "Nenhuma consulta registrada." << endl;
        } else {
            cout << "Informações das consultas:" << endl;
            for (int i = 0; i < consultas.size(); i++) {
                cout << "Paciente: " << consultas[i].paciente->getNome() << endl;
                cout << "CPF do Paciente: " << consultas[i].paciente->getCpf() << endl;
                cout << "Data de Nascimento do Paciente: " << consultas[i].paciente->getDt_nascimento() << endl;
                cout << "Medico: " << consultas[i].medico->getNome() << endl;
                cout << "CRM do Medico: " << consultas[i].medico->getCrm() << endl;
                cout << "Especialidade do Medico: " << consultas[i].medico->getEspecialidade() << endl;
                cout << "data da consulta: " << consultas[i].getData() << endl;
                cout << "Horario da consulta: " << consultas[i].getHora() << endl;
                cout << "duracao da consulta: " << consultas[i].getDuracao() << endl;
                cout << "Convenio: " << consultas[i].getConvenio() << endl;
                cout << "Consulta realizada?" << consultas[i].getValida() << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    static void excluirConsulta(vector<Consulta>&consultas){

            string aux_cpf, aux_crm;

                cout << "Informe o CRM do medico que deseja excluir.";
                cin.ignore();
                getline(cin, aux_crm);

                for(int i =0; i < consultas.size(); i++){
                        if(consultas[i].medico->getCrm() == aux_crm)
          
                        cout << consultas[i].paciente->getNome() << endl;
                        cout << consultas[i].paciente->getCpf() << endl;
                    }

                cout << "Digite o CPF do paciente que deseja excluir" << endl;
                getline(cin, aux_cpf);

            for(int i=0; i < consultas.size(); i++){
                if(consultas[i].medico->getCrm() == aux_crm && consultas[i].paciente->getCpf() == aux_cpf){


                    cout << "Consulta do paciente: " << consultas[i].paciente->getNome() << " Apagada!" << endl;
                    consultas.erase(consultas.begin() + i);
                }
            }

    }

    static void alterarConsulta(vector<Consulta>&consultas){

        string aux_crm, aux_cpf, aux_data, aux_hora, aux_duracao, aux_convenio;
        string aux_realizada;

        cout << "Digite o CRM do medico para listar as consultas";
        cin.ignore();
        getline(cin, aux_crm);

        for(int j =0; j < consultas.size(); j++){
            if(consultas[j].medico->getCrm() == aux_crm){
                cout << "Nome: "<< consultas[j].paciente->getNome() << endl;
                cout << "CPF: "<< consultas[j].paciente->getCpf() << endl;
                cout << " - - - -" << endl;
            }
        }           

        cout << "Digite o CPF do paciente que deseja alterar: " << endl;
        getline(cin, aux_cpf);

        for(int i=0; i < consultas.size(); i++){
            if(consultas[i].paciente->getCpf() == aux_cpf){
                cout << "Consulta ja realizada? Digite (s/n)" << endl;
                getline(cin, aux_realizada);

                if(aux_realizada == "s"){
                    consultas[i].setValida('s');
                    break;
                    }else{
                        cout << "Deseja alterar a Data? (s/n)";
                        getline(cin, aux_realizada);
                        if(aux_realizada == "s"){
                            cout << "Digite a nova data ";
                            getline(cin, aux_data); 
                            consultas[i].setData(aux_data);
                        }
                        cout << "Deseja alterar a Hora? (s/n)";
                        getline(cin, aux_realizada);
                        if(aux_realizada == "s"){
                            cout << "Digite a nova hora";
                            getline(cin, aux_hora); 
                            consultas[i].setHora(aux_hora);
                        }
                        cout << "Deseja alterar a duracao da consulta? (s/n)";
                        getline(cin, aux_realizada);
                        if(aux_realizada == "s"){
                            cout << "Digite a nova duracao";
                            getline(cin, aux_duracao); 
                            consultas[i].setDuracao(aux_duracao);
                        }
                        cout << "Deseja alterar o convenio? (s/n)";
                        getline(cin, aux_convenio);
                        if(aux_convenio == "s"){
                            cout << "Digite o convenio: " << endl;
                            getline(cin, aux_convenio);
                            consultas[i].setConvenio(aux_convenio);
                        }
                        }
            }
        }
    }


};

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Consulta> consultas;
    int op, opcao;

    do{
    cout << "Seja bem ao Sistema de Gestao" << endl << "Clinica Medica Sem Dodoi Ltda." << endl << endl;
    cout << "Escolha uma opção de gerenciamento" << endl << endl;
    cout << "1. Gestao de Pacientes." << endl;
    cout << "2. Gestao de Medicos" << endl;
    cout << "3. Gestao de Consultas. " << endl;
    cout << "0. Sair do Programa. " << endl;
    cin >> opcao;

    if(opcao == 1){
        do {
            cout << "---------Menu--------" << endl;
            cout << "1. Incluir paciente" << endl;
            cout << "2. Excluir Paciente" << endl;
            cout << "3. Alterar dados paciente" << endl;
            cout << "4. Listar pacientes" << endl;
            cout << "5. Buscar paciente especifico" << endl;
            cout << "0. Sair" << endl;
            cin >> op;

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
            cin >> op;

            if(op == 1){
                Medico::adcionarMedicos(medicos);
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
            cin >> op;

            if (op == 1) {
               Consulta::incluirConsulta(pacientes, medicos, consultas);
            }
            if(op == 2){
               Consulta::imprimirInformacoesConsulta(consultas);
            }
            if(op == 3){
              Consulta::excluirConsulta(consultas);
            }
            if(op == 4){
               Consulta::alterarConsulta(consultas);
            }
        } while (op != 0);
    }
    }while(opcao != 0);
}