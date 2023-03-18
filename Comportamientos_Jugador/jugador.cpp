#include "jugador.hpp"
#include <iostream>
using namespace std;

void PonerTerrenoEnMatriz(const vector<unsigned char> & terreno, const state &st, vector<vector<unsigned char>> &matriz) {
	matriz[st.fil][st.col] = terreno[0];
}

Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;
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

	//Decisiones

	if (sensores.terreno[0]=='G' and !bien_situado){
		current_state.fil = sensores.posF;
		current_state.col= sensores.posC;
		current_state.brujula = sensores.sentido;
		bien_situado = true;
	}

	if (bien_situado){
		PonerTerrenoEnMatriz(sensores.terreno, current_state, mapaResultado);
	}

	if((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G') and sensores.superficie[2] == '_') {
		accion = actFORWARD;
	} else if(!girar_derecha) {
		accion = actTURN_SL;
		girar_derecha = (rand()%2 ==0);
	} else {
		accion = actTURN_SR;
		girar_derecha = (rand()%2 ==0);
	}

	// Devolver posicion - Determinar el efecto de la ultima accion enviada
	last_action = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
