#ifndef MIRROR_H_INCLUDED
#define MIRROR_H_INCLUDED

#include<simplecpp>

class mirror
{
public:

    float r,coord[][2],index;
    float x,y;
    double distx;
    float xi,yi,tx,sloperl,slopecl;

public:

//To draw principal axis
    void drawpx();

// To limit the range for clicking the object
    void rangebox();

// To get radius of the convex/concave mirror
    void getradius(int);

//To find the intersection point of two lines given their slopes and a point lying on them
    void intersection(float x1,float y1,float m1,float x2,float y2,float m2,float &x,float &y);

//To mark the centre of curvature and focus for a mirror
    void mark(int);

//To draw mirrors
    void drawmir(int);

//To draw dash lines
//Function arguments are initial x,initial y,final x,final y coordinates respectively
//Note that this function will only execute if first point is to the left of the second point
    void Dash(float x1,float y1,float x2,float y2);

//For an extended object-Take input from array the x and y coordinates of the object
    void intersection(float &ax,float &ay,int n1,int p);

//Inputs the number of sides of the polygon-n
//Stores the x and y coordinates of the object in an nx2 array
    void extended(int);

// Displays the image points
    void extendeddisplay(float a[][2],int n);

// To get object co-ordinate by getClick()
    void getobject(int);

// To draw a horizontal line from the object to the mirror
    void drawpl(int);

//To draw line from mirror to image
    void drawrl(int);

// To draw a line passing through centre of curvature
    void drawcl(int);

// To calculate Image co-ordinates
    void getimage(int);

//To display information about the image formed
    void display(int);
};



void mirror :: drawpx()
    {
        Line px(100,249,1250,249);
        px.imprint();
    }

void mirror :: rangebox()
    {
        Rectangle r(675,250,1250,340);
        r.imprint();
    }

void mirror :: getradius(int p)
    {
        if(p==1 || p==2)
        {
            cout<<"Enter radius of the mirror: ";
            cin>>r;
        }
    }

void mirror :: intersection(float x1,float y1,float m1,float x2,float y2,float m2,float &x,float &y)      //Call by reference
    {
        x=(y2-(m2*x2)-y1+(m1*x1))/(m1-m2);
        y=y1+(m1*(x-x1));
    }

void mirror :: mark(int p)
    {
        //For a convex mirror
        if(p==1)
        {
            Circle Cpoint(783+r,249,2);                                                        // Displaying the required
            Cpoint.setColor(COLOR("green"));                                                   // points
            Cpoint.imprint();
            Text center(783+r,259,"C");
            center.imprint();
            Circle Fpoint(783+0.5*r,249,2);
            Fpoint.setColor(COLOR("blue"));
            Fpoint.imprint();
            Text focus(783+0.5*r,259,"F");
            focus.imprint();
            Circle Opoint(783,249,2);
            Opoint.setColor(COLOR("green"));
            Opoint.imprint();
            Text ocenter(773,259,"O");
            ocenter.imprint();
        }
        //For a concave mirror
        if(p==2)
        {
            Circle Cpoint(783-r,249,2);                                                         // Displaying the required
            Cpoint.setColor(COLOR("green"));                                                    // points
            Cpoint.imprint();
            Text center(783-r,259,"C");
            center.imprint();
            Circle Fpoint(783-0.5*r,249,2);
            Fpoint.setColor(COLOR("blue"));
            Fpoint.imprint();
            Text focus(783-0.5*r,259,"F");
            focus.imprint();
            Circle Opoint(783,249,2);
            Opoint.setColor(COLOR("green"));
            Opoint.imprint();
            Text ocenter(793,259,"O");
            ocenter.imprint();
        }
    }

