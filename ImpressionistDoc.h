// 
// impressionistDoc.h
//
// header file for Doc 
//

#ifndef ImpressionistDoc_h
#define ImpressionistDoc_h

#include "impressionist.h"
#include "bitmap.h"

class ImpressionistUI;

class ImpressionistDoc 
{
public:
	ImpressionistDoc();

	void	setUI(ImpressionistUI* ui);		// Assign the UI to use

	int		loadImage(char *iname);			// called by the UI to load image
	int		saveImage(char *iname);			// called by the UI to save image


	int     clearCanvas();// called by the UI to clear the drawing canvas
	int		swapContent();
	int		getSize();						// get the UI size
	int		getLineWidth();
	int		getLineAngle();
	int		getSpacing();
	bool    getSizeRand();
	float	getAlpha();
	Point   getPreviousPoint();
	void	setSize(int size);				// set the UI size
	void	setBrushType(int type);			// called by the UI to set the brushType
	void    setStrokeDir(int type);
	void   setPreviousPoint(Point pp);
	char*	getImageName();					// get the current image name
	

// Attributes
public:
	// Dimensions of original window.
	int				m_nWidth, 
					m_nHeight;
	// Dimensions of the paint window.
	int				m_nPaintWidth, 
					m_nPaintHeight;	
	// Bitmaps for original image and painting.  c
	unsigned char*	m_ucBitmap;
	unsigned char*	m_ucPainting;


	// The current active brush.
	ImpBrush*			m_pCurrentBrush;
	// The current stroke direction
	int m_pCurrentStrokeDir;
	// Size of the brush.
	int m_nSize;							
	Point previous_point;
	ImpressionistUI*	m_pUI;

// Operations
public:
	// Get the color of the original picture at the specified coord
	GLubyte* GetOriginalPixel( int x, int y );   
	// Get the color of the original picture at the specified point	
	GLubyte* GetOriginalPixel( const Point p );  


private:
	char			m_imageName[256];

};

extern void MessageBox(char *message);

#endif
