app:start.c tank.c ui.c loop.c framework.c
	gcc -Wint-to-pointer-cast -o app start.c tank.c ui.c loop.c framework.c -I. -L/home/yangu/allegro5/lib -lallegro -lallegro_main -lallegro_image
