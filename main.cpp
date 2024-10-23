#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <memory>
#include "src/genpass.hpp" // Inclua o arquivo de cabeçalho do gerador de senha

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Criar a janela principal
    QWidget window;
    window.setWindowTitle("Gerador de Senhas");

    // Criar o layout vertical
    QVBoxLayout *layout = new QVBoxLayout();

    // Caixa de texto com o dizer "Clique no botão abaixo"
    QLabel *label = new QLabel("Clique no botão abaixo:");

    // Botão para gerar a senha
    QPushButton *generateButton = new QPushButton("Gerar Senha");

    // Caixa de texto para mostrar a senha gerada
    QLineEdit *passwordField = new QLineEdit();
    passwordField->setReadOnly(true); // Somente leitura

    // Conectar o botão para gerar a senha
    QObject::connect(generateButton, &QPushButton::clicked, [&]() {
        // Criação do gerador de senha
        std::unique_ptr<GenPass> generator = std::make_unique<GenPass>();
        // Geração da senha
        std::string generatedPassword = generator->gen_pass(32); // Defina o tamanho da senha conforme desejado
        // Exibir a senha no campo de texto
        passwordField->setText(QString::fromStdString(generatedPassword));
    });

    // Adicionar os widgets ao layout
    layout->addWidget(label);
    layout->addWidget(generateButton);
    layout->addWidget(passwordField);
    
    window.resize(400,100);

    // Configurar o layout na janela principal
    window.setLayout(layout);

    // Exibir a janela
    window.show();

    return app.exec();
}

