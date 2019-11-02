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

GtkWidget *ui_toolkit::make_playground(GtkWidget *widget, gpointer data){
    GtkWidget *space;
    PlaygroundDimensions *p = (PlaygroundDimensions*)data;
    p->play = gtk_grid_new();
    int r = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->row));
    int c = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->col));

    for(int i = 0; i < r; i++){
        space = gtk_label_new("r");
        gtk_grid_attach(GTK_GRID(p->play), space, 0, i, 1, 1);
    }
    for(int i = 0; i < c; i++){
        space = gtk_label_new("c");
        gtk_grid_attach(GTK_GRID(p->play), space, i, 0, 1, 1);
    }
    cout << r << "x" << c << " playground created." << endl;

//    GtkWidget *sep;
//    sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
//    gtk_grid_attach (GTK_GRID (p->grid), sep, 3, 0, 1, 6);
//    cout << p->row << "x" << p->col << " playground created yes." << endl;
//    gtk_grid_attach (GTK_GRID (p->grid), p->play, 4, 0, c, r);
//    cout << p->row << "x" << p->col << " playground created yes yes." << endl;
    return p->play;
}