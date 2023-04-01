#include "jugador.hpp"
#include <iostream>
using namespace std;

void PonerTerrenoEnMatriz(const vector<unsigned char> & terreno, const state &st, vector<vector<unsigned char>> &matriz) {

	int fila = st.fil;
	int col = st.col;

	switch(st.brujula) {
		case norte:
			matriz[fila][col] = terreno[0];
			matriz[fila-1][col-1] = terreno[1];
			matriz[fila-1][col] = terreno[2];
			matriz[fila-1][col+1] = terreno[3];
			matriz[fila-2][col-2] = terreno[4];
			matriz[fila-2][col-1] = terreno[5];
			matriz[fila-2][col] = terreno[6];
			matriz[fila-2][col+1] = terreno[7];
			matriz[fila-2][col+2] = terreno[8];
			matriz[fila-3][col-3] = terreno[9];
			matriz[fila-3][col-2] = terreno[10];
			matriz[fila-3][col-1] = terreno[11];
			matriz[fila-3][col] = terreno[12];
			matriz[fila-3][col+1] = terreno[13];
			matriz[fila-3][col+2] = terreno[14];
			matriz[fila-3][col+3] = terreno[15];
		break;
		case noreste:
			matriz[fila][col] = terreno[0];
			matriz[fila-1][col] = terreno[1];
			matriz[fila-1][col+1] = terreno[2];
			matriz[fila][col+1] = terreno[3];
			matriz[fila-2][col] = terreno[4];
			matriz[fila-2][col+1] = terreno[5];
			matriz[fila-2][col+2] = terreno[6];
			matriz[fila-1][col+2] = terreno[7];
			matriz[fila][col+2] = terreno[8];
			matriz[fila-3][col] = terreno[9];
			matriz[fila-3][col+1] = terreno[10];
			matriz[fila-3][col+2] = terreno[11];
			matriz[fila-3][col+3] = terreno[12];
			matriz[fila-2][col+3] = terreno[13];
			matriz[fila-1][col+3] = terreno[14];
			matriz[fila][col+3] = terreno[15];
		break;
		case este:
			matriz[fila][col] = terreno[0];
			matriz[fila-1][col+1] = terreno[1];
			matriz[fila][col+1] = terreno[2];
			matriz[fila+1][col+1] = terreno[3];
			matriz[fila-2][col+2] = terreno[4];
			matriz[fila-1][col+2] = terreno[5];
			matriz[fila][col+2] = terreno[6];
			matriz[fila+1][col+2] = terreno[7];
			matriz[fila+2][col+2] = terreno[8];
			matriz[fila-3][col+3] = terreno[9];
			matriz[fila-2][col+3] = terreno[10];
			matriz[fila-1][col+3] = terreno[11];
			matriz[fila][col+3] = terreno[12];
			matriz[fila+1][col+3] = terreno[13];
			matriz[fila+2][col+3] = terreno[14];
			matriz[fila+3][col+3] = terreno[15];
		break;
		case sureste:
			matriz[fila][col] = terreno[0];
			matriz[fila][col+1] = terreno[1];
			matriz[fila+1][col+1] = terreno[2];
			matriz[fila+1][col] = terreno[3];
			matriz[fila][col+2] = terreno[4];
			matriz[fila+1][col+2] = terreno[5];
			matriz[fila+2][col+2] = terreno[6];
			matriz[fila+2][col+1] = terreno[7];
			matriz[fila+2][col] = terreno[8];
			matriz[fila][col+3] = terreno[9];
			matriz[fila+1][col+3] = terreno[10];
			matriz[fila+2][col+3] = terreno[11];
			matriz[fila+3][col+3] = terreno[12];
			matriz[fila+3][col+2] = terreno[13];
			matriz[fila+3][col+1] = terreno[14];
			matriz[fila+3][col] = terreno[15];
		break;
		case sur:
			matriz[fila][col] = terreno[0];
			matriz[fila+1][col+1] = terreno[1];
			matriz[fila+1][col] = terreno[2];
			matriz[fila+1][col-1] = terreno[3];
			matriz[fila+2][col+2] = terreno[4];
			matriz[fila+2][col+1] = terreno[5];
			matriz[fila+2][col] = terreno[6];
			matriz[fila+2][col-1] = terreno[7];
			matriz[fila+2][col-2] = terreno[8];
			matriz[fila+3][col+3] = terreno[9];
			matriz[fila+3][col+2] = terreno[10];
			matriz[fila+3][col+1] = terreno[11];
			matriz[fila+3][col] = terreno[12];
			matriz[fila+3][col-1] = terreno[13];
			matriz[fila+3][col-2] = terreno[14];
			matriz[fila+3][col-3] = terreno[15];
		break;
		case suroeste:
			matriz[fila][col] = terreno[0];
			matriz[fila+1][col] = terreno[1];
			matriz[fila+1][col-1] = terreno[2];
			matriz[fila][col-1] = terreno[3];
			matriz[fila+2][col] = terreno[4];
			matriz[fila+2][col-1] = terreno[5];
			matriz[fila+2][col-2] = terreno[6];
			matriz[fila+1][col-2] = terreno[7];
			matriz[fila][col-2] = terreno[8];
			matriz[fila+3][col] = terreno[9];
			matriz[fila+3][col-1] = terreno[10];
			matriz[fila+3][col-2] = terreno[11];
			matriz[fila+3][col-3] = terreno[12];
			matriz[fila+2][col-3] = terreno[13];
			matriz[fila+1][col-3] = terreno[14];
			matriz[fila][col-3] = terreno[15];
		break;
		case oeste:
			matriz[fila][col] = terreno[0];
			matriz[fila+1][col-1] = terreno[1];
			matriz[fila][col-1] = terreno[2];
			matriz[fila-1][col-1] = terreno[3];
			matriz[fila+2][col-2] = terreno[4];
			matriz[fila+1][col-2] = terreno[5];
			matriz[fila][col-2] = terreno[6];
			matriz[fila-1][col-2] = terreno[7];
			matriz[fila-2][col-2] = terreno[8];
			matriz[fila+3][col-3] = terreno[9];
			matriz[fila+2][col-3] = terreno[10];
			matriz[fila+1][col-3] = terreno[11];
			matriz[fila][col-3] = terreno[12];
			matriz[fila-1][col-3] = terreno[13];
			matriz[fila-2][col-3] = terreno[14];
			matriz[fila-3][col-3] = terreno[15];
		break;
		case noroeste:
			matriz[fila][col] = terreno[0];
			matriz[fila][col-1] = terreno[1];
			matriz[fila-1][col-1] = terreno[2];
			matriz[fila-1][col] = terreno[3];
			matriz[fila][col-2] = terreno[4];
			matriz[fila-1][col-2] = terreno[5];
			matriz[fila-2][col-2] = terreno[6];
			matriz[fila-2][col-1] = terreno[7];
			matriz[fila-2][col] = terreno[8];
			matriz[fila][col-3] = terreno[9];
			matriz[fila-1][col-3] = terreno[10];
			matriz[fila-2][col-3] = terreno[11];
			matriz[fila-3][col-3] = terreno[12];
			matriz[fila-3][col-2] = terreno[13];
			matriz[fila-3][col-1] = terreno[14];
			matriz[fila-3][col] = terreno[15];
		break;
	}
}

