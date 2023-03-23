#!/bin/bash
echo nivel 0
./practica1SG ./mapas/mapa30.map 1 0 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa50.map 1 0 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa75.map 1 0 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa100.map 1 0 15 15 1 | tail -1

echo nivel 1
./practica1SG ./mapas/mapa30.map 1 1 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa50.map 1 1 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa75.map 1 1 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa100.map 1 1 15 15 1 | tail -1

echo nivel 2
./practica1SG ./mapas/mapa30.map 1 2 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa50.map 1 2 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa75.map 1 2 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa100.map 1 2 15 15 1 | tail -1

echo nivel 3
./practica1SG ./mapas/mapa30.map 1 3 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa50.map 1 3 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa75.map 1 3 15 15 1 | grep  Porcentaje
./practica1SG ./mapas/mapa100.map 1 3 15 15 1 | tail -1