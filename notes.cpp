//#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
//#include <gtk/gtk.h>
//
//static GtkWidget *make_hbox(gboolean homogeneous, gint spacing, gboolean expand, gboolean fill, guint padding){
//    GtkWidget *box;
//    GtkWidget *button;
//    char padstr[80];
//
//    box = gtk_hbox_new(homogeneous, spacing);
//
//    button = gtk_button_new_with_label("gtk_box_pack");
//    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
//    gtk_widget_show(button);
//
//    button = gtk_button_new_with_label ("(box,");
//    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
//    gtk_widget_show (button);
//
//    button = gtk_button_new_with_label ("button,");
//    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
//    gtk_widget_show (button);
//
//    /* Button with the label depending on value of expand */
//    if(expand)
//        button = gtk_button_new_with_label("True");
//    else
//        button = gtk_button_new_with_label("False");
//
//    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
//    gtk_widget_show(button);
//
//    /*Shorthand true false*/
//    button = gtk_button_new_with_label(fill?"TRUE," : "FALSE,");
//    gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
//    gtk_widget_show(button);
//
//    sprintf(padstr, "%d;", padding);
//
//    button = gtk_button_new_with_label (padstr);
//    gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
//    gtk_widget_show (button);
//
//    return box;
//}
//static void callback(GtkWidget *widget, gpointer data){
//    g_print("Hello! %s was pressed\n", (gchar *) data);
//}
//
//static void hello(GtkWidget *widget, gpointer data){
//    g_print("Hello World!\n");
//}
//
//static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
//    g_print("delete event occurred\n");
//    gtk_main_quit();
//
//    /* Return FALSE to let GTK emit the "destroy" signal */
//    return FALSE;
//    /* Return TRUE to stop the window from being destroyed -- useful for confirming quit request popups */
//    //return TRUE;
//}
//
//static void destroy(GtkWidget *widget, gpointer data){
//    gtk_main_quit();
//}
//
////int main(int argc, char *argv[]) {
//    /* GtkWidget is the storage type for widgets */
//    GtkWidget *window;
//    GtkWidget *button;
//    GtkWidget *box1;
//    GtkWidget *box2;
//    GtkWidget *separator;
//    GtkWidget *label;
//    GtkWidget *quitbox;
//    GtkWidget *table;
//    int which = 1;
//
//    /** Our init, never forget this!!
//     * calls gtk_init(gint *argc, gchar ***argv) to set up default visual and color map
//     * calls gdk_init(gint *argc, gchar ***argv) to set up default signal handlers and checks the arguments
//     *       passed to your application on the command line. Removes gtk-module, g-fatal-warnings, gtk-debug,
//     *       gtk-no-debug, display, sync, name, class. Creates a set of standard arguments accepted by all GTK applications */
//    gtk_init(&argc, &argv);
//
//    //if(argc != 2){
//    //    fprintf (stderr, "usage: packbox num, where num is 1, 2, or 3.\n");
//    /*Cleans up in GTK and exists with an exit status of 1*/
//    //    std::cout << argc;
//    //    exit(1);
//    //}
//
//    //which = atoi (argv[1]);
//
//    /** Create a window
//     * GTK_WINDOW_TOPLEVEL says that we want the window to undergo window manager decoration and placement. Creates a
//     * window of 200x200 by default to allow manipulation even w/o children */
//    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
//
//    /* Set title of window */
//    gtk_window_set_title(GTK_WINDOW(window), "Hello Buttons!");
//
//    /** gulong g_signal_connect(gpointer *object, const gchar *name, GCallback func, gpointer func_data);*/
//
//    /** "delete-event" signal
//     * Given by the window manager ("close option" or on the titlebar)
//     * We ask it to call the delete_event() function and the data passed back to the callback
//     * function is NULL and ignored in the callback function.
//     */
//    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);
//
//    /* Set the border width of the window */
//    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
//
//
//    //box1 = gtk_hbox_new(TRUE, 10);
//    //box1 = gtk_vbox_new(FALSE, 0);
//    table = gtk_table_new(2,2,TRUE);
//    gtk_container_add(GTK_CONTAINER(window), table);
//
////    switch(which){
////        case 1:
////            label = gtk_label_new("gtk_hbox_new(FALSE, 0);");
////            /* Align the label to the left side. */
////            gtk_misc_set_alignment(GTK_MISC(label),0,0);
////            gtk_box_pack_start(GTK_BOX(box1), label, FALSE, FALSE, 0);
////            gtk_widget_show(label);
////            /* Call our make box function - homogeneous = FALSE, spacing = 0,
////	 * expand = FALSE, fill = FALSE, padding = 0 */
////            box2 = make_hbox (FALSE, 0, FALSE, FALSE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Call our make box function - homogeneous = FALSE, spacing = 0,
////             * expand = TRUE, fill = FALSE, padding = 0 */
////            box2 = make_hbox (FALSE, 0, TRUE, FALSE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (FALSE, 0, TRUE, TRUE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Creates a separator, we'll learn more about these later,
////             * but they are quite simple. */
////            separator = gtk_hseparator_new ();
////
////            /* Pack the separator into the vbox. Remember each of these
////             * widgets is being packed into a vbox, so they'll be stacked
////         * vertically. */
////            gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
////            gtk_widget_show (separator);
////
////            /* Create another new label, and show it. */
////            label = gtk_label_new ("gtk_hbox_new (TRUE, 0);");
////            gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
////            gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
////            gtk_widget_show (label);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (TRUE, 0, TRUE, FALSE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (TRUE, 0, TRUE, TRUE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Another new separator. */
////            separator = gtk_hseparator_new ();
////            /* The last 3 arguments to gtk_box_pack_start are:
////             * expand, fill, padding. */
////            gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
////            gtk_widget_show (separator);
////            break;
////
////        case 2:
////            /* Create a new label, remember box1 is a vbox as created
////	 * near the beginning of main() */
////            label = gtk_label_new ("gtk_hbox_new (FALSE, 10);");
////            gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
////            gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
////            gtk_widget_show (label);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (FALSE, 10, TRUE, FALSE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (FALSE, 10, TRUE, TRUE, 0);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            separator = gtk_hseparator_new ();
////            /* The last 3 arguments to gtk_box_pack_start are:
////             * expand, fill, padding. */
////            gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
////            gtk_widget_show (separator);
////
////            label = gtk_label_new ("gtk_hbox_new (FALSE, 0);");
////            gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
////            gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
////            gtk_widget_show (label);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (FALSE, 0, TRUE, FALSE, 10);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* Args are: homogeneous, spacing, expand, fill, padding */
////            box2 = make_hbox (FALSE, 0, TRUE, TRUE, 10);
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            separator = gtk_hseparator_new ();
////            /* The last 3 arguments to gtk_box_pack_start are: expand, fill, padding. */
////            gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
////            gtk_widget_show (separator);
////            break;
////        case 3:
////            /* This demonstrates the ability to use gtk_box_pack_end() to
////	 * right justify widgets. First, we create a new box as before. */
////            box2 = make_hbox (FALSE, 0, FALSE, FALSE, 0);
////
////            /* Create the label that will be put at the end. */
////            label = gtk_label_new ("end");
////            /* Pack it using gtk_box_pack_end(), so it is put on the right
////             * side of the hbox created in the make_box() call. */
////            gtk_box_pack_end (GTK_BOX (box2), label, FALSE, FALSE, 0);
////            /* Show the label. */
////            gtk_widget_show (label);
////
////            /* Pack box2 into box1 (the vbox remember ? :) */
////            gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
////            gtk_widget_show (box2);
////
////            /* A separator for the bottom. */
////            separator = gtk_hseparator_new ();
////            /* This explicitly sets the separator to 400 pixels wide by 5 pixels
////             * high. This is so the hbox we created will also be 400 pixels wide,
////             * and the "end" label will be separated from the other labels in the
////             * hbox. Otherwise, all the widgets in the hbox would be packed as
////             * close together as possible. */
////            gtk_widget_set_size_request (separator, 400, 5);
////            /* pack the separator into the vbox (box1) created near the start
////             * of main() */
////            gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
////            gtk_widget_show (separator);
////            break;
////    }
//
//    button = gtk_button_new_with_label("Button 1");
//
//    g_signal_connect(button,"clicked",G_CALLBACK(callback),(gpointer)"button 1");
//
//    /*Pack button 1 (and eventually button 2) from left to right*/
//    //gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);
//
//    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 1, 0, 1);
//    gtk_widget_show(button);
//
//    button = gtk_button_new_with_label("Button 2");
//
//    g_signal_connect(button, "clicked", G_CALLBACK(callback),(gpointer)"button 2");
//    //gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);
//    gtk_table_attach_defaults(GTK_TABLE(table), button, 1, 2, 0, 1);
//    gtk_widget_show(button);
//
//    //quitbox = gtk_hbox_new(FALSE,0);
//
//    button = gtk_button_new_with_label("Quit");
//
//    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_main_quit), window);
//    gtk_table_attach_defaults(GTK_TABLE(table), button, 0, 2, 1, 2);
//    gtk_widget_show(button);
//    /* Pack the button into the quitbox.
//     * The last 3 arguments to gtk_box_pack_start are:
//     * expand, fill, padding. */
//    //gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
//    /* pack the quitbox into the vbox (box1) */
//    //gtk_box_pack_start (GTK_BOX (box1), quitbox, FALSE, FALSE, 0);
//
//
//    //gtk_container_add(GTK_CONTAINER(window),box1);
//    gtk_widget_show(table);
//
//
//    /** "destroy" signal
//     * Occurs when we call gtk_widget_destroy() on the window OR if we return FALSE in the "delete-event" callback.
//     */
//    // g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
//
//    /* Sets the border width of the window */
//    //gtk_container_set_border_width(GTK_CONTAINER(window), 10);
//
//    /* Creates a new button with the label "Hello World" */
//    //button = gtk_button_new_with_label ("Hello World");
//
//    /** "clicked" signal
//     * When button is clicked, it will call the function hello() passing it NULL as its argument
//     */
//    //g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
//
//    /** "clicked" signal con't
//     * Causes the window to be destroyed by calling gtk_widget_destroy(window) when "clicked"
//     * Destroy signal can come from here or the window manager
//     */
//    //g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
//
//    /* Pack the button into a window (aka a gtk container) */
//    //gtk_container_add(GTK_CONTAINER(window), button);
//
//    /* Displays button */
//    //gtk_widget_show(button);
//    //gtk_widget_show(quitbox);
//    //gtk_widget_show(box1);
//
//    /** Displays the window
//     * Lets GTK know that we are done setting the attributes of this widget and that it can display it
//     */
//    gtk_widget_show(window);
//
//    /** Enters the GTK main processing loop
//     * When control reaches this point, GTK will sleep waiting for events (button/key presses), timeouts,
//     * or file IO notifications to occur.
//     */
//    gtk_main();
//    //return 0;
////}
//
