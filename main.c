#include <stdio.h>
#include <stdlib.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>

#include <X11/Xaw/Command.h>
#include <X11/Xaw/Paned.h>
//#include <X11/Xaw/Label.h>
//#include <X11/Xaw/Repeater.h>
//#include <X11/Xaw/Toggle.h>
//#include <X11/Xaw/Viewport.h>

void quit(Widget w, XtPointer client_data, XtPointer call_data) {
    exit(0);
}

void printHello(Widget w, XtPointer client_data, XtPointer call_data) {
    puts("Hello,World");
}

int main(int argc, char *argv[]) {
    // setting the local
    XtSetLanguageProc(NULL, NULL, NULL);

    XtAppContext app_context;
    Widget toplevel,
            quitBtn,
            helloBtn,
            panel;

    toplevel = XtVaAppInitialize(
            &app_context,
            "XAthena",
            NULL,
            0,
            &argc, argv,
            NULL,
            NULL);

    panel = XtVaCreateManagedWidget(
            "panel",
            panedWidgetClass,
            toplevel,
            XtNwidth, 256,
            NULL);

    helloBtn = XtVaCreateManagedWidget(
            "printhello",
            commandWidgetClass,
            panel,
            NULL);

    XtVaSetValues(helloBtn,
                  XtNlabel, "Print \"Hello world!\"",
                  NULL);

    quitBtn = XtVaCreateManagedWidget(
            "quitBtn",
            commandWidgetClass,
            panel,
            XtNlabel, "Quit!",
            NULL);

    XtAddCallback(helloBtn, XtNcallback, (XtCallbackProc) printHello, NULL);
    XtAddCallback(quitBtn, XtNcallback, (XtCallbackProc) quit, NULL);

    XtRealizeWidget(toplevel);
    XtAppMainLoop(app_context);
    return 0;
}
