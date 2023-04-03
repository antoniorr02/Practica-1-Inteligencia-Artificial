#include "jugador.hpp"
#include <iostream>
using namespace std;

/**
 * @brief Actualizamos la posición del agente en el mapaResultado según se va desplazando.
 * 
 * @param a 
 * @param girar_derecha 
 * @param lastAction 
 * @param st 
 */
void ActualizarMapaResultado(int & a, bool & girar_derecha, Action lastAction, state &st) {

	switch(lastAction) {
		case actFORWARD:
			switch(st.brujula) {
				case norte:
					st.fil--;
				break;
				case noreste:
					st.fil--;
					st.col++;
				break;
				case este:
					st.col++;
				break;
				case sureste:
					st.fil++;
					st.col++;
				break;
				case sur:
					st.fil++;
				break;
				case suroeste:
					st.fil++;
					st.col--;
				break;
				case oeste:
					st.col--;
				break;
				case noroeste:
					st.fil--;
					st.col--;
				break;
			}
		break;
		case actTURN_SL:
			a = st.brujula;
			a = (a+7)%8;
			st.brujula = static_cast<Orientacion>(a);
			girar_derecha = (rand()%2 ==0);
		break;
		case actTURN_SR:
			a = st.brujula;
			a = (a+1)%8;
			st.brujula = static_cast<Orientacion>(a);
			girar_derecha = (rand()%2 ==0);
		break;
		case actTURN_BL:
			a = st.brujula;
			a = (a+5)%8;
			st.brujula = static_cast<Orientacion>(a);
		break;
		case actTURN_BR:
			a = st.brujula;
			a = (a+3)%8;
			st.brujula = static_cast<Orientacion>(a);
		break;
	}

}

/**
 * @brief Pintamos en el mapaResultado lo que vamos viendo.
 * 
 * @param terreno 
 * @param st 
 * @param matriz 
 */
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

/**
 * @brief Actualizamos la posición y orientación del agente en la matrizDesconocido conforme se va moviendo en el mapaResultado
 * para poder pintar en las casillas correctas de la misma.
 * 
 * @param last_action 
 * @param filaMatrizDesubicado 
 * @param colMatrizDesubicado 
 * @param brujulaDesorientada 
 * @param b 
 */
void ActualizarMatrizDesconocido(Action last_action, int & filaMatrizDesubicado, int & colMatrizDesubicado, int & brujulaDesorientada, int & b) {

	switch(last_action) {
		case actFORWARD:
			switch(brujulaDesorientada) {
				case 0:
					filaMatrizDesubicado--;
					//cout << "Avanza hacia el norte" << endl;
				break;
				case 1:
					filaMatrizDesubicado--;
					colMatrizDesubicado++;
					//cout << "Avanza hacia el noreste" << endl;
				break;
				case 2:
					colMatrizDesubicado++;
					//cout << "Avanza hacia el este" << endl;
				break;
				case 3:
					filaMatrizDesubicado++;
					colMatrizDesubicado++;
					//cout << "Avanza hacia el sureste" << endl;
				break;
				case 4:
					filaMatrizDesubicado++;
					//cout << "Avanza hacia el sur" << endl;
				break;
				case 5:
					filaMatrizDesubicado++;
					colMatrizDesubicado--;
					//cout << "Avanza hacia el suroeste" << endl;
				break;
				case 6:
					colMatrizDesubicado--;
					//cout << "Avanza hacia el oeste" << endl;
				break;
				case 7:
					filaMatrizDesubicado--;
					colMatrizDesubicado--;
					//cout << "Avanza hacia el noroeste" << endl;
				break;
			}
		break;
		case actTURN_SL:
			b = brujulaDesorientada;
			b = (b+7)%8;
			brujulaDesorientada = b;
		break;
		case actTURN_SR:
			b = brujulaDesorientada;
			b = (b+1)%8;
			brujulaDesorientada = b;
		break;
		case actTURN_BL:
			b = brujulaDesorientada;
			b = (b+5)%8;
			brujulaDesorientada = b;
		break;
		case actTURN_BR:
			b = brujulaDesorientada;
			b = (b+3)%8;
			brujulaDesorientada = b;
		break;
	}


}

