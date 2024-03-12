#include <string>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <locale.h>

const int linha = 40;
const int coluna = 60;
const int altura = 10;
const char* foguete = "\
       | \n\
      / \\ \n\
     /   \\ \n\
    |     | \n\
    |     | \n\
    |     | \n\
    |     | \n\
    |  |  | \n\
   .   |   . \n\
  .____|____. \n\
   ***  ***   \n\
";

void imprimiF() {
	std::string mode = "mode con cols=" + std::to_string(coluna) + " lines=" + std::to_string(linha);
	system(mode.c_str());
	system("color 1F"); 
}
void contagem(){
	for (int count = 10; count > 0; count--) {
		system("cls");
		std::printf("%d", count);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
void decolagem() {
	for (int i = linha; i > altura; i--) {
		system("cls");
		for (int j = i - altura; j > 0; j--)
			std::printf("\n");
		std::printf(foguete);
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	imprimiF();
	system("pause");
	system("cls");
	std::printf("Preparar para Decolagem");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	contagem();
	system("cls");
	std::printf("Saindo da Órbita!");
	std::this_thread::sleep_for(std::chrono::seconds(2));
	decolagem();
	system("cls");
	std::printf("Parabéns Você está no Espaço. \n");
	
	return 0;
}
