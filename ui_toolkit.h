//
// Created by Jessica Wei on 10/31/19.
//

#ifndef INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#define INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#include <gtk/gtk.h>
#include <string>
#include "TextCustom.h"
using namespace std;

class ui_toolkit {
public:
    static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
    static GtkWidget *make_playground(GtkWidget *widget, gpointer data);
    static GtkWidget *make_text(GtkWidget *widget, gpointer data);
    static GtkWidget *make_button(GtkWidget *widget, gpointer data);
    static GtkWidget *attach_text(GtkWidget *widget, gpointer data);

    struct PlaygroundDimensions{
        GtkWidget *row, *col, *rowSize, *colSize, *borSize;
        GtkWidget *play;
        GtkWidget *playwin;
    };
    struct PlaygroundText{
        GtkWidget *textbox;
        GtkWidget *userText;
        GtkWidget *posRow, *posCol, *maxRow, *maxCol;
        GtkWidget *play;
        GtkWidget *playwin, *maingrid, *configwin, *mainwin, *configgrid, *configspace;
        string compString, txtstr;
        gint rp, cp;
    };
    struct PlaygroundButton{
        GtkWidget *button;
        GtkWidget *playwin, *configwin, *mainwin;
        string compString;
        gint compCount;
    };
};


#endif //INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