void mirror :: drawmir(int p)
    {
        //Construction of a convex mirror
        if(p==1)
        {
            rangebox();
            getradius(p);
            Turtle t;
            Turtle m;
            t.penUp();
            m.penUp();
            t.forward(100);
            t.left(90);
            m.forward(100);
            m.left(90);
            t.forward(150);
            m.forward(150);
            m.right(180);
            t.penDown();
            m.penDown();
            repeat(60)
            {
                m.forward(3.14159*r/180);
                m.right(359);
                t.forward(3.14159*r/180);
                t.left(359);
            }
            mark(p);
            double p,q,th=-1;
            repeat(16)                                                                      // Construction of Slash lines
            {
                Line l1(p,q,p+8*cos(1-th),q-8*sin(1-th));
                l1.imprint();
                p = 783+r - (r)*cos(th);
                q = 249-(r)*sin(th);
                th = th + (1/(7.0));
            }
        }
        //Construction of a concave mirror
        if(p==2)
        {
            rangebox();
            getradius(p);
            Turtle t;
            Turtle m;
            t.penUp();
            m.penUp();
            t.forward(100);
            t.left(90);
            m.forward(100);
            m.left(90);
            t.forward(150);
            m.forward(150);
            m.right(180);
            t.penDown();
            m.penDown();
            repeat(60)
            {
                m.forward(3.14159*r/180);
                m.right(1);
                t.forward(3.14159*r/180);
                t.left(1);
            }
            mark(p);
            //Drawing the slash lines behind the mirror
            double p,q,th=-1;
            repeat(16)                                                                  // Construction of Slash lines
            {
                Line l1(p,q,p+12*cos(1-th),q-12*sin(1-th));
                l1.imprint();
                p = 783-r + (r)*cos(th);
                q = 249+(r)*sin(th);
                th = th + (1/(7.0));
            }
        }
        // For plane mirror
        if(p==3)
        {
            rangebox();
            int i=0;
            Line mir(675,99,675,399);
            mir.imprint();
            repeat(30)                                                                      // Construction of Slash lines
            {
                Line slash1(675,105+10*i,685,115+10*i);
                slash1.imprint();
                i++;
            }
        }
    }

void mirror :: Dash(float x1,float y1,float x2,float y2)
    {
        int j=0;
        float dist=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        float d=dist/19;                                                        //Dividing the distance into equal parts
        float slope = (y2-y1)/(x2-x1);
        repeat(10)
        {
            //Constructing the parts using the parametric form of a line
            Line dash1(x1+j*d*cos(atan(slope)),y1+j*d*sin(atan(slope)),x1+(j+1)*d*cos(atan(slope)),y1+(j+1)*d*sin(atan(slope)));
            j=j+2;
            dash1.imprint();
        }
    }

void mirror :: intersection(float &ax,float &ay,int n1,int p)                         //Call by reference
    {
        //For a convex mirror
        if(p==1)
        {
            float m1,m2;
            m2=(249-ay)/(ax-783);
            m1=(249-ay)/(783+r-ax);
            intersection(ax,ay,m1,783,249,m2,ax,ay);                            //The image coordinates are stored in
                                                                                //place of object coordinates after the
                                                                                //function is executed.
        }
        //For a concave mirror
        if(p==2)
        {
            float m1,m2;
            m2=(249-ay)/(ax-783);
            m1=(249-ay)/(783-r-ax);
            intersection(ax,ay,m1,783,249,m2,ax,ay);                            //The image coordinates are stored in
                                                                                //place of object coordinates after the
                                                                                //function is executed.
        }
        //For a plane mirror
        if(p==3)
        {
            float m1,m2;
            m2=(249-ay)/(ax-675);
            m1=0;
            intersection(ax,ay,m1,675,249,m2,ax,ay);                            //The image coordinates are stored in
                                                                                //place of object coordinates after the
                                                                                //function is executed.
        }
        //For a convex lens
        if(p==4)
        {
            float dir,m1,m2;
            dir=r*(1-cos(3.141592/6));
            float f=r/(2*(index-1));
            m1=(249-ay)/(783-dir-ax);
            m2=(249-ay)/(f);
            intersection(ax,ay,m1,783-dir,ay,m2,ax,ay);                         //The image coordinates are stored in
                                                                                //place of object coordinates after the
                                                                                //function is executed.
        }
        //For a concave lens
        if(p==5)
        {
            float m1,m2;
            float f=r/(2*(index-1));
            m2=(249-ay)/(f);
            m1=(249-ay)/(773-ax);
            intersection(ax,ay,m1,773,ay,m2,ax,ay);                             //The image coordinates are stored in
                                                                                //place of object coordinates after the
                                                                                //function is executed.
        }
    }

