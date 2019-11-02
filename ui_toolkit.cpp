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
bool ui_toolkit::callback(GtkWidget *widget, gpointer data){
    g_print("Hello! Callback was called\n");
    bool *d = (bool*)data;
    *d = true;
    return true;
}

gboolean ui_toolkit::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
    g_print("Program closed.\n");
    gtk_main_quit();

    /* Return FALSE to let GTK emit the "destroy" signal */
    return FALSE;
    /* Return TRUE to stop the window from being destroyed -- useful for confirming quit request popups */
    //return TRUE;
}

GtkWidget *ui_toolkit::make_playground(GtkWidget *widget, gpointer data){
    GtkWidget *space;
    PlaygroundDimensions *p = (PlaygroundDimensions*)data;

    p->playwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(p->playwin), "Playground");

    g_signal_connect(p->playwin, "delete-event", G_CALLBACK(gtk_window_close),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(p->playwin), 30);

    p->play = gtk_grid_new();

    int r = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->row));
    int c = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->col));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            space = gtk_label_new("new!");
            gtk_grid_attach(GTK_GRID(p->play), space, j, i, 1,  1);
            gtk_widget_show(space);
        }
    }
    cout << r << "x" << c << " playground created." << endl;
    gtk_container_add (GTK_CONTAINER (p->playwin), p->play);

//    GtkWidget *sep;
//    sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
//    gtk_widget_show(sep);
//    if(r <= 6)
//        gtk_grid_attach (GTK_GRID (p->play), sep, 3, 0, 1, 6);
//    else
//        gtk_grid_attach (GTK_GRID (p->play), sep, 3, 0, 1, r);
//    cout << r << "x" << c << " playground created yes." << endl;

    gtk_widget_show(p->playwin);
    gtk_widget_show(p->play);
    return p->play;
}