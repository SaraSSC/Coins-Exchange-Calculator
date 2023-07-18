#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Função para calcular o troco
void calcularTroco(double valorPago, double valorTotal) {
    double troco = valorPago - valorTotal;
    vector<double> moedas = {2.0, 1.0, 0.5, 0.2, 0.1, 0.05};
    vector<int> quantidadeMoedas(moedas.size(), 0);

    cout << "Troco: " << fixed << setprecision(2) << troco << "€" << endl;

    for (size_t i = 0; i < moedas.size(); i++) {
        while (troco >= moedas[i]) {
            quantidadeMoedas[i]++;
            troco -= moedas[i];
        }
    }

    for (size_t i = 0; i < moedas.size(); i++) {
        if (quantidadeMoedas[i] > 0) {
            cout << "Moeda de " << moedas[i] << "€: " << quantidadeMoedas[i] << endl;
        }
    }
}

int main() {
    double precoCafe = 0.25;
    double precoCappuccino = 0.30;
    double precoChocolate = 0.35;
    double precoCha = 0.20;

    double valorPago = 0.0;
    double valorTotal = 0.0;

    int opcao = 0;


//Uso um switch case para determinar a bebida escolhida 
    
    while (true) {
        cout << "======== Máquina de Bebidas Quentes ========" << endl;
        cout << "Opções: " << endl;
        cout << "1. Café - " << precoCafe << "€" << endl;
        cout << "2. Cappuccino - " << precoCappuccino << "€" << endl;
        cout << "3. Chocolate - " << precoChocolate << "€" << endl;
        cout << "4. Chá - " << precoCha << "€" << endl;
        cout << "0. Sair" << endl;

        cout << "Selecione uma opção: ";
        cin >> opcao;

        if (opcao == 0) {
            break;
        } else if (opcao >= 1 && opcao <= 4) {
            switch (opcao) {
                case 1:
                    valorTotal = precoCafe;
                    break;
                case 2:
                    valorTotal = precoCappuccino;
                    break;
                case 3:
                    valorTotal = precoChocolate;
                    break;
                case 4:
                    valorTotal = precoCha;
                    break;
            }

            cout << "Insira o valor pago: ";
            cin >> valorPago;

            while (valorPago < valorTotal) {
                cout << "Valor insuficiente. Insira um valor igual ou superior a " << valorTotal << "€: " <<endl;
                cin >> valorPago;
            }

            calcularTroco(valorPago, valorTotal);
        } else {
            cout << "Opção inválida. Por favor, selecione uma opção válida." << endl;
        }
        cout << endl;
    }

    cout << "Programa encerrado." << endl;

    return 0;
}