/**
 * @brief Pintamos en la matrizDesconocido lo que vamos viendo.
 * 
 * @param terreno 
 * @param matrizDesubicado 
 * @param filaMatrizDesubicado 
 * @param colMatrizDesubicado 
 * @param brujulaDesorientada 
 */
void PonerTerrenoEnMatrizDesconocido(const vector<unsigned char> & terreno, char ** matrizDesubicado, int & filaMatrizDesubicado, int & colMatrizDesubicado, int & brujulaDesorientada) {

	switch(brujulaDesorientada) {
		case 0: //Norte
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-1] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+1] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-2] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-1] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+1] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+2] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = terreno[15];
			cout << "Esta mirando hacia 0" << endl;
		break;
		case 1: //Noreste
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+1] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+2] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+1] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+2] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+3] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+3] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = terreno[15];
			cout << "Esta mirando hacia 1" << endl;
		break;
		case 2: //Este
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+2] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+2] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado+3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado+3] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado+3] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+3] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+3] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = terreno[15];
			cout << "Esta mirando hacia 2" << endl;
		break;
		case 3: //sureste
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+2] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+1] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado+3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+3] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+3] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+2] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+1] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = terreno[15];
			cout << "Esta mirando hacia 3" << endl;
		break;
		case 4: //sur
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado+1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado+1] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-1] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+2] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado+1] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-1] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-2] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = terreno[15];
			cout << "Esta mirando hacia 4" << endl;
		break;
		case 5: //suroeste
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-1] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-2] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-1] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-2] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-3] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-3] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = terreno[15];
			cout << "Esta mirando hacia 5" << endl;
		break;
		case 6: //oeste
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-2] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-2] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado+3][colMatrizDesubicado-3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado+2][colMatrizDesubicado-3] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado+1][colMatrizDesubicado-3] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-3] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-3] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = terreno[15];
			cout << "Esta mirando hacia 6" << endl;
		break;
		case 7: //noroeste
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado] = terreno[0];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-1] = terreno[1];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-1] = terreno[2];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado] = terreno[3];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-2] = terreno[4];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-2] = terreno[5];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-2] = terreno[6];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-1] = terreno[7];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado] = terreno[8];
			matrizDesubicado[filaMatrizDesubicado][colMatrizDesubicado-3] = terreno[9];
			matrizDesubicado[filaMatrizDesubicado-1][colMatrizDesubicado-3] = terreno[10];
			matrizDesubicado[filaMatrizDesubicado-2][colMatrizDesubicado-3] = terreno[11];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-3] = terreno[12];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-2] = terreno[13];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado-1] = terreno[14];
			matrizDesubicado[filaMatrizDesubicado-3][colMatrizDesubicado] = terreno[15];
			cout << "Esta mirando hacia 7" << endl;
		break;
	}
	
}

/**
 * @brief Comprueba si hay alguna casilla de ubicación dentro de la vista del agente.
 * 
 * @param terreno 
 * @return int 
 */
int BuscarPuntoUbicacion(const vector<unsigned char> & terreno) {
	int punto_ubicacion = 0;
	for (int i = 0; i < terreno.size(); i++) {
		if (terreno[i] == 'G') {
			punto_ubicacion = i;
		}
	}
	return punto_ubicacion;
}

/**
 * @brief Se define el comportamiento del agente para ir hacia el punto que hará que se ubique en el mapaResultado.
 * 
 * @param terreno 
 * @param accion 
 * @param punto_ubicacion 
 */
void IrHaciaPuntoUbicacion(const vector<unsigned char> & terreno, vector<Action> &accion, const int punto_ubicacion) {
	
	switch (punto_ubicacion) {
		//// Inicio hacia delante.
		case 2:
			accion.push_back(actFORWARD);
		break;
		case 6:
			if (terreno[2] != 'M' && terreno[2] != 'P') {
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 12:
			// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
			if (terreno[2] != 'M' && terreno[2] != 'P' && terreno[6] != 'M' && terreno[6] != 'P') {
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
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 15:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[8] != 'M' && terreno[8] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 7:
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			}
		break;
		case 13:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 14:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
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
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);				
			}
		break;
		case 9:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[4] != 'M' && terreno[4] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 5:
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			}
		break;
		case 11:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 10:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
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

