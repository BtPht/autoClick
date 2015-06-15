#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

#define RMB 1 /*  Right Mouse Button */

int main(int argc, char **argv)
{
        Display *d;
        struct timespec interval;
        interval.tv_sec = 0;
        interval.tv_nsec = 100000000;

        if(!(d = XOpenDisplay(NULL))) {
                fprintf(stderr, "\"%s\" can't open.\n", XDisplayName(NULL));
                exit(EXIT_FAILURE);
        }

        int ignore;
        if(!(XQueryExtension(d, "XTEST", &ignore, &ignore, &ignore))) {
                fprintf(stderr, "\"XTEST\" extension disabled.\n");
                exit(EXIT_FAILURE);
        }

        while(1){
                XTestFakeButtonEvent(d, RMB, True, 0);
                XTestFakeButtonEvent(d, RMB, False, 0);
                nanosleep(&interval, NULL);
                XSync(d, False);
        }
        XCloseDisplay(d);
        exit(EXIT_SUCCESS);
}
