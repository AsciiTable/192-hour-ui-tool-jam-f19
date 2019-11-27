//
// Created by Jessica Wei on 10/31/19.
//

#include "ui_toolkit.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <gtk/gtk.h>
using namespace std;

int *COMPONENTCOUNT = 0;

int init_compcount(){
    *COMPONENTCOUNT = 0;
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
    gtk_window_set_resizable(GTK_WINDOW(p->playwin), false);
    gtk_window_set_position(GTK_WINDOW(p->playwin), GTK_WIN_POS_CENTER_ALWAYS);

    g_signal_connect(p->playwin, "delete-event", G_CALLBACK(gtk_window_close),NULL);

    int b = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->borSize));
    gtk_container_set_border_width(GTK_CONTAINER(p->playwin), b);

    p->play = gtk_grid_new();
    int rS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->rowSize));
    int cS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->colSize));

    gtk_grid_set_row_spacing(GTK_GRID(p->play), rS);
    gtk_grid_set_column_spacing(GTK_GRID(p->play),cS);

    int r = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->row));
    int c = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(p->col));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            space = gtk_label_new("__|");
            gtk_grid_attach(GTK_GRID(p->play), space, j, i, 1,  1);
            gtk_widget_show(space);
        }
    }
    cout << r << "x" << c << " playground created." << endl;
    gtk_container_add (GTK_CONTAINER (p->playwin), p->play);

    gtk_widget_show(p->play);
    gtk_widget_show(p->playwin);

    return p->playwin;
}

GtkWidget *ui_toolkit::make_text(GtkWidget *widget, gpointer data){
    PlaygroundText *t = (PlaygroundText*)data;
    GtkWidget *label, *button;

    // Create Text Manager Popup
    GtkWidget *configwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(configwin), "Configure Textbox");
    gtk_window_set_resizable(GTK_WINDOW(configwin), false);
    gtk_container_set_border_width(GTK_CONTAINER(configwin), 20);
    GtkWidget *configgrid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(configgrid),5);
    gtk_grid_set_column_spacing(GTK_GRID(configgrid),15);
    gtk_container_add (GTK_CONTAINER (configwin), configgrid);


    /* Entry (Textbox) */
    label = gtk_label_new("Text");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(configgrid), label, 0, 0, 1, 1);
    gtk_widget_show(label);

    GtkWidget *userText = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(configgrid), userText, 1, 0, 1, 1);
    gtk_widget_show(userText);

    int rMax = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->maxRow));
    int cMax = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->maxCol));

    /* Row Scroll */
    label = gtk_label_new("Row Position");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(configgrid), label, 0, 2, 1, 1);
    gtk_widget_show(label);

    GtkWidget *posRow = gtk_spin_button_new_with_range(0, rMax, 1);
    gtk_grid_attach(GTK_GRID(configgrid), posRow, 1, 2, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(posRow), true);
    gtk_widget_show(posRow);
    gint rp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(posRow))-1;

    /* Column Scroll */
    label = gtk_label_new("Column Position");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(configgrid), label, 0, 3, 1, 1);
    gtk_widget_show(label);

    GtkWidget *posCol = gtk_spin_button_new_with_range(0, cMax, 1);
    gtk_grid_attach(GTK_GRID(configgrid), posCol, 1, 3, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(posCol), true);
    gtk_widget_show(posCol);
    gint cp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(posCol)) - 1;

    /* Space */
    GtkWidget *configspace = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(configgrid), configspace, 0, 4, 2, 1);
    gtk_widget_show(configspace);

    cout << "RP BEFORE ATTACH: " << rp;
    /* Add & Close Window Button */
    button = gtk_button_new_with_label ("Create Text");
    g_signal_connect (button, "clicked",G_CALLBACK (attach_text), &t);
    gtk_grid_attach(GTK_GRID(configgrid), button, 0, 5, 2, 1);
    gtk_widget_show (button);

    /* Show everything and save values*/
    gtk_widget_show(configgrid);
    gtk_widget_show(configwin);



    //gtk_grid_attach(GTK_GRID(t->maingrid), label, 6, 1, 1, 1);

    // Add new Text manager to On-Screen Components w/ Remove Button
    cout << "Textbox making in progress!\n";
    return userText;
}

GtkWidget *ui_toolkit::attach_text(GtkWidget *widget, gpointer data){
    PlaygroundText *t = (PlaygroundText*)data;
    //t->txtstr = gtk_entry_get_text(GTK_ENTRY(t->userText));
    cout << "TXTSTR: " << t->txtstr<<"\n";
    //gtk_grid_attach(GTK_GRID(t->maingrid), t->posCol, 6, 1, 1, 1);
    if(t->maingrid != NULL)
        cout << "Grid is something...\n";

    if(t->mainwin != NULL)
        cout << "Main Win is something...\n";

    if(t->configwin != NULL)
        cout << "Window is something...\n";
    else
        cout << "Try again CONFIG WIN HAHAHA\n";

    cout << "Checking data... " << t->rp << "\n";

    cout << "Made Textbox\n";
    return t->textbox;
}

GtkWidget *ui_toolkit::make_button(GtkWidget *widget, gpointer data){
    PlaygroundButton *b = (PlaygroundButton*)data;
    cout << "Button making in progress!\n";
    return b->button;
}