void mirror :: extended(int q)
    {
        int n;
        float x1,y1,x2,y2;
        cout<<"Enter the number of sides of the polygon"<<endl;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            int r=getClick();
            int x=r/65536;
            int y=r%65536;
            coord[i][0]=x;
            coord[i][1]=y;
            Circle c(coord[i][0],coord[i][1],2);
            c.imprint();
            Text t((coord[i][0])-10,(coord[i][1])-10,"Object");
            t.imprint();
            Text t1((coord[i][0])+10,(coord[i][1])+10,i+1);
            t1.imprint();
            Text m(300,450,"Warning: Please select the points on any ONE side of the focus");
            m.imprint();
        }
        x1=coord[0][0];                                                         //Need to store these values as after the
        y1=coord[0][1];                                                         //function is executed(call by reference)
        x2=coord[n-1][0];                                                       //they will be lost.
        y2=coord[n-1][1];
        for(int i=0; i<n; i++)
        {
            if(i!=n-1)
            {
                Line l(coord[i][0],coord[i][1],coord[i+1][0],coord[i+1][1]);    //Line joining consecutive points
                l.imprint();
            }
            intersection(coord[i][0],coord[i][1],i,q);
            // coord[][] is modified to contain the image coordinates
            extendeddisplay(coord,i);                                           //Displays the image points
        }
        Line l(x2,y2,x1,y1);
        l.imprint();
        for(int i=0; i<n-1; i++)
        {
            Line l1(coord[i][0],coord[i][1],coord[i+1][0],coord[i+1][1]);       //Joins the displayed image points
            l1.imprint();
        }
        Line l2(coord[n-1][0],coord[n-1][1],coord[0][0],coord[0][1]);
        l2.imprint();
    }

void mirror :: extendeddisplay(float a[][2],int n)
    {
        Circle c(coord[n][0],coord[n][1],2);
        c.imprint();
        Text t1((coord[n][0])+10,(coord[n][1])+10,n+1);
        t1.imprint();
    }

void mirror :: getobject(int w)
    {
        x=w/65536;
        y=w%65536;
        if((x<50||x>1300)||(y<80)||(y>420))                                      // If clicked outside the box,Canvas closes
        {
            closeCanvas();
        }
        distx=675-x;
        Circle objpoint(x,y,2);
        objpoint.setColor(COLOR("red"));                                        // Displays the image point
        objpoint.imprint();
        Text object(x-10,y-10,"Object");
        object.setColor(COLOR("red"));
        object.imprint();
    }

void mirror :: drawpl(int p)
    {
        //For a convex mirror
        if(p==1)
        {
            //For a real object
            if(x<783)
            {
                Line pl(x,y,(783+r)-sqrt(r*r-(249-y)*(249-y)),y);
                pl.imprint();
            }
            //For a virtual object
            if(x>783)
            {
                Dash((783+r)-sqrt(r*r-(249-y)*(249-y)),y,x,y);
            }
        }
        //For a concave mirror
        if(p==2)
        {
            //For a virtual object
            if(x<783)
            {
                Line pl(x,y,783,249);
                pl.imprint();
            }
            //For a real object
            if(x>=783)
            {
                Dash((783-r)+sqrt(r*r-(249-y)*(249-y)),y,x,y);
            }
        }
        //For a plane mirror
        if(p==3)
        {
            // For a real object
            if(x<675)
            {
                Line pl(x,y,x+distx,y);
                pl.imprint();
                Line p2(x,y,675,249);
                p2.imprint();
            }
            // For a virtual object
            if(x>=675)
            {
                Dash(675,249,x,y);
                Dash(x+distx,y,x,y);
            }
        }
    }

