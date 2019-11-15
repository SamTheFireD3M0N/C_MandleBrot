#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <complex>
#include <iostream>
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;
double mandelbrot(complex<double>c);
int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);
	complex <double>c;
	int num;
		for(double i= -2; i < 2; i+=.01)
		for (double j = -2; j < 2; j+=.01) {
			c = complex<double>(i, j);//convert the i, j coordinat pair to a complex number
			num = mandelbrot(c); //runs that number through the mandlebroth function
			al_put_pixel(i*100+400, j*100+400, al_map_rgb(num*num, num/20, num*10));//use the output of the function to determin color
			cout << "num is  " << num << " at " << i*100+400 << " " << j*100+400 << endl;
			al_flip_display();
		}
	
	system("Pause");
	al_destroy_display(display);

}
double mandelbrot(complex<double>c) {
	complex<double>z = 0;
	int count = 0;
	while (abs(z) < 2 && count < 80) {
		z = z * z + c;
		count++;
	}
	return count;
}
