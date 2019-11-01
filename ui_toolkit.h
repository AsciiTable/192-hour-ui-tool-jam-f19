//
// Created by Jessica Wei on 10/31/19.
//

#ifndef INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#define INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
#include <gtk/gtk.h>

class ui_toolkit {
private:
public:
    GtkWidget *make_hbox(gboolean homogeneous, gint spacing, gboolean expand, gboolean fill, guint padding);
    static void callback(GtkWidget *widget, gpointer data);
    static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);
    static void hello(GtkWidget *widget, gpointer data);
    static void destroy(GtkWidget *widget, gpointer data);
};


#endif //INC_192_HOUR_UI_TOOL_JAM_UI_TOOLKIT_H
