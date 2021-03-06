//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Color_Chooser.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;
	Fl_Choice*			m_BrushStokeDirChoice;
	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushLineWidthSlider;
	Fl_Slider*			m_BrushLineAngleSlider;
	Fl_Slider*			m_BrushAlphaSlider;
	Fl_Slider*			m_SpacingSlider;
	Fl_Slider*			m_EdgeThresholdSlider;
	Fl_Button*          m_ClearCanvasButton;
	Fl_Button*          m_AutoPaintButton;
	Fl_Button*          m_DoEdgeThresholdButton;
	Fl_Light_Button*    m_EdgeClippingButton;
	Fl_Light_Button*    m_AnotherGradientButton;
	Fl_Light_Button*	m_SizeRandButton;
	
	Fl_Window*			m_colorDialog;
	Fl_Color_Chooser*	m_ColorSelector;



	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	int					getLineWidth();
	int					getLineAngle();
	float				getAlpha();
	float*				getColorBlend();
	int					getSpacing();
	bool				getSizeRand();
	void				setSize(int size);
	void				setLineWidth(int width);
	void				setLineAngle(int angle);
	void				setAlpha(float alpha);

private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
	int     m_nLineWidth;
	int     m_nLineAngle;
	float     m_nAlpha;
	float		m_colorBlend[3];
	int     m_nSpacing;
	int		m_nEdgeThre;
	bool isEdgeClipping;
	bool isAnotherGradient;
	bool isSizeRand;
	
	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item		StokeDirMenu[4];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_color(Fl_Menu_* o, void* v);
	static void	cb_swap_content(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);

	static void	cb_stroke_dir_Choice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_edge_clipping_button(Fl_Widget* o, void* v);
	static void	cb_another_gradient_button(Fl_Widget* o, void* v);
	static void cb_size_rand_button(Fl_Widget* o, void* v);
	static void cb_auto_print_button(Fl_Widget* o, void* v);
	static void cb_do_edge_thre_button(Fl_Widget* o, void* v);



	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void cb_lineWidthSlides(Fl_Widget* o, void* v);
	static void cb_lineAngleSlides(Fl_Widget* o, void* v);
	static void cb_alphaSlides(Fl_Widget* o, void* v);

	static void cb_spacingSlides(Fl_Widget* o, void* v);
	static void cb_edgeThreSlides(Fl_Widget* o, void* v);
	static void cb_colorSelector(Fl_Widget * o, void* v);
};

#endif
