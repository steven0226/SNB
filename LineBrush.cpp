//
// LineBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "linebrush.h"
#include "math.h"
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
	int half_length = pDoc->getSize();
	half_length /= 2;
	int angle = pDoc->getLineAngle();

	glBegin(GL_LINES);
	SetColor(source);
	if (angle <= 180){
		glVertex2d(target.x - half_length*cos(double(angle)), target.y - half_length*sin(double(angle)));
		glVertex2d(target.x + half_length*cos(double(angle)), target.y + half_length*sin(double(angle)));
	}
	else{
		glVertex2d(target.x + half_length*cos(double(angle)), target.y + half_length*sin(double(angle)));
		glVertex2d(target.x - half_length*cos(double(angle)), target.y - half_length*sin(double(angle)));
	}
	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

