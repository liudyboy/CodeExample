#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <string>
namespace shapes
{
  class Rectangle
  {
  public:
    int x0, y0, x1, y1;      // 矩形对角线上的两个点坐标
    Rectangle();
    Rectangle(int x0, int y0, int x1, int y1);
    Rectangle(const std::string& msg);
    ~Rectangle();
    int getArea();
    void getSize(int* width, int* height);
    void move(int dx, int dy);
  };
}
#endif
