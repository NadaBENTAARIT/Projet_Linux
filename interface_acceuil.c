#include <gtk/gtk.h>
void load_css(void)
{
    GtkCssProvider *provider;
    GdkDisplay *display;

    GdkScreen *scrw;
    //load css
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




 void button1_click()
{
   
    system("/home/nada/Bureau/Projetlinux/Tube/bild/run_client_tube.sh");
}
    void button2_click()
{
    system("/home/nada/Bureau/Projetlinux/Socket/bild/run_client_socket.sh");
}


    gtk_init(&argc, &argv);

//system("gnome-terminal -e 'sh -c\"gcc -o /home/nada/Bureau/Projetlinux/Tube/Serveur && /home/nada/Bureau/Projetlinux/Tube/serveur.c\"'");
//system("gnome-terminal -e 'sh -c\"gcc -o /home/nada/Bureau/Projetlinux/Socket/Serveur && /home/nada/Bureau/Projetlinux/Socket/serveur.c\"'");
    
    GtkWidget *window;
    GtkWidget *button1;
    GtkWidget *button2;
    GtkWidget *title;


    GtkWidget *fixed;
    load_css();
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //box=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    fixed = gtk_fixed_new();
    
    title=gtk_label_new("Bienvenue dans notre application,\n Choisissez le mode de communication !");
    button1 = gtk_button_new_with_mnemonic("Communication avec Tube nommé");
    button2 = gtk_button_new_with_label("Communication avec Socket mode TCP");


    g_signal_connect_swapped(button1, "clicked",G_CALLBACK(button1_click),window);
    g_signal_connect_swapped(button2, "clicked",G_CALLBACK(button2_click),window);

  

    gtk_widget_set_size_request(GTK_WIDGET(button1), 70, 70);
    gtk_widget_set_size_request(GTK_WIDGET(button2), 70, 70);
    gtk_container_add(GTK_CONTAINER(window), fixed);
    //gtk_box_pack_start(GTK_BOX(box),button1,TRUE,TRUE,50);
    //gtk_box_pack_start(GTK_BOX(box),button2,TRUE,TRUE,50);
    gtk_fixed_put(GTK_FIXED(fixed), title, 250, 50);

    gtk_fixed_put(GTK_FIXED(fixed), button1, 250, 50);
    gtk_fixed_put(GTK_FIXED(fixed), button2, 250, 200);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);
    gtk_window_set_title(GTK_WINDOW(window), "Acceuil");
    gtk_window_set_default_size(GTK_WINDOW(window), 700, 500);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    //a loop
    gtk_main();
    return 0;
}



