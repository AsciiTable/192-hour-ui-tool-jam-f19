#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string>
#include "ui_toolkit.h"
using namespace std;

int main(int argc, char* argv[]) {
    ui_toolkit tool;
    ui_toolkit::PlaygroundDimensions pdimen;
    ui_toolkit::PlaygroundText ptext;
    ui_toolkit::PlaygroundText* ptextp = &ptext;
    ui_toolkit::PlaygroundButton pbutton;
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;
    GtkWidget *label, *space;
    GtkWidget *rspin, *cspin;
    GtkWidget *bspin;
    GtkWidget *sep;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "UI Toolkit");
    gtk_window_set_resizable(GTK_WINDOW(window), false);

    g_signal_connect(window, "delete-event", G_CALLBACK(tool.delete_event),NULL);

    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid),15);
    gtk_grid_set_column_spacing(GTK_GRID(grid),15);
    /* Puts the table in the main window */
    gtk_container_add (GTK_CONTAINER (window), grid);

    ptext.mainwin = window;
    ptext.maingrid = grid;

    /* Option Section Header */
    label = gtk_label_new("Configurations");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    gtk_widget_show(label);

    /* Row Spin Button */
    label = gtk_label_new("Row: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
    gtk_widget_show(label);

    rspin = gtk_spin_button_new_with_range(1, 10, 1);
    gtk_grid_attach(GTK_GRID(grid), rspin, 1, 1, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(rspin), true);
    gtk_widget_show(rspin);
    pdimen.row = rspin;
    ptext.maxRow = rspin;

    /* Row Space Spin Button */
    label = gtk_label_new("Row Space: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);
    gtk_widget_show(label);

    rspin = gtk_spin_button_new_with_range(5, 100, 1);
    gtk_grid_attach(GTK_GRID(grid), rspin, 1, 2, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(rspin), true);
    gtk_widget_show(rspin);
    pdimen.rowSize = rspin;

    /* Column Spin Button */
    label = gtk_label_new("Column: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 3, 1, 1);
    gtk_widget_show(label);

    cspin = gtk_spin_button_new_with_range(1, 10, 1);
    gtk_grid_attach(GTK_GRID(grid), cspin, 1, 3, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(cspin), true);
    gtk_widget_show(cspin);
    pdimen.col = cspin;
    ptext.maxCol = cspin;

    /* Column Space Spin Button */
    label = gtk_label_new("Column Space: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 4, 1, 1);
    gtk_widget_show(label);

    cspin = gtk_spin_button_new_with_range(5, 100, 1);
    gtk_grid_attach(GTK_GRID(grid), cspin, 1, 4, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(cspin), true);
    gtk_widget_show(cspin);
    pdimen.colSize = cspin;

    /* Border Width Spin Button */
    label = gtk_label_new("Border Width: ");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 5, 1, 1);
    gtk_widget_show(label);

    bspin = gtk_spin_button_new_with_range(0, 250, 5);
    gtk_grid_attach(GTK_GRID(grid), bspin, 1, 5, 1, 1);
    gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(bspin), true);
    gtk_widget_show(bspin);
    pdimen.borSize = bspin;

    /* Create Textbox Button */
    button = gtk_button_new_with_label ("Create Text");


    g_signal_connect (button, "clicked",G_CALLBACK (tool.make_text), ptextp);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 1, 1);
    gtk_widget_show (button);

    /* Create Button Button */
    button = gtk_button_new_with_label ("Create Button");
    g_signal_connect (button, "clicked",G_CALLBACK (tool.make_button), &pbutton);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 6, 1, 1);
    gtk_widget_show (button);

    /* Create Playground Button */
    button = gtk_button_new_with_label ("Create Playground");
    g_signal_connect (button, "clicked",G_CALLBACK (tool.make_playground), &pdimen);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 7, 2, 1);
    gtk_widget_show (button);

    /* Quit Button */
    button = gtk_button_new_with_label("Quit");
    g_signal_connect(button, "clicked", G_CALLBACK(tool.delete_event), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 8, 2, 1);
    gtk_widget_show(button);

    /* Vertical Separator */
    sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    gtk_grid_attach(GTK_GRID(grid), sep, 4, 0, 1, 11);
    gtk_widget_show(sep);

    /* Space for Formatting */
    space = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(grid), space, 5, 0, 1, 1);
    gtk_widget_show(space);

    /* List of Components */
    // Do something to allow for scrolling if On-Screen Components gets too long
    label = gtk_label_new("On-Screen Components");
    gtk_label_set_xalign(GTK_LABEL(label), 0);
    gtk_grid_attach(GTK_GRID(grid), label, 6, 0, 1, 1);
    gtk_widget_show(label);

    gtk_widget_show(grid);
    gtk_widget_show(window);

    gtk_main();
    return 0;
}

