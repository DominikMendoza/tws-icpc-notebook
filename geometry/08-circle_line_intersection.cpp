//having the equation of a line and the coordinates of the center (0,0) of a circle and its radius
//we will find the intersection points

//case circle_circle_intersection
//we can reduce this case to circle_line_intersection
//(X2,Y2): center of the second circle
//then we have equation (ax+by+c=0): a = -2(X2) b: -2(Y2) c: (X2)^2 + (Y2)^2 + r1^2 - r2^2

double r, a, b, c; // input

double x0 = -a*c/(a*a+b*b), y0 = -b*c/(a*a+b*b);

const double EPS = 1E-9; 

if (c*c > r*r*(a*a+b*b)+EPS)
    puts ("no points");
else if (abs (c*c - r*r*(a*a+b*b)) < EPS) {
    puts ("1 point");
    cout << x0 << ' ' << y0 << '\n';
}
else {
    double d = r*r - c*c/(a*a+b*b);
    double mult = sqrt (d / (a*a+b*b));
    double ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    puts ("2 points");
    cout << ax << ' ' << ay << '\n' << bx << ' ' << by << '\n';

    //points: (ax,ay) && (bx,by)
}