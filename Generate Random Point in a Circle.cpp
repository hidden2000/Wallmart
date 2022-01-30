class Solution {
public:
double x, y, r;
double PI = 3.14159265358979323846264;

Solution(double radius, double x_center, double y_center) {
    
    r = radius;
    x = x_center;
    y = y_center;
    
}

double gen( )     
{
    double a =(double) rand( )/ RAND_MAX;    
    return a;
}

vector<double> randPoint() {
    
    double length = sqrt(gen( )) * r;    
    double theta = gen() * 2* PI;    
    double xaxis = x + length*cos(theta);    
    double yaxis = y + length*sin(theta);    
    return vector<double>{xaxis,yaxis};
}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */