#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	int enableCubes[3][3][3];
	int size;
	int color;

	Shape();
	virtual ~Shape();

	void initShape();
	void createShape();
	void drawShape(int d, float x, float y, float z, int leftRight_rotation, int upDown_x, int upDown_z);
	void rotateShape_x();
	void rotateShape_y();
	void rotateShape_z();
};

#endif /* SHAPE_H_ */
