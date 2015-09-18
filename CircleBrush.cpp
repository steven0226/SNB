//
// CircleBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "circlebrush.h"
#include "math.h"
extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void CircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("CircleBrush::BrushMove  document is NULL\n");
		return;
	}

	

	double theta = 2*M_PI/ 360.0;
	double tangetial_factor = tan(theta);//calculate the tangential factor 
	double radial_factor = cos(theta);//calculate the radial factor 
	double radius;
	glGetDoublev(GL_POINT_SIZE, &radius);
	radius = radius / 2.0;
	double x = radius; 

	double y = 0;

	glBegin(GL_POLYGON);
	SetColor(source);
	for (int i=0; i< 360; i++)
	{
		glVertex2f(x + target.x, y + target.y);
		double tx = -y;
		double ty = x;
		x += tx * tangetial_factor;
		y += ty * tangetial_factor;
		x *= radial_factor;
		y *= radial_factor;
	}

	glEnd();
}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

