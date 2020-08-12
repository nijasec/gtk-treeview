#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include <stdlib.h>
G_MODULE_EXPORT void on_btn_clicked();
GtkBuilder *builder;
GtkWidget  *lbl1;
GtkWidget   *button1;
GtkWidget   *btnimg;
GtkTreeView *tv1;
GtkTreeViewColumn *cx1;
GtkTreeViewColumn *cx2;
GtkTreeSelection *selection;
GtkTreeStore *treestore; 
GtkCellRenderer *cr1,*cr2;
GtkFixed *fixed1;
GtkLabel *label;
 
 
int main(int argc, char *argv[])
{

	

	GtkWidget *window;
int i;
	gtk_init (&argc, &argv);
	builder=gtk_builder_new_from_file("tree.glade");

	window =GTK_WIDGET(gtk_builder_get_object(builder,"mainwindow"));// gtk_window_new (GTK_WINDOW_TOPLEVEL);
    tv1=GTK_TREE_VIEW(gtk_builder_get_object(builder,"tv1"));
    treestore=GTK_TREE_STORE(gtk_builder_get_object(builder,"treeStore"));
    cx1=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cx1"));
    cx2=GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder,"cx2"));
    cr1=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cr1"));
    label=GTK_LABEL(gtk_builder_get_object(builder,"log"));
    
    cr2=GTK_CELL_RENDERER(gtk_builder_get_object(builder,"cr2"));
    
    selection=GTK_TREE_SELECTION(gtk_builder_get_object(builder,"select"));
    gtk_tree_view_column_add_attribute(cx1,cr1,"text",0);
    gtk_tree_view_column_add_attribute(cx2,cr2,"text",1);
    GtkTreeIter iter,child1,child2;
    gtk_tree_store_append(treestore,&iter,NULL);
    gtk_tree_store_set(treestore,&iter,0,"row 1",-1);
    gtk_tree_store_set(treestore,&iter,1,"row 2 data",-1);
    
     gtk_tree_store_append(treestore,&child1,&iter);
    gtk_tree_store_set(treestore,&child1,0,"row child 1",-1);
   gtk_tree_store_set(treestore,&child1,1,"row child 2",-1);
    
        gtk_tree_store_append(treestore,&iter,NULL);
    gtk_tree_store_set(treestore,&iter,0,"row 2",-1);
    gtk_tree_store_set(treestore,&iter,1,"row 2",-1);
     gtk_tree_store_append(treestore,&child2,&iter);
    gtk_tree_store_set(treestore,&child2,0,"row child 1",-1);
    gtk_tree_store_set(treestore,&child2,1,"row child 2",-1);
    
    
    
 //   listbox=GTK_WIDGET(gtk_builder_get_object(builder,"listbox"));
	//button1=GTK_WIDGET(gtk_builder_get_object(builder,"button1"));
	//lbl1=GTK_WIDGET(gtk_builder_get_object(builder,"lbl1"));
	//btnimg=GTK_WIDGET(gtk_builder_get_object(builder,"btnimage"));
	//fixed1=GTK_WIDGET(gtk_builder_get_object(builder,"fixed1"));
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder,NULL);
      selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(tv1));  
       
	gtk_widget_show_all (window);

	gtk_main ();
   // int fd=popen("o.exe","r");
    
	//fgets(fd,)
	return 0;
}
G_MODULE_EXPORT void on_button1_clicked()
{
   
    //g_print("row selsesss:%d",d);    
}
G_MODULE_EXPORT void on_select_changed(GtkWidget *c)
{
    gchar *value;
    GtkTreeIter iter;
    GtkTreeModel *model;
    if(gtk_tree_selection_get_selected(GTK_TREE_SELECTION(c),&model,&iter)==FALSE)
        return;
    gtk_tree_model_get(model,&iter,0,&value,-1);
    printf("col 0=%s",value);
    
    
    
}