/**
 * @brief En el momento que estamos ubicados esta función pasa lo de nuestra matriz auxiliar, matrizDesubicado, que ha guardado el terreno 
 * antes de ubicarse a nuestra matriz mapaResultado.
 * 
 * @param mapaResultado 
 * @param matrizDesubicado 
 * @param fila_inicial_traspaso 
 * @param col_inicial_traspaso 
 */
void TraspasarDesconocidoAMapa(vector<vector<unsigned char>> &mapaResultado, char ** matrizDesubicado, int fila_inicial_traspaso, int col_inicial_traspaso) {
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
}

/**
 * @brief Buscamos las casillas especiales dentro del campo de visión del agente.
 * 
 * @param terreno 
 * @param num_acciones 
 * @param bikini 
 * @param zapatillas 
 * @param bateria 
 * @param punto_bikini 
 * @param punto_zapatillas 
 * @param punto_recarga 
 */
void BuscarCasillasEspeciales(const vector<unsigned char> & terreno, int num_acciones, bool bikini, bool zapatillas, int bateria, int & punto_bikini, int & punto_zapatillas, int & punto_recarga) {
	if ((!bikini || !zapatillas) && num_acciones == 0) {
		for (int i = 1; i < terreno.size(); i++) {
			if (terreno[i] == 'K') {
				punto_bikini = i;
			}
			if (terreno[i] == 'D') {
				punto_zapatillas = i;
			}
		}
	}
	if (bateria < 3000) {
		for (int i = 1; i < terreno.size(); i++) {
			if (terreno[i] == 'X') {
				punto_recarga = i;
			}
		}
	}
}

/**
 * @brief Se define el comportamiento del agente para ir hacia el punto que contiene el bikini.
 * 
 * @param terreno 
 * @param accion 
 * @param punto_bikini 
 */
void IrHaciaPuntoBikini(const vector<unsigned char> & terreno, vector<Action> &accion, const int punto_bikini) {
	switch (punto_bikini) {
		//// Inicio hacia delante.
		case 2:
			accion.push_back(actFORWARD);
		break;
		case 6:
			if (terreno[2] != 'M' && terreno[2] != 'P') {
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 12:
			// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
			if (terreno[2] != 'M' && terreno[2] != 'P' && terreno[6] != 'M' && terreno[6] != 'P') {
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
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 15:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[8] != 'M' && terreno[8] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 7:
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			}
		break;
		case 13:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 14:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
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
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);				
			}
		break;
		case 9:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[4] != 'M' && terreno[4] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 5:
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			}
		break;
		case 11:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 10:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
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

/**
 * @brief Se define el comportamiento del agente para ir hacia el punto que contiene las zapatillas.
 * 
 * @param terreno 
 * @param accion 
 * @param punto_zapatillas 
 */
void IrHaciaPuntoZapatillas(const vector<unsigned char> & terreno, vector<Action> &accion, const int punto_zapatillas) {
	switch (punto_zapatillas) {
		//// Inicio hacia delante.
		case 2:
			accion.push_back(actFORWARD);
		break;
		case 6:
			if (terreno[2] != 'M' && terreno[2] != 'P') {
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 12:
			// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
			if (terreno[2] != 'M' && terreno[2] != 'P' && terreno[6] != 'M' && terreno[6] != 'P') {
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
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 15:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[8] != 'M' && terreno[8] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 7:
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			}
		break;
		case 13:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 14:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
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
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);				
			}
		break;
		case 9:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[4] != 'M' && terreno[4] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 5:
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			}
		break;
		case 11:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 10:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
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

/**
 * @brief Se define el comportamiento del agente para ir hacia el punto de recarga.
 * 
 * @param terreno 
 * @param accion 
 * @param punto_recarga 
 */
