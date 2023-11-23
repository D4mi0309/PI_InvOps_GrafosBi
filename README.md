# PI_InvOps_GrafosBi
Esto es un repositorio donde se almacena una biblioteca en lenguaje C para la asignación de salas de computo de la UCEVA, mediante grafos bipartitos.

Pasos para la compilación y ejecución del proyecto:
gcc -c -Wall -Werror -fpic libinvops.c
gcc -shared -o libinvops.so  libinvops.o
nm -a libinvops.so
gcc -L/home/ubuntu/pi_io/libgrafosbi -Wall -o ejecutable main.c -linvops
sudo cp libinvops.so /usr/lib
sudo ldconfig
./ejecutable
