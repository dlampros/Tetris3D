#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <GL/gl.h>     // openGL header
#include <GL/glu.h>   // glut header
#include <GL/glut.h>   // glut header
#include "Shape.h"

using namespace std;

Shape::Shape() {}
Shape::~Shape() {}

void Shape::createShape() {
	size = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				enableCubes[i][j][k] = 0;
			}
		}
	}
}

void Shape::initShape() {
	srand(time(0));

	bool ok = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (rand() % 100 > 40)
				{
					enableCubes[i][j][k] = 1;
					size++;

					if (size > 1)
					{
						if (i > 0 && !ok)
						{
							if (enableCubes[i - 1][j][k] == 1)
								ok = true;
						}

						if (j > 0 && !ok)
						{
							if (enableCubes[i][j - 1][k] == 1)
								ok = true;
						}

						if (k > 0 && !ok)
						{
							if (enableCubes[i][j][k - 1] == 1)
								ok = true;
						}

						if (i < 2 && !ok)
						{
							if (enableCubes[i + 1][j][k] == 1)
								ok = true;
						}

						if (j < 2 && !ok)
						{
							if (enableCubes[i][j + 1][k] == 1)
								ok = true;
						}

						if (k < 2 && !ok)
						{
							if (enableCubes[i][j][k + 1] == 1)
								ok = true;
						}


						if (!ok)
						{
							enableCubes[i][j][k] = 0;
							size--;
						}
						else
						{
							ok = false;
						}
					}
				}
			}
		}
	}

	if (size == 0)
	{
		enableCubes[1][1][1] = 1;
		size++;
	}
}

void Shape::drawShape(int d, float x, float y, float z, int leftRight_rotation, int upDown_x, int upDown_z) {
	int r = 0, g = 0, b = 0;

	if (size < 10)
	{
		r = 1;
		g = 1;
		color = 1;
	}
	else if (size >= 20)
	{
		r = 1;
		color = 3;
	}
	else
	{
		b = 1;
		color = 2;
	}

	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 3; l++)
			{
				if (enableCubes[j][k][l] == 1)
				{
					glPushMatrix();

					glTranslatef(0, 0, 0);
					glRotatef(leftRight_rotation, 0, 1, 0);
					glRotatef(upDown_x, 1, 0, 0);
					glRotatef(upDown_z, 0, 0, 1);

					glColor3f(r, g, b);
					glTranslatef(j + x, y - k, l + z);
					glutSolidCube(0.99);
					//glutWireCube(1);

					glPopMatrix();
				}
			}
		}
	}
}

void Shape::rotateShape_x() {
	int temp[3][3][3];
	int i, j, k;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = enableCubes[i][2 - k][j];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				enableCubes[i][j][k] = temp[i][j][k];
}

void Shape::rotateShape_y() {
	int temp[3][3][3];
	int i, j, k;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = enableCubes[2 - k][j][i];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				enableCubes[i][j][k] = temp[i][j][k];
}

void Shape::rotateShape_z() {
	int temp[3][3][3];
	int i, j, k;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				temp[i][j][k] = enableCubes[j][2 - i][k];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				enableCubes[i][j][k] = temp[i][j][k];
}
