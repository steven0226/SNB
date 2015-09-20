//
// LineBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"
#include <cmath>
extern float frand();

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	int width = pDoc->getLineWidth();

	glPointSize((float)size);
	glLineWidth((float)width);
	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;
	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}
	int stroke_dir = pDoc->m_pCurrentStrokeDir;
	int half_length = pDoc->getSize()/2;
	int angle = pDoc->getLineAngle();
	double PI_angle = (angle % 360) * M_PI / 180;
	double x = half_length*cos(PI_angle);
	double y = half_length*sin(PI_angle);

	switch (stroke_dir){
	case SLIDER_OR_RMOUSE:  break;
	case GRADIENT:			{


							break;
							}

	case BRUSH_DIRECTION:	{

							break;
							}
	}
	glBegin(GL_LINES);
	SetColor(source);
	glVertex2d(target.x -x, target.y -y);
	glVertex2d(target.x +x, target.y + y);

	
	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

