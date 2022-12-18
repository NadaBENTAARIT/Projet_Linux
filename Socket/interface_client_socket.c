#include <gtk/gtk.h>
#include <stdlib.h>
void load_css(void)
{
    GtkCssProvider *provider;
    GdkDisplay *display;

    GdkScreen *scrw;
    // load css
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    scrw = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(scrw, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gsize bytes_written, bytes_read;
    const gchar *file = "style.css";
    GError *error = 0;
    gtk_css_provider_load_from_path(provider, g_filename_to_utf8(file, strlen(file), &bytes_read, &bytes_written, &error), NULL);
    g_object_unref(provider);
}
int main(int argc, char **argv)
{
    GtkWidget *title1;
    GtkWidget *title2;

    // Opening file to read response
    FILE *fPtr;
    char line[50];
    char resultat[50] = "";

    int num;
    FILE *fptr;
    fptr = fopen("Socket/data_file.txt", "r");

    if (fptr == NULL)
    {
        printf("Error! opening file");
        strcat(resultat, "Error !! ");
        exit(1);
    }

    while (fgets(line, 50, fptr))
    {
        printf("%s", line);
        strcat(resultat, line);
    }

    /* Close file to save file data */
    fclose(fptr);
    remove("Socket/data.txt");

    gtk_init(&argc, &argv);
    // gtk code comes here
    // gtk window
    // with gtk box we can add multiple widgets
    GtkWidget *window1;

    GtkWidget *fixed;

    load_css();

    // load_css();
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // box=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    fixed = gtk_fixed_new();

    // title=gtk_label_new(num);

    gtk_container_add(GTK_CONTAINER(window1), fixed);
    // gtk_box_pack_start(GTK_BOX(box),button1,TRUE,TRUE,50);
    // gtk_box_pack_start(GTK_BOX(box),button2,TRUE,TRUE,50);
    // gtk_fixed_put(GTK_FIXED(fixed), title, 250, 50);

    title1 = gtk_label_new("____Vous etes bien connecté au serveur mode Socket TCP____");
    title2 = gtk_label_new(resultat);


    gtk_fixed_put(GTK_FIXED(fixed), title1,3, 50);
    gtk_fixed_put(GTK_FIXED(fixed), title2, 20, 120);

    gtk_window_set_resizable(GTK_WINDOW(window1), FALSE);
    gtk_window_set_title(GTK_WINDOW(window1), "Resultat_Socket");
    gtk_window_set_default_size(GTK_WINDOW(window1), 700, 500);
    gtk_window_set_position(GTK_WINDOW(window1), GTK_WIN_POS_CENTER);
    g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window1);
    // a loop
    gtk_main();
    return 0;
}
