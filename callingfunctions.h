#ifndef CALLINGFUNCTIONS_H_INCLUDED
#define CALLINGFUNCTIONS_H_INCLUDED

#include "lens.h"

// Executed only on clicking extended object button
// Called from respective optical instrument object initializer
// Function to initialize object for class mirror
void extendedobjmir(int p)
{
    initCanvas("ImaGe",1366,798);
    mirror v;
    v.drawpx();
    Text instruct1(600,40,"Please enter radius of the mirror in the Terminal/cmd window.");
    instruct1.imprint();
    v.drawmir(p);
    Text instruct2(600,60,"Please enter the number of polygon sides in the Terminal/cmd window.");
    instruct2.imprint();
    Text instruct3(600,80,"Please enter the objects within the box.");
    instruct3.imprint();
    v.extended(p);
    getClick();
}

// Executed only on clicking extended object button
// Called from respective optical instrument object initializer
// Function to initialize object for class lens
void extendedobjlens(int p)
{
    initCanvas("ImaGe",1366,798);
    lens l;
    l.drawpx();
    Text instruct1(600,40,"Please enter radius  & refractive index of the lens in the Terminal/cmd window.");
    instruct1.imprint();
    l.drawlens(p);
    l.mark2(5);
    Text instruct2(600,60,"Please enter the number of polygon sides in the Terminal/cmd window.");
    instruct2.imprint();
    Text instruct3(600,80,"Please enter the objects within the box.");
    instruct3.imprint();
    l.extended(p);
    getClick();
}

// Executed after convex mirror option is selected
// Function to initialize object for class mirror
void convexmirror(int q)
{
    if(q==0)                                                                      // Corresponds to point object selection
    {
        initCanvas("ImaGe",1366,798);
        mirror x;
        x.drawpx();
        Text instruct(600,80,"Please enter the radius in the Terminal/cmd window");
        instruct.imprint();
        x.drawmir(1);
        Text warn(600,60,"Please enter the object within box.");
        warn.imprint();
        int q = getClick();
        x.getobject(q);
        x.drawpl(1);
        x.drawrl(1);
        x.drawcl(1);
        x.getimage(1);
        x.display(1);
        wait(5);
        getClick();
        closeCanvas();
    }
    else if(q==1)                                                             // Corresponds to extended object selection
    {
        extendedobjmir(q);
    }
}

// Executed when concave mirror option is selected
// Function which initializes object for class mirror
void concavemirror(int q)
{
    if(q==0)                                                                // Corresponds to point object selection
    {
        initCanvas("ImaGe",1366,798);
        mirror v;
        v.drawpx();
        Text instruct(600,80,"Please enter the radius in the Terminal/cmd window");
        instruct.imprint();
        v.drawmir(2);
        Text warn(600,60,"Please enter the object within box.");
        warn.imprint();
        int q = getClick();
        v.getobject(q);
        if(v.x<783)                                                         // Sequence of construction lines is
        {                                                                   // IMPORTANT
            v.drawpl(2);
            v.getimage(2);
            v.drawrl(2);
            v.drawcl(2);
        }
        if(v.x>=783)                                                        // Sequence of construction lines is
        {                                                                   // IMPORTANT
            v.drawrl(2);
            v.drawpl(2);
            v.drawcl(2);
            v.getimage(2);
        }
        v.display(2);
        wait(5);
        getClick();
        closeCanvas();
    }
    else if(q==2)                                                           // Corresponds to extended object selection
    {
        extendedobjmir(q);
    }
}

// Executed after plane mirror option is selected
// Function which initializes the object for class mirror
void planemirror(int q)
{
    if(q==0)                                                                      // Corresponds to point object selection
    {
        initCanvas("ImaGe",1366,798);
        mirror m;
        m.drawpx();
        m.drawmir(3);
        Text warn(600,60,"Please enter the object within box.");
        warn.imprint();
        int q = getClick();
        m.getobject(q);
        if(m.x<675)
        {
            m.drawpl(3);
            m.drawrl(3);
        }
        if(m.x>675)
        {
            m.drawrl(3);
            m.drawpl(3);
        }
        m.getimage(3);
        m.display(3);
        wait(5);
        getClick();
        closeCanvas();
    }
    else if(q==3)
    {
        extendedobjmir(q);                                                    // Corresponds to extended object selection
    }
}

// Executed when convex lens option is selected
// Function which initializes object for class lens
void convexlens(int q)
{
    if(q==0)                                                                // Corresponds to point object selection
    {
        initCanvas("ImaGe",1366,798);
        lens lx;
        lx.drawpx();
        Text instruct(600,80,"Please enter the radius & refractive index in the Terminal/cmd window");
        instruct.imprint();
        lx.drawlens(4);
        Text warn(600,60,"Please enter the object within box.");
        warn.imprint();
        int q = getClick();
        lx.getobject(q);
        lx.drawpl2(4);
        lx.drawrl2(4);
        lx.drawol(4);
        lx.getimage2(4);
        wait(5);
        getClick();
        closeCanvas();
    }
    else if(q==4)
    {
        extendedobjlens(q);                                                 // Corresponds to extended object selection
    }
}

// Executed when concave lens option is selected
// Function which initializes object for class lens
void concavelens(int q)
{
    if(q==0)                                                                      // Corresponds to point object selection
    {
        initCanvas("ImaGe",1366,798);
        lens lc;
        lc.drawpx();
        Text instruct(600,80,"Please enter the radius & refractive index in the Terminal/cmd window");
        instruct.imprint();
        lc.drawlens(5);
        Text warn(600,60,"Please enter the object within box.");
        warn.imprint();
        lc.mark2(5);
        int q = getClick();
        lc.getobject(q);
        lc.drawpl2(5);
        lc.drawrl2(5);
        lc.drawol(5);
        lc.getimage2(5);
        wait(5);
        getClick();
        closeCanvas();
    }
    if(q==5)
    {
        extendedobjlens(q);                                                   // Corresponds to extended object selection
    }
}

// Executed when INFO button is clicked
// Displays the INFO box
void info()
{
    initCanvas("Info",300,300);
    Text t1(150,25,"ImaGe-Image Generator");
    t1.imprint();
    Text t2(150,50,"This is a copyright of ");
    t2.imprint();
    Text t3(150,75,"Team ImaGe");
    t3.imprint();
    Text t7(150,100,"TEAM MEMBERS:");
    t7.imprint();
    Text t8(150,125,"ADITYA SINGHAL");
    t8.imprint();
    Text t9(150,150,"AKHIL VARMA");
    t9.imprint();
    Text t10(150,175,"SAI THEJA");
    t10.imprint();
    Text t11(150,200,"SHANTANU SHAH");
    t11.imprint();
    Text t4(150,225,"CS-101 PROJECT");
    t4.imprint();
    Text t5(150,250,"Spring Semester");
    t5.imprint();
    Text t6(150,275,"2014-2015");
    t6.imprint();
    wait(10);
}

// Executed when HELP button is clicked
// Displays the HELP box
void help()
{
    initCanvas("HELP",500,200);
    Text os(50,10,"HELP BOX:-");
    os.setColor(COLOR("blue"));
    os.imprint();
    Text os1(250,50,"1)Please click on any one of optical instrument shown in the window.");
    os1.imprint();
    Text os2(201,70,"2)Enter the radius and refractive index in the terminal.");
    os2.imprint();
    Text os3(228,90,"3)For an extended object,enter the number of sides in terminal.");
    os3.imprint();
    wait(10);
}

#endif
