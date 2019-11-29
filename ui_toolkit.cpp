//
// Created by Jessica Wei on 10/31/19.
//

#include "ui_toolkit.h"
#include "TextCustom.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <gtk/gtk.h>
#include <vector>
using namespace std;

static int textCount = 0;
int compTextInc(){
    textCount++;
    return textCount;
}

static vector<TextCustom*> txtList;
void addText(string txt, int rpos, int cpos){
    TextCustom* tc = new TextCustom(txt, rpos, cpos);
    txtList.push_back(tc);
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
    PlaygroundText *t;

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

    /* Load the Text Boxes */
    GtkWidget* screenTxt;
    for(int i = 0; i < txtList.size();i++){
        screenTxt = gtk_label_new(txtList.at(i)->getString().c_str());
        int tr = 0;
        int tc = 0;
        if(txtList.at(i)->getRowPos() >0)
            tr = txtList.at(i)->getRowPos()-1;

        if(txtList.at(i)->getColPos() >0)
            tc = txtList.at(i)->getColPos()-1;

        gtk_grid_attach(GTK_GRID(p->play), screenTxt, tc, tr, 1, 1);
        gtk_widget_show(screenTxt);
    }

    cout << r << "x" << c << " playground created." << endl;
    gtk_container_add (GTK_CONTAINER (p->playwin), p->play);

    gtk_widget_show(p->play);
    gtk_widget_show(p->playwin);

    return p->playwin;
}

GtkWidget *ui_toolkit::make_text(GtkWidget *widget, gpointer data){
    PlaygroundText* t = (PlaygroundText*) data;
    GtkWidget *label, *button;

    // Create Text Manager Popup
    t->configwin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(t->configwin), "Configure Textbox");
    gtk_window_set_resizable(GTK_WINDOW(t->configwin), false);
    gtk_container_set_border_width(GTK_CONTAINER(t->configwin), 20);
    t->configgrid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(t->configgrid),5);
    gtk_grid_set_column_spacing(GTK_GRID(t->configgrid),15);
    gtk_container_add (GTK_CONTAINER (t->configwin), t->configgrid);


    /* Entry (Textbox) */
    label = gtk_label_new("Text");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(t->configgrid), label, 0, 0, 1, 1);
    gtk_widget_show(label);

    t->userText = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(t->configgrid), t->userText, 1, 0, 1, 1);
    gtk_widget_show(t->userText);

    int rMax = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->maxRow));
    int cMax = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->maxCol));

    /* Row Scroll */
    label = gtk_label_new("Row Position");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(t->configgrid), label, 0, 2, 1, 1);
    gtk_widget_show(label);

    t->posRow = gtk_spin_button_new_with_range(1, rMax, 1);
    gtk_grid_attach(GTK_GRID(t->configgrid), t->posRow, 1, 2, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(t->posRow), true);
    gtk_widget_show(t->posRow);
    t->rp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(t->posRow))-1;

    /* Column Scroll */
    label = gtk_label_new("Column Position");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(t->configgrid), label, 0, 3, 1, 1);
    gtk_widget_show(label);

    t->posCol = gtk_spin_button_new_with_range(1, cMax, 1);
    gtk_grid_attach(GTK_GRID(t->configgrid), t->posCol, 1, 3, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(t->posCol), true);
    gtk_widget_show(t->posCol);
    t->cp = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(t->posCol)) - 1;

    /* Space */
    t->configspace = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(t->configgrid), t->configspace, 0, 4, 2, 1);
    gtk_widget_show(t->configspace);

    /* Add & Close Window Button */
    button = gtk_button_new_with_label ("Create Text");
    g_signal_connect (button, "clicked",G_CALLBACK (attach_text), data);
    gtk_grid_attach(GTK_GRID(t->configgrid), button, 0, 5, 2, 1);
    gtk_widget_show (button);

    /* Show everything and save values*/
    gtk_widget_show(t->configgrid);
    gtk_widget_show(t->configwin);

    // Add new Text manager to On-Screen Components w/ Remove Button
    cout << "Textbox making in progress!\n";
    return t->userText;
}

GtkWidget *ui_toolkit::attach_text(GtkWidget *widget, gpointer data){
    PlaygroundText* t = (PlaygroundText*) data;
    int r = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->posRow));
    int c = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(t->posCol));
    string str = gtk_entry_get_text(GTK_ENTRY(t->userText));
    string lab = "Textbox: "+str+" @ " + to_string(r) + ", " + to_string(c);
    GtkWidget *label = gtk_label_new(lab.c_str());
    int co = compTextInc();
    cout << "Text Comp Count: " << co << "\n";
    gtk_grid_attach(GTK_GRID(t->maingrid), label, 6, co, 1, 1);
    gtk_widget_show(label);

    addText(str, r, c);

    // Remove Button
    GtkWidget *button = gtk_button_new_with_label("Remove");
    gtk_grid_attach(GTK_GRID(t->maingrid), button, 7, co, 1, 1);
    gtk_widget_show(button);
    gtk_widget_destroy(t->configwin);

    return widget;
}

GtkWidget *ui_toolkit::make_button(GtkWidget *widget, gpointer data){
    PlaygroundButton *b = (PlaygroundButton*)data;
    cout << "Button making in progress!\n";
    return b->button;
}