void IrHaciaPuntoRecarga(const vector<unsigned char> & terreno, vector<Action> &accion, const int punto_recarga) {
	switch (punto_recarga) {
		//// Inicio hacia delante.
		case 2:
			accion.push_back(actFORWARD);
		break;
		case 6:
			if (terreno[2] != 'M' && terreno[2] != 'P') {
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 12:
			// NOTA: PODRÍA PONER DIFERENTES CAMINOS --> TODAS LAS CASUÍSTICAS.
			if (terreno[2] != 'M' && terreno[2] != 'P' && terreno[6] != 'M' && terreno[6] != 'P') {
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
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 15:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[8] != 'M' && terreno[8] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 7:
			if (terreno[3] != 'M' && terreno[3] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
			}
		break;
		case 13:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 14:
			if (terreno[3] != 'M' && terreno[3] != 'P' && terreno[7] != 'M' && terreno[7] != 'P') {
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
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);				
			}
		break;
		case 9:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[4] != 'M' && terreno[4] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 5:
			if (terreno[1] != 'M' && terreno[1] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
			}
		break;
		case 11:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
				accion.push_back(actTURN_SL);
				accion.push_back(actFORWARD);
				accion.push_back(actTURN_SR);
				accion.push_back(actFORWARD);
				accion.push_back(actFORWARD);
			}
		break;
		case 10:
			if (terreno[1] != 'M' && terreno[1] != 'P' && terreno[5] != 'M' && terreno[5] != 'P') {
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

/**
 * @brief Calcula el número de casillas desconocidas en cada uno de los cuadrantes 5x5.
 * 
 * @param mapaResultado 
 * @param matrizCuadrantesNoVisitados 
 * @param num_cuadrantes 
 */
void NumDesconocidasPorCuadrante(vector<vector<unsigned char>> &mapaResultado, int ** matrizCuadrantesNoVisitados, int num_cuadrantes) {
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
}

/**
 * @brief Determinamos cuál es cuadrante con mayor número de casillas desconocidas y determinamos hacia cuál ir.
 * 
 * @param st 
 * @param matrizCuadrantesNoVisitados 
 * @param num_cuadrantes 
 * @param cuadranteFijado 
 * @return int 
 */
int CuadranteOptimo(state &st, int ** matrizCuadrantesNoVisitados, int num_cuadrantes, bool &cuadranteFijado) {
	// Ahora queremos ver el cuadrante en el que estamos situados en concreto:
	int filaCuadrantes, colCuadrantes;
	if (st.fil < 5) {
		filaCuadrantes = 0;
	} else {
		filaCuadrantes = (st.fil / 5) - 1;
	}
	if (st.col < 5) {
		colCuadrantes = 0;
	} else {
		colCuadrantes = (st.col / 5) - 1;
	}

	// Una vez sabemos en que cuadrante estamos ubicados, comprobaremos si alguno de los contiguos tiene 
	// una proporción de muros contiene una proporción mucho mayor de desconocidos.
	int cuadrante[8] = {0};
	if (filaCuadrantes > 0 && colCuadrantes > 0) {
		cuadrante[0] = matrizCuadrantesNoVisitados[filaCuadrantes-1][colCuadrantes-1];
	} else {
		cuadrante[0] = -1;
	}
	if (filaCuadrantes > 0) {
		cuadrante[1] = matrizCuadrantesNoVisitados[filaCuadrantes-1][colCuadrantes];
	} else {
		cuadrante[1] = -1;
	}
	if (filaCuadrantes > 0 && colCuadrantes < num_cuadrantes) {
		cuadrante[2] = matrizCuadrantesNoVisitados[filaCuadrantes-1][colCuadrantes+1];
	} else {
		cuadrante[2] = -1;
	}
	if (colCuadrantes > 0) {
		cuadrante[3] = matrizCuadrantesNoVisitados[filaCuadrantes][colCuadrantes-1];
	} else {
		cuadrante[3] = -1;
	}
	if (colCuadrantes < num_cuadrantes) {
		cuadrante[4] = matrizCuadrantesNoVisitados[filaCuadrantes][colCuadrantes+1];
	} else {
		cuadrante[4] = -1;
	}
	if (filaCuadrantes < num_cuadrantes && colCuadrantes > 0) {
		cuadrante[5] = matrizCuadrantesNoVisitados[filaCuadrantes+1][colCuadrantes-1];
	} else {
		cuadrante[5] = -1;
	}
	if (filaCuadrantes < num_cuadrantes) {
		cuadrante[6] = matrizCuadrantesNoVisitados[filaCuadrantes+1][colCuadrantes];
	} else {
		cuadrante[6] = -1;
	}
	if (filaCuadrantes < num_cuadrantes && colCuadrantes < num_cuadrantes) {
		cuadrante[7] = matrizCuadrantesNoVisitados[filaCuadrantes+1][colCuadrantes+1];
	} else {
		cuadrante[7] = -1;
	}

	// Ahora que sabemos el número de casillas desconocidas de los cuadrantes contiguos, decidimos cuál nos interesa más 
	// para orientar más tarde el agente hacia el mismo.
	/**
	 * @brief Sabemos que:
	 * [0] --> noroeste
	 * [1] --> norte
	 * [2] --> noreste
	 * [3] --> oeste
	 * [4] --> este
	 * [5] --> suroeste
	 * [6] --> sur
	 * [7] --> sureste
	 */
	int cuadranteElegido = -1;
	int valorCuadranteElegido = 0;
	for (int i = 0; i < 8; i++) {
		if (cuadrante[i] == 25) {
			cuadranteElegido = i;
			break;
		} else {
			if (valorCuadranteElegido < cuadrante[i]) {
				valorCuadranteElegido = cuadrante[i];
				cuadranteElegido = i;
			}
		}
	}
	//cout << "CUADRANTE ELEGIDO: " << cuadranteElegido << endl;
	if (cuadranteElegido != -1) {
		cuadranteFijado = true;
	}

	return cuadranteElegido;
}

/**
 * @brief Según el cuadrante al que queramos ir y nuestra orientación determinaremos las accciones para orientarnos hacia el correcto.
 * 
 * @param st 
 * @param accion 
 * @param cuadranteElegido 
 */
void OrientarHaciaCuadrante(state &st, vector<Action> &accion, int cuadranteElegido) {
	switch (cuadranteElegido) {
		/*case -1:
			// Este caso significaría que los cuadrantes contiguos ya han sido visitados
			// Podría idear una función para ir hacia cuadrantes con una proporción muy diferente en el mapa general (cuadrantes más alejados).
		break;*/
		case 0: // noroeste
			// Según la orientación actual, para orientarse hacia algun cuadrante en concreto, deberá de 
			// hacer unos giros diferentes para orientarse, hacia el cuadrante deseado.
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_SL);
				break;
				case noreste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case este:
					accion.push_back(actTURN_BL);
				break;
				case sureste:
					accion.push_back(actTURN_SR);
					accion.push_back(actTURN_BR);
				break;
				case sur:
					accion.push_back(actTURN_BR);
				break;
				case suroeste:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case oeste:
					accion.push_back(actTURN_SR);
				break;
			}
		break;
		case 1: // norte
			switch (st.brujula) {
				case noreste:
					accion.push_back(actTURN_SL);
				break;
				case este:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case sureste:
					accion.push_back(actTURN_BL);
				break;
				case sur:
					accion.push_back(actTURN_SR);
					accion.push_back(actTURN_BR);
				break;
				case suroeste:
					accion.push_back(actTURN_BR);
				break;
				case oeste:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case noroeste:
					accion.push_back(actTURN_SR);
				break;
			}
		break;
		case 2: // noreste
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_SR);
				break;
				case este:
					accion.push_back(actTURN_SL);
				break;
				case sureste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case sur:
					accion.push_back(actTURN_BL);
				break;
				case suroeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
				case oeste:
					accion.push_back(actTURN_BR);
				break;
				case noroeste:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
			}
		break;
		case 3: // oeste
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case noreste:
					accion.push_back(actTURN_BL);
				break;
				case este:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
				case sureste:
					accion.push_back(actTURN_BR);
				break;
				case sur:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case suroeste:
					accion.push_back(actTURN_SR);
				break;
				case noroeste:
					accion.push_back(actTURN_SL);
				break;
			}
		break;
		case 4: // este
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case noreste:
					accion.push_back(actTURN_SR);
				break;
				case sureste:
					accion.push_back(actTURN_SL);
				break;
				case sur:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case suroeste:
					accion.push_back(actTURN_BL);
				break;
				case oeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
				case noroeste:
					accion.push_back(actTURN_BR);
				break;
			}
		break;
		case 5: // suroeste
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_BL);
				break;
				case noreste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
				case este:
					accion.push_back(actTURN_BR);
				break;
				case sureste:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case sur:
					accion.push_back(actTURN_SR);
				break;
				case oeste:
					accion.push_back(actTURN_SL);
				break;
				case noroeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
			}
		break;
		case 6: // sur
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
				case noreste:
					accion.push_back(actTURN_BR);
				break;
				case este:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case sureste:
					accion.push_back(actTURN_SR);
				break;
				case suroeste:
					accion.push_back(actTURN_SL);
				break;
				case oeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case noroeste:
					accion.push_back(actTURN_BL);
				break;
			}
		break;
		case 7: // sureste
			switch (st.brujula) {
				case norte:
					accion.push_back(actTURN_BR);
				break;
				case noreste:
					accion.push_back(actTURN_BL);
					accion.push_back(actTURN_BL);
				break;
				case este:
					accion.push_back(actTURN_SR);
				break;
				case sur:
					accion.push_back(actTURN_SL);
				break;
				case suroeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_BR);
				break;
				case oeste:
					accion.push_back(actTURN_BL);
				break;
				case noroeste:
					accion.push_back(actTURN_BR);
					accion.push_back(actTURN_SR);
				break;
			}
		break;
	}
}

