//
// ScatteredLineBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredlinebrush.h"
#include <cmath>
extern float frand();
extern int irand(int size);

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	int width = pDoc->getLineWidth();
	int StrokeDirType = pDoc->m_pCurrentStrokeDir;

	glPointSize((float)size);
	glLineWidth((float)width);
	if (StrokeDirType != BRUSH_DIRECTION)
	BrushMove(source, target);
}

void ScatteredLineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredLineBrush::BrushMove  document is NULL\n");
		return;
	}
	int size = pDoc->getSize();
	//SetColor(source);
	int orginalAngle = pDoc->getLineAngle();
	Point previous_point = pDoc->getPreviousPoint();
	int angle = (int)(atan2((double)target.y - previous_point.y, (double)target.x - previous_point.x) * 180 / M_PI);
	if (angle < 0)
		angle += 360;
	dlg->setLineAngle(angle);
	for (int j = 0; j < 4; j++)
	{
		int x = irand(size)  - size / 2;
		int y = irand(size) - size / 2;
		
		Point subs = Point(source.x+x, source.y+y);
		Point subt = Point(target.x+x,target.y+y); 

		ImpBrush::c_pBrushes[BRUSH_LINES]->BrushMove(subs, subt);
	}

}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

