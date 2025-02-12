/**
 * @file jugador.cpp
 * @author Antonio Rodríguez Rodríguez (antoniorr@correo.ugr.es)
 * @brief Práctica 1 Inteligencia Artificial
 * Ingeniería Informática + ADE, Universidad de Granada.
 * @version 0.1
 * @date 2023-04-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

struct state {
  int fil;
  int col;
  Orientacion brujula;
};

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      current_state.fil = current_state.col = 99;
      current_state.brujula = norte;
      last_action = actIDLE;
      girar_derecha = false;
      bien_situado = false;

      matrizPaso = new int*[size];
      for (int i = 0; i < size; i++) {
            matrizPaso[i] = new int[size];
      }
      for (unsigned int i = 0; i < size; i++) {
        for (unsigned int j = 0; j < size; j++) {
          matrizPaso[i][j] = 0;
        }
      }
      
      num_cuadrantes = size/5;
      matrizCuadrantesNoVisitados = new int*[num_cuadrantes];
      for (int i = 0; i < num_cuadrantes; i++) {
            matrizCuadrantesNoVisitados[i] = new int[num_cuadrantes];
      }
      for (unsigned int i = 0; i < num_cuadrantes; i++) {
        for (unsigned int j = 0; j < num_cuadrantes; j++) {
          matrizCuadrantesNoVisitados[i][j] = 0;
        }
      }

      matrizCuadrantesPrincipales = new int*[2];
      for (int i = 0; i < 2; i++) {
            matrizCuadrantesPrincipales[i] = new int[2];
      }
      for (unsigned int i = 0; i < 2; i++) {
        for (unsigned int j = 0; j < 2; j++) {
          matrizCuadrantesPrincipales[i][j] = 0;
        }
      }

      matrizDesubicado = new char*[(size*2)+1];
      for (int i = 0; i < (size*2)+1; i++) {
            matrizDesubicado[i] = new char[(size*2)+1];
      }
      for (unsigned int i = 0; i < (size*2)+1; i++) {
        for (unsigned int j = 0; j < (size*2)+1; j++) {
          matrizDesubicado[i][j] = '?';
        }
      }
      
      bikini = false;
      zapatillas = false;
      accion.push_back(actIDLE);
      vector<Action> accion;
      giros_acumulados = 0;
      filaMatrizDesubicado = size;
      colMatrizDesubicado = size;
      brujulaDesorientada = 0;
      num_avances = 0;
      solventandoAtasco = false;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Declarar aquí las variables de estado
  Action last_action;
  state current_state;
  bool girar_derecha;
  bool bien_situado;
  int ** matrizPaso;
  int ** matrizCuadrantesNoVisitados;
  int ** matrizCuadrantesPrincipales;
  char ** matrizDesubicado;
  int filaMatrizDesubicado, colMatrizDesubicado, brujulaDesorientada;
  bool bikini, zapatillas;
  vector<Action> accion;
  int giros_acumulados, num_cuadrantes, num_avances;
  bool solventandoAtasco;
};

#endif

