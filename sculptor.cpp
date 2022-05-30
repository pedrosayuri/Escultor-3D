#include "sculptor.hpp"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
	this -> nx = _nx;
	this -> ny = _ny;
	this -> nz = _nz;
	this -> r = 0;
	this -> g = 0;
	this -> b = 0;
	this -> a = 0;

	vox = new Voxel **[_nx];
	for (int i = 0; i < _nx; i++) {
		vox[i] = new Voxel * [_ny];
		for (int j = 0; j < _ny; j++) {
			vox[i][j] = new Voxel[_nz];
			for (int k = 0; k < _nz; k++) {
				this->vox[i][j][k].r = 0;
				this->vox[i][j][k].g = 0;
				this->vox[i][j][k].b = 0;
				this->vox[i][j][k].a = 0;
				this->vox[i][j][k].isOn = false;
			}
		}
	}
	std::cout << "Construtor OK!" << std::endl;
}

Sculptor::~Sculptor() {

	if (nx == 0 || ny == 0 || nz == 0) {
		std::cout << "Destruidor falhou" << std::endl;
		return;
	}

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			delete[] vox[i][j];
		}
		delete[] vox[i];
	}
	delete[] vox;

	std::cout << "Destruidor OK!" << std::endl;
}

void Sculptor::setColor(float r, float g, float b, float alpha) {
	this -> r = r;
	this -> g = g;
	this -> b = b;
	this -> a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z) {
	vox[x][y][z].isOn = true;
	vox[x][y][z].r = r;
	vox[x][y][z].g = g;
	vox[x][y][z].b = b;
	vox[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z) {
	vox[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1) {
	x0 = (x0 < 0) ? 0 : x0;
	x1 = (x1 > this -> nx) ? this -> nx : x1;
	y0 = (y0 < 0) ? 0 : y0;
	y1 = (y1 > this -> ny) ? this -> ny : y1;
	z0 = (z0 < 0) ? 0 : z0;
	z1 = (z1 > this -> nz) ? this -> nz : z1;
	
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				this -> putVoxel(i, j, k);
			}
		}
	}
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; k < z1; k++) {
				this -> cutVoxel(i, j, k);
			}
		}
	}
}

void Sculptor::putShepre(int xcenter, int ycenter, int zcenter, int radius) {
	double rd = radius / 2.0;
	double dist;

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				dist = (i - xcenter / 2.0) * (i - xcenter / 2.0) / (pow(rd, 2)) +
					(j - ycenter / 2.0) * (j - ycenter / 2.0) / (pow(rd, 2)) +
					(k - zcenter / 2.0) * (k - zcenter / 2.0) / (pow(rd, 2));

				if (dist <= 1.0) {
					vox[i][j][k].isOn = true;
					vox[i][j][k].r = r;
					vox[i][j][k].g = g;
					vox[i][j][k].b = b;
					vox[i][j][k].a = a;
				}
			}
		}
	}
}

void Sculptor::cutShepre(int xcenter, int ycenter, int zcenter, int radius) {
	double rd = radius / 2.0;
	double dist;

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				dist = (i - xcenter / 2.0) * (i - xcenter / 2.0) / (pow(rd, 2)) +
					(j - ycenter / 2.0) * (j - ycenter / 2.0) / (pow(rd, 2)) +
					(k - zcenter / 2.0) * (k - zcenter / 2.0) / (pow(rd, 2));

				if (dist <= 1.0) {
					vox[i][j][k].isOn = false;
				}
			}
		}
	}
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
	int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
	int x1 = (xcenter + rx > this->nx) ? this -> nx : xcenter + rx;
	int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
	int y1 = (ycenter + ry > this -> ny) ? this -> ny : ycenter + ry;
	int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
	int z1 = (zcenter + rz > this-> nz) ? this -> nz : zcenter + rz;

	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; j < z1; k++) {
				if (pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2) < 1) {
					this->putVoxel(i, j, k);
				}
			}
		}
	}
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
	int x0 = (xcenter - rx < 0) ? 0 : xcenter - rx;
	int x1 = (xcenter + rx > this -> nx) ? this -> nx : xcenter + rx;
	int y0 = (ycenter - ry < 0) ? 0 : ycenter - ry;
	int y1 = (ycenter + ry > this -> ny) ? this -> ny : ycenter + ry;
	int z0 = (zcenter - rz < 0) ? 0 : zcenter - rz;
	int z1 = (zcenter + rz > this -> nz) ? this -> nz : zcenter + rz;

	for (int i = x0; i < x1; i++) {
		for (int j = y0; j < y1; j++) {
			for (int k = z0; j < z1; k++) {
				if (pow(i - xcenter, 2) / pow(rx, 2) + pow(j - ycenter, 2) / pow(ry, 2) + pow(k - zcenter, 2) / pow(rz, 2) < 1) {
					this -> cutVoxel(i, j, k);
				}
			}
		}
	}
}

void Sculptor::writeOFF(char* filename) {
	
	int NVoxels = 0, NVertices, NFaces;
	float faces = 0;

	std::ofstream fout;

	fout.open(filename);
	if (!fout.is_open()) {
		exit(1);
		std::cout << "Não foi possivel abrir este arquivo";
	}

	fout << "OFF" << std::endl;

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn == true) {
					NVoxels++;
				}
			}
		}
	}

	NVertices = 8 * NVoxels;
	NFaces = 6 * NVoxels;

	fout << NVertices << " " << NFaces << " " << 0 << std::endl;

	for (int i = 0; i < nz; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nx; k++) {
				if (vox[i][j][k].isOn) {
					fout << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
						<< i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
						<< i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << std::endl
						<< i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << std::endl
						<< i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl
						<< i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
						<< i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << std::endl
						<< i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << std::endl;
				}
			}
		}
	}

	for (int i = 0; i < nx; i++) {
		for (int j = 0; j < ny; j++) {
			for (int k = 0; k < nz; k++) {
				if (vox[i][j][k].isOn) {
					fout << 4 << " " << 0 + faces << " " << 3 + faces << " " << 2 + faces << " " << 1 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl
						<< 4 << " " << 4 + faces << " " << 5 + faces << " " << 6 + faces << " " << 7 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl
						<< 4 << " " << 0 + faces << " " << 1 + faces << " " << 5 + faces << " " << 4 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl
						<< 4 << " " << 0 + faces << " " << 4 + faces << " " << 7 + faces << " " << 3 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl
						<< 4 << " " << 3 + faces << " " << 7 + faces << " " << 6 + faces << " " << 2 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl
						<< 4 << " " << 1 + faces << " " << 2 + faces << " " << 6 + faces << " " << 5 + faces << " "
						<< vox[i][j][k].r << " " << vox[i][j][k].g << " " << vox[i][j][k].b << " " << vox[i][j][k].a << std::endl;
					faces = faces + 8;
				}
			}
		}
	}

	fout.close();
}