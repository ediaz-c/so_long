# So_long
El proyecto **so_long** consiste en crear un juego en **2D** en C.

El primer proyecto de gráficos del cursus, el que se utilizarán ventanas, colores, eventos, texturas, etc.

El proyecto utiliza la librería **miniLibX**, una librería interna creada por el campus.
## Instalación
    $ git clone https://github.com/ediaz-c/so_long.git so_long
    $ cd so_long

## Juego
El proyecto tiene una parte **obligatoria** y un **bonus**.
Para iniciar el juego, hay que ejecutar **so_long** y como argumento la ruta al archivo del mapa a jugar.
### Mandatory
    $ make
### Bonus
    $ make bonus
### Ejecución
    $ ./so_long {ruta al archivo .ber}
- El objetivo es recolectar todos los objetos y salir por la puerta.
- Para mover al personaje se puedes usar las **flechas** o **W, A, S, D**.
- Si no exite camino posible, o el mapa no está cerrado por muros, no se podrá jugar.
## Anotaciones
- Los mapas se crean con carácteres:
    - **1** Para los muros
    - **0** Para el suelo
    - **P** Para el jugador
    - **E** Para la salida
    - **C** Para los coleccionables
    - **Z** Para los enemigos (con bonus)
- La extensión del mapa debe ser **.ber**, no se admite otra.
