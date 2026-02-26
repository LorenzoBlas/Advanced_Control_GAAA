# Uso de ESP-IDF con VSCOde

El siguiente repositorio tratara de representar la estructura y el uso de esta extension para programar microcontroladores esp32 y su posterior uso.


## 📋 Tabla de Contenidos

- [Introducción](#introducción)
- [Requisitos](#requisitos)
- [Instalación](#instalación)
- [Uso](#uso)
- [Configuración](#configuración)
- [Estructura de Archivos](#estructura-de-archivos)

## 🎯 Introducción

La implementacion de los microcontroladores es una de las tecnologias de vanguardia al momento de innovar con la creacion de algoritoms/rutinas que satisfazcan una necesidad.
es por esto, que con este trabajo se pretende entender un poco mas acerca de este tema.

## 📋 Requisitos

### Hardware
- ESP32 / Aca es donde podremos ver fisicamente el comportamiento de nuestros codigos

### Software
- Python >= 3.10.x
- Visual Studio COde
- ESP-IDF Extension de VSCode

### Sistema Operativo
- Ubuntu 22.04 LTS (recomendado)
- Windows 10/11 (con WSL2)

## 🚀 Instalación
Inicialmente se debe contar con git y python para el uso de este tipo de trabajos, despues de ello, se necesita que desde VSCode se instale el debido lenguaje C y sus complementos.
* Es importante tener todo esto antes de intentar instalar la extension de ESP-IDF

Despues de ello, se necesitara seguir la documentacion dada por la extension, aunque de forma resumida, podemos definir como crear un new proyect con el comando de esp-idf, y despues montar la estructura de carpetas necesarias para que sea
reconocible por nuestra extension.

### Clonación del Repositorio
```bash
git clone https://github.com/LorenzoBlas/Advanced_Control_GAAA.git
cd Advanced_Control_GAAAa
```

Es importante antes de intentar usar lso codigos de la extension de esp-idf cargar el entorno instalado del EIM del instaldor.
