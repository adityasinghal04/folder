#ifndef LENS_H_INCLUDED
#define LENS_H_INCLUDED

#include "mirror.h"

class lens: public mirror
{
public:
    float index;

// To display the center of curvature, optical center and the focus of a lens
    void mark2(int);
// To input the radius of curvature of the lens
    void getradius2(int);

// To construct the lens
    void drawlens(int);
// To draw parallel lines from object to lens
    void drawpl2(int);

// To draw line from lens to image
    void drawrl2(int);

// To draw a line passing through Optical Centre
    void drawol(int);

// To calculate image coordinates
    void getimage2(int);

};

void lens :: mark2(int p)
    {
        // For a convex lens
        if(p==4)
        {
            double d=r*(1-cos(3.141592654/6));
            Circle Opoint(783-(1.9*d),249,2);
            Opoint.setColor(COLOR("green"));
            Opoint.imprint();
            Text center(783-d,259,"O");
            center.imprint();
            Circle Fpoint2(783-(r/(2*(index-1))),249,2);
            Fpoint2.setColor(COLOR("blue"));
            Fpoint2.imprint();
            Text focus2(793-(r/(2*(index-1))),259,"F2");
            focus2.imprint();
            Circle Fpoint1(783-(2*d)+(r/(2*(index-1))),249,2);
            Fpoint1.setColor(COLOR("blue"));
            Fpoint1.imprint();
            Text focus1(793-(2*d)+(r/(2*(index-1))),259,"F1");
            focus1.imprint();
            Text ocenter1(783-(2*d)+r,259,"C1");
            ocenter1.imprint();
            Circle Cpoint2(783-r,249,2);
            Cpoint2.setColor(COLOR("green"));
            Cpoint2.imprint();
            Text ocenter2(793-r,259,"C2");
            ocenter2.imprint();
        }
        // For concave lens
        if(p==5)
        {
            float f=(r/(2*(index-1)));
            Circle Opoint(773,249,2);
            Opoint.setColor(COLOR("green"));
            Opoint.imprint();
            Text center(783,259,"O");
            center.imprint();
            Circle Fpoint2(783+f,249,2);
            Fpoint2.setColor(COLOR("blue"));
            Fpoint2.imprint();
            Text focus2(793+f,259,"F2");
            focus2.imprint();
            Circle Fpoint1(763-f,249,2);
            Fpoint1.setColor(COLOR("blue"));
            Fpoint1.imprint();
            Text focus1(773-f,259,"F1");
            focus1.imprint();
            Text ocenter1(763-r,259,"C1");
            ocenter1.imprint();
            Circle Cpoint2(783+r,249,2);
            Cpoint2.setColor(COLOR("green"));
            Cpoint2.imprint();
            Text ocenter2(793+r,259,"C2");
            ocenter2.imprint();
        }

    }

void lens :: getradius2(int p)
    {
        //For convex and concave lens
        if (p==4 || p==5)
        {
            cout<<"Enter radius of the lens: ";
            cin>>r;
            cout<<"Enter refractive index of the lens: ";
            cin>>index;
        }
    }

void lens :: drawlens(int p)
    {
        // Construction of convex lens
        if (p==4)
        {
            rangebox();                                                        // Creates the limited region for clicking
            getradius2(p);
            Turtle t;
            Turtle m;
            t.penUp();
            m.penUp();
            t.forward(100);
            m.forward(100);
            t.left(90);
            m.left(90);
            t.forward(150);
            m.forward(150);
            t.penDown();
            m.penDown();
            m.right(180);
            repeat(30)
            {
                m.forward(3.14159*r/100);
                m.right(1);
                t.forward(3.14159*r/100);
                t.left(1);
            }
            m.right(120);
            t.left(120);
            tx=t.getX();
            repeat(30)
            {
                m.forward(3.14159*r/100);
                m.right(1);
                t.forward(3.14159*r/100);
                t.left(1);
            }
            mark2(p);
        }
        // Construction of concave lens
        if(p==5)
        {
            rangebox();
            getradius2(p);
            Turtle t1,t2;
            Turtle m1,m2;
            t1.penUp();
            t2.penUp();
            m1.penUp();
            m2.penUp();
            t1.forward(100);
            t2.forward(100);
            t1.left(90);
            t2.left(90);
            t1.forward(150);
            t2.forward(150);
            t2.right(180);

            t1.penDown();
            t2.penDown();
            m1.forward(100);
            m2.forward(100);

            m1.left(90);
            m2.left(90);

            m1.forward(150);
            m2.forward(150);

            m1.left(90);
            m2.left(90);

            m1.forward(20);
            m2.forward(20);

            m1.right(90);
            m2.left(90);

            m1.penDown();
            m2.penDown();

            repeat(60)
            {
                m1.forward(3.14159*r/180);
                m1.left(1);

                m2.forward(3.14159*r/180);
                m2.right(1);

                t1.forward(3.14159*r/180);
                t1.right(1);

                t2.forward(3.14159*r/180);
                t2.left(1);
            }
            m1.right(150);
            m1.forward(783-m1.getX());
            m2.left(150);
            m2.forward(783-m2.getX());

            t1.left(150);
            t1.forward(t1.getX()-783);
            t2.right(150);
            t2.forward(t2.getX()-783);
        }

    }

