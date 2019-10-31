#include <iostream>
#include <stdio.h>
#include <gtk/gtk.h>

static void callback(GtkWidget *widget, gpointer data){
    g_print("Hello! %s was pressed\n", (gchar *) data);
}

static void hello(GtkWidget *widget, gpointer data){
    g_print("Hello World!\n");
}

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
    g_print("delete event occurred\n");
    gtk_main_quit();

    /* Return FALSE to let GTK emit the "destroy" signal */
    return FALSE;
    /* Return TRUE to stop the window from being destroyed -- useful for confirming quit request popups */
    //return TRUE;
}

static void destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;

    /**
     * calls gtk_init(gint *argc, gchar ***argv) to set up default visual and color map
     * calls gdk_init(gint *argc, gchar ***argv) to set up default signal handlers and checks the arguments
     *       passed to your application on the command line. Removes gtk-module, g-fatal-warnings, gtk-debug,
     *       gtk-no-debug, display, sync, name, class. Creates a set of bstandard arguments accepted by all GTK applications */
    gtk_init(&argc, & argv);

    /** Create a window
     * GTK_WINDOW_TOPLEVEL says that we want the window to undergo window manager decoration and placement. Creates a
     * window of 200x200 by default to allow manipulation even w/o children */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* Set title of window */
    gtk_window_set_title(GTK_WINDOW(window), "Hello Buttons!");

    /** gulong g_signal_connect(gpointer *object, const gchar *name, GCallback func, gpointer func_data);*/

    /** "delete-event" signal
     * Given by the window manager ("close option" or on the titlebar)
     * We ask it to call the delete_event() function and the data passed back to the callback
     * function is NULL and ignored in the callback function.
     */
    g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);

    /* Set the border width of the window */
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);


    box1 = gtk_hbox_new(FALSE, 0);

    gtk_container_add(GTK_CONTAINER(window),box1);

    button = gtk_button_new_with_label("Button 1");

    /** "destroy" signal
     * Occurs when we call gtk_widget_destroy() on the window OR if we return FALSE in the "delete-event" callback.
     */
    // g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    /* Sets the border width of the window */
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    /* Creates a new button with the label "Hello World" */
    button = gtk_button_new_with_label ("Hello World");

    /** "clicked" signal
     * When button is clicked, it will call the function hello() passing it NULL as its argument
     */
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);

    /** "clicked" signal con't
     * Causes the window to be destroyed by calling gtk_widget_destroy(window) when "clicked"
     * Destroy signal can come from here or the window manager
     */
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    /* Pack the button into a window (aka a gtk container) */
    gtk_container_add(GTK_CONTAINER(window), button);

    /* Displays button */
    gtk_widget_show(button);

    /** Displays the window
     * Lets GTK know that we are done setting the attributes of this widget and that it can display it
     */
    gtk_widget_show(window);

    /** Enters the GTK main processing loop
     * When control reaches this point, GTK will sleep waiting for events (button/key presses), timeouts,
     * or file IO notifications to occur.
     */
    gtk_main();
    return 0;
}

