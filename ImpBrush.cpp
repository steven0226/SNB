//
// ImpBrush.cpp
//
// The implementation of virtual brush. All the other brushes inherit from it.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "ImpBrush.h"
#include <cmath>
// Static class member initializations
int			ImpBrush::c_nBrushCount	= 0;
ImpBrush**	ImpBrush::c_pBrushes	= NULL;

ImpBrush::ImpBrush(ImpressionistDoc*	pDoc, 
				   char*				name) :
					m_pDoc(pDoc), 
					m_pBrushName(name)
{
}

//---------------------------------------------------
// Return m_pDoc, which connects the UI and brushes
//---------------------------------------------------
ImpressionistDoc* ImpBrush::GetDocument(void)
{
	return m_pDoc;
}

//---------------------------------------------------
// Return the name of the current brush
//---------------------------------------------------
char* ImpBrush::BrushName(void)
{
	return m_pBrushName;
}

//----------------------------------------------------
// Set the color to paint with to the color at source,
// which is the coord at the original window to sample 
// the color from
//----------------------------------------------------
void ImpBrush::SetColor (const Point source)
{
	ImpressionistDoc* pDoc = GetDocument();
	float alpha = pDoc->getAlpha();
	float* colorBlend = pDoc->getColorBlend();
	
	
	GLubyte color[4];
	
	memcpy ( color, pDoc->GetOriginalPixel( source ), 3 );
	color[0] = static_cast<GLubyte> (color[0] * colorBlend[0]);
	color[1] = static_cast<GLubyte> (color[1] * colorBlend[1]);
	color[2] = static_cast<GLubyte> (color[2] * colorBlend[2]);
	color[3] = static_cast<GLubyte>(alpha * 255.f);
	glColor4ubv( color );

}