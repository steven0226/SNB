//
// ScatteredPointBrush.cpp
//


#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredpointbrush.h"

extern float frand();

ScatteredPointBrush::ScatteredPointBrush(ImpressionistDoc* pDoc, char* name) :
ImpBrush(pDoc, name)
{
}

void ScatteredPointBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();
	glPointSize((float)size);

	BrushMove(source, target);
}

void ScatteredPointBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("ScatteredPointBrush::BrushMove  document is NULL\n");
		return;
	}
	int size = pDoc->getSize();
	glPointSize((float)1);

	

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (frand() > 0.10f) continue;
			Point subs = Point(source.x+(-size/2+i), source.y+(-size/2+j));
			Point subt = Point(target.x+(-size/2+i), target.y+(-size/2+j));
			ImpBrush::c_pBrushes[BRUSH_POINTS]->BrushMove(subs, subt);
		}
	}

	glPointSize((float)size);
	
}

void ScatteredPointBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

