#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "teste.h"

using namespace std;


int main(){
	membro tabelinha[16];
	string palavra = "dasdsadwd";
	//busca de letra em letra;
	int newTam = Search_L(tabelinha, palavra);
	//ordena a tabelinha;
	quick_s(tabelinha, newTam);
  imprimirTabela(tabelinha, newTam);	
}
