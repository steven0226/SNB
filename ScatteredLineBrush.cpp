//
// ScatteredLineBrush.cpp
//
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredlinebrush.h"

extern float frand();

ScatteredLineBrush::ScatteredLineBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredLineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

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
	SetColor(source);
	for (int j = 0; j < 4; j++)
	{
		int x = (frand() - 0.5f) *size;
		int y = (frand() - 0.5f) *size; // a random point round the target point

		Point subs = Point(source.x+x, source.y+y);
		Point subt = Point(target.x+x,target.y+y); // a random point around the original one

		ImpBrush::c_pBrushes[BRUSH_LINES]->BrushMove(subs, subt);
	}

}

void ScatteredLineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