Action ComportamientoJugador::think(Sensores sensores){

	int a;

	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Noreste" << endl; break;
		case 2: cout << "Este" << endl; break;
		case 3: cout << "Sureste" << endl; break;
		case 4: cout << "Sur " << endl; break;
		case 5: cout << "Suroeste" << endl; break;
		case 6: cout << "Oeste" << endl; break;
		case 7: cout << "Noroeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;

	//Actualizacion

	switch(last_action) {
		case actFORWARD:
			switch(current_state.brujula) {
				case norte:
					current_state.fil--;
				break;
				case noreste:
					current_state.fil--;
					current_state.col++;
				break;
				case este:
					current_state.col++;
				break;
				case sureste:
					current_state.fil++;
					current_state.col++;
				break;
				case sur:
					current_state.fil++;
				break;
				case suroeste:
					current_state.fil++;
					current_state.col--;
				break;
				case oeste:
					current_state.col--;
				break;
				case noroeste:
					current_state.fil--;
					current_state.col--;
				break;
			}
		break;
		case actTURN_SL:
			a = current_state.brujula;
			a = (a+7)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			girar_derecha = (rand()%2 ==0);
		break;
		case actTURN_SR:
			a = current_state.brujula;
			a = (a+1)%8;
			current_state.brujula = static_cast<Orientacion>(a);
			girar_derecha = (rand()%2 ==0);
		break;
		case actTURN_BL:
			a = current_state.brujula;
			a = (a+5)%8;
			current_state.brujula = static_cast<Orientacion>(a);
		break;
		case actTURN_BR:
			a = current_state.brujula;
			a = (a+3)%8;
			current_state.brujula = static_cast<Orientacion>(a);
		break;
	}

		///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	if (!bien_situado) {

		//////////////////////////////////////////////////////
		//////////////////////////////////////////////////////
			switch(last_action) {
				case actFORWARD:
					switch(brujulaDesorientada) {
						case 0:
							filaMatrizDesubicado--;
							cout << "Avanza hacia el norte" << endl;
						break;
						case 1:
							filaMatrizDesubicado--;
							colMatrizDesubicado++;
							cout << "Avanza hacia el noreste" << endl;
						break;
						case 2:
							colMatrizDesubicado++;
							cout << "Avanza hacia el este" << endl;
						break;
						case 3:
							filaMatrizDesubicado++;
							colMatrizDesubicado++;
							cout << "Avanza hacia el sureste" << endl;
						break;
						case 4:
							filaMatrizDesubicado++;
							cout << "Avanza hacia el sur" << endl;
						break;
						case 5:
							filaMatrizDesubicado++;
							colMatrizDesubicado--;
							cout << "Avanza hacia el suroeste" << endl;
						break;
						case 6:
							colMatrizDesubicado--;
							cout << "Avanza hacia el oeste" << endl;
						break;
						case 7:
							filaMatrizDesubicado--;
							colMatrizDesubicado--;
							cout << "Avanza hacia el noroeste" << endl;
						break;
					}
				break;
				case actTURN_SL:
					a = brujulaDesorientada;
					a = (a+7)%8;
					brujulaDesorientada = a;
				break;
				case actTURN_SR:
					a = brujulaDesorientada;
					a = (a+1)%8;
					brujulaDesorientada = a;
				break;
				case actTURN_BL:
					a = brujulaDesorientada;
					a = (a+5)%8;
					brujulaDesorientada = a;
				break;
				case actTURN_BR:
					a = brujulaDesorientada;
					a = (a+3)%8;
					brujulaDesorientada = a;
				break;
			}

		/////////////////////////////////////////////////////
		//////////////////////////////////////////////////////

		switch(brujulaDesorientada) {
			case 0: //Norte
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-1] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+1] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-2] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-1] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+1] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+2] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = sensores.terreno[15];
				cout << "Esta mirando hacia 0" << endl;
			break;
			case 1: //Noreste
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+1] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+2] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+1] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+2] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+3] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+3] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = sensores.terreno[15];
				cout << "Esta mirando hacia 1" << endl;
			break;
			case 2: //Este
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+2] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+2] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+3] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+3] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+3] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+3] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = sensores.terreno[15];
				cout << "Esta mirando hacia 2" << endl;
			break;
			case 3: //sureste
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+2] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+1] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+3] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+3] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+2] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+1] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = sensores.terreno[15];
				cout << "Esta mirando hacia 3" << endl;
			break;
			case 4: //sur
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+1] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-1] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+2] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+1] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-1] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-2] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = sensores.terreno[15];
				cout << "Esta mirando hacia 4" << endl;
			break;
			case 5: //suroeste
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-1] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-2] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-1] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-2] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-3] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-3] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = sensores.terreno[15];
				cout << "Esta mirando hacia 5" << endl;
			break;
			case 6: //oeste
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-2] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-2] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-3] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-3] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-3] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-3] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = sensores.terreno[15];
				cout << "Esta mirando hacia 6" << endl;
			break;
			case 7: //noroeste
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = sensores.terreno[0];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = sensores.terreno[1];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = sensores.terreno[2];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = sensores.terreno[3];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = sensores.terreno[4];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-2] = sensores.terreno[5];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = sensores.terreno[6];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-1] = sensores.terreno[7];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = sensores.terreno[8];
				matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = sensores.terreno[9];
				matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-3] = sensores.terreno[10];
				matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-3] = sensores.terreno[11];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = sensores.terreno[12];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-2] = sensores.terreno[13];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-1] = sensores.terreno[14];
				matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = sensores.terreno[15];
				cout << "Esta mirando hacia 7" << endl;
			break;
		}
	}
	///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////
	accion.erase(accion.begin()); // Borramos la accion que se ha realizado.

	//Decisiones
	
	// A partir de nivel 1, buscar ubicarse en el mapa.
	int punto_ubicacion;
	if (sensores.nivel != 0 && !bien_situado && accion.size() == 0) {
		for (int i = 0; i < sensores.terreno.size(); i++) {
			if (sensores.terreno[i] == 'G') {
				punto_ubicacion = i;
			}
		}

		if (punto_ubicacion != 0) {
			switch (punto_ubicacion) {
				//// Inicio hacia delante.
				case 2:
					accion.push_back(actFORWARD);
				break;
				case 6:
					if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 12:
					// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
					if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P') {
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				//// Inicio a la derecha
				case 3:
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				break;
				case 8:
					if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 15:
					if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[8] != 'M' && sensores.terreno[8] != 'P') {
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 7:
					if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
					}
				break;
				case 13:
					if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 14:
					if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
					}
				break;
				///// Inicio a la izquierda
				case 1:
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				break;
				case 4:
					if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);				
					}
				break;
				case 9:
					if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[4] != 'M' && sensores.terreno[4] != 'P') {
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 5:
					if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
					}
				break;
				case 11:
					if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actFORWARD);
					}
				break;
				case 10:
					if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SR);
						accion.push_back(actFORWARD);
						accion.push_back(actTURN_SL);
						accion.push_back(actFORWARD);
					}
				break;
			}

		}
	}


	if ((sensores.terreno[0]=='G' and !bien_situado) || (sensores.nivel == 0 and !bien_situado)){
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;

		if (sensores.nivel > 0) {
			int fila_inicial_traspaso = filaMatrizDesubicado - current_state.fil;
			int col_inicial_traspaso = colMatrizDesubicado - current_state.col;
			int cont_fila = 0, cont_col = 0;
			for (int i = fila_inicial_traspaso; i < fila_inicial_traspaso + mapaResultado.size(); i++){
				for (int j = col_inicial_traspaso; j < col_inicial_traspaso + mapaResultado.size(); j++){
					if (matrizDesubicado[i][j] != '?') {
						mapaResultado[cont_fila][cont_col] = matrizDesubicado[i][j];
					}
					cont_col++;
				}
				cont_col = 0;
				cont_fila++;
			}
			// Borramos la matriz auxiliar por si perdemos la orientación y tenemos que volver a utilizarla
			for (int i = 0; i < mapaResultado.size()*2 + 1; i++){
				for (int j = 0; j < mapaResultado.size()*2 + 1; j++){
					matrizDesubicado[i][j] = '?';
				}
			}
			brujulaDesorientada = 0;
			//DUDA: Si perdemos la orientación por morir reaparecemos mirando al norte?
		}
	}


	// Voy añadiendo 1 a la matriz de paso cada vez q paso por la misma casilla
	// Luego buscaré dar prioridad a las casillas no visitadas.
	if (bien_situado) {
		matrizPaso[current_state.fil][current_state.col] += 1;
		for (unsigned int i = 0; i < sensores.terreno.size(); i++) {
			for (unsigned int j = 0; j < sensores.terreno.size(); j++) {
				cout << matrizPaso[i][j] << " ";
			}
			cout << endl;
		}
	}


	int veces[3];
	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);
		switch(current_state.brujula) {
			case norte:
				try {
					veces[0] = matrizPaso[current_state.fil-1][current_state.col-1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil-1][current_state.col];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil-1][current_state.col+1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case noreste:
				try {
					veces[0] = matrizPaso[current_state.fil-1][current_state.col];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil-1][current_state.col+1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil][current_state.col+1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case este:
				try {
					veces[0] = matrizPaso[current_state.fil-1][current_state.col+1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil][current_state.col+1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil+1][current_state.col+1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case sureste:
				try {
					veces[0] = matrizPaso[current_state.fil][current_state.col+1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil+1][current_state.col+1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil+1][current_state.col];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case sur:
				try {
					veces[0] = matrizPaso[current_state.fil+1][current_state.col+1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil+1][current_state.col];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil+1][current_state.col-1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case suroeste:
				try {
					veces[0] = matrizPaso[current_state.fil+1][current_state.col];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil+1][current_state.col-1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil][current_state.col-1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case oeste:
				try {
					veces[0] = matrizPaso[current_state.fil+1][current_state.col-1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil][current_state.col-1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil-1][current_state.col-1];
				} catch (...) {
					veces[2] = 1000;
				}
			break;
			case noroeste:
				try {
					veces[0] = matrizPaso[current_state.fil][current_state.col-1];
				} catch (...) {
					veces[0] = 1000;
				}
				try {
					veces[1] = matrizPaso[current_state.fil-1][current_state.col-1];
				} catch (...) {
					veces[1] = 1000;
				}
				try {
				veces[2] = matrizPaso[current_state.fil-1][current_state.col];		
				} catch (...) {
					veces[2] = 1000;
				}
			break;
		}
	/*
		switch(current_state.brujula) {
			case norte:
				veces = matrizPaso[current_state.fil-1][current_state.col];
			break;
			case noreste:
				veces = matrizPaso[current_state.fil-1][current_state.col+1];
			break;
			case este:
				veces = matrizPaso[current_state.fil][current_state.col+1];
			break;
			case sureste:
				veces = matrizPaso[current_state.fil+1][current_state.col+1];
			break;
			case sur:
				veces = matrizPaso[current_state.fil+1][current_state.col];
			break;
			case suroeste:
				veces = matrizPaso[current_state.fil+1][current_state.col-1];
			break;
			case oeste:
				veces = matrizPaso[current_state.fil][current_state.col-1];
			break;
			case noroeste:
				veces = matrizPaso[current_state.fil-1][current_state.col-1];
			break;
		}
	*/
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// Comprobación de objetos y batería.

	if (sensores.terreno[0] == 'K') {
		bikini = true;
	}
	if (sensores.terreno[0] == 'D') {
		zapatillas = true;
	}

	int punto_bikini = 0;
	int punto_zapatillas = 0;
	int punto_recarga = 0;
	if ((!bikini || !zapatillas) && accion.size() == 0) {
		for (int i = 1; i < sensores.terreno.size(); i++) {
			if (sensores.terreno[i] == 'K') {
				punto_bikini = i;
			}
			if (sensores.terreno[i] == 'D') {
				punto_zapatillas = i;
			}
		}
	}
	if (sensores.bateria < 3000) {
		for (int i = 1; i < sensores.terreno.size(); i++) {
			if (sensores.terreno[i] == 'X') {
				punto_recarga = i;
			}
		}
	}

	////////////////////////////////////////////////

	if (sensores.bateria < 3000 && punto_recarga != 0 && accion.size() == 0) {
		switch (punto_recarga) {
			//// Inicio hacia delante.
			case 2:
				accion.push_back(actFORWARD);
			break;
			case 6:
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 12:
				// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			//// Inicio a la derecha
			case 3:
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			break;
			case 8:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 15:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[8] != 'M' && sensores.terreno[8] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 7:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
			case 13:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 14:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			///// Inicio a la izquierda
			case 1:
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			break;
			case 4:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);				
				}
			break;
			case 9:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[4] != 'M' && sensores.terreno[4] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 5:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			case 11:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 10:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
		}
	}

	if (!bikini && punto_bikini != 0 && accion.size() == 0) {
		switch (punto_bikini) {
			//// Inicio hacia delante.
			case 2:
				accion.push_back(actFORWARD);
			break;
			case 6:
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 12:
				// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			//// Inicio a la derecha
			case 3:
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			break;
			case 8:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 15:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[8] != 'M' && sensores.terreno[8] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 7:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
			case 13:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 14:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			///// Inicio a la izquierda
			case 1:
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			break;
			case 4:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);				
				}
			break;
			case 9:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[4] != 'M' && sensores.terreno[4] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 5:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			case 11:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 10:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
		}
	}

	if (!zapatillas && punto_zapatillas != 0 && accion.size() == 0) {
		switch (punto_zapatillas) {
			//// Inicio hacia delante.
			case 2:
				accion.push_back(actFORWARD);
			break;
			case 6:
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 12:
				// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
				if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P') {
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			//// Inicio a la derecha
			case 3:
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			break;
			case 8:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 15:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[8] != 'M' && sensores.terreno[8] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 7:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
			case 13:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 14:
				if (sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			///// Inicio a la izquierda
			case 1:
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			break;
			case 4:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);				
				}
			break;
			case 9:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[4] != 'M' && sensores.terreno[4] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 5:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
				}
			break;
			case 11:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actFORWARD);
				}
			break;
			case 10:
				if (sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SR);
					accion.push_back(actFORWARD);
					accion.push_back(actTURN_SL);
					accion.push_back(actFORWARD);
				}
			break;
		}
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	 * Agrupo en cuadrantes de 5*5, ya que son mcm de 30,50, 75 y 100, y en cada agrupación - cuadrante, almaceno el número de  casillas desconocidas '?'
	 * en una matriz auxiliar, con ello, más tarde redirigiré eventualmente al robot de forma que se oriente a zonas con muchas casillas menos sin visitar.
	 */
	int num_desconocidas[num_cuadrantes*num_cuadrantes] = {0};
	int fila = 0;
	for (int n = 0; n < num_cuadrantes*num_cuadrantes; n++) {
		if ((n)%num_cuadrantes == 0 && n > 0 && n+5 < num_cuadrantes*num_cuadrantes) {fila+=5;}
		for (int i = fila; i < fila + 5; i++) {
			for (int j = (n%num_cuadrantes)*5; j < ((n%num_cuadrantes)*5) + 5; j++) {
				//cout << "n: " << n << " i: " << i << " j: " << j << endl;
				if (mapaResultado[i][j] == '?') {
					num_desconocidas[n]++;
				}
			}
		}
	}

	int cont = 0;
	for (int i = 0; i < num_cuadrantes; i++) {
		for (int j = 0; j < num_cuadrantes; j++) {
			matrizCuadrantesNoVisitados[i][j] = num_desconocidas[cont];
			cont++;
		}
	}

	// Con esto podemos ir viendo como se actualiza la matriz de casillas visitadas.
	cout << "\nEl número de interrogaciones en la matriz completa es de: " << endl;
	for (int i = 0; i < num_cuadrantes; i++) {
		for (int j = 0; j < num_cuadrantes; j++) {
			cout << matrizCuadrantesNoVisitados[i][j] << " ";
		}
		cout << endl;
	}
	

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (accion.size() == 0) {

		//bool condicion1 = veces < 3;
		bool casilla_libre = sensores.superficie[2] == '_';
		bool casilla_libreA = sensores.superficie[1] == '_';
		bool casilla_libreB = sensores.superficie[3] == '_';
		bool condicion1 = (sensores.terreno[2] == 'T' || sensores.terreno[2] == 'S' || sensores.terreno[2] == 'G' || (sensores.terreno[2] == 'A' && bikini) || (sensores.terreno[2] == 'B' && zapatillas)) && casilla_libre;
		bool condicion1a = (sensores.terreno[1] == 'T' || sensores.terreno[1] == 'S' || sensores.terreno[1] == 'G' || (sensores.terreno[1] == 'A' && bikini) || (sensores.terreno[1] == 'B' && zapatillas)) && casilla_libreA;
		bool condicion1b = (sensores.terreno[3] == 'T' || sensores.terreno[3] == 'S' || sensores.terreno[3] == 'G' || (sensores.terreno[3] == 'A' && bikini) || (sensores.terreno[3] == 'B' && zapatillas)) && casilla_libreB;
		bool condicion2 = (sensores.terreno[2] == 'K' || sensores.terreno[2] == 'X' || sensores.terreno[2] == 'D') && casilla_libre;
		bool salir_entre_muros_dcha = sensores.terreno[3] == 'M' && (sensores.terreno[7] == 'T' ||  sensores.terreno[7] == 'S' || (sensores.terreno[7] == 'A' && bikini) || (sensores.terreno[7] == 'B' && zapatillas));
		bool salir_entre_muros_izda = sensores.terreno[1] == 'M' && (sensores.terreno[5] == 'T' ||  sensores.terreno[5] == 'S' || (sensores.terreno[5] == 'A' && bikini) || (sensores.terreno[5] == 'B' && zapatillas));

		if (sensores.terreno[0] == 'X' && sensores.bateria < 4900) {
			if (sensores.vida < sensores.bateria) {
				if (condicion1 || condicion2) {
					accion.push_back(actFORWARD);
				} else {
					if(!girar_derecha) {
						accion.push_back(actTURN_SL);
						girar_derecha = (rand()%2 == 0);
					}  else {
						accion.push_back(actTURN_SR);
						girar_derecha = (rand()%2 == 0);
						giros_acumulados++;
					}
				}
			} else {
				accion.push_back(actIDLE);
			}
		} else if (salir_entre_muros_izda && sensores.terreno[2] != 'M' && casilla_libre && veces[1] < 3) {
			accion.push_back(actFORWARD);
			accion.push_back(actTURN_SL);
			accion.push_back(actFORWARD);
			if(mapaResultado.size() >= 75){accion.push_back(actTURN_SL);}
		} else if (salir_entre_muros_dcha && sensores.terreno[2] != 'M' && casilla_libre && veces[1] < 3) {
			accion.push_back(actFORWARD);
			accion.push_back(actTURN_SR);
			accion.push_back(actFORWARD);
			if(mapaResultado.size() >= 75) {accion.push_back(actTURN_SR);}
		} else if (((sensores.terreno[5] == 'M' && sensores.terreno[7] == 'M' && sensores.terreno[6] != 'M' && sensores.terreno[2] != 'M') ||
					(sensores.terreno[5] == 'P' && sensores.terreno[7] == 'P' && sensores.terreno[6] != 'P' && sensores.terreno[2] != 'P')) && casilla_libre) { // Salir entre muros
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (((sensores.terreno[11] == 'M' && sensores.terreno[13] == 'M' && sensores.terreno[12] != 'M' && sensores.terreno[2] != 'M' && sensores.terreno[6] != 'M') ||
					(sensores.terreno[11] == 'P' && sensores.terreno[13] == 'P' && sensores.terreno[12] != 'P' && sensores.terreno[2] != 'P' && sensores.terreno[6] != 'P')) && casilla_libre) {
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (condicion2) {
			accion.push_back(actFORWARD);
		}  else if (condicion1 && veces[1] < 1) { // Ver que valor le doy a veces[1]
			accion.push_back(actFORWARD);
		} else if (condicion1 || condicion1a || condicion1b) {
			int casilla_optima = 1;
			int valor = 3;
			for (int i = 0; i < 3; i++) {
				if (valor > veces[i]) {
					casilla_optima = i;
				}
			}
			if (casilla_optima == 0 && condicion1a) {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			} else if (casilla_optima == 1 && condicion1) {
				accion.push_back(actFORWARD);
			} else if (casilla_optima == 2 && condicion1b) {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			} else if (condicion1 && veces[1] < 3) {
				accion.push_back(actFORWARD);
			} else if(!girar_derecha) {
				accion.push_back(actTURN_SL);
				girar_derecha = (rand()%2 == 0);
			}  else {
				accion.push_back(actTURN_SR);
				girar_derecha = (rand()%2 == 0);
				giros_acumulados++;
			}
		} else if(!girar_derecha) {
			accion.push_back(actTURN_SL);
			girar_derecha = (rand()%2 == 0);
		}  else {
			accion.push_back(actTURN_SR);
			girar_derecha = (rand()%2 == 0);
			giros_acumulados++;
		}
	}

	if (giros_acumulados > 5) { // Es posible que sea necesario que sea más restrictivo.
		if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
			accion.clear();
			accion.push_back(actFORWARD);
			giros_acumulados = 0;
		}
 	}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

	// AÑADIR CONTROL DE CHOQUES O CAIDAS PARA PERDER OBJETOS
	/*if (sensores.colision) {
		if (sensores.superficie[0] == 'a') {
			accion.push_back(actIDLE);
		}
		/*if (sensores.reset) {
			bikini = false;
			zapatillas = false;
			current_state.fil = sensores.posF;
			current_state.col= sensores.posC;
			current_state.brujula = sensores.sentido;
		}*/
	/*}
	if (sensores.superficie[0] == 'l') {
		accion.clear();
		accion.push_back(actIDLE);
		bikini = false;
		zapatillas = false;
		bien_situado = false;
	}  // ME CAGO EN SU PUTA MADRE.

*/

	// Devolver posicion - Determinar el efecto de la ultima accion enviada
	last_action = accion[0];
	return last_action;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
