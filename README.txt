La IA tiene 5 estados:
- Patrol: Patrulla entre 3 puntos colocados en la escena
- Chase: Cuando ve al jugador (Líneas de visión rojas) lo persigue
- Attack: Si está a menos de X distancia del jugador cambia su Sprite al de ataque
- Investigate: Mientras ve al jugador, si este se aleja (Líneas de visión rojas) comienza a perseguirlo yendo al último punto donde vio al jugador y luego buscando puntos aleatorios en torno al último punto donde vio al jugador
- Die: Cuando su vida es <= 0 deja de hacer acciones

El jugador se puede mover en todas direcciones con W,A,S,D y atacar al enemigo si se pulsa Space (le hace daño tan solo con pulsarlo, no es necesario estar a < de X distancia)