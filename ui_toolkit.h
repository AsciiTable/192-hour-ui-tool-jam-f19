//
// Created by Jessica Wei on 10/31/19.
//

#ifndef INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#define INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#include <gtk/gtk.h>
#include <string>
using namespace std;

class ui_toolkit {
public:
    static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
    static GtkWidget *make_playground(GtkWidget *widget, gpointer data);
    struct PlaygroundDimensions{
        GtkWidget *row, *col, *rowSize, *colSize;
        GtkWidget *play;
        GtkWidget *playwin;
    };
    struct PlaygroundText{
        GtkWidget *textbox;
        GtkWidget *userText;
        GtkWidget *posRow, *posCol;
        GtkWidget *playwin, *configwin, *mainwin;
        string compString;
    };
    struct PlaygroundButton{
        GtkWidget *playwin, *configwin, *mainwin;
    };
};


#endif //INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