void lens :: drawpl2(int p)
    {
        float x1,y1;
        // For a convex lens
        if(p==4)
        {
            double dir=r*(1-cos(3.141592/6));
            Line pl(x,y,783-dir,y);
            pl.imprint();
        }
        // For a concave lens
        if(p==5)
        {
            // For a real object
            if(x<783)
            {
                Line pl(x,y,773,y);
                pl.imprint();
                Line p2(x,y,773,249);
                p2.imprint();
                float m2=(249-y)/(773-x);                                       // Construction of line joining the object
                float slocos=1/(sqrt(1+(m2*m2)));                               // to the optical center using parametric
                float slosin=m2*slocos;                                         // form
                Line l(x,y,x+(700*slocos),y+(700*slosin));
                l.imprint();
                float f=r/(2*(index-1));                                        // Construction of line appearing to pass
                float sloper=(y-249)*2*(index-1)/r;                             // through the focus of the mirror using
                float slocosr=1/(sqrt(1+(sloper*sloper)));                      // the parametric form
                float slosinr=sloper*slocosr;
                Line rl(773,y,773+(400*slocosr),y+(400*slosinr));
                Dash(763-f,249,773,y);                                          // The above line extended backwards
                rl.imprint();
                intersection(773,249,m2,773,y,sloper,x1,y1);                    // To find the image coordinates
                Circle c1(x1,y1,2);
                c1.imprint();
                Text t1(x1-10,y1+10,"Image");
                t1.imprint();
            }
            // For virtual object
            if(x>=783)
            {
                Dash(773,y,x,y);                                                // Lines for apparant formation of object
                Dash(773,249,x,y);
                Line li(450,y,773,y);
                li.imprint();
                float sloper=(y-249)*2*(index-1)/r;                             // Construction of line appearing to pass
                float slocosr=1/(sqrt(1+(sloper*sloper)));                      // through the focus using parametric form
                float slosinr=sloper*slocosr;
                float slopel=(y-249)/(x-773);                                   // Construction of incident ray passing through
                float slocosl=1/(sqrt(1+(slopel*slopel)));                      // the optical center
                float slosinl=slopel*slocosl;
                Line rl(773,y,773+(400*slocosr),y+(400*slosinr));
                Dash(773-(300*slocosr),y-(300*slosinr),773,y);
                Line lin(773-(300*slocosl),249-(300*slosinl),773,249);
                lin.imprint();
                rl.imprint();
            }
        }

    }

void lens :: drawrl2(int p)
    {
        // For convex lens
        if(p==4)
        {
            float dir=r*(1-cos(3.14/6));                                      // Calculation of position of optical center
            float slope=(249-y)/((r/2)-dir);
            float slocos=1/(sqrt(1+(slope*slope)));                             // Construction of the line using
            float slosin=slope*slocos;                                          // parametric form
            Line rl(783-dir,y,783-dir+(700*slocos),y+(700*slosin));
            rl.imprint();
        }
    }

void lens :: drawol(int p)
    {
        // For a convex lens
        if(p==4)
        {
            float dir=r*(1-cos(3.14/6));
            float slope=(249-y)/((783-dir-x)-10);
            float slocos=1/(sqrt(1+(slope*slope)));
            float slosin=slope*slocos;
            Line ol(x,y,x+(700*slocos),y+(700*slosin));
            ol.imprint();
        }
    }

void lens :: getimage2(int p)
    {
        float x1,y1;
        // For a convex lens
        if(p==4)
        {
            double f=r/(2*(index-1));
            double dir=r*(1-cos(3.141592/6));
            float m1=(249-y)/(783-dir-x);
            float m2=(249-y)/(f-dir);
            intersection(783-dir,249,m1,783-dir,y,m2,x1,y1);
            Circle imgpoint(xi,yi,2);
            imgpoint.setColor(COLOR("red"));
            imgpoint.imprint();
            Text image(xi-10,yi-10,"Image");
            image.setColor(COLOR("red"));
            image.imprint();
        }
    }



#endif
