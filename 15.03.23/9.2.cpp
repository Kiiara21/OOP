#include <iostream>
#include <cmath>

struct Point{
    int x;
    int y;
};

class Line{

private:
    Point m_first;
    Point m_second;
public:

    Line(){
        m_first.x = 0;
        m_first.y = 0;
        m_second.x = 0;
        m_second.y = 0;
    }

    Line(Point& first, Point& second){
        m_first = first;
        m_second = second;
    }

    void setFirstPoint(Point& first){
        m_first = first;
    }

    void setSecondPoint(Point& second){
        m_second = second;  
    }

    Point getFirstPoint() const { return m_first; }
    Point getSecondPoint() const { return m_second; }

    void print() const{
        std::cout << "(" << m_first.x << ", " << m_first.y << ")\n";
        std::cout << "(" << m_second.x << ", " << m_second.y << ")\n";
    }

    bool isUsporedni(Line& other){
        int x1, x2, y1, y2;
        int x3, x4, y3, y4;

        x1 = m_first.x;
        x2 = other.m_first.x;
        y1 = m_first.y;
        y2 = other.m_first.y;

        x3 = m_second.x;
        x4 = other.m_second.x;
        y3 = m_second.y;
        y4 = other.m_second.y;

        return sqrt(pow((x1-x2),2)+pow((y1-y2),2)) == sqrt(pow((x3-x4),2)+pow((y3-y4),2));
    }

    // fuck geometry 
    // bool pointOnLine(Point& point);
    // Point crossPoint(Line& other);

};

int main(){

    Point p1, p2, p3, p4;    
    p1.x = 2;
    p1.y = 4;
    p2.x = 2;
    p2.y = 0;
    p3.x = 4;
    p3.y = 4;
    p4.x = 4;
    p4.y = 0;


    Line l1(p1, p2);
    l1.print();
    Line l2(p3, p4);
    l2.print();

    std::cout << l1.isUsporedni(l2);

    return 0;
}