/**
 * @brief Evaluamos el número de veces que hemos pasado por las casillas 1, 2 y 3, es decir, las contiguas en la vista.
 * 
 * @param st 
 * @param veces 
 * @param matrizPaso 
 */
void VecesPasadasSiguientesCasillas(state &st, int * veces, int ** matrizPaso) {
	switch(st.brujula) {
		case norte:
			try {
				veces[0] = matrizPaso[st.fil-1][st.col-1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil-1][st.col];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil-1][st.col+1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case noreste:
			try {
				veces[0] = matrizPaso[st.fil-1][st.col];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil-1][st.col+1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil][st.col+1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case este:
			try {
				veces[0] = matrizPaso[st.fil-1][st.col+1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil][st.col+1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil+1][st.col+1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case sureste:
			try {
				veces[0] = matrizPaso[st.fil][st.col+1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil+1][st.col+1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil+1][st.col];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case sur:
			try {
				veces[0] = matrizPaso[st.fil+1][st.col+1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil+1][st.col];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil+1][st.col-1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case suroeste:
			try {
				veces[0] = matrizPaso[st.fil+1][st.col];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil+1][st.col-1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil][st.col-1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case oeste:
			try {
				veces[0] = matrizPaso[st.fil+1][st.col-1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil][st.col-1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil-1][st.col-1];
			} catch (...) {
				veces[2] = 1000;
			}
		break;
		case noroeste:
			try {
				veces[0] = matrizPaso[st.fil][st.col-1];
			} catch (...) {
				veces[0] = 1000;
			}
			try {
				veces[1] = matrizPaso[st.fil-1][st.col-1];
			} catch (...) {
				veces[1] = 1000;
			}
			try {
			veces[2] = matrizPaso[st.fil-1][st.col];		
			} catch (...) {
				veces[2] = 1000;
			}
		break;
	}
}

Action ComportamientoJugador::think(Sensores sensores){

	int a, b;

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

	//ACTUALIZACIÓN.

	if (sensores.reset) {
		bikini = false;
		zapatillas = false;
		last_action = actIDLE;
		filaMatrizDesubicado = mapaResultado.size();
		colMatrizDesubicado = mapaResultado.size();
		brujulaDesorientada = 0; // Reaparecemos mirando el norte.
		bien_situado = false;
	}

	if ((sensores.superficie[2] != '_' || sensores.terreno[2] == 'M' || sensores.terreno[2] == 'P' ) && last_action == actFORWARD) { //POSIBILIDAD DE AÑADIR FILTRO PARA MUROS, PREC, Y AGUA-BOSQUE SIN OBJETOS --> IR HASTA CUADRANTE. 
		accion.clear();
		accion.push_back(actIDLE);
	}
	ActualizarMapaResultado(a, girar_derecha ,last_action, current_state);

	/**
	 * @brief En caso de estar en un nivel superior al 0 como comenzamos sin conocer la orientación ni la posición
	 * Iremos guardando en una matriz auxiliar de tamaño size*2 + 1 lo que vayamos viendo, de forma que cuando nos 
	 * ubiquemos pasemos esta información a nuestro mapaResultado.
	 * 
	 */
	if (!bien_situado) {
		ActualizarMatrizDesconocido(last_action, filaMatrizDesubicado, colMatrizDesubicado, brujulaDesorientada, b);
		PonerTerrenoEnMatrizDesconocido(sensores.terreno, matrizDesubicado, filaMatrizDesubicado, colMatrizDesubicado, brujulaDesorientada);
	}

	// Elminamos de nuestro vector de acciones la acción que ya ha llevado a cabo el agente.
	accion.erase(accion.begin());

	//DECISIONES.
	
	// A partir de nivel 1, buscar ubicarse en el mapa.
	if (sensores.nivel != 0 && !bien_situado && accion.size() == 0) {
		int punto_ubicacion = BuscarPuntoUbicacion(sensores.terreno);
		if (punto_ubicacion != 0) {
			IrHaciaPuntoUbicacion(sensores.terreno, accion, punto_ubicacion);
		}
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Nos hemos ubicado en el mapa.
	if ((sensores.terreno[0]=='G' and !bien_situado) || (sensores.nivel == 0 and !bien_situado)){
		/**
		 * @brief En este punto estamos ya ubicados, luego los sensores comienzan a funcionar, con lo que tomamos sus valores.
		 */
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;

		if (sensores.nivel > 0) {
			int fila_inicial_traspaso = filaMatrizDesubicado - current_state.fil;
			int col_inicial_traspaso = colMatrizDesubicado - current_state.col;
			TraspasarDesconocidoAMapa(mapaResultado, matrizDesubicado, fila_inicial_traspaso, col_inicial_traspaso);
		}
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
	BuscarCasillasEspeciales(sensores.terreno, accion.size(), bikini, zapatillas, sensores.bateria, punto_bikini, punto_zapatillas, punto_recarga);

	////////////////////////////////////////////////

	if (sensores.bateria < 3000 && punto_recarga != 0 && accion.size() == 0) {
		IrHaciaPuntoRecarga(sensores.terreno, accion, punto_recarga);
	}

	if (!bikini && punto_bikini != 0 && accion.size() == 0) {
		IrHaciaPuntoBikini(sensores.terreno, accion, punto_bikini);
	}

	if (!zapatillas && punto_zapatillas != 0 && accion.size() == 0) {
		IrHaciaPuntoZapatillas(sensores.terreno, accion, punto_zapatillas);
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int veces[3];
	if (bien_situado){

		PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Cuadrantes 5*5.

		NumDesconocidasPorCuadrante(mapaResultado, matrizCuadrantesNoVisitados, num_cuadrantes);
		if (accion.size() == 0 && num_avances >= 10) {
			num_avances = 0;
			int cuadranteElegido = CuadranteOptimo(current_state, matrizCuadrantesNoVisitados, num_cuadrantes, cuadranteFijado);
			if (cuadranteFijado) {
				OrientarHaciaCuadrante(current_state, accion, cuadranteElegido);
			}
		}
		// Con esto podemos ir viendo como se actualiza la matriz de casillas visitadas.
		/*cout << "\nEl número de interrogaciones en la matriz completa es de: " << endl;
		for (int i = 0; i < num_cuadrantes; i++) {
			for (int j = 0; j < num_cuadrantes; j++) {
				cout << matrizCuadrantesNoVisitados[i][j] << " ";
			}
			cout << endl;
		}*/

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Calcular desconocidas por cuadrante

		// Ver si alguno tiene el doble de no visitadas

		// Ir hacia aquel que tenga el doble de no visitadas que el resto

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		// Voy añadiendo 1 a la matriz de paso cada vez q paso por la misma casilla
		// Luego buscaré dar prioridad a las casillas no visitadas.
		matrizPaso[current_state.fil][current_state.col] += 1;
		// Para ver la matriz de paso:
		/*for (unsigned int i = 0; i < sensores.terreno.size(); i++) {
			for (unsigned int j = 0; j < sensores.terreno.size(); j++) {
				cout << matrizPaso[i][j] << " ";
			}
			cout << endl;
		}*/
		VecesPasadasSiguientesCasillas(current_state, veces, matrizPaso);
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (accion.size() == 0) {
		solventandoAtasco = false;

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
		} else if (salir_entre_muros_izda && sensores.terreno[2] != 'M' && casilla_libre) {
			accion.push_back(actFORWARD);
			accion.push_back(actTURN_SL);
			accion.push_back(actFORWARD);
		} else if (salir_entre_muros_dcha && sensores.terreno[2] != 'M' && casilla_libre) {
			accion.push_back(actFORWARD);
			accion.push_back(actTURN_SR);
			accion.push_back(actFORWARD);
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
		}  else if (condicion1 && veces[1] < 1) {
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

	if (giros_acumulados > 15) { // Evita que se quede atrapado en casilla especial rodeada de bosque o agua.
		if (sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P' && ((sensores.terreno[2] == 'A' && !bikini) || (sensores.terreno[2] == 'B' && !zapatillas))) {
			accion.clear();
			accion.push_back(actFORWARD);
			giros_acumulados = 0;
		}
 	}

	if (((sensores.terreno[0] == 'A' && !bikini) || (sensores.terreno[0] == 'B' && !zapatillas)) && !solventandoAtasco) {
		accion.clear();
		solventandoAtasco = true; 
		if (sensores.terreno[2] != 'A' && sensores.terreno[2] != 'B' && sensores.terreno[2] != 'M' && sensores.terreno[2] != 'P') {
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[1] != 'A' && sensores.terreno[1] != 'B' && sensores.terreno[1] != 'M' && sensores.terreno[1] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[3] != 'A' && sensores.terreno[3] != 'B' && sensores.terreno[3] != 'M' && sensores.terreno[3] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[6] != 'A' && sensores.terreno[6] != 'B' && sensores.terreno[6] != 'M' && sensores.terreno[6] != 'P') {
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[12] != 'A' && sensores.terreno[12] != 'B' && sensores.terreno[12] != 'M' && sensores.terreno[12] != 'P') {
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		}  else if (sensores.terreno[4] != 'A' && sensores.terreno[4] != 'B' && sensores.terreno[4] != 'M' && sensores.terreno[4] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[9] != 'A' && sensores.terreno[9] != 'B' && sensores.terreno[9] != 'M' && sensores.terreno[9] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[8] != 'A' && sensores.terreno[8] != 'B' && sensores.terreno[8] != 'M' && sensores.terreno[8] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[15] != 'A' && sensores.terreno[15] != 'B' && sensores.terreno[15] != 'M' && sensores.terreno[15] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[5] != 'A' && sensores.terreno[5] != 'B' && sensores.terreno[5] != 'M' && sensores.terreno[5] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[1] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[7] != 'A' && sensores.terreno[7] != 'B' && sensores.terreno[7] != 'M' && sensores.terreno[7] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[1] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[11] != 'A' && sensores.terreno[11] != 'B' && sensores.terreno[11] != 'M' && sensores.terreno[11] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[1] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[13] != 'A' && sensores.terreno[13] != 'B' && sensores.terreno[13] != 'M' && sensores.terreno[13] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[3] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			accion.push_back(actFORWARD);
		} else if (sensores.terreno[10] != 'A' && sensores.terreno[10] != 'B' && sensores.terreno[10] != 'M' && sensores.terreno[10] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[1] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[5] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
		} else if(sensores.terreno[14] != 'A' && sensores.terreno[14] != 'B' && sensores.terreno[14] != 'M' && sensores.terreno[14] != 'P') {
			if (sensores.terreno[0] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[3] == 'B') {
				accion.push_back(actTURN_SL);
			} else {
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
				accion.push_back(actTURN_BL);
			}
			accion.push_back(actFORWARD);
			if (sensores.terreno[7] == 'B') {
				accion.push_back(actTURN_SR);
			} else {
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
				accion.push_back(actTURN_BR);
			}
			accion.push_back(actFORWARD);
		} else {
			accion.push_back(actTURN_BR);
		}
	}

	if (accion[0] == actFORWARD) {
		num_avances++;
	}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

	if (sensores.superficie[2] != '_' && accion[0] == actFORWARD) {
		accion.clear();
		accion.push_back(actIDLE);
	}

	// Devolver posicion - Determinar el efecto de la ultima accion enviada
	last_action = accion[0];
	return last_action;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
