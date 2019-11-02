//
// Created by Jessica Wei on 10/31/19.
//

#ifndef INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#define INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#include <gtk/gtk.h>

class ui_toolkit {
public:
    static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
    static GtkWidget *make_playground(GtkWidget *widget, gpointer data);
    struct PlaygroundDimensions{
        GtkWidget *row, *col, *rowSize, *colSize;
        GtkWidget *play;
        GtkWidget *playwin;
    };
};


#endif //INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
