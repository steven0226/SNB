//
// ScatteredCircleBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredcirclebrush.h"

extern float frand();
extern int irand(int max);

ScatteredCircleBrush::ScatteredCircleBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredCircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void ScatteredCircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredCircleBrush::BrushMove  document is NULL\n");
		return;
	}

	int size = pDoc->getSize();
	//glGetIntegerv(GL_POINT_SIZE, &size);

	int no_of_circle = irand(2) + 3; //3 or 4 circle 
	for (int i = 0; i< no_of_circle; i++)
	{
		int rx = (frand() - 0.5f)*size;
		int ry = (frand() - 0.5f)*size;

		Point subs = Point(source.x+rx, source.y+ry);
		Point subt = Point(target.x+rx, target.y+ry); 
		ImpBrush::c_pBrushes[BRUSH_CIRCLES]->BrushMove(subs, subt);
	}
	

	
}

void ScatteredCircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

