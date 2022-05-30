#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "sculptor.hpp"


using namespace std;

int main() {

	Sculptor MinhaEscultura (200, 200, 200);

	MinhaEscultura.setColor(143, 255, 38, 1.0);
	
	//(int x0, int x1, int y0, int y1, int z0, int z1)

	//Chão
	MinhaEscultura.setColor(152, 251, 152, 1);
	MinhaEscultura.putBox(0, 45, 0, 2, 0, 200);

	//Torres
	MinhaEscultura.setColor(128, 128, 128, 1);
	MinhaEscultura.putBox(0, 5, 2, 32, 0, 5);
	MinhaEscultura.putBox(40, 45, 2, 32, 0, 5);
	MinhaEscultura.putBox(0, 5, 2, 32, 40, 45);
	MinhaEscultura.putBox(40, 45, 2, 32, 40, 45);
	
	//Piramides das torres
	int pos_x0_1 = 0, pos_z0_1 = 0, pos_x1_1 = 5, pos_z1_1 = 5;

	MinhaEscultura.setColor(128, 128, 128, 1);
	for (int pos_y1 = 31; pos_y1 < 37; pos_y1++) {
		MinhaEscultura.putBox(pos_x0_1, pos_x1_1, pos_y1, pos_y1 + 1, pos_z0_1, pos_z1_1);
		pos_x0_1++;
		pos_z0_1++;
		pos_x1_1--;
		pos_z1_1--;
	}

	int pos_x0_2 = 40, pos_z0_2 = 0, pos_x1_2 = 45, pos_z1_2 = 5;
	
	MinhaEscultura.setColor(128, 128, 128, 1);
	for (int pos_y2 = 31; pos_y2 < 37; pos_y2++) {
		MinhaEscultura.putBox(pos_x0_2, pos_x1_2, pos_y2, pos_y2 + 1, pos_z0_2, pos_z1_2);
		pos_x0_2++;
		pos_z0_2++;
		pos_x1_2--;
		pos_z1_2--;
	}

	int pos_x0_3 = 0, pos_z0_3 = 40, pos_x1_3 = 5, pos_z1_3 = 45;

	MinhaEscultura.setColor(128, 128, 128, 1);
	for (int pos_y3 = 31; pos_y3 < 37; pos_y3++) {
		MinhaEscultura.putBox(pos_x0_3, pos_x1_3, pos_y3, pos_y3 + 1, pos_z0_3, pos_z1_3);
		pos_x0_3++;
		pos_z0_3++;
		pos_x1_3--;
		pos_z1_3--;
	}

	int pos_x0_4 = 40, pos_z0_4 = 40, pos_x1_4 = 45, pos_z1_4 = 45;

	MinhaEscultura.setColor(128, 128, 128, 1);
	for (int pos_y4 = 31; pos_y4 < 37; pos_y4++) {
		MinhaEscultura.putBox(pos_x0_4, pos_x1_4, pos_y4, pos_y4 + 1, pos_z0_4, pos_z1_4);
		pos_x0_4++;
		pos_z0_4++;
		pos_x1_4--;
		pos_z1_4--;
	}

	//Estruta
	MinhaEscultura.setColor(128, 128, 128, 1);
	MinhaEscultura.putBox(3, 42, 2, 22, 3, 42);

	//Muro da estrutura
	MinhaEscultura.putBox(3, 42, 21, 24, 3, 5);
 	MinhaEscultura.putBox(3, 5, 21, 24, 3, 42);
	MinhaEscultura.putBox(3, 42, 21, 24, 40, 42);
	MinhaEscultura.putBox(40, 42, 21, 24, 3, 42);

	//Porta do castelo
	MinhaEscultura.setColor(139, 69, 19, 1);
	MinhaEscultura.putBox(18, 27, 2, 3, 41, 56);
	MinhaEscultura.cutBox(18, 27, 4, 17, 40, 42);

	//Dentro do castelo
	MinhaEscultura.cutBox(5, 40, 4, 27, 5, 40);
	MinhaEscultura.putBox(18, 27, 4, 6, 10, 17);
	MinhaEscultura.putBox(18, 27, 6, 10, 10, 17);
	MinhaEscultura.cutBox(19, 26, 6, 10, 11, 17);

	//Rio
	MinhaEscultura.setColor(0, 0, 255, 1);
	MinhaEscultura.putBox(18, 45, 1, 2, 116, 133);
	MinhaEscultura.putBox(13, 20, 1, 2, 120, 122);
	MinhaEscultura.putBox(20, 27, 1, 2, 133, 135);
	MinhaEscultura.putBox(0, 20, 1, 2, 122, 139);

	//Ponte
	MinhaEscultura.setColor(139, 69, 19, 1);
	MinhaEscultura.putBox(15, 30, 2, 3, 109, 111);
	MinhaEscultura.putBox(15, 30, 2, 4, 111, 114);
	MinhaEscultura.putBox(15, 30, 3, 4, 114, 116);
	MinhaEscultura.putBox(15, 30, 2, 4, 144, 146);
	MinhaEscultura.putBox(15, 30, 2, 3, 146, 148);
	MinhaEscultura.putBox(15, 30, 4, 6, 113, 144);
	MinhaEscultura.cutBox(15, 30, 5, 6, 113, 115);
	MinhaEscultura.putBox(15, 30, 2, 4, 143, 144);
	MinhaEscultura.putBox(15, 30, 2, 4, 144, 146);
	MinhaEscultura.putBox(15, 30, 2, 3, 146, 148);
	MinhaEscultura.putBox(15, 30, 3, 4, 141, 144);
	MinhaEscultura.cutBox(15, 30, 5, 6, 142, 144);

	//Arvore
	MinhaEscultura.setColor(210, 105, 30, 1);
	MinhaEscultura.putBox(8, 9, 2, 15, 80, 81);
	

	int pos_x0_5 = 5, pos_z0_5 = 77, pos_x1_5 = 12, pos_z1_5 = 84;

	MinhaEscultura.setColor(50, 205, 50, 1);
	MinhaEscultura.putBox(5, 12, 10, 15, 77, 84);
	for (int pos_y5 = 15; pos_y5 < 30; pos_y5++) {
		MinhaEscultura.putBox(pos_x0_5, pos_x1_5, pos_y5, pos_y5 + 1, pos_z0_5, pos_z1_5);
		pos_x0_5++;
		pos_z0_5++;
		pos_x1_5--;
		pos_z1_5--;
	}

	MinhaEscultura.setColor(210, 105, 30, 1);
	MinhaEscultura.putBox(36, 37, 2, 15, 80, 81);


	int pos_x0_6 = 33, pos_z0_6 = 77, pos_x1_6 = 40, pos_z1_6 = 84;

	MinhaEscultura.setColor(50, 205, 50, 1);
	MinhaEscultura.putBox(33, 40, 10, 15, 77, 84);
	for (int pos_y6 = 15; pos_y6 < 30; pos_y6++) {
		MinhaEscultura.putBox(pos_x0_6, pos_x1_6, pos_y6, pos_y6 + 1, pos_z0_6, pos_z1_6);
		pos_x0_6++;
		pos_z0_6++;
		pos_x1_6--;
		pos_z1_6--;
	}

	MinhaEscultura.setColor(210, 105, 30, 1);
	MinhaEscultura.putBox(8, 9, 2, 15, 170, 171);


	int pos_x0_7 = 5, pos_z0_7 = 167, pos_x1_7 = 12, pos_z1_7 = 173;

	MinhaEscultura.setColor(50, 205, 50, 1);
	MinhaEscultura.putBox(5, 12, 10, 15, 167, 173);
	for (int pos_y7 = 15; pos_y7 < 30; pos_y7++) {
		MinhaEscultura.putBox(pos_x0_7, pos_x1_7, pos_y7, pos_y7 + 1, pos_z0_7, pos_z1_7);
		pos_x0_7++;
		pos_z0_7++;
		pos_x1_7--;
		pos_z1_7--;
	}

	MinhaEscultura.setColor(210, 105, 30, 1);
	MinhaEscultura.putBox(36, 37, 2, 15, 170, 171);

	int pos_x0_8 = 33, pos_z0_8 = 167, pos_x1_8 = 40, pos_z1_8 = 173;

	MinhaEscultura.setColor(50, 205, 50, 1);
	MinhaEscultura.putBox(33, 40, 10, 15, 167, 173);
	for (int pos_y8 = 15; pos_y8 < 30; pos_y8++) {
		MinhaEscultura.putBox(pos_x0_8, pos_x1_8, pos_y8, pos_y8 + 1, pos_z0_8, pos_z1_8);
		pos_x0_8++;
		pos_z0_8++;
		pos_x1_8--;
		pos_z1_8--;
	}
	

	//Estrada
	MinhaEscultura.setColor(205, 133, 63, 1);
	MinhaEscultura.putBox(15, 30, 1, 2, 144, 200);
	MinhaEscultura.putBox(15, 30, 1, 2, 41, 109);
	


	MinhaEscultura.writeOFF((char*)"ProjetoEscultura3D.OFF"); 
	

	system("pause");

	return 0;

}