void mirror :: drawrl(int p)
    {
        //For a convex mirror
        if(p==1)
        {
            //For a real object
            if(x<783)
            {
                Line rl((783+r)-sqrt(r*r-(249-y)*(249-y)),y,783+r/2,249);
                rl.imprint();
            }
            //For a virtual object
            if(x>783)
            {
                float slopef,slopefcos,slopefsin;
                slopef=(y-249)/((783+r)-sqrt(r*r-(249-y)*(249-y))-(783+r/2));
                slopefcos=1/sqrt(1+(slopef*slopef));
                slopefsin= slopef * slopefcos;
                sloperl=slopef;
                Line rl2(200,y,(783+r)-sqrt(r*r-(249-y)*(249-y)),y);
                rl2.imprint();
                Line rl3((783+r)-sqrt((r*r)-(249-y)*(249-y)),y,(783+r)-sqrt((r*r)-(249-y)*(249-y))-100*slopefcos,y-100*slopefsin);
                rl3.imprint();
                Dash((783+r)-sqrt(r*r-(249-y)*(249-y)),y,(783+r)-sqrt(r*r-(249-y)*(249-y))-200*slopefcos,y-200*slopefsin);
            }
        }
        //For a concave mirror
        if(p==2)
        {
            // For a real object
            if(x<783)
            {
                Line rl(783,249,xi,yi);
                rl.imprint();
            }
            // For a virtual object
            if(x>=783)
            {
                float slopef,slopefcos,slopefsin;
                slopef=(y-249)/((783-r)+sqrt(r*r-(249-y)*(249-y))-(783-r/2));
                slopefcos=1/sqrt(1+(slopef*slopef));
                slopefsin= slopef * slopefcos;
                sloperl=slopef;
                Line rl2(200,y,(783-r)+sqrt(r*r-(249-y)*(249-y)),y);
                rl2.imprint();
                Line rl3((783-r)+sqrt((r*r)-(249-y)*(249-y)),y,(783-r)+sqrt((r*r)-(249-y)*(249-y))-100*slopefcos,y-100*slopefsin);
                rl3.imprint();
                Dash((783-r)+sqrt(r*r-(249-y)*(249-y)),y,(783-r)+sqrt(r*r-(249-y)*(249-y))-200*slopefcos,y-200*slopefsin);
            }
        }
        // For a plane mirror
        if(p==3)
        {
            // For a real object
            if(x<675)
            {
                Line rl(675,249,x,249+(249-y));
                rl.imprint();
                Dash(675,249,x+2*distx,y);
                Dash(x+distx,y,x+2*distx,y);
            }
            //For a virtual object
            if(x>675)
            {
                Line rl1(x+2*distx,y,x+distx,y);
                rl1.imprint();
                Line rl2(x+2*distx,y,675,249);
                rl2.imprint();
                Line rl3(675,249,x+2*distx,249+(249-y));
                rl3.imprint();
            }
        }

    }

