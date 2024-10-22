#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <memory>
#include "src/genpass.hpp"

int main(){
    QApplication app(argc, argv);

    // Criar widget principal
    QWidget window;
    window.setWindowTitle("Gerador de Senhas");

    auto g = std::make_unique<GenPass>();
    std::cout << g->gen_pass(32) << '\n';

    return 0;
}
