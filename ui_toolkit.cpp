//
// Created by Jessica Wei on 10/31/19.
//

#include "ui_toolkit.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
using namespace std;

GtkWidget *ui_toolkit::make_hbox(gboolean homogeneous, gint spacing, gboolean expand, gboolean fill, guint padding){
    GtkWidget *box;
    GtkWidget *button;
    char padstr[80];

    box = gtk_hbox_new(homogeneous, spacing);

    button = gtk_button_new_with_label("gtk_box_pack");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    button = gtk_button_new_with_label ("(box,");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);

    button = gtk_button_new_with_label ("button,");
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);

    /* Button with the label depending on value of expand */
    if(expand)
        button = gtk_button_new_with_label("True");
    else
        button = gtk_button_new_with_label("False");

    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    /*Shorthand true false*/
    button = gtk_button_new_with_label(fill?"TRUE," : "FALSE,");
    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
    gtk_widget_show(button);

    sprintf(padstr, "%d;", padding);

    button = gtk_button_new_with_label (padstr);
    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
    gtk_widget_show (button);

    return box;
}
void ui_toolkit::callback(GtkWidget *widget, gpointer data){
    g_print("Hello! %s was pressed\n", (gchar *) data);
}

void ui_toolkit::hello(GtkWidget *widget, gpointer data){
    g_print("Hello World!\n");
}

gboolean ui_toolkit::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
    g_print("delete event occurred\n");
    gtk_main_quit();

    /* Return FALSE to let GTK emit the "destroy" signal */
    return FALSE;
    /* Return TRUE to stop the window from being destroyed -- useful for confirming quit request popups */
    //return TRUE;
}

void ui_toolkit::destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

GtkWidget *ui_toolkit::make_playground(int r, int c, bool h){
    GtkWidget *playground;

    playground = gtk_table_new(r, c, h);
    //gtk_container_add (GTK_CONTAINER (window), playground);

    return playground;
}