void mirror :: drawcl(int p)
    {
        // For a convex mirror
        if(p==1)
        {
            // For a real object
            if(x<783)
            {
                Line cl(x,y,783+r,249);
                cl.imprint();
            }
            // For a virtual object
            if(x>783)
            {
                float slopef,slopefcos,slopefsin;
                slopef = (249-y)/(783+r-x);                                         // Construction of line using the
                slopefcos=1/sqrt(1+(slopef*slopef));                                // parametric form.
                slopefsin= slopef * slopefcos;
                slopecl=slopef;
                Dash(783+r,249,x,y);
                Dash(783+r-200*slopefcos,249-200*slopefsin,783+r,249);
            }
        }
        // For a concave mirror
        if(p==2)
        {
            // For a real object
            if(x<783)
            {
                Line cl(x,y,xi,yi);
                cl.imprint();
            }
            // For a virtual object
            if(x>=783)
            {
                float slopef,slopefcos,slopefsin;
                slopef = (249-y)/(783-r-x);                                             // Construction of line using the
                slopefcos=1/sqrt(1+(slopef*slopef));                                    // the parametric form.
                slopefsin= slopef * slopefcos;
                slopecl=slopef;
                Dash(783-r,249,x,y);
                Dash(783-r-200*slopefcos,249-200*slopefsin,783-r,249);
            }
        }
    }

void mirror :: getimage(int p)
    {
        // For a convex mirror
        if(p==1)
        {
            // For a real object
            if(x<783)
            {
                xi=(783+r) - r*(x-(783+r))/(2*(x-(783+r))+r);
                yi=((y-249)*(xi-(783+r))/(x-(783+r)))+249;
            }
            // For a virtual object
            if(x>=783)
            {
                intersection(x,y,slopecl,(783+r)-sqrt((r*r)-(249-y)*(249-y)),y,sloperl,xi,yi);
                Dash(xi,yi,783+r,249);
            }
        }
        //For a concave mirror
        if(p==2)
        {
            // For a real object
            if(x<783)
            {
                xi=(783-r) + r*(x-(783-r))/(2*(x-(783-r))-r);
                yi=((y-249)*(xi-(783-r))/(x-(783-r)))+249;
            }
            // For a virtual object
            if(x>=783)
            {
                intersection(x,y,slopecl,(783-r)+sqrt((r*r)-(249-y)*(249-y)),y,sloperl,xi,yi);
                Dash(xi,yi,783+r,249);

            }
        }
        // For a plane mirror
        if(p==3)
        {
            xi=x+2*distx;
            yi=y;
        }
        Circle imgpoint(xi,yi,2);
        imgpoint.setColor(COLOR("red"));
        imgpoint.imprint();
        Text image(xi-10,yi-10,"Image");
        image.setColor(COLOR("red"));
        image.imprint();
    }


void mirror :: display(int p)
    {
        // For convex & concave mirrors
        if(p==1||p==2)
        {
            Text radius(150,450,"Radius of Mirror: ");
            radius.imprint();
            Text radval(250,450,r);
            radval.imprint();
        }
        // For convex and concave lens
        if(p==4||p==5)
        {
            Text radius(150,450,"Radius of lens:");
            radius.imprint();
            //Text index(150,510,"Refractive index of the material:");
            //index.imprint();
            Text radval(250,450,r);
            radval.imprint();
            //Text indexval(250,470,index);
            //indexval.imprint();
        }
        if(p!=3)
        {
            Text objcoor(150,470,"Object Co-ordinates (in pixel): (");
            objcoor.imprint();
            Text objx(265,470,x-783);
            objx.imprint();
            Text comma1(283,470,",");
            comma1.imprint();
            Text objy(298,470,y-249);
            objy.imprint();
            Text objbrack(315,470,")");
            objbrack.imprint();
            Text imgcoor(150,490,"Image Co-ordinates (in pixel): (  ");
            imgcoor.imprint();
            Text imgx(265,490,xi-783);
            imgx.imprint();
            Text comma2(305,490,",");
            comma2.imprint();
            Text imgy(335,490,yi-249);
            imgy.imprint();
            Text imgbrack(375,490,")");
            imgbrack.imprint();
            // For convex and concave mirrors
            if(p==1||p==2)
            {
                float m=-(xi-783)/(x-783);                                      // Formula for longitudinal magnification
                Text magnif(150,510,"Magnification:");                          // m=-(Image coordinate)/(Object coordinate)
                magnif.imprint();
                Text magnifval(245,510,m);
                magnifval.imprint();
            }
        }
    }